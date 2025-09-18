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
    #include "SymbolTable.h"
}

@parser::members {
    SymbolTable symbolTable{7}; // Initialize with 7 buckets, using default hash function
    std::string currentTypeSpecifier = ""; // Store the current type specifier
    int func_def = 0;

    // ICG related variables
    std::ofstream codeFile;
    std::ofstream optimizedCodeFile;
    int labelCounter = 0;
    int stackOffset = 0;
    int paramIndex = -1;
    int currentParamCount = 0; // Current scope parameter count

    // Store main function text separately
    std::string mainFunctionCode = "";

    bool inFunction = false; // true if inside a function
    std::string dataSegment = ""; // Accumulate global variable declarations
    
    int localStackOffset = 0; // Offset for local variables in current function

    vector<std::string> elseLabelsVec; // Store labels for ELSE statements
    vector<std::string> exitLabelsVec; // Store labels for exit statements


    std::string generateLabel() {
        return "L" + std::to_string(++labelCounter);
    }

        void writeCode(const std::string& code) {
        if (codeFile.is_open()) {
            codeFile << code << std::endl;
        }
    }
    
    void writeOptimizedCode(const std::string& code) {
        if (optimizedCodeFile.is_open()) {
            optimizedCodeFile << code << std::endl;
        }
    }
    
    void initializeAssemblyFiles() {
        codeFile.open("output/code.asm");
        optimizedCodeFile.open("output/optimized_code.asm");
        
        std::string header = ".MODEL SMALL\n.STACK 1000H\n.DATA\n\tnumber DB \"00000$\"\n";
        header += dataSegment; // Add global variables here
        
        writeCode(header);
        writeOptimizedCode(header);
    }
    
    void closeAssemblyFiles() {
        if (codeFile.is_open()) codeFile.close();
        if (optimizedCodeFile.is_open()) optimizedCodeFile.close();
    }
    
}

start:
	p = program {

        initializeAssemblyFiles();

        // Start code section
        writeCode(".CODE");
        writeCode("");
        
        // Write the main function's statements
        writeCode(mainFunctionCode);

        
        // Add procedures AFTER main procedure
        writeCode("");
        writeCode("new_line PROC");
        writeCode("\tpush ax");
        writeCode("\tpush dx");
        writeCode("\tmov ah,2");
        writeCode("\tmov dl,0Dh");
        writeCode("\tint 21h");
        writeCode("\tmov ah,2");
        writeCode("\tmov dl,0Ah");
        writeCode("\tint 21h");
        writeCode("\tpop dx");
        writeCode("\tpop ax");
        writeCode("\tret");
        writeCode("new_line ENDP");
        writeCode("");
        writeCode("print_output PROC  ;print what is in ax");
        writeCode("\tpush ax");
        writeCode("\tpush bx");
        writeCode("\tpush cx");
        writeCode("\tpush dx");
        writeCode("\tpush si");
        writeCode("\tlea si,number");
        writeCode("\tmov bx,10");
        writeCode("\tadd si,4");
        writeCode("\tcmp ax,0");
        writeCode("\tjnge negate");
        writeCode("print:");
        writeCode("\txor dx,dx");
        writeCode("\tdiv bx");
        writeCode("\tmov [si],dl");
        writeCode("\tadd [si],'0'");
        writeCode("\tdec si");
        writeCode("\tcmp ax,0");
        writeCode("\tjne print");
        writeCode("\tinc si");
        writeCode("\tlea dx,si");
        writeCode("\tmov ah,9");
        writeCode("\tint 21h");
        writeCode("\tpop si");
        writeCode("\tpop dx");
        writeCode("\tpop cx");
        writeCode("\tpop bx");
        writeCode("\tpop ax");
        writeCode("\tret");
        writeCode("negate:");
        writeCode("\tpush ax");
        writeCode("\tmov ah,2");
        writeCode("\tmov dl,'-'");
        writeCode("\tint 21h");
        writeCode("\tpop ax");
        writeCode("\tneg ax");
        writeCode("\tjmp print");
        writeCode("print_output ENDP");
        writeCode("");
        writeCode("END main");
        
        closeAssemblyFiles();
        
    };

program:
	p = program u = unit {
        
    }
	| u = unit {
        
    };

unit:
	v = var_declaration {
        
    }
	| fd = func_declaration {
        
    }
	| fdef = func_definition {
        
    };

func_declaration:
	t = type_specifier i = ID lp = LPAREN {
        
    } p = parameter_list rp = RPAREN s = SEMICOLON {
        bool inserted = symbolTable.insert($i->getText(), currentTypeSpecifier);
    }
	| t = type_specifier i = ID lp = LPAREN rp = RPAREN s = SEMICOLON {
        bool inserted = symbolTable.insert($i->getText(), currentTypeSpecifier);
    };

func_definition:
	t = type_specifier i = ID {
        // Reset parameter index for new function
        paramIndex = -1;
        // First insert the function name in the current scope
        bool inserted = symbolTable.insert($i->getText(), currentTypeSpecifier);
        // Generate function label
        mainFunctionCode += $i->getText() + " PROC\n";

        cout <<  $i->getText() << endl;

        if ($i->getText() == "main") {

            cout << "Inside main3" << endl;
            mainFunctionCode += "\tMOV AX, @DATA\n";
            mainFunctionCode += "\tMOV DS, AX\n\n";

        }

        mainFunctionCode += "\tPUSH BP\n";
        mainFunctionCode += "\tMOV BP, SP\n\n";
        
    } lp = LPAREN {
        func_def = 1;
        inFunction = true; // Set flag to true when entering a function
        localStackOffset = 0; // Reset local stack offset for new function
        // Enter a new scope for function parameters
        symbolTable.enterScope();
    } p = parameter_list rp = RPAREN c = compound_statement {
        // At function end, clean up and return

        cout << "CurrentParamCount: " << currentParamCount << endl;

        cout << "Before Return" << endl;

        if (localStackOffset > 0) {
            mainFunctionCode += "\tADD SP, " + std::to_string(localStackOffset) + "\n";
        }

        mainFunctionCode += "\tPOP BP\n";

        mainFunctionCode += "\tRET " + std::to_string(currentParamCount * 2) + "\n";

        if($i->getText() != "main") {
            mainFunctionCode += $i->getText() + " ENDP\n\n";
        }

        // Exit the function scope
        inFunction = false;
    }
	| t = type_specifier i = ID {
        // First insert the function name in the current scope
        bool inserted = symbolTable.insert($i->getText(), currentTypeSpecifier);
        // Generate function label
        mainFunctionCode += $i->getText() + " PROC\n";

        cout << $i->getText() << endl;
        
        if ($i->getText() == "main") {

            cout << "Inside main2" << endl;
            mainFunctionCode += "\tMOV AX, @DATA\n";
            mainFunctionCode += "\tMOV DS, AX\n\n";

        }

        mainFunctionCode += "\tPUSH BP\n";
        mainFunctionCode += "\tMOV BP, SP\n\n";
        
    } lp = LPAREN {
        func_def = 1;
        inFunction = true; // Set flag to true when entering a function
        localStackOffset = 0; // Reset local stack offset for new function
        // Enter a new scope for function parameters (even if none)
        symbolTable.enterScope();
    } rp = RPAREN c = compound_statement {
        // At function end, clean up and return

        cout << "Before Return" << endl;
        cout << "CurrentParamCount: " << currentParamCount << endl;

        if (localStackOffset > 0) {
            mainFunctionCode += "\tADD SP, " + std::to_string(localStackOffset) + "\n";
        }

        mainFunctionCode += "\tPOP BP\n";

        if($i->getText() != "main") {
            mainFunctionCode += "\tRET " + std::to_string(currentParamCount * 2) + "\n";
        }

        if($i->getText() == "main") {
            mainFunctionCode += "\tMOV AX, 4CH\n";
            mainFunctionCode += "\tINT 21h\n";
        }

        mainFunctionCode += $i->getText() + " ENDP\n\n";
        
        // Exit the function scope
        inFunction = false;
    };

parameter_list:
	p = parameter_list c = COMMA t = type_specifier i = ID {
        if (func_def == 1) {
            // Increment parameter index for this parameter (starts from 0)
            paramIndex++;
            
            bool inserted = symbolTable.insert($i->getText(), currentTypeSpecifier);
            SymbolInfo* sym = symbolTable.lookUp($i->getText());
            
            if (sym) {
                // Store the parameter index (0-based)
                sym->setParamIndex(paramIndex);
                sym->setIsParameter(true);
                sym->setIsGlobalVar(false);
                // Add to parameter count in current scope
                symbolTable.incrementCurrentScopeParamCount();
            }
        }
    }
    | p = parameter_list c = COMMA t = type_specifier {
        
    }
    | t = type_specifier i = ID {
        if (func_def == 1) {
            paramIndex++;
            bool inserted = symbolTable.insert($i->getText(), currentTypeSpecifier);
            SymbolInfo* sym = symbolTable.lookUp($i->getText());
            
            if (sym) {
                sym->setParamIndex(paramIndex);
                sym->setIsParameter(true);
                sym->setIsGlobalVar(false);
                // Add to parameter count in current scope
                symbolTable.incrementCurrentScopeParamCount();
            }
        }
    }
    | t = type_specifier {
        
    };

compound_statement:
	l = LCURL {
        if (func_def == 1) {
            func_def = 0;
           
        } else {
            symbolTable.enterScope();
        }
    } s = statements r = RCURL {

        currentParamCount = symbolTable.getCurrentScopeParamCount();

        cout << "CurrentParamCount: " << currentParamCount << endl;

        symbolTable.exitScope();
        paramIndex = -1;

        if (inFunction) {
            inFunction = false;
        }

    }
	| l = LCURL {
        if (func_def == 1) {
            func_def = 0;
            
        } else {
            symbolTable.enterScope();
        }
    } r = RCURL {

        currentParamCount = symbolTable.getCurrentScopeParamCount();
        cout << "CurrentParamCount: " << currentParamCount << endl;

        symbolTable.exitScope();
        paramIndex = -1;

        if (inFunction) {
            inFunction = false;
        }


    };

var_declaration:
	t = type_specifier dl = declaration_list sm = SEMICOLON {
        
    }
	| t = type_specifier de = declaration_list_err sm = SEMICOLON {
        
    };

declaration_list_err
	returns[std::string error_name]:
	{
        $error_name = "Error in declaration list";
    };

type_specifier:
	INT {
        currentTypeSpecifier = "INT"; // Store the current type
    }
	| FLOAT {
        currentTypeSpecifier = "FLOAT"; // Store the current type
    }
	| VOID {
        currentTypeSpecifier = "VOID"; // Store the current type
    };

declaration_list:
	dl = declaration_list cm = COMMA id = ID {

        bool inserted = symbolTable.insert($id->getText(), currentTypeSpecifier);
        SymbolInfo* sym = symbolTable.lookUp($id->getText());
        if (sym) sym->setIsGlobalVar(!inFunction);
        
        if (!inFunction) {
            dataSegment += "\t" + $id->getText() + " DW 1 DUP (0000H)\n";
        } else {
            // Local variable: allocate stack space and set offset
            localStackOffset += 2;
            if (sym) sym->setOffset(localStackOffset);
            mainFunctionCode += "\tSUB SP, 2\n";
        }

    }
	| dl = declaration_list cm = COMMA id = ID LTHIRD ci = CONST_INT RTHIRD {
        
        // Handle array declaration
        bool inserted = symbolTable.insert($id->getText(), currentTypeSpecifier);
        SymbolInfo* sym = symbolTable.lookUp($id->getText());
        

        cout << "Array" << endl;
        
        if (sym) {
            sym->setIsGlobalVar(!inFunction);
            sym->setIsArray(true);
            int arraySize = std::stoi($ci->getText());
            sym->setArraySize(arraySize);
            
            if (!inFunction) {
                // Global array declaration
                dataSegment += "\t" + $id->getText() + " DW " + std::to_string(arraySize) + " DUP (0000H)\n";
            } else {
                // Local array declaration: allocate space on stack
                localStackOffset += arraySize * 2; // Each element is 2 bytes (WORD)
                sym->setOffset(localStackOffset);
                mainFunctionCode += "\tSUB SP, " + std::to_string(arraySize * 2) + "\n";
            }
        }
    }
	| id = ID {

        bool inserted = symbolTable.insert($id->getText(), currentTypeSpecifier);
        SymbolInfo* sym = symbolTable.lookUp($id->getText());

        if (sym) sym->setIsGlobalVar(!inFunction);

        if (!inFunction) {
            dataSegment += "\t" + $id->getText() + " DW 1 DUP (0000H)\n";
        } else {
            localStackOffset += 2;
            if (sym) sym->setOffset(localStackOffset);
            mainFunctionCode += "\tSUB SP, 2\n";
        }

    }
	| id = ID LTHIRD ci = CONST_INT RTHIRD {
        
        bool inserted = symbolTable.insert($id->getText(), currentTypeSpecifier);
        SymbolInfo* sym = symbolTable.lookUp($id->getText());

        if (sym) {
            sym->setIsGlobalVar(!inFunction);
            sym->setIsArray(true);
            int arraySize = std::stoi($ci->getText());
            sym->setArraySize(arraySize);
            
            if (!inFunction) {
                // Global array declaration
                dataSegment += "\t" + $id->getText() + " DW " + std::to_string(arraySize) + " DUP (0000H)\n";
            } else {
                // Local array declaration: allocate space on stack
                localStackOffset += arraySize * 2; // Each element is 2 bytes (WORD)
                sym->setOffset(localStackOffset);
                mainFunctionCode += "\tSUB SP, " + std::to_string(arraySize * 2) + "\n";
            }
        }

    };

statements:
	s = statement {
        std::string label = generateLabel();
        mainFunctionCode += label + ":\n";
    }
	| ss = statements s = statement {
        std::string label = generateLabel();
        mainFunctionCode += label + ":\n";
    };

statement:
	v = var_declaration {
        
    }
	| es = expression_statement {
        
    }
	| c = compound_statement {
        
	}
	| f = FOR lp = LPAREN {

        std::string condLabel = generateLabel();
        std::string bodyLabel = generateLabel();
        std::string incLabel = generateLabel();
        std::string endLabel = generateLabel();

    } e1 = expression_statement {
        
        mainFunctionCode += "\tPUSH AX\n";
        mainFunctionCode += condLabel + ":  ;condLabel\n";
        
    } e2 = expression_statement {

        mainFunctionCode += "\tPUSH AX\n";      // Not sure just for testing  

        mainFunctionCode += "\tPOP AX\n"; // Pop the condition result
        mainFunctionCode += "\tCMP AX, 0\n";
        mainFunctionCode += "\tJE " + endLabel + "  ;endLabel \n";
        mainFunctionCode += "\tJMP " + bodyLabel + "\n";

        mainFunctionCode += incLabel + ":   ;incLabel \n";
        
    } e3 = expression_statement {
        mainFunctionCode += "\tJMP " + condLabel + "  ;condLabel\n";
        mainFunctionCode += bodyLabel + ":     ;body label \n"; // Place the body label
        
    } s = statement {
        // The body of the loop is generated here!
        mainFunctionCode += "\tJMP " + incLabel + "  ; inc label after body\n";
        mainFunctionCode += endLabel + ":  ;end label after loop\n"; // Place the end label
    }
    
	| i = IF lp = LPAREN exp = expression {        
        std::string endLabel = generateLabel();
        elseLabelsVec.push_back(endLabel); // Store the end label for IF statement

        mainFunctionCode += "\tPOP AX\n"; // Pop the condition result
        mainFunctionCode += "\tCMP AX, 0\n"; // Compare with zero
        mainFunctionCode += "\tJE " + endLabel + "\n"; // Jump to end if condition is false
        
    } rp = RPAREN s = statement {
        endLabel = elseLabelsVec.back(); // Get the end label
        elseLabelsVec.pop_back(); // Remove it from the stack
        mainFunctionCode += endLabel + ":\n"; // Place the end label (no jump needed for simple IF)
    }
	| i = IF lp = LPAREN exp = expression {

        std::string elseLabel = generateLabel();
        std::string endLabel = generateLabel();

        elseLabelsVec.push_back(elseLabel); // Store the else label
        exitLabelsVec.push_back(endLabel);  // Store the end label

        mainFunctionCode += "\tPOP AX\n"; // Pop the condition result
        mainFunctionCode += "\tCMP AX, 0\n"; // Compare with zero
        mainFunctionCode += "\tJE " + elseLabel + "\n"; // Jump to else if condition is false
        
    } rp = RPAREN s1 = statement {

        elseLabel = elseLabelsVec.back(); // Get the else label
        endLabel = exitLabelsVec.back();  // Get the end label
        elseLabelsVec.pop_back(); // Remove else label from stack
        
        mainFunctionCode += "\tJMP " + endLabel + "\n"; // Jump to end after IF body
        mainFunctionCode += elseLabel + ":\n"; // Place else label

    } el = ELSE s2 = statement {
        
        endLabel = exitLabelsVec.back(); // Get the end label
        exitLabelsVec.pop_back(); // Remove end label from stack
        mainFunctionCode += endLabel + ":\n"; // Place end label after ELSE body
        
    }
	| w = WHILE lp = LPAREN {

        std::string condLabel = generateLabel();
        std::string bodyLabel = generateLabel();
        std::string endLabel = generateLabel();

        //mainFunctionCode += "\tPUSH AX\n"; // Not sure just for testing

        mainFunctionCode += condLabel + ":  ;condLabel\n";
        
    } exp = expression {

        mainFunctionCode += "\tPOP AX\n"; // Pop the condition result
        mainFunctionCode += "\tCMP AX, 0\n";
        mainFunctionCode += "\tJE " + endLabel + "  ;endLabel \n";
        mainFunctionCode += "\tJMP " + bodyLabel + "\n";

        mainFunctionCode += bodyLabel + ":     ;body label \n"; // Place the body label
        
    } rp = RPAREN s = statement {
        // The body of the loop is generated here!
        mainFunctionCode += "\tJMP " + condLabel + "  ;jump back to condition\n";
        mainFunctionCode += endLabel + ":  ;end label after loop\n"; // Place the end label
    }
	| p = PRINTLN lp = LPAREN id = ID rp = RPAREN sm = SEMICOLON {
        SymbolInfo* sym = symbolTable.lookUp($id->getText());

        if (sym) {
            if (sym->getIsGlobalVar()) {
                mainFunctionCode += "\tMOV AX, " + $id->getText() + "\n";
            } 
            
            else if (sym->getIsParameter()) {

                cout << "ScopeParamCount: " << symbolTable.getCurrentScopeParamCount() << endl;
                cout << "ParamIndex: " << sym->getParamIndex() << endl;
                cout << "SymbolInfo Name: " << sym->getName() << ", Type: " << sym->getType() << ", IsParameter: " << sym->getIsParameter() << endl;
                
                int offset = 2 * (symbolTable.getCurrentScopeParamCount() - sym->getParamIndex() + 1);
                mainFunctionCode += "\tMOV AX, [BP+" + std::to_string(offset) + "]\n";
            }
            
            else {
                int offset = sym->getOffset();
                mainFunctionCode += "\tMOV AX, [BP-" + std::to_string(offset) + "]\n";
            }

            mainFunctionCode += "\tCALL print_output\n";
            mainFunctionCode += "\tCALL new_line\n";
        }
    }
	| r = RETURN exp = expression sm = SEMICOLON {
        mainFunctionCode += "\tPOP AX   ; Pop the return value\n";
    };

expression_statement:
	s = SEMICOLON {
        
    }
	| e = expression s=SEMICOLON {
       mainFunctionCode += "\tPOP AX  ; New Pop ; Line No: " +  std::to_string($s->getLine()) + "\n";
    };

variable returns [string varName, bool isArray = false, string indexReg = ""]:
    id = ID {
        $varName = $id->getText();
        $isArray = false;
    }
    | id = ID LTHIRD e = expression RTHIRD {
        $varName = $id->getText();
        $isArray = true;
        
        // Get the array index from stack and calculate byte offset
        mainFunctionCode += "\t; Array index calculation for " + $id->getText() + "\n";
        mainFunctionCode += "\tPOP BX\n";  // Get the index from stack
        mainFunctionCode += "\tSHL BX, 1\n";  // Multiply by 2 (word size)
        $indexReg = "BX";
    };

expression:
	l = logic_expression {
        
    }
    | v = variable a = ASSIGNOP l = logic_expression {
        SymbolInfo* sym = symbolTable.lookUp($v.varName);
        if (sym) {
            mainFunctionCode += "\t; Assignment to " + $v.varName + ($v.isArray ? "[index]" : "") + "\n";
            mainFunctionCode += "\tPOP AX\n";  // Get the value to assign
            
            if ($v.isArray) {
                if (sym->getIsGlobalVar()) {
                    // Global array assignment (e.g., w[0] = -2)
                    mainFunctionCode += "\tMOV " + $v.varName + "[" + $v.indexReg + "], AX\n";
                } else {
                    // Local array assignment (e.g., x[0] = w[0])
                    int offset = sym->getOffset();
                    mainFunctionCode += "\tMOV SI, BP\n";
                    mainFunctionCode += "\tSUB SI, " + std::to_string(offset) + "\n";
                    mainFunctionCode += "\tADD SI, " + $v.indexReg + "\n";
                    mainFunctionCode += "\tMOV [SI], AX\n";
                }
            } else {
                // Scalar variable assignment
                if (sym->getIsGlobalVar()) {
                    mainFunctionCode += "\tMOV " + $v.varName + ", AX\n";
                } else if (sym->getIsParameter()) {
                    int offset = 2 * (symbolTable.getCurrentScopeParamCount() - sym->getParamIndex() + 1);
                    mainFunctionCode += "\tMOV [BP+" + std::to_string(offset) + "], AX\n";
                } else {
                    int offset = sym->getOffset();
                    mainFunctionCode += "\tMOV [BP-" + std::to_string(offset) + "], AX\n";
                }
            }

            mainFunctionCode += "\tPUSH AX\n";
        }
    };

logic_expression:
	r = rel_expression {
        
    }
	| r1 = rel_expression l = LOGICOP r2 = rel_expression {
        std::string logicOp = $l->getText();
        std::string shortCircuitLabel = generateLabel();
        std::string endLabel = generateLabel();
    
        if(logicOp == "&&") {
            // For AND: if first operand is false, short-circuit to false
        
            mainFunctionCode += "\tPOP AX\n";          // Pop first operand
            mainFunctionCode += "\tCMP AX, 0\n";
            mainFunctionCode += "\tJE " + shortCircuitLabel + "\n";  // If false, short-circuit
        
            // First operand is true, check second operand
            mainFunctionCode += "\tPOP AX\n";          // Pop second operand
            mainFunctionCode += "\tCMP AX, 0\n";
            mainFunctionCode += "\tJE " + shortCircuitLabel + "\n";  // If false, result is false
        
            // Both operands are true
            mainFunctionCode += "\tPUSH 1\n";
            mainFunctionCode += "\tJMP " + endLabel + "\n";
        
            // Short-circuit case: result is false
            mainFunctionCode += shortCircuitLabel + ":\n";
            mainFunctionCode += "\tADD SP, 2\n";       // Clean up remaining operand on stack
            mainFunctionCode += "\tPUSH 0\n";
            mainFunctionCode += endLabel + ":\n";
        }

        else if(logicOp == "||") {
            // For OR: if first operand is true, short-circuit to true
        
            mainFunctionCode += "\tPOP AX\n";          // Pop first operand
            mainFunctionCode += "\tCMP AX, 0\n";
            mainFunctionCode += "\tJNE " + shortCircuitLabel + "\n"; // If true, short-circuit
        
            // First operand is false, check second operand
            mainFunctionCode += "\tPOP AX\n";          // Pop second operand
            mainFunctionCode += "\tCMP AX, 0\n";
            mainFunctionCode += "\tJNE " + shortCircuitLabel + "\n"; // If true, result is true
        
            // Both operands are false
            mainFunctionCode += "\tPUSH 0\n";
            mainFunctionCode += "\tJMP " + endLabel + "\n";
        
            // Short-circuit case: result is true
            mainFunctionCode += shortCircuitLabel + ":\n";
            mainFunctionCode += "\tADD SP, 2\n";       // Clean up remaining operand on stack
            mainFunctionCode += "\tPUSH 1\n";
            mainFunctionCode += endLabel + ":\n";
        }
    };

// rel_expression:
// 	s = simple_expression {

//     }
// 	| s1 = simple_expression r = RELOP s2 = simple_expression {
//         // Extract operands from stack
//         mainFunctionCode += "\tPOP BX\n\tPOP AX\n";

//         std::string relOp = $r->getText();
//         std::string successLabel = generateLabel();
//         std::string exitLabel = generateLabel();

//         // Less than comparison
//         if(relOp == "<") {
//     std::string endLabel = generateLabel();
    
//     if(logicOp == "&&") {
//         // For AND: if first operand is false, short-circuit to false
//         // Stack at this point: [second_operand, first_operand] (top to bottom)
        
//         mainFunctionCode += "\tPOP AX\n";          // Pop first operand
//         mainFunctionCode += "\tCMP AX, 0\n";
//         mainFunctionCode += "\tJE " + shortCircuitLabel + "\n";  // If false, short-circuit
        
//         // First operand is true, check second operand
//         mainFunctionCode += "\tPOP AX\n";          // Pop second operand
//         mainFunctionCode += "\tCMP AX, 0\n";
//         mainFunctionCode += "\tJE " + shortCircuitLabel + "\n";  // If false, result is false
        
//         // Both operands are true
//         mainFunctionCode += "\tPUSH 1\n";
//         mainFunctionCode += "\tJMP " + endLabel + "\n";
        
//         // Short-circuit case: result is false
//         mainFunctionCode += shortCircuitLabel + ":\n";
//         mainFunctionCode += "\tADD SP, 2\n";       // Clean up remaining operand on stack
//         mainFunctionCode += "\tPUSH 0\n";
//         mainFunctionCode += endLabel + ":\n";
//     } 
//     else if(logicOp == "||") {
//         // For OR: if first operand is true, short-circuit to true
//         // Stack at this point: [second_operand, first_operand] (top to bottom)
        
//         mainFunctionCode += "\tPOP AX\n";          // Pop first operand
//         mainFunctionCode += "\tCMP AX, 0\n";
//         mainFunctionCode += "\tJNE " + shortCircuitLabel + "\n"; // If true, short-circuit
        
//         // First operand is false, check second operand
//         mainFunctionCode += "\tPOP AX\n";          // Pop second operand
//         mainFunctionCode += "\tCMP AX, 0\n";
//         mainFunctionCode += "\tJNE " + shortCircuitLabel + "\n"; // If true, result is true
        
//         // Both operands are false
//         mainFunctionCode += "\tPUSH 0\n";
//         mainFunctionCode += "\tJMP " + endLabel + "\n";
        
//         // Short-circuit case: result is true
//         mainFunctionCode += shortCircuitLabel + ":\n";
//         mainFunctionCode += "\tADD SP, 2\n";       // Clean up remaining operand on stack
//         mainFunctionCode += "\tPUSH 1\n";
//         mainFunctionCode += endLabel + ":\n";
//     }
// };

rel_expression:
	s = simple_expression {
        
    }
	| s1 = simple_expression r = RELOP s2 = simple_expression {
        // Extract operands from stack
        mainFunctionCode += "\tPOP BX\n\tPOP AX\n";
        
        std::string relOp = $r->getText();
        std::string successLabel = generateLabel();
        std::string exitLabel = generateLabel();
        
        // Less than comparison
        if(relOp == "<") {
            mainFunctionCode += "\tCMP AX, BX\n\tJL " + successLabel + "\n";
        } 
        // Less than or equal comparison
        else if(relOp == "<=") {
            mainFunctionCode += "\tCMP AX, BX\n\tJLE " + successLabel + "\n";
        } 
        // Greater than comparison
        else if(relOp == ">") {
            mainFunctionCode += "\tCMP AX, BX\n\tJG " + successLabel + "\n";
        } 
        // Greater than or equal comparison
        else if(relOp == ">=") {
            mainFunctionCode += "\tCMP AX, BX\n\tJGE " + successLabel + "\n";
        } 
        // Equality comparison
        else if(relOp == "==") {
            mainFunctionCode += "\tCMP AX, BX\n\tJE " + successLabel + "\n";
        } 
        // Inequality comparison
        else if(relOp == "!=") {
            mainFunctionCode += "\tCMP AX, BX\n\tJNE " + successLabel + "\n";
        }
        
        // Comparison failed - push false
        mainFunctionCode += "\tPUSH 0\n";
        mainFunctionCode += "\tJMP " + exitLabel + "\n";
        // Comparison succeeded - push true
        mainFunctionCode += successLabel + ":\n";
        mainFunctionCode += "\tPUSH 1\n";
        mainFunctionCode += exitLabel + ":\n";
    };

simple_expression:
	t = term {
        
    }
	| s = simple_expression a = ADDOP t = term {
        
        mainFunctionCode += "\tPOP BX\n";
        mainFunctionCode += "\tPOP AX\n";

        std::string op = $a->getText();

        if (op == "+") {
            mainFunctionCode += "\tADD AX, BX\n";


        } else if (op == "-") {
            mainFunctionCode += "\tSUB AX, BX\n";
        }

        mainFunctionCode += "\tPUSH AX ;add operation\n";
    };

term:
	u = unary_expression {
       
    }
	| t = term m = MULOP u = unary_expression {

        mainFunctionCode += "\tPOP BX\n";
        mainFunctionCode += "\tPOP AX\n";

        std::string op = $m->getText();

        if(op == "*") {
            mainFunctionCode += "\tMUL BX\n";
        }

        else if(op == "/") {
            mainFunctionCode += "\tDIV BX\n";
        }

        else if(op == "%") {
            mainFunctionCode += "\tDIV BX\n";
            mainFunctionCode += "\tMOV AX, DX\n";
        }

        mainFunctionCode += "\tPUSH AX\n";

    };

unary_expression:
	a = ADDOP u = unary_expression {
        mainFunctionCode += "\tPOP AX\n";

        if($a->getText() == "+") {
            mainFunctionCode += "\tPUSH AX\n";
        }

        else if($a->getText() == "-") {
            mainFunctionCode += "\tNEG AX\n";
            mainFunctionCode += "\tPUSH AX\n";
        }
    }
	| n = NOT u = unary_expression {
        mainFunctionCode += "\tPOP ax\n";
        mainFunctionCode += "\tNOT AX\n";
        mainFunctionCode += "\tPUSH AX\n";
    }
	| f = factor {
        
    };

factor:
    v = variable {
        SymbolInfo* sym = symbolTable.lookUp($v.varName);
        cout << "Variable: " << $v.varName << std::endl;

        if (sym) {
            cout << "hvuhvuvuu"<<std::endl;
            
            if ($v.isArray) {
                // Handle array access
                if (sym->getIsGlobalVar()) {
                    // Global array access (e.g., w[0])
                    mainFunctionCode += "\t; Accessing global array " + $v.varName + "[" + $v.indexReg + "]\n";
                    mainFunctionCode += "\tMOV AX, " + $v.varName + "[" + $v.indexReg + "]\n";
                } else {
                    // Local array access (e.g., x[0])
                    int offset = sym->getOffset();
                    mainFunctionCode += "\t; Accessing local array " + $v.varName + "[" + $v.indexReg + "]\n";
                    mainFunctionCode += "\tMOV SI, BP\n";
                    mainFunctionCode += "\tSUB SI, " + std::to_string(offset) + "\n";
                    mainFunctionCode += "\tADD SI, " + $v.indexReg + "\n";
                    mainFunctionCode += "\tMOV AX, [SI]\n";
                }
            } else {
                // Handle scalar variable access
                if (sym->getIsGlobalVar()) {
                    mainFunctionCode += "\tMOV AX, " + $v.varName + "\n";
                } else if (sym->getIsParameter()) {
                    cout << "ScopeParamCount: " << symbolTable.getCurrentScopeParamCount() << endl;
                    cout << "ParamIndex: " << sym->getParamIndex() << endl;
                    cout << "SymbolInfo Name: " << sym->getName() << ", Type: " << sym->getType() << ", IsParameter: " << sym->getIsParameter() << endl;

                    int offset = 2 * (symbolTable.getCurrentScopeParamCount() - sym->getParamIndex() + 1);
                    mainFunctionCode += "\tMOV AX, [BP+" + std::to_string(offset) + "]\n";
                } else {
                    int offset = sym->getOffset();
                    mainFunctionCode += "\tMOV AX, [BP-" + std::to_string(offset) + "]\n";
                }
            }

            mainFunctionCode += "\tPUSH AX\n";
        
        }
    }    
	| ID lp = LPAREN a = argument_list rp = RPAREN {
        mainFunctionCode += "\tCALL " + $ID.text + "\n";
        mainFunctionCode += "\tPUSH AX\n";
    }
	| lp = LPAREN e = expression rp = RPAREN
	|CONST_INT {
        mainFunctionCode += "\tPUSH " + $CONST_INT.text + "\n";
    }
	| cf = CONST_FLOAT {
        
    }
	| v = variable ic = INCOP {
        // mainFunctionCode += "\tPOP AX\n";
        // mainFunctionCode += "\tINC AX\n";
        // mainFunctionCode += "\tPUSH AX\n";
        
        SymbolInfo* sym = symbolTable.lookUp($v.varName);

        // if (sym) {
        //     if (sym->getIsGlobalVar()) {
        //         mainFunctionCode += "\tMOV " + $v.varName + ", AX\n";
        //     } 
            
        //     else if (sym->getIsParameter()) {
        //         int offset = 2 * (symbolTable.getCurrentScopeParamCount() - sym->getParamIndex() + 1);
        //         mainFunctionCode += "\tMOV [BP+" + std::to_string(offset) + "], AX\n";

        //     }
        //     else {
        //         int offset = sym->getOffset();
        //         mainFunctionCode += "\tMOV [BP-" + std::to_string(offset) + "], AX\n";
        //     }
        // }

        if (sym) {
            if ($v.isArray) {
                // Handle array increment
                if (sym->getIsGlobalVar()) {
                    // Global array increment (e.g., arr[i]++)
                    mainFunctionCode += "\tMOV AX, " + $v.varName + "[" + $v.indexReg + "]\n";  // Load array element
                    mainFunctionCode += "\tPUSH AX\n";  // Push original value
                    mainFunctionCode += "\tINC AX\n";     // Increment
                    mainFunctionCode += "\tMOV " + $v.varName + "[" + $v.indexReg + "], AX\n";  // Store back
                
                } else {
                    // Local array increment
                    int offset = sym->getOffset();
                    mainFunctionCode += "\tMOV SI, BP\n";
                    mainFunctionCode += "\tSUB SI, " + std::to_string(offset) + "\n";
                    mainFunctionCode += "\tADD SI, " + $v.indexReg + "\n";  // SI now points to array element
                    mainFunctionCode += "\tMOV AX, [SI]\n";  // Load array element
                    mainFunctionCode += "\tPUSH AX\n";       // Push original value
                    mainFunctionCode += "\tINC AX\n";        // Increment
                    mainFunctionCode += "\tMOV [SI], AX\n";  // Store back
                }
            } else {
                // Handle scalar variable increment (original code)
                if (sym->getIsGlobalVar()) {
                    mainFunctionCode += "\tMOV AX, " + $v.varName + "\n";
                    mainFunctionCode += "\tPUSH AX\n";
                    mainFunctionCode += "\tINC AX\n";
                    mainFunctionCode += "\tMOV " + $v.varName + ", AX\n";
                } else if (sym->getIsParameter()) {
                    int offset = 2 * (symbolTable.getCurrentScopeParamCount() - sym->getParamIndex() + 1);
                    mainFunctionCode += "\tMOV AX, [BP+" + std::to_string(offset) + "]\n";
                    mainFunctionCode += "\tPUSH AX\n";
                    mainFunctionCode += "\tINC AX\n";
                    mainFunctionCode += "\tMOV [BP+" + std::to_string(offset) + "], AX\n";
                } else {
                    int offset = sym->getOffset();
                    mainFunctionCode += "\tMOV AX, [BP-" + std::to_string(offset) + "]\n";
                    mainFunctionCode += "\tPUSH AX\n";
                    mainFunctionCode += "\tINC AX\n";
                    mainFunctionCode += "\tMOV [BP-" + std::to_string(offset) + "], AX\n";
                }
            }
        }

    }
	| v = variable dc = DECOP {
        // mainFunctionCode += "\tPOP AX\n";
        // mainFunctionCode += "\t
        // mainFunctionCode += "\tPUSH AX\n";
        // mainFunctionCode += "\tDEC AX\n";
        
        SymbolInfo* sym = symbolTable.lookUp($v.varName);
        if (sym) {
            if (sym->getIsGlobalVar()) {
                mainFunctionCode += "\tMOV AX, " + $v.varName + "\n";
                mainFunctionCode += "\tPUSH AX\n";
                mainFunctionCode += "\tDEC AX\n";
                mainFunctionCode += "\tMOV " + $v.varName + ", AX\n";
            } 
            
            else if (sym->getIsParameter()) {
                int offset = 2 * (symbolTable.getCurrentScopeParamCount() - sym->getParamIndex() + 1);
                mainFunctionCode += "\tMOV AX, [BP+" + std::to_string(offset) + "]\n";
                mainFunctionCode += "\tPUSH AX\n";
                mainFunctionCode += "\tDEC AX\n";
                mainFunctionCode += "\tMOV [BP+" + std::to_string(offset) + "], AX\n";
            }
            
            else {
                int offset = sym->getOffset();
                mainFunctionCode += "\tMOV AX, [BP-" + std::to_string(offset) + "]\n";
                mainFunctionCode += "\tPUSH AX\n";
                mainFunctionCode += "\tDEC AX\n";
                mainFunctionCode += "\tMOV [BP-" + std::to_string(offset) + "], AX\n";
            }
        }
    };


argument_list:
	a = arguments {
        
    }
	| {
        
    };

arguments:
	a = arguments c = COMMA l=logic_expression {

    }
	| l=logic_expression {
    };