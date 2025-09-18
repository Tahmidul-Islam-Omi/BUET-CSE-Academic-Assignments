parser grammar C2105115Parser;

options {
    tokenVocab = C2105115Lexer;
}

@parser::header {
    #pragma once
    #include <iostream>
    #include <fstream>
    #include <string>
    #include <cstdlib>
    #include "C2105115Lexer.h"
    #include "2105115_SymbolTable.h"  

    extern std::ofstream parserLogFile;
    extern std::ofstream errorFile;

    extern int syntaxErrorCount;

}

@parser::members {
    SymbolTable symbolTable{7}; // Initialize with 7 buckets, using default hash function
    std::string currentTypeSpecifier = ""; // Store the current type specifier
    int func_def=0;
    
    void writeIntoparserLogFile(const std::string message) {
        if (!parserLogFile) {
            std::cout << "Error opening parserLogFile.txt" << std::endl;
            return;
        }

        parserLogFile << message << std::endl;
        parserLogFile.flush();
    }

    void writeIntoErrorFile(const std::string message) {
        if (!errorFile) {
            std::cout << "Error opening errorFile.txt" << std::endl;
            return;
        }
        errorFile << message << std::endl;
        errorFile.flush();
    }
}


start : p=program
	{
        writeIntoparserLogFile(std::string("Line ") + std::to_string($p.stop->getLine()) + ": start : program");
        writeIntoparserLogFile("");
        symbolTable.printAllScopeTables(parserLogFile);
        writeIntoparserLogFile("");
        writeIntoparserLogFile("Total number of lines: " + std::to_string($p.stop->getLine()));
        writeIntoparserLogFile("Total number of errors: " + std::to_string(syntaxErrorCount));
	}
	;

program returns [std::string text]
    : p=program u=unit {
            $text = $p.text + "\n" + $u.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($u.stop->getLine()) + ": program : program unit");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	| u=unit {
            $text = $u.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($u.stop->getLine()) + ": program : unit");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	;
	
unit returns [std::string text]
 : v=var_declaration {
            $text = $v.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($v.stop->getLine()) + ": unit : var_declaration");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($v.text);
            writeIntoparserLogFile("");
        }
     | fd=func_declaration {
            $text = $fd.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($fd.stop->getLine()) + ": unit : func_declaration");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($fd.text);
            writeIntoparserLogFile("");
        }
     | fdef=func_definition {
            $text = $fdef.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($fdef.stop->getLine()) + ": unit : func_definition");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($fdef.text);
            writeIntoparserLogFile("");
        }
     ;
     
func_declaration returns [std::string text]
        : t=type_specifier i=ID lp=LPAREN{

        } p=parameter_list rp=RPAREN s=SEMICOLON {
            $text = $t.text + " " + $i->getText() + $lp->getText() + $p.text + $rp->getText() + $s->getText();

            bool inserted = symbolTable.insert($i->getText(), currentTypeSpecifier , parserLogFile);

 		    if (!inserted) {
 		        writeIntoErrorFile("Error in func_declaration");
 		         syntaxErrorCount++;
 		    }

            writeIntoparserLogFile(std::string("Line ") + std::to_string($i->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		| t=type_specifier i=ID lp=LPAREN rp=RPAREN s=SEMICOLON {
            $text = $t.text + " " + $i->getText() + $lp->getText() + $rp->getText() + $s->getText();

            bool inserted = symbolTable.insert($i->getText(), currentTypeSpecifier , parserLogFile);

 		    if (!inserted) {
 		        writeIntoErrorFile("Error in func_declaration");
 		          syntaxErrorCount++;
 		    }

            writeIntoparserLogFile(std::string("Line ") + std::to_string($i->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		;
		 
func_definition returns [std::string text]
         : t=type_specifier i=ID {

            // First insert the function name in the current scope
            bool inserted = symbolTable.insert($i->getText(), currentTypeSpecifier, parserLogFile);

         }lp=LPAREN {
            
            func_def = 1;
            // Enter a new scope for function parameters
            symbolTable.enterScope();
         } p=parameter_list rp=RPAREN c=compound_statement {
            $text = $t.text + " " + $i->getText() + $lp->getText() + $p.text + $rp->getText() + $c.text;

            writeIntoparserLogFile(std::string("Line ") + std::to_string($c.stop->getLine()) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		| t=type_specifier i=ID {
            // First insert the function name in the current scope
            bool inserted = symbolTable.insert($i->getText(), currentTypeSpecifier, parserLogFile);

        }lp=LPAREN {
            func_def = 1;
            // Enter a new scope for function parameters (even if none)
            symbolTable.enterScope();
        } rp=RPAREN c=compound_statement {
            $text = $t.text + " " + $i->getText() + $lp->getText() + $rp->getText() + $c.text;

            writeIntoparserLogFile(std::string("Line ") + std::to_string($c.stop->getLine()) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
 		;				


parameter_list returns [std::string text]
        : p=parameter_list c=COMMA t=type_specifier i=ID {
            $text = $p.text + $c->getText() + " " + $t.text + " " + $i->getText();

            if(func_def == 1) {

                bool inserted = symbolTable.insert($i->getText(), currentTypeSpecifier , parserLogFile);

 		        if (!inserted) {
 		            writeIntoErrorFile("Error in parameter_list");
                    writeIntoErrorFile("");
 		            syntaxErrorCount++;
 		        }

            }

            writeIntoparserLogFile(std::string("Line ") + std::to_string($i->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		| p=parameter_list c=COMMA t=type_specifier {
            $text = $p.text + $c->getText() + " " + $t.text;

            writeIntoparserLogFile(std::string("Line ") + std::to_string($t.start->getLine()) + ": parameter_list : parameter_list COMMA type_specifier");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
 		| t=type_specifier i=ID {
            $text = $t.text + " " + $i->getText();

            if(func_def == 1) {

                bool inserted = symbolTable.insert($i->getText(), currentTypeSpecifier , parserLogFile);

 		        if (!inserted) {
 		            writeIntoErrorFile("Error in parameter_list");
                    writeIntoErrorFile("");
 		            syntaxErrorCount++;
 		        }

            }

            writeIntoparserLogFile(std::string("Line ") + std::to_string($i->getLine()) + ": parameter_list : type_specifier ID");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		| t=type_specifier {
            $text = $t.text;

            writeIntoparserLogFile(std::string("Line ") + std::to_string($t.start->getLine()) + ": parameter_list : type_specifier");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
 		;

 		
compound_statement returns [std::string text]
        : l=LCURL {
            	if (func_def==1) {
                    func_def=0;
                }

                else {
                    symbolTable.enterScope();
                }

        }s=statements r=RCURL {

            cout<<"nice"<<endl;
            $text = $l->getText() + "\n" + $s.text + "\n" + $r->getText();
            writeIntoparserLogFile(std::string("Line ") + std::to_string($r->getLine()) + ": compound_statement : LCURL statements RCURL");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
            
            // Print the symbol table before exiting the scope
            writeIntoparserLogFile("");
            symbolTable.printAllScopeTables(parserLogFile);                               
            writeIntoparserLogFile("");
            symbolTable.exitScope(parserLogFile);
            cout<<"nice222"<<endl;
            
        }
 		| l=LCURL {
                if (func_def==1) {
                    func_def=0;
                }

                else {
                    symbolTable.enterScope();
                }
                
        }r=RCURL {
            $text = $l->getText() + $r->getText();
            writeIntoparserLogFile(std::string("Line ") + std::to_string($r->getLine()) + ": compound_statement : LCURL RCURL");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
            
            // Print the symbol table before exiting the scope
            writeIntoparserLogFile("");
            symbolTable.printAllScopeTables(parserLogFile);
            writeIntoparserLogFile("");
            symbolTable.exitScope(parserLogFile);
            
        }
 		;
 		    
var_declaration returns [std::string text]
    : t=type_specifier dl=declaration_list sm=SEMICOLON {
        writeIntoparserLogFile(std::string("Line ") + std::to_string($sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON");
		writeIntoparserLogFile("");
        $text = $t.text + " " + $dl.text + $sm->getText();
        writeIntoparserLogFile($text);
        writeIntoparserLogFile("");
      }

    | t=type_specifier de=declaration_list_err sm=SEMICOLON {
        writeIntoErrorFile(
            std::string("Line# ") + std::to_string($sm->getLine()) +
            " with error name: " + $de.error_name +
            " - Syntax error at declaration list of variable declaration"
        );
        writeIntoErrorFile("");
        $text = $t.text + " error" + $sm->getText();
        syntaxErrorCount++;
      }
    ;

declaration_list_err returns [std::string error_name]: {
        $error_name = "Error in declaration list";
    };

 		 
type_specifier returns [std::string name_line, std::string text]	
        : INT {
            $name_line = "INT";
            $text = $INT->getText();
            currentTypeSpecifier = "INT"; // Store the current type
            writeIntoparserLogFile(std::string("Line ") + std::to_string($INT->getLine()) + ": type_specifier : " + $name_line);
			writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
 		| FLOAT {
            $name_line = "FLOAT";
            $text = $FLOAT->getText();
            currentTypeSpecifier = "FLOAT"; // Store the current type
            writeIntoparserLogFile(std::string("Line ") + std::to_string($FLOAT->getLine()) + ": type_specifier : " + $name_line);
			writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
 		| VOID {
            $name_line = "VOID";
            $text = $VOID->getText();
            currentTypeSpecifier = "VOID"; // Store the current type
            writeIntoparserLogFile(std::string("Line ") + std::to_string($VOID->getLine()) + ": type_specifier : " + $name_line);
			writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
 		;
 		
declaration_list returns [std::string text]
 		  : dl=declaration_list cm=COMMA id=ID {
 		      $text = $dl.text + $cm->getText() + $id->getText();
 		      // Insert ID into symbol table with current type
 		      bool inserted = symbolTable.insert($id->getText(), currentTypeSpecifier , parserLogFile);
 		      if (!inserted) {
 		          writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + $id->getText());
                  writeIntoErrorFile("");
 		          syntaxErrorCount++;
 		      }
 		      writeIntoparserLogFile(std::string("Line ") + std::to_string($id->getLine()) + ": declaration_list : declaration_list COMMA ID");
 		      writeIntoparserLogFile("");
			  writeIntoparserLogFile($text);
			  writeIntoparserLogFile("");
 		      
 		  }
 		  | dl=declaration_list cm=COMMA id=ID LTHIRD ci=CONST_INT RTHIRD {
            cout<<"test1"<<endl;
 		      $text = $dl.text + $cm->getText() + $id->getText() + $LTHIRD->getText() + $ci->getText() + $RTHIRD->getText();
 		      // Insert array ID into symbol table with current type + array notation
 		      std::string arrayType = currentTypeSpecifier + "[" + $ci->getText() + "]";
 		      bool inserted = symbolTable.insert($id->getText(), arrayType, parserLogFile);
 		      if (!inserted) {
 		          writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + $id->getText());
 		          writeIntoErrorFile("");
                  syntaxErrorCount++;
 		      }
 		      writeIntoparserLogFile(std::string("Line ") + std::to_string($id->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
 		      writeIntoparserLogFile("");
			  writeIntoparserLogFile($text);
			  writeIntoparserLogFile("");
            cout<<"test2"<<endl;
 		      
 		  }
 		  | id=ID {
 		      $text = $id->getText();
 		      // Insert ID into symbol table with current type
 		      bool inserted = symbolTable.insert($id->getText(), currentTypeSpecifier, parserLogFile);
 		      if (!inserted) {
 		          writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + $id->getText());
 		          writeIntoErrorFile("");
                  syntaxErrorCount++;
 		      }
 		      writeIntoparserLogFile(std::string("Line ") + std::to_string($id->getLine()) + ": declaration_list : ID");
 		      writeIntoparserLogFile("");
			  writeIntoparserLogFile($text);
			  writeIntoparserLogFile("");
 		     
 		  }
 		  | id=ID LTHIRD ci=CONST_INT RTHIRD {
 		      $text = $id->getText() + $LTHIRD->getText() + $ci->getText() + $RTHIRD->getText();
 		      // Insert array ID into symbol table with current type + array notation
 		      std::string arrayType = currentTypeSpecifier + "[" + $ci->getText() + "]";
 		      bool inserted = symbolTable.insert($id->getText(), arrayType , parserLogFile);
 		      if (!inserted) {
 		          writeIntoErrorFile("Error at line " + std::to_string($id->getLine()) + ": Multiple declaration of " + $id->getText());
 		          writeIntoErrorFile("");
                  syntaxErrorCount++;
 		      }
 		      writeIntoparserLogFile(std::string("Line ") + std::to_string($id->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD");
 		      writeIntoparserLogFile("");
			  writeIntoparserLogFile($text);
			  writeIntoparserLogFile("");
 		    
 		  }
 		  ;
 		  
statements returns [std::string text]
       : s=statement {
            $text = $s.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($s.start->getLine()) + ": statements : statement");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	   | ss=statements s=statement {
            $text = $ss.text + "\n" + $s.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($s.stop->getLine()) + ": statements : statements statement");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	   ;
	   
statement returns [std::string text]
      : v=var_declaration {
            $text = $v.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($v.stop->getLine()) + ": statement : var_declaration");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	  | es=expression_statement {
            $text = $es.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($es.stop->getLine()) + ": statement : expression_statement");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	  | c=compound_statement {
            $text = $c.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($c.stop->getLine()) + ": statement : compound_statement");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	  | f=FOR lp=LPAREN e1=expression_statement e2=expression_statement exp=expression rp=RPAREN s=statement {
            $text = $f->getText() + $lp->getText() + $e1.text + $e2.text + $exp.text + $rp->getText() + $s.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($s.stop->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	  | i=IF lp=LPAREN exp=expression rp=RPAREN s=statement {
            $text = $i->getText() + $lp->getText() + $exp.text + $rp->getText() + $s.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($s.stop->getLine()) + ": statement : IF LPAREN expression RPAREN statement");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	  | i=IF lp=LPAREN exp=expression rp=RPAREN s1=statement el=ELSE s2=statement {
            $text = $i->getText() + $lp->getText() + $exp.text + $rp->getText() + $s1.text + " " + $el->getText() + " " + $s2.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($s2.stop->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	  | w=WHILE lp=LPAREN exp=expression rp=RPAREN s=statement {
            $text = $w->getText() + $lp->getText() + $exp.text + $rp->getText() + $s.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($s.stop->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	  | p=PRINTLN lp=LPAREN id=ID rp=RPAREN sm=SEMICOLON {
            cout << "Printf" << endl;
            $text = $p->getText() + $lp->getText() + $id->getText() + $rp->getText() + $sm->getText();
            writeIntoparserLogFile(std::string("Line ") + std::to_string($sm->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	  | r=RETURN exp=expression sm=SEMICOLON {
            $text = $r->getText() + " " + $exp.text + $sm->getText();
            writeIntoparserLogFile(std::string("Line ") + std::to_string($sm->getLine()) + ": statement : RETURN expression SEMICOLON");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	  ;
	  
expression_statement returns [std::string text]
        : s=SEMICOLON {
            $text = $s->getText();
            writeIntoparserLogFile(std::string("Line ") + std::to_string($s->getLine()) + ": expression_statement : SEMICOLON");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		| e=expression s=SEMICOLON {
            $text = $e.text + $s->getText();
            writeIntoparserLogFile(std::string("Line ") + std::to_string($e.start->getLine()) + ": expression_statement : expression SEMICOLON");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		;
	  
variable returns [std::string text]
      : id=ID {
            $text = $id->getText();
            writeIntoparserLogFile(std::string("Line ") + std::to_string($id->getLine()) + ": variable : ID");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	 | id=ID l=LTHIRD e=expression r=RTHIRD {
            $text = $id->getText() + $l->getText() + $e.text + $r->getText();
            writeIntoparserLogFile(std::string("Line ") + std::to_string($id->getLine()) + ": variable : ID LTHIRD expression RTHIRD");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	 ;
	 
expression returns [std::string text]
       : l=logic_expression {
             $text = $l.text;
             writeIntoparserLogFile(std::string("Line ") + std::to_string($l.start->getLine()) + ": expression : logic_expression");
             writeIntoparserLogFile("");
             writeIntoparserLogFile($text);
             writeIntoparserLogFile("");
         }
	   | v=variable a=ASSIGNOP l=logic_expression {
             $text = $v.text + $a->getText() + $l.text;
             writeIntoparserLogFile(std::string("Line ") + std::to_string($v.start->getLine()) + ": expression : variable ASSIGNOP logic_expression");
             writeIntoparserLogFile("");
             writeIntoparserLogFile($text);
             writeIntoparserLogFile("");
         }
	   ;
			
logic_expression returns [std::string text]
        : r=rel_expression {
            $text = $r.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($r.start->getLine()) + ": logic_expression : rel_expression");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		 | r1=rel_expression l=LOGICOP r2=rel_expression {
            $text = $r1.text + $l->getText() + $r2.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($r1.start->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		 ;
			
rel_expression returns [std::string text]
        : s=simple_expression {
            $text = $s.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($s.start->getLine()) + ": rel_expression : simple_expression");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		| s1=simple_expression r=RELOP s2=simple_expression {
            $text = $s1.text + $r->getText() + $s2.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($s1.start->getLine()) + ": rel_expression : simple_expression RELOP simple_expression");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		;
				
simple_expression returns [std::string text]
        : t=term {
            $text = $t.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($t.start->getLine()) + ": simple_expression : term");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		  | s=simple_expression a=ADDOP t=term {
            $text = $s.text + $a->getText() + $t.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($s.start->getLine()) + ": simple_expression : simple_expression ADDOP term");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		  ;
					
term returns [std::string text]
    : u=unary_expression {
            $text = $u.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($u.start->getLine()) + ": term : unary_expression");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
     | t=term m=MULOP u=unary_expression {
            $text = $t.text + $m->getText() + $u.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($t.start->getLine()) + ": term : term MULOP unary_expression");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
     ;

unary_expression returns [std::string text]
        : a=ADDOP u=unary_expression {
            $text = $a->getText() + $u.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($a->getLine()) + ": unary_expression : ADDOP unary_expression");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		 | n=NOT u=unary_expression {
            $text = $n->getText() + $u.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($n->getLine()) + ": unary_expression : NOT unary_expression");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		 | f=factor {
            $text = $f.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($f.start->getLine()) + ": unary_expression : factor");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		 ;
	
factor returns [std::string text]
    : v=variable {
            $text = $v.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($v.start->getLine()) + ": factor : variable");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	| id=ID lp=LPAREN a=argument_list rp=RPAREN {
            $text = $id->getText() + $lp->getText() + $a.text + $rp->getText();
            writeIntoparserLogFile(std::string("Line ") + std::to_string($id->getLine()) + ": factor : ID LPAREN argument_list RPAREN");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	| lp=LPAREN e=expression rp=RPAREN {
            $text = $lp->getText() + $e.text + $rp->getText();
            writeIntoparserLogFile(std::string("Line ") + std::to_string($lp->getLine()) + ": factor : LPAREN expression RPAREN");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	| ci=CONST_INT {
            $text = $ci->getText();
            writeIntoparserLogFile(std::string("Line ") + std::to_string($ci->getLine()) + ": factor : CONST_INT");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	| cf=CONST_FLOAT {
            $text = $cf->getText();
            writeIntoparserLogFile(std::string("Line ") + std::to_string($cf->getLine()) + ": factor : CONST_FLOAT");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	| v=variable ic=INCOP {
            $text = $v.text + $ic->getText();
            writeIntoparserLogFile(std::string("Line ") + std::to_string($v.start->getLine()) + ": factor : variable INCOP");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	| v=variable dc=DECOP {
            $text = $v.text + $dc->getText();
            writeIntoparserLogFile(std::string("Line ") + std::to_string($v.start->getLine()) + ": factor : variable DECOP");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	;
	
argument_list returns [std::string text]
        : a=arguments {
            $text = $a.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($a.start->getLine()) + ": argument_list : arguments");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
		| {
            $text = "";
        }
		;
	
arguments returns [std::string text]
        : a=arguments c=COMMA l=logic_expression {
            $text = $a.text + $c->getText() + $l.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($a.start->getLine()) + ": arguments : arguments COMMA logic_expression");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	      | l=logic_expression {
            $text = $l.text;
            writeIntoparserLogFile(std::string("Line ") + std::to_string($l.start->getLine()) + ": arguments : logic_expression");
            writeIntoparserLogFile("");
            writeIntoparserLogFile($text);
            writeIntoparserLogFile("");
        }
	      ;
