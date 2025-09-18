
// Generated from C2105115Parser.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "C2105115Parser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by C2105115Parser.
 */
class  C2105115ParserListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(C2105115Parser::StartContext *ctx) = 0;
  virtual void exitStart(C2105115Parser::StartContext *ctx) = 0;

  virtual void enterProgram(C2105115Parser::ProgramContext *ctx) = 0;
  virtual void exitProgram(C2105115Parser::ProgramContext *ctx) = 0;

  virtual void enterUnit(C2105115Parser::UnitContext *ctx) = 0;
  virtual void exitUnit(C2105115Parser::UnitContext *ctx) = 0;

  virtual void enterFunc_declaration(C2105115Parser::Func_declarationContext *ctx) = 0;
  virtual void exitFunc_declaration(C2105115Parser::Func_declarationContext *ctx) = 0;

  virtual void enterFunc_definition(C2105115Parser::Func_definitionContext *ctx) = 0;
  virtual void exitFunc_definition(C2105115Parser::Func_definitionContext *ctx) = 0;

  virtual void enterParameter_list(C2105115Parser::Parameter_listContext *ctx) = 0;
  virtual void exitParameter_list(C2105115Parser::Parameter_listContext *ctx) = 0;

  virtual void enterCompound_statement(C2105115Parser::Compound_statementContext *ctx) = 0;
  virtual void exitCompound_statement(C2105115Parser::Compound_statementContext *ctx) = 0;

  virtual void enterVar_declaration(C2105115Parser::Var_declarationContext *ctx) = 0;
  virtual void exitVar_declaration(C2105115Parser::Var_declarationContext *ctx) = 0;

  virtual void enterDeclaration_list_err(C2105115Parser::Declaration_list_errContext *ctx) = 0;
  virtual void exitDeclaration_list_err(C2105115Parser::Declaration_list_errContext *ctx) = 0;

  virtual void enterType_specifier(C2105115Parser::Type_specifierContext *ctx) = 0;
  virtual void exitType_specifier(C2105115Parser::Type_specifierContext *ctx) = 0;

  virtual void enterDeclaration_list(C2105115Parser::Declaration_listContext *ctx) = 0;
  virtual void exitDeclaration_list(C2105115Parser::Declaration_listContext *ctx) = 0;

  virtual void enterStatements(C2105115Parser::StatementsContext *ctx) = 0;
  virtual void exitStatements(C2105115Parser::StatementsContext *ctx) = 0;

  virtual void enterStatement(C2105115Parser::StatementContext *ctx) = 0;
  virtual void exitStatement(C2105115Parser::StatementContext *ctx) = 0;

  virtual void enterExpression_statement(C2105115Parser::Expression_statementContext *ctx) = 0;
  virtual void exitExpression_statement(C2105115Parser::Expression_statementContext *ctx) = 0;

  virtual void enterVariable(C2105115Parser::VariableContext *ctx) = 0;
  virtual void exitVariable(C2105115Parser::VariableContext *ctx) = 0;

  virtual void enterExpression(C2105115Parser::ExpressionContext *ctx) = 0;
  virtual void exitExpression(C2105115Parser::ExpressionContext *ctx) = 0;

  virtual void enterLogic_expression(C2105115Parser::Logic_expressionContext *ctx) = 0;
  virtual void exitLogic_expression(C2105115Parser::Logic_expressionContext *ctx) = 0;

  virtual void enterRel_expression(C2105115Parser::Rel_expressionContext *ctx) = 0;
  virtual void exitRel_expression(C2105115Parser::Rel_expressionContext *ctx) = 0;

  virtual void enterSimple_expression(C2105115Parser::Simple_expressionContext *ctx) = 0;
  virtual void exitSimple_expression(C2105115Parser::Simple_expressionContext *ctx) = 0;

  virtual void enterTerm(C2105115Parser::TermContext *ctx) = 0;
  virtual void exitTerm(C2105115Parser::TermContext *ctx) = 0;

  virtual void enterUnary_expression(C2105115Parser::Unary_expressionContext *ctx) = 0;
  virtual void exitUnary_expression(C2105115Parser::Unary_expressionContext *ctx) = 0;

  virtual void enterFactor(C2105115Parser::FactorContext *ctx) = 0;
  virtual void exitFactor(C2105115Parser::FactorContext *ctx) = 0;

  virtual void enterArgument_list(C2105115Parser::Argument_listContext *ctx) = 0;
  virtual void exitArgument_list(C2105115Parser::Argument_listContext *ctx) = 0;

  virtual void enterArguments(C2105115Parser::ArgumentsContext *ctx) = 0;
  virtual void exitArguments(C2105115Parser::ArgumentsContext *ctx) = 0;


};

