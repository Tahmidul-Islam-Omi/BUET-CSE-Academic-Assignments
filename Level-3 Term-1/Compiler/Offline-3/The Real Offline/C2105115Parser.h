
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



// Generated from C2105115Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  C2105115Parser : public antlr4::Parser {
public:
  enum {
    LINE_COMMENT = 1, BLOCK_COMMENT = 2, STRING = 3, WS = 4, IF = 5, ELSE = 6, 
    FOR = 7, WHILE = 8, PRINTLN = 9, RETURN = 10, INT = 11, FLOAT = 12, 
    VOID = 13, LPAREN = 14, RPAREN = 15, LCURL = 16, RCURL = 17, LTHIRD = 18, 
    RTHIRD = 19, SEMICOLON = 20, COMMA = 21, ADDOP = 22, SUBOP = 23, MULOP = 24, 
    INCOP = 25, DECOP = 26, NOT = 27, RELOP = 28, LOGICOP = 29, ASSIGNOP = 30, 
    ID = 31, CONST_INT = 32, CONST_FLOAT = 33
  };

  enum {
    RuleStart = 0, RuleProgram = 1, RuleUnit = 2, RuleFunc_declaration = 3, 
    RuleFunc_definition = 4, RuleParameter_list = 5, RuleCompound_statement = 6, 
    RuleVar_declaration = 7, RuleDeclaration_list_err = 8, RuleType_specifier = 9, 
    RuleDeclaration_list = 10, RuleStatements = 11, RuleStatement = 12, 
    RuleExpression_statement = 13, RuleVariable = 14, RuleExpression = 15, 
    RuleLogic_expression = 16, RuleRel_expression = 17, RuleSimple_expression = 18, 
    RuleTerm = 19, RuleUnary_expression = 20, RuleFactor = 21, RuleArgument_list = 22, 
    RuleArguments = 23
  };

  explicit C2105115Parser(antlr4::TokenStream *input);

  C2105115Parser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~C2105115Parser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


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


  class StartContext;
  class ProgramContext;
  class UnitContext;
  class Func_declarationContext;
  class Func_definitionContext;
  class Parameter_listContext;
  class Compound_statementContext;
  class Var_declarationContext;
  class Declaration_list_errContext;
  class Type_specifierContext;
  class Declaration_listContext;
  class StatementsContext;
  class StatementContext;
  class Expression_statementContext;
  class VariableContext;
  class ExpressionContext;
  class Logic_expressionContext;
  class Rel_expressionContext;
  class Simple_expressionContext;
  class TermContext;
  class Unary_expressionContext;
  class FactorContext;
  class Argument_listContext;
  class ArgumentsContext; 

  class  StartContext : public antlr4::ParserRuleContext {
  public:
    C2105115Parser::ProgramContext *p = nullptr;
    StartContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StartContext* start();

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::ProgramContext *p = nullptr;
    C2105115Parser::UnitContext *u = nullptr;
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnitContext *unit();
    ProgramContext *program();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ProgramContext* program();
  ProgramContext* program(int precedence);
  class  UnitContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::Var_declarationContext *v = nullptr;
    C2105115Parser::Func_declarationContext *fd = nullptr;
    C2105115Parser::Func_definitionContext *fdef = nullptr;
    UnitContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    Func_declarationContext *func_declaration();
    Func_definitionContext *func_definition();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  UnitContext* unit();

  class  Func_declarationContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *i = nullptr;
    antlr4::Token *lp = nullptr;
    C2105115Parser::Parameter_listContext *p = nullptr;
    antlr4::Token *rp = nullptr;
    antlr4::Token *s = nullptr;
    Func_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *SEMICOLON();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_declarationContext* func_declaration();

  class  Func_definitionContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *i = nullptr;
    antlr4::Token *lp = nullptr;
    C2105115Parser::Parameter_listContext *p = nullptr;
    antlr4::Token *rp = nullptr;
    C2105115Parser::Compound_statementContext *c = nullptr;
    Func_definitionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *RPAREN();
    Compound_statementContext *compound_statement();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Func_definitionContext* func_definition();

  class  Parameter_listContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::Parameter_listContext *p = nullptr;
    C2105115Parser::Type_specifierContext *t = nullptr;
    antlr4::Token *i = nullptr;
    antlr4::Token *c = nullptr;
    Parameter_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    antlr4::tree::TerminalNode *ID();
    Parameter_listContext *parameter_list();
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Parameter_listContext* parameter_list();
  Parameter_listContext* parameter_list(int precedence);
  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    antlr4::Token *l = nullptr;
    C2105115Parser::StatementsContext *s = nullptr;
    antlr4::Token *r = nullptr;
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LCURL();
    StatementsContext *statements();
    antlr4::tree::TerminalNode *RCURL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Compound_statementContext* compound_statement();

  class  Var_declarationContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::Type_specifierContext *t = nullptr;
    C2105115Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *sm = nullptr;
    C2105115Parser::Declaration_list_errContext *de = nullptr;
    Var_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_specifierContext *type_specifier();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *SEMICOLON();
    Declaration_list_errContext *declaration_list_err();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Var_declarationContext* var_declaration();

  class  Declaration_list_errContext : public antlr4::ParserRuleContext {
  public:
    std::string error_name;
    Declaration_list_errContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_list_errContext* declaration_list_err();

  class  Type_specifierContext : public antlr4::ParserRuleContext {
  public:
    std::string name_line;
    std::string text;
    antlr4::Token *intToken = nullptr;
    antlr4::Token *floatToken = nullptr;
    antlr4::Token *voidToken = nullptr;
    Type_specifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *VOID();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Type_specifierContext* type_specifier();

  class  Declaration_listContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::Declaration_listContext *dl = nullptr;
    antlr4::Token *id = nullptr;
    antlr4::Token *lthirdToken = nullptr;
    antlr4::Token *ci = nullptr;
    antlr4::Token *rthirdToken = nullptr;
    antlr4::Token *cm = nullptr;
    Declaration_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    antlr4::tree::TerminalNode *RTHIRD();
    antlr4::tree::TerminalNode *CONST_INT();
    Declaration_listContext *declaration_list();
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Declaration_listContext* declaration_list();
  Declaration_listContext* declaration_list(int precedence);
  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::StatementsContext *ss = nullptr;
    C2105115Parser::StatementContext *s = nullptr;
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    StatementsContext *statements();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementsContext* statements();
  StatementsContext* statements(int precedence);
  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::Var_declarationContext *v = nullptr;
    C2105115Parser::Expression_statementContext *es = nullptr;
    C2105115Parser::Compound_statementContext *c = nullptr;
    antlr4::Token *f = nullptr;
    antlr4::Token *lp = nullptr;
    C2105115Parser::Expression_statementContext *e1 = nullptr;
    C2105115Parser::Expression_statementContext *e2 = nullptr;
    C2105115Parser::ExpressionContext *exp = nullptr;
    antlr4::Token *rp = nullptr;
    C2105115Parser::StatementContext *s = nullptr;
    antlr4::Token *i = nullptr;
    C2105115Parser::StatementContext *s1 = nullptr;
    antlr4::Token *el = nullptr;
    C2105115Parser::StatementContext *s2 = nullptr;
    antlr4::Token *w = nullptr;
    antlr4::Token *p = nullptr;
    antlr4::Token *id = nullptr;
    antlr4::Token *sm = nullptr;
    antlr4::Token *r = nullptr;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_declarationContext *var_declaration();
    std::vector<Expression_statementContext *> expression_statement();
    Expression_statementContext* expression_statement(size_t i);
    Compound_statementContext *compound_statement();
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *ELSE();
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *PRINTLN();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *SEMICOLON();
    antlr4::tree::TerminalNode *RETURN();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  Expression_statementContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    antlr4::Token *s = nullptr;
    C2105115Parser::ExpressionContext *e = nullptr;
    Expression_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *SEMICOLON();
    ExpressionContext *expression();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Expression_statementContext* expression_statement();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    antlr4::Token *id = nullptr;
    antlr4::Token *l = nullptr;
    C2105115Parser::ExpressionContext *e = nullptr;
    antlr4::Token *r = nullptr;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LTHIRD();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RTHIRD();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  VariableContext* variable();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::Logic_expressionContext *l = nullptr;
    C2105115Parser::VariableContext *v = nullptr;
    antlr4::Token *a = nullptr;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    VariableContext *variable();
    antlr4::tree::TerminalNode *ASSIGNOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpressionContext* expression();

  class  Logic_expressionContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::Rel_expressionContext *r = nullptr;
    C2105115Parser::Rel_expressionContext *r1 = nullptr;
    antlr4::Token *l = nullptr;
    C2105115Parser::Rel_expressionContext *r2 = nullptr;
    Logic_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Rel_expressionContext *> rel_expression();
    Rel_expressionContext* rel_expression(size_t i);
    antlr4::tree::TerminalNode *LOGICOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Logic_expressionContext* logic_expression();

  class  Rel_expressionContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::Simple_expressionContext *s = nullptr;
    C2105115Parser::Simple_expressionContext *s1 = nullptr;
    antlr4::Token *r = nullptr;
    C2105115Parser::Simple_expressionContext *s2 = nullptr;
    Rel_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);
    antlr4::tree::TerminalNode *RELOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Rel_expressionContext* rel_expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::Simple_expressionContext *s = nullptr;
    C2105115Parser::TermContext *t = nullptr;
    antlr4::Token *a = nullptr;
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TermContext *term();
    Simple_expressionContext *simple_expression();
    antlr4::tree::TerminalNode *ADDOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Simple_expressionContext* simple_expression();
  Simple_expressionContext* simple_expression(int precedence);
  class  TermContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::TermContext *t = nullptr;
    C2105115Parser::Unary_expressionContext *u = nullptr;
    antlr4::Token *m = nullptr;
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Unary_expressionContext *unary_expression();
    TermContext *term();
    antlr4::tree::TerminalNode *MULOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  TermContext* term();
  TermContext* term(int precedence);
  class  Unary_expressionContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    antlr4::Token *a = nullptr;
    C2105115Parser::Unary_expressionContext *u = nullptr;
    antlr4::Token *n = nullptr;
    C2105115Parser::FactorContext *f = nullptr;
    Unary_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ADDOP();
    Unary_expressionContext *unary_expression();
    antlr4::tree::TerminalNode *NOT();
    FactorContext *factor();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Unary_expressionContext* unary_expression();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::VariableContext *v = nullptr;
    antlr4::Token *id = nullptr;
    antlr4::Token *lp = nullptr;
    C2105115Parser::Argument_listContext *a = nullptr;
    antlr4::Token *rp = nullptr;
    C2105115Parser::ExpressionContext *e = nullptr;
    antlr4::Token *ci = nullptr;
    antlr4::Token *cf = nullptr;
    antlr4::Token *ic = nullptr;
    antlr4::Token *dc = nullptr;
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    Argument_listContext *argument_list();
    antlr4::tree::TerminalNode *RPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *CONST_INT();
    antlr4::tree::TerminalNode *CONST_FLOAT();
    antlr4::tree::TerminalNode *INCOP();
    antlr4::tree::TerminalNode *DECOP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  FactorContext* factor();

  class  Argument_listContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::ArgumentsContext *a = nullptr;
    Argument_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ArgumentsContext *arguments();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  Argument_listContext* argument_list();

  class  ArgumentsContext : public antlr4::ParserRuleContext {
  public:
    std::string text;
    C2105115Parser::ArgumentsContext *a = nullptr;
    C2105115Parser::Logic_expressionContext *l = nullptr;
    antlr4::Token *c = nullptr;
    ArgumentsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Logic_expressionContext *logic_expression();
    ArgumentsContext *arguments();
    antlr4::tree::TerminalNode *COMMA();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ArgumentsContext* arguments();
  ArgumentsContext* arguments(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool programSempred(ProgramContext *_localctx, size_t predicateIndex);
  bool parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex);
  bool declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex);
  bool statementsSempred(StatementsContext *_localctx, size_t predicateIndex);
  bool simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex);
  bool termSempred(TermContext *_localctx, size_t predicateIndex);
  bool argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};

