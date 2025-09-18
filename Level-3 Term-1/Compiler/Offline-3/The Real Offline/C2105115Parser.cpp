
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


#include "C2105115ParserListener.h"

#include "C2105115Parser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct C2105115ParserStaticData final {
  C2105115ParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  C2105115ParserStaticData(const C2105115ParserStaticData&) = delete;
  C2105115ParserStaticData(C2105115ParserStaticData&&) = delete;
  C2105115ParserStaticData& operator=(const C2105115ParserStaticData&) = delete;
  C2105115ParserStaticData& operator=(C2105115ParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag c2105115parserParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<C2105115ParserStaticData> c2105115parserParserStaticData = nullptr;

void c2105115parserParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (c2105115parserParserStaticData != nullptr) {
    return;
  }
#else
  assert(c2105115parserParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<C2105115ParserStaticData>(
    std::vector<std::string>{
      "start", "program", "unit", "func_declaration", "func_definition", 
      "parameter_list", "compound_statement", "var_declaration", "declaration_list_err", 
      "type_specifier", "declaration_list", "statements", "statement", "expression_statement", 
      "variable", "expression", "logic_expression", "rel_expression", "simple_expression", 
      "term", "unary_expression", "factor", "argument_list", "arguments"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'if'", "'else'", "'for'", "'while'", "'printf'", 
      "'return'", "'int'", "'float'", "'void'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "';'", "','", "", "", "", "'++'", "'--'", "'!'", "", 
      "", "'='"
    },
    std::vector<std::string>{
      "", "LINE_COMMENT", "BLOCK_COMMENT", "STRING", "WS", "IF", "ELSE", 
      "FOR", "WHILE", "PRINTLN", "RETURN", "INT", "FLOAT", "VOID", "LPAREN", 
      "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON", "COMMA", 
      "ADDOP", "SUBOP", "MULOP", "INCOP", "DECOP", "NOT", "RELOP", "LOGICOP", 
      "ASSIGNOP", "ID", "CONST_INT", "CONST_FLOAT"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,33,405,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,1,0,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,5,
  	1,60,8,1,10,1,12,1,63,9,1,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,1,2,3,2,74,
  	8,2,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,1,3,3,
  	3,92,8,3,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,1,4,
  	1,4,1,4,1,4,1,4,3,4,113,8,4,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,3,5,123,8,
  	5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,1,5,5,5,136,8,5,10,5,12,5,139,
  	9,5,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,151,8,6,1,7,1,7,1,7,1,
  	7,1,7,1,7,1,7,1,7,1,7,1,7,3,7,163,8,7,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,
  	3,9,173,8,9,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,3,10,183,8,10,1,10,
  	1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,1,10,5,10,196,8,10,10,10,
  	12,10,199,9,10,1,11,1,11,1,11,1,11,1,11,1,11,1,11,1,11,5,11,209,8,11,
  	10,11,12,11,212,9,11,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,1,12,
  	3,12,266,8,12,1,13,1,13,1,13,1,13,1,13,1,13,3,13,274,8,13,1,14,1,14,1,
  	14,1,14,1,14,1,14,1,14,1,14,3,14,284,8,14,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,3,15,294,8,15,1,16,1,16,1,16,1,16,1,16,1,16,1,16,1,16,3,
  	16,304,8,16,1,17,1,17,1,17,1,17,1,17,1,17,1,17,1,17,3,17,314,8,17,1,18,
  	1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,5,18,325,8,18,10,18,12,18,328,
  	9,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,5,19,339,8,19,10,19,
  	12,19,342,9,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	3,20,355,8,20,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,
  	1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,1,21,
  	1,21,3,21,383,8,21,1,22,1,22,1,22,1,22,3,22,389,8,22,1,23,1,23,1,23,1,
  	23,1,23,1,23,1,23,1,23,1,23,5,23,400,8,23,10,23,12,23,403,9,23,1,23,0,
  	7,2,10,20,22,36,38,46,24,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,
  	34,36,38,40,42,44,46,0,0,421,0,48,1,0,0,0,2,51,1,0,0,0,4,73,1,0,0,0,6,
  	91,1,0,0,0,8,112,1,0,0,0,10,122,1,0,0,0,12,150,1,0,0,0,14,162,1,0,0,0,
  	16,164,1,0,0,0,18,172,1,0,0,0,20,182,1,0,0,0,22,200,1,0,0,0,24,265,1,
  	0,0,0,26,273,1,0,0,0,28,283,1,0,0,0,30,293,1,0,0,0,32,303,1,0,0,0,34,
  	313,1,0,0,0,36,315,1,0,0,0,38,329,1,0,0,0,40,354,1,0,0,0,42,382,1,0,0,
  	0,44,388,1,0,0,0,46,390,1,0,0,0,48,49,3,2,1,0,49,50,6,0,-1,0,50,1,1,0,
  	0,0,51,52,6,1,-1,0,52,53,3,4,2,0,53,54,6,1,-1,0,54,61,1,0,0,0,55,56,10,
  	2,0,0,56,57,3,4,2,0,57,58,6,1,-1,0,58,60,1,0,0,0,59,55,1,0,0,0,60,63,
  	1,0,0,0,61,59,1,0,0,0,61,62,1,0,0,0,62,3,1,0,0,0,63,61,1,0,0,0,64,65,
  	3,14,7,0,65,66,6,2,-1,0,66,74,1,0,0,0,67,68,3,6,3,0,68,69,6,2,-1,0,69,
  	74,1,0,0,0,70,71,3,8,4,0,71,72,6,2,-1,0,72,74,1,0,0,0,73,64,1,0,0,0,73,
  	67,1,0,0,0,73,70,1,0,0,0,74,5,1,0,0,0,75,76,3,18,9,0,76,77,5,31,0,0,77,
  	78,5,14,0,0,78,79,6,3,-1,0,79,80,3,10,5,0,80,81,5,15,0,0,81,82,5,20,0,
  	0,82,83,6,3,-1,0,83,92,1,0,0,0,84,85,3,18,9,0,85,86,5,31,0,0,86,87,5,
  	14,0,0,87,88,5,15,0,0,88,89,5,20,0,0,89,90,6,3,-1,0,90,92,1,0,0,0,91,
  	75,1,0,0,0,91,84,1,0,0,0,92,7,1,0,0,0,93,94,3,18,9,0,94,95,5,31,0,0,95,
  	96,6,4,-1,0,96,97,5,14,0,0,97,98,6,4,-1,0,98,99,3,10,5,0,99,100,5,15,
  	0,0,100,101,3,12,6,0,101,102,6,4,-1,0,102,113,1,0,0,0,103,104,3,18,9,
  	0,104,105,5,31,0,0,105,106,6,4,-1,0,106,107,5,14,0,0,107,108,6,4,-1,0,
  	108,109,5,15,0,0,109,110,3,12,6,0,110,111,6,4,-1,0,111,113,1,0,0,0,112,
  	93,1,0,0,0,112,103,1,0,0,0,113,9,1,0,0,0,114,115,6,5,-1,0,115,116,3,18,
  	9,0,116,117,5,31,0,0,117,118,6,5,-1,0,118,123,1,0,0,0,119,120,3,18,9,
  	0,120,121,6,5,-1,0,121,123,1,0,0,0,122,114,1,0,0,0,122,119,1,0,0,0,123,
  	137,1,0,0,0,124,125,10,4,0,0,125,126,5,21,0,0,126,127,3,18,9,0,127,128,
  	5,31,0,0,128,129,6,5,-1,0,129,136,1,0,0,0,130,131,10,3,0,0,131,132,5,
  	21,0,0,132,133,3,18,9,0,133,134,6,5,-1,0,134,136,1,0,0,0,135,124,1,0,
  	0,0,135,130,1,0,0,0,136,139,1,0,0,0,137,135,1,0,0,0,137,138,1,0,0,0,138,
  	11,1,0,0,0,139,137,1,0,0,0,140,141,5,16,0,0,141,142,6,6,-1,0,142,143,
  	3,22,11,0,143,144,5,17,0,0,144,145,6,6,-1,0,145,151,1,0,0,0,146,147,5,
  	16,0,0,147,148,6,6,-1,0,148,149,5,17,0,0,149,151,6,6,-1,0,150,140,1,0,
  	0,0,150,146,1,0,0,0,151,13,1,0,0,0,152,153,3,18,9,0,153,154,3,20,10,0,
  	154,155,5,20,0,0,155,156,6,7,-1,0,156,163,1,0,0,0,157,158,3,18,9,0,158,
  	159,3,16,8,0,159,160,5,20,0,0,160,161,6,7,-1,0,161,163,1,0,0,0,162,152,
  	1,0,0,0,162,157,1,0,0,0,163,15,1,0,0,0,164,165,6,8,-1,0,165,17,1,0,0,
  	0,166,167,5,11,0,0,167,173,6,9,-1,0,168,169,5,12,0,0,169,173,6,9,-1,0,
  	170,171,5,13,0,0,171,173,6,9,-1,0,172,166,1,0,0,0,172,168,1,0,0,0,172,
  	170,1,0,0,0,173,19,1,0,0,0,174,175,6,10,-1,0,175,176,5,31,0,0,176,183,
  	6,10,-1,0,177,178,5,31,0,0,178,179,5,18,0,0,179,180,5,32,0,0,180,181,
  	5,19,0,0,181,183,6,10,-1,0,182,174,1,0,0,0,182,177,1,0,0,0,183,197,1,
  	0,0,0,184,185,10,4,0,0,185,186,5,21,0,0,186,187,5,31,0,0,187,196,6,10,
  	-1,0,188,189,10,3,0,0,189,190,5,21,0,0,190,191,5,31,0,0,191,192,5,18,
  	0,0,192,193,5,32,0,0,193,194,5,19,0,0,194,196,6,10,-1,0,195,184,1,0,0,
  	0,195,188,1,0,0,0,196,199,1,0,0,0,197,195,1,0,0,0,197,198,1,0,0,0,198,
  	21,1,0,0,0,199,197,1,0,0,0,200,201,6,11,-1,0,201,202,3,24,12,0,202,203,
  	6,11,-1,0,203,210,1,0,0,0,204,205,10,1,0,0,205,206,3,24,12,0,206,207,
  	6,11,-1,0,207,209,1,0,0,0,208,204,1,0,0,0,209,212,1,0,0,0,210,208,1,0,
  	0,0,210,211,1,0,0,0,211,23,1,0,0,0,212,210,1,0,0,0,213,214,3,14,7,0,214,
  	215,6,12,-1,0,215,266,1,0,0,0,216,217,3,26,13,0,217,218,6,12,-1,0,218,
  	266,1,0,0,0,219,220,3,12,6,0,220,221,6,12,-1,0,221,266,1,0,0,0,222,223,
  	5,7,0,0,223,224,5,14,0,0,224,225,3,26,13,0,225,226,3,26,13,0,226,227,
  	3,30,15,0,227,228,5,15,0,0,228,229,3,24,12,0,229,230,6,12,-1,0,230,266,
  	1,0,0,0,231,232,5,5,0,0,232,233,5,14,0,0,233,234,3,30,15,0,234,235,5,
  	15,0,0,235,236,3,24,12,0,236,237,6,12,-1,0,237,266,1,0,0,0,238,239,5,
  	5,0,0,239,240,5,14,0,0,240,241,3,30,15,0,241,242,5,15,0,0,242,243,3,24,
  	12,0,243,244,5,6,0,0,244,245,3,24,12,0,245,246,6,12,-1,0,246,266,1,0,
  	0,0,247,248,5,8,0,0,248,249,5,14,0,0,249,250,3,30,15,0,250,251,5,15,0,
  	0,251,252,3,24,12,0,252,253,6,12,-1,0,253,266,1,0,0,0,254,255,5,9,0,0,
  	255,256,5,14,0,0,256,257,5,31,0,0,257,258,5,15,0,0,258,259,5,20,0,0,259,
  	266,6,12,-1,0,260,261,5,10,0,0,261,262,3,30,15,0,262,263,5,20,0,0,263,
  	264,6,12,-1,0,264,266,1,0,0,0,265,213,1,0,0,0,265,216,1,0,0,0,265,219,
  	1,0,0,0,265,222,1,0,0,0,265,231,1,0,0,0,265,238,1,0,0,0,265,247,1,0,0,
  	0,265,254,1,0,0,0,265,260,1,0,0,0,266,25,1,0,0,0,267,268,5,20,0,0,268,
  	274,6,13,-1,0,269,270,3,30,15,0,270,271,5,20,0,0,271,272,6,13,-1,0,272,
  	274,1,0,0,0,273,267,1,0,0,0,273,269,1,0,0,0,274,27,1,0,0,0,275,276,5,
  	31,0,0,276,284,6,14,-1,0,277,278,5,31,0,0,278,279,5,18,0,0,279,280,3,
  	30,15,0,280,281,5,19,0,0,281,282,6,14,-1,0,282,284,1,0,0,0,283,275,1,
  	0,0,0,283,277,1,0,0,0,284,29,1,0,0,0,285,286,3,32,16,0,286,287,6,15,-1,
  	0,287,294,1,0,0,0,288,289,3,28,14,0,289,290,5,30,0,0,290,291,3,32,16,
  	0,291,292,6,15,-1,0,292,294,1,0,0,0,293,285,1,0,0,0,293,288,1,0,0,0,294,
  	31,1,0,0,0,295,296,3,34,17,0,296,297,6,16,-1,0,297,304,1,0,0,0,298,299,
  	3,34,17,0,299,300,5,29,0,0,300,301,3,34,17,0,301,302,6,16,-1,0,302,304,
  	1,0,0,0,303,295,1,0,0,0,303,298,1,0,0,0,304,33,1,0,0,0,305,306,3,36,18,
  	0,306,307,6,17,-1,0,307,314,1,0,0,0,308,309,3,36,18,0,309,310,5,28,0,
  	0,310,311,3,36,18,0,311,312,6,17,-1,0,312,314,1,0,0,0,313,305,1,0,0,0,
  	313,308,1,0,0,0,314,35,1,0,0,0,315,316,6,18,-1,0,316,317,3,38,19,0,317,
  	318,6,18,-1,0,318,326,1,0,0,0,319,320,10,1,0,0,320,321,5,22,0,0,321,322,
  	3,38,19,0,322,323,6,18,-1,0,323,325,1,0,0,0,324,319,1,0,0,0,325,328,1,
  	0,0,0,326,324,1,0,0,0,326,327,1,0,0,0,327,37,1,0,0,0,328,326,1,0,0,0,
  	329,330,6,19,-1,0,330,331,3,40,20,0,331,332,6,19,-1,0,332,340,1,0,0,0,
  	333,334,10,1,0,0,334,335,5,24,0,0,335,336,3,40,20,0,336,337,6,19,-1,0,
  	337,339,1,0,0,0,338,333,1,0,0,0,339,342,1,0,0,0,340,338,1,0,0,0,340,341,
  	1,0,0,0,341,39,1,0,0,0,342,340,1,0,0,0,343,344,5,22,0,0,344,345,3,40,
  	20,0,345,346,6,20,-1,0,346,355,1,0,0,0,347,348,5,27,0,0,348,349,3,40,
  	20,0,349,350,6,20,-1,0,350,355,1,0,0,0,351,352,3,42,21,0,352,353,6,20,
  	-1,0,353,355,1,0,0,0,354,343,1,0,0,0,354,347,1,0,0,0,354,351,1,0,0,0,
  	355,41,1,0,0,0,356,357,3,28,14,0,357,358,6,21,-1,0,358,383,1,0,0,0,359,
  	360,5,31,0,0,360,361,5,14,0,0,361,362,3,44,22,0,362,363,5,15,0,0,363,
  	364,6,21,-1,0,364,383,1,0,0,0,365,366,5,14,0,0,366,367,3,30,15,0,367,
  	368,5,15,0,0,368,369,6,21,-1,0,369,383,1,0,0,0,370,371,5,32,0,0,371,383,
  	6,21,-1,0,372,373,5,33,0,0,373,383,6,21,-1,0,374,375,3,28,14,0,375,376,
  	5,25,0,0,376,377,6,21,-1,0,377,383,1,0,0,0,378,379,3,28,14,0,379,380,
  	5,26,0,0,380,381,6,21,-1,0,381,383,1,0,0,0,382,356,1,0,0,0,382,359,1,
  	0,0,0,382,365,1,0,0,0,382,370,1,0,0,0,382,372,1,0,0,0,382,374,1,0,0,0,
  	382,378,1,0,0,0,383,43,1,0,0,0,384,385,3,46,23,0,385,386,6,22,-1,0,386,
  	389,1,0,0,0,387,389,6,22,-1,0,388,384,1,0,0,0,388,387,1,0,0,0,389,45,
  	1,0,0,0,390,391,6,23,-1,0,391,392,3,32,16,0,392,393,6,23,-1,0,393,401,
  	1,0,0,0,394,395,10,2,0,0,395,396,5,21,0,0,396,397,3,32,16,0,397,398,6,
  	23,-1,0,398,400,1,0,0,0,399,394,1,0,0,0,400,403,1,0,0,0,401,399,1,0,0,
  	0,401,402,1,0,0,0,402,47,1,0,0,0,403,401,1,0,0,0,26,61,73,91,112,122,
  	135,137,150,162,172,182,195,197,210,265,273,283,293,303,313,326,340,354,
  	382,388,401
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  c2105115parserParserStaticData = std::move(staticData);
}

}

C2105115Parser::C2105115Parser(TokenStream *input) : C2105115Parser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

C2105115Parser::C2105115Parser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  C2105115Parser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *c2105115parserParserStaticData->atn, c2105115parserParserStaticData->decisionToDFA, c2105115parserParserStaticData->sharedContextCache, options);
}

C2105115Parser::~C2105115Parser() {
  delete _interpreter;
}

const atn::ATN& C2105115Parser::getATN() const {
  return *c2105115parserParserStaticData->atn;
}

std::string C2105115Parser::getGrammarFileName() const {
  return "C2105115Parser.g4";
}

const std::vector<std::string>& C2105115Parser::getRuleNames() const {
  return c2105115parserParserStaticData->ruleNames;
}

const dfa::Vocabulary& C2105115Parser::getVocabulary() const {
  return c2105115parserParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView C2105115Parser::getSerializedATN() const {
  return c2105115parserParserStaticData->serializedATN;
}


//----------------- StartContext ------------------------------------------------------------------

C2105115Parser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::ProgramContext* C2105115Parser::StartContext::program() {
  return getRuleContext<C2105115Parser::ProgramContext>(0);
}


size_t C2105115Parser::StartContext::getRuleIndex() const {
  return C2105115Parser::RuleStart;
}

void C2105115Parser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void C2105115Parser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

C2105115Parser::StartContext* C2105115Parser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, C2105115Parser::RuleStart);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    antlrcpp::downCast<StartContext *>(_localctx)->p = program(0);

            writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<StartContext *>(_localctx)->p != nullptr ? (antlrcpp::downCast<StartContext *>(_localctx)->p->stop) : nullptr)->getLine()) + ": start : program");
            writeIntoparserLogFile("");
            symbolTable.printAllScopeTables(parserLogFile);
            writeIntoparserLogFile("");
            writeIntoparserLogFile("Total number of lines: " + std::to_string((antlrcpp::downCast<StartContext *>(_localctx)->p != nullptr ? (antlrcpp::downCast<StartContext *>(_localctx)->p->stop) : nullptr)->getLine()));
            writeIntoparserLogFile("Total number of errors: " + std::to_string(syntaxErrorCount));
    	
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramContext ------------------------------------------------------------------

C2105115Parser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::UnitContext* C2105115Parser::ProgramContext::unit() {
  return getRuleContext<C2105115Parser::UnitContext>(0);
}

C2105115Parser::ProgramContext* C2105115Parser::ProgramContext::program() {
  return getRuleContext<C2105115Parser::ProgramContext>(0);
}


size_t C2105115Parser::ProgramContext::getRuleIndex() const {
  return C2105115Parser::RuleProgram;
}

void C2105115Parser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void C2105115Parser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}


C2105115Parser::ProgramContext* C2105115Parser::program() {
   return program(0);
}

C2105115Parser::ProgramContext* C2105115Parser::program(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105115Parser::ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, parentState);
  C2105115Parser::ProgramContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, C2105115Parser::RuleProgram, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(52);
    antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

                antlrcpp::downCast<ProgramContext *>(_localctx)->text =  antlrcpp::downCast<ProgramContext *>(_localctx)->u->text;
                writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<ProgramContext *>(_localctx)->u != nullptr ? (antlrcpp::downCast<ProgramContext *>(_localctx)->u->stop) : nullptr)->getLine()) + ": program : unit");
                writeIntoparserLogFile("");
                writeIntoparserLogFile(_localctx->text);
                writeIntoparserLogFile("");
            
    _ctx->stop = _input->LT(-1);
    setState(61);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ProgramContext>(parentContext, parentState);
        _localctx->p = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleProgram);
        setState(55);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(56);
        antlrcpp::downCast<ProgramContext *>(_localctx)->u = unit();

                              antlrcpp::downCast<ProgramContext *>(_localctx)->text =  antlrcpp::downCast<ProgramContext *>(_localctx)->p->text + "\n" + antlrcpp::downCast<ProgramContext *>(_localctx)->u->text;
                              writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<ProgramContext *>(_localctx)->u != nullptr ? (antlrcpp::downCast<ProgramContext *>(_localctx)->u->stop) : nullptr)->getLine()) + ": program : program unit");
                              writeIntoparserLogFile("");
                              writeIntoparserLogFile(_localctx->text);
                              writeIntoparserLogFile("");
                           
      }
      setState(63);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- UnitContext ------------------------------------------------------------------

C2105115Parser::UnitContext::UnitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::Var_declarationContext* C2105115Parser::UnitContext::var_declaration() {
  return getRuleContext<C2105115Parser::Var_declarationContext>(0);
}

C2105115Parser::Func_declarationContext* C2105115Parser::UnitContext::func_declaration() {
  return getRuleContext<C2105115Parser::Func_declarationContext>(0);
}

C2105115Parser::Func_definitionContext* C2105115Parser::UnitContext::func_definition() {
  return getRuleContext<C2105115Parser::Func_definitionContext>(0);
}


size_t C2105115Parser::UnitContext::getRuleIndex() const {
  return C2105115Parser::RuleUnit;
}

void C2105115Parser::UnitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnit(this);
}

void C2105115Parser::UnitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnit(this);
}

C2105115Parser::UnitContext* C2105115Parser::unit() {
  UnitContext *_localctx = _tracker.createInstance<UnitContext>(_ctx, getState());
  enterRule(_localctx, 4, C2105115Parser::RuleUnit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(73);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(64);
      antlrcpp::downCast<UnitContext *>(_localctx)->v = var_declaration();

                  antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->v->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<UnitContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<UnitContext *>(_localctx)->v->stop) : nullptr)->getLine()) + ": unit : var_declaration");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(antlrcpp::downCast<UnitContext *>(_localctx)->v->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(67);
      antlrcpp::downCast<UnitContext *>(_localctx)->fd = func_declaration();

                  antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->fd->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<UnitContext *>(_localctx)->fd != nullptr ? (antlrcpp::downCast<UnitContext *>(_localctx)->fd->stop) : nullptr)->getLine()) + ": unit : func_declaration");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(antlrcpp::downCast<UnitContext *>(_localctx)->fd->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(70);
      antlrcpp::downCast<UnitContext *>(_localctx)->fdef = func_definition();

                  antlrcpp::downCast<UnitContext *>(_localctx)->text =  antlrcpp::downCast<UnitContext *>(_localctx)->fdef->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<UnitContext *>(_localctx)->fdef != nullptr ? (antlrcpp::downCast<UnitContext *>(_localctx)->fdef->stop) : nullptr)->getLine()) + ": unit : func_definition");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(antlrcpp::downCast<UnitContext *>(_localctx)->fdef->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_declarationContext ------------------------------------------------------------------

C2105115Parser::Func_declarationContext::Func_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::Type_specifierContext* C2105115Parser::Func_declarationContext::type_specifier() {
  return getRuleContext<C2105115Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105115Parser::Func_declarationContext::ID() {
  return getToken(C2105115Parser::ID, 0);
}

tree::TerminalNode* C2105115Parser::Func_declarationContext::LPAREN() {
  return getToken(C2105115Parser::LPAREN, 0);
}

C2105115Parser::Parameter_listContext* C2105115Parser::Func_declarationContext::parameter_list() {
  return getRuleContext<C2105115Parser::Parameter_listContext>(0);
}

tree::TerminalNode* C2105115Parser::Func_declarationContext::RPAREN() {
  return getToken(C2105115Parser::RPAREN, 0);
}

tree::TerminalNode* C2105115Parser::Func_declarationContext::SEMICOLON() {
  return getToken(C2105115Parser::SEMICOLON, 0);
}


size_t C2105115Parser::Func_declarationContext::getRuleIndex() const {
  return C2105115Parser::RuleFunc_declaration;
}

void C2105115Parser::Func_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_declaration(this);
}

void C2105115Parser::Func_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_declaration(this);
}

C2105115Parser::Func_declarationContext* C2105115Parser::func_declaration() {
  Func_declarationContext *_localctx = _tracker.createInstance<Func_declarationContext>(_ctx, getState());
  enterRule(_localctx, 6, C2105115Parser::RuleFunc_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(91);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(75);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(76);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->i = match(C2105115Parser::ID);
      setState(77);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->lp = match(C2105115Parser::LPAREN);


              
      setState(79);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->p = parameter_list(0);
      setState(80);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->rp = match(C2105115Parser::RPAREN);
      setState(81);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->s = match(C2105115Parser::SEMICOLON);

                  antlrcpp::downCast<Func_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->i->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->lp->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->p->text + antlrcpp::downCast<Func_declarationContext *>(_localctx)->rp->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->s->getText();

                  bool inserted = symbolTable.insert(antlrcpp::downCast<Func_declarationContext *>(_localctx)->i->getText(), currentTypeSpecifier , parserLogFile);

       		    if (!inserted) {
       		        writeIntoErrorFile("Error in func_declaration");
       		         syntaxErrorCount++;
       		    }

                  writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->i->getLine()) + ": func_declaration : type_specifier ID LPAREN parameter_list RPAREN SEMICOLON");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(84);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->t = type_specifier();
      setState(85);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->i = match(C2105115Parser::ID);
      setState(86);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->lp = match(C2105115Parser::LPAREN);
      setState(87);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->rp = match(C2105115Parser::RPAREN);
      setState(88);
      antlrcpp::downCast<Func_declarationContext *>(_localctx)->s = match(C2105115Parser::SEMICOLON);

                  antlrcpp::downCast<Func_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Func_declarationContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Func_declarationContext *>(_localctx)->i->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->lp->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->rp->getText() + antlrcpp::downCast<Func_declarationContext *>(_localctx)->s->getText();

                  bool inserted = symbolTable.insert(antlrcpp::downCast<Func_declarationContext *>(_localctx)->i->getText(), currentTypeSpecifier , parserLogFile);

       		    if (!inserted) {
       		        writeIntoErrorFile("Error in func_declaration");
       		          syntaxErrorCount++;
       		    }

                  writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Func_declarationContext *>(_localctx)->i->getLine()) + ": func_declaration : type_specifier ID LPAREN RPAREN SEMICOLON");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Func_definitionContext ------------------------------------------------------------------

C2105115Parser::Func_definitionContext::Func_definitionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::Type_specifierContext* C2105115Parser::Func_definitionContext::type_specifier() {
  return getRuleContext<C2105115Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105115Parser::Func_definitionContext::ID() {
  return getToken(C2105115Parser::ID, 0);
}

tree::TerminalNode* C2105115Parser::Func_definitionContext::LPAREN() {
  return getToken(C2105115Parser::LPAREN, 0);
}

C2105115Parser::Parameter_listContext* C2105115Parser::Func_definitionContext::parameter_list() {
  return getRuleContext<C2105115Parser::Parameter_listContext>(0);
}

tree::TerminalNode* C2105115Parser::Func_definitionContext::RPAREN() {
  return getToken(C2105115Parser::RPAREN, 0);
}

C2105115Parser::Compound_statementContext* C2105115Parser::Func_definitionContext::compound_statement() {
  return getRuleContext<C2105115Parser::Compound_statementContext>(0);
}


size_t C2105115Parser::Func_definitionContext::getRuleIndex() const {
  return C2105115Parser::RuleFunc_definition;
}

void C2105115Parser::Func_definitionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunc_definition(this);
}

void C2105115Parser::Func_definitionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunc_definition(this);
}

C2105115Parser::Func_definitionContext* C2105115Parser::func_definition() {
  Func_definitionContext *_localctx = _tracker.createInstance<Func_definitionContext>(_ctx, getState());
  enterRule(_localctx, 8, C2105115Parser::RuleFunc_definition);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(112);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(93);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(94);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->i = match(C2105115Parser::ID);


                  // First insert the function name in the current scope
                  bool inserted = symbolTable.insert(antlrcpp::downCast<Func_definitionContext *>(_localctx)->i->getText(), currentTypeSpecifier, parserLogFile);

               
      setState(96);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lp = match(C2105115Parser::LPAREN);

                  
                  func_def = 1;
                  // Enter a new scope for function parameters
                  symbolTable.enterScope();
               
      setState(98);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->p = parameter_list(0);
      setState(99);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rp = match(C2105115Parser::RPAREN);
      setState(100);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->c = compound_statement();

                  antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->i->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->lp->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->p->text + antlrcpp::downCast<Func_definitionContext *>(_localctx)->rp->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->text;

                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->stop) : nullptr)->getLine()) + ": func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(103);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->t = type_specifier();
      setState(104);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->i = match(C2105115Parser::ID);

                  // First insert the function name in the current scope
                  bool inserted = symbolTable.insert(antlrcpp::downCast<Func_definitionContext *>(_localctx)->i->getText(), currentTypeSpecifier, parserLogFile);

              
      setState(106);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->lp = match(C2105115Parser::LPAREN);

                  func_def = 1;
                  // Enter a new scope for function parameters (even if none)
                  symbolTable.enterScope();
              
      setState(108);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->rp = match(C2105115Parser::RPAREN);
      setState(109);
      antlrcpp::downCast<Func_definitionContext *>(_localctx)->c = compound_statement();

                  antlrcpp::downCast<Func_definitionContext *>(_localctx)->text =  antlrcpp::downCast<Func_definitionContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Func_definitionContext *>(_localctx)->i->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->lp->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->rp->getText() + antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->text;

                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<Func_definitionContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<Func_definitionContext *>(_localctx)->c->stop) : nullptr)->getLine()) + ": func_definition : type_specifier ID LPAREN RPAREN compound_statement");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Parameter_listContext ------------------------------------------------------------------

C2105115Parser::Parameter_listContext::Parameter_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::Type_specifierContext* C2105115Parser::Parameter_listContext::type_specifier() {
  return getRuleContext<C2105115Parser::Type_specifierContext>(0);
}

tree::TerminalNode* C2105115Parser::Parameter_listContext::ID() {
  return getToken(C2105115Parser::ID, 0);
}

C2105115Parser::Parameter_listContext* C2105115Parser::Parameter_listContext::parameter_list() {
  return getRuleContext<C2105115Parser::Parameter_listContext>(0);
}

tree::TerminalNode* C2105115Parser::Parameter_listContext::COMMA() {
  return getToken(C2105115Parser::COMMA, 0);
}


size_t C2105115Parser::Parameter_listContext::getRuleIndex() const {
  return C2105115Parser::RuleParameter_list;
}

void C2105115Parser::Parameter_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameter_list(this);
}

void C2105115Parser::Parameter_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameter_list(this);
}


C2105115Parser::Parameter_listContext* C2105115Parser::parameter_list() {
   return parameter_list(0);
}

C2105115Parser::Parameter_listContext* C2105115Parser::parameter_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105115Parser::Parameter_listContext *_localctx = _tracker.createInstance<Parameter_listContext>(_ctx, parentState);
  C2105115Parser::Parameter_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 10;
  enterRecursionRule(_localctx, 10, C2105115Parser::RuleParameter_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(122);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx)) {
    case 1: {
      setState(115);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
      setState(116);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->i = match(C2105115Parser::ID);

                  antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->i->getText();

                  if(func_def == 1) {

                      bool inserted = symbolTable.insert(antlrcpp::downCast<Parameter_listContext *>(_localctx)->i->getText(), currentTypeSpecifier , parserLogFile);

       		        if (!inserted) {
       		            writeIntoErrorFile("Error in parameter_list");
                          writeIntoErrorFile("");
       		            syntaxErrorCount++;
       		        }

                  }

                  writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->i->getLine()) + ": parameter_list : type_specifier ID");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 2: {
      setState(119);
      antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();

                  antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->text;

                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->start) : nullptr)->getLine()) + ": parameter_list : type_specifier");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(137);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(135);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->p = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(124);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(125);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->c = match(C2105115Parser::COMMA);
          setState(126);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();
          setState(127);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->i = match(C2105115Parser::ID);

                                antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->p->text + antlrcpp::downCast<Parameter_listContext *>(_localctx)->c->getText() + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->i->getText();

                                if(func_def == 1) {

                                    bool inserted = symbolTable.insert(antlrcpp::downCast<Parameter_listContext *>(_localctx)->i->getText(), currentTypeSpecifier , parserLogFile);

                     		        if (!inserted) {
                     		            writeIntoErrorFile("Error in parameter_list");
                                        writeIntoErrorFile("");
                     		            syntaxErrorCount++;
                     		        }

                                }

                                writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Parameter_listContext *>(_localctx)->i->getLine()) + ": parameter_list : parameter_list COMMA type_specifier ID");
                                writeIntoparserLogFile("");
                                writeIntoparserLogFile(_localctx->text);
                                writeIntoparserLogFile("");
                            
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Parameter_listContext>(parentContext, parentState);
          _localctx->p = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleParameter_list);
          setState(130);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(131);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->c = match(C2105115Parser::COMMA);
          setState(132);
          antlrcpp::downCast<Parameter_listContext *>(_localctx)->t = type_specifier();

                                antlrcpp::downCast<Parameter_listContext *>(_localctx)->text =  antlrcpp::downCast<Parameter_listContext *>(_localctx)->p->text + antlrcpp::downCast<Parameter_listContext *>(_localctx)->c->getText() + " " + antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->text;

                                writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<Parameter_listContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<Parameter_listContext *>(_localctx)->t->start) : nullptr)->getLine()) + ": parameter_list : parameter_list COMMA type_specifier");
                                writeIntoparserLogFile("");
                                writeIntoparserLogFile(_localctx->text);
                                writeIntoparserLogFile("");
                            
          break;
        }

        default:
          break;
        } 
      }
      setState(139);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

C2105115Parser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105115Parser::Compound_statementContext::LCURL() {
  return getToken(C2105115Parser::LCURL, 0);
}

C2105115Parser::StatementsContext* C2105115Parser::Compound_statementContext::statements() {
  return getRuleContext<C2105115Parser::StatementsContext>(0);
}

tree::TerminalNode* C2105115Parser::Compound_statementContext::RCURL() {
  return getToken(C2105115Parser::RCURL, 0);
}


size_t C2105115Parser::Compound_statementContext::getRuleIndex() const {
  return C2105115Parser::RuleCompound_statement;
}

void C2105115Parser::Compound_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompound_statement(this);
}

void C2105115Parser::Compound_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompound_statement(this);
}

C2105115Parser::Compound_statementContext* C2105115Parser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 12, C2105115Parser::RuleCompound_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(150);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(140);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->l = match(C2105115Parser::LCURL);

                  	if (func_def==1) {
                          func_def=0;
                      }

                      else {
                          symbolTable.enterScope();
                      }

              
      setState(142);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->s = statements(0);
      setState(143);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->r = match(C2105115Parser::RCURL);


                  cout<<"nice"<<endl;
                  antlrcpp::downCast<Compound_statementContext *>(_localctx)->text =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->l->getText() + "\n" + antlrcpp::downCast<Compound_statementContext *>(_localctx)->s->text + "\n" + antlrcpp::downCast<Compound_statementContext *>(_localctx)->r->getText();
                  writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->r->getLine()) + ": compound_statement : LCURL statements RCURL");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
                  
                  // Print the symbol table before exiting the scope
                  writeIntoparserLogFile("");
                  symbolTable.printAllScopeTables(parserLogFile);                               
                  writeIntoparserLogFile("");
                  symbolTable.exitScope(parserLogFile);
                  cout<<"nice222"<<endl;
                  
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(146);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->l = match(C2105115Parser::LCURL);

                      if (func_def==1) {
                          func_def=0;
                      }

                      else {
                          symbolTable.enterScope();
                      }
                      
              
      setState(148);
      antlrcpp::downCast<Compound_statementContext *>(_localctx)->r = match(C2105115Parser::RCURL);

                  antlrcpp::downCast<Compound_statementContext *>(_localctx)->text =  antlrcpp::downCast<Compound_statementContext *>(_localctx)->l->getText() + antlrcpp::downCast<Compound_statementContext *>(_localctx)->r->getText();
                  writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Compound_statementContext *>(_localctx)->r->getLine()) + ": compound_statement : LCURL RCURL");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
                  
                  // Print the symbol table before exiting the scope
                  writeIntoparserLogFile("");
                  symbolTable.printAllScopeTables(parserLogFile);
                  writeIntoparserLogFile("");
                  symbolTable.exitScope(parserLogFile);
                  
              
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_declarationContext ------------------------------------------------------------------

C2105115Parser::Var_declarationContext::Var_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::Type_specifierContext* C2105115Parser::Var_declarationContext::type_specifier() {
  return getRuleContext<C2105115Parser::Type_specifierContext>(0);
}

C2105115Parser::Declaration_listContext* C2105115Parser::Var_declarationContext::declaration_list() {
  return getRuleContext<C2105115Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C2105115Parser::Var_declarationContext::SEMICOLON() {
  return getToken(C2105115Parser::SEMICOLON, 0);
}

C2105115Parser::Declaration_list_errContext* C2105115Parser::Var_declarationContext::declaration_list_err() {
  return getRuleContext<C2105115Parser::Declaration_list_errContext>(0);
}


size_t C2105115Parser::Var_declarationContext::getRuleIndex() const {
  return C2105115Parser::RuleVar_declaration;
}

void C2105115Parser::Var_declarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVar_declaration(this);
}

void C2105115Parser::Var_declarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVar_declaration(this);
}

C2105115Parser::Var_declarationContext* C2105115Parser::var_declaration() {
  Var_declarationContext *_localctx = _tracker.createInstance<Var_declarationContext>(_ctx, getState());
  enterRule(_localctx, 14, C2105115Parser::RuleVar_declaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(152);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(153);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl = declaration_list(0);
      setState(154);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105115Parser::SEMICOLON);

              writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) + ": var_declaration : type_specifier declaration_list SEMICOLON");
      		writeIntoparserLogFile("");
              antlrcpp::downCast<Var_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text + " " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->dl->text + antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getText();
              writeIntoparserLogFile(_localctx->text);
              writeIntoparserLogFile("");
            
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(157);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->t = type_specifier();
      setState(158);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->de = declaration_list_err();
      setState(159);
      antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm = match(C2105115Parser::SEMICOLON);

              writeIntoErrorFile(
                  std::string("Line# ") + std::to_string(antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getLine()) +
                  " with error name: " + antlrcpp::downCast<Var_declarationContext *>(_localctx)->de->error_name +
                  " - Syntax error at declaration list of variable declaration"
              );
              writeIntoErrorFile("");
              antlrcpp::downCast<Var_declarationContext *>(_localctx)->text =  antlrcpp::downCast<Var_declarationContext *>(_localctx)->t->text + " error" + antlrcpp::downCast<Var_declarationContext *>(_localctx)->sm->getText();
              syntaxErrorCount++;
            
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_list_errContext ------------------------------------------------------------------

C2105115Parser::Declaration_list_errContext::Declaration_list_errContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t C2105115Parser::Declaration_list_errContext::getRuleIndex() const {
  return C2105115Parser::RuleDeclaration_list_err;
}

void C2105115Parser::Declaration_list_errContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list_err(this);
}

void C2105115Parser::Declaration_list_errContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list_err(this);
}

C2105115Parser::Declaration_list_errContext* C2105115Parser::declaration_list_err() {
  Declaration_list_errContext *_localctx = _tracker.createInstance<Declaration_list_errContext>(_ctx, getState());
  enterRule(_localctx, 16, C2105115Parser::RuleDeclaration_list_err);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

            antlrcpp::downCast<Declaration_list_errContext *>(_localctx)->error_name =  "Error in declaration list";
        
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specifierContext ------------------------------------------------------------------

C2105115Parser::Type_specifierContext::Type_specifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105115Parser::Type_specifierContext::INT() {
  return getToken(C2105115Parser::INT, 0);
}

tree::TerminalNode* C2105115Parser::Type_specifierContext::FLOAT() {
  return getToken(C2105115Parser::FLOAT, 0);
}

tree::TerminalNode* C2105115Parser::Type_specifierContext::VOID() {
  return getToken(C2105115Parser::VOID, 0);
}


size_t C2105115Parser::Type_specifierContext::getRuleIndex() const {
  return C2105115Parser::RuleType_specifier;
}

void C2105115Parser::Type_specifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_specifier(this);
}

void C2105115Parser::Type_specifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_specifier(this);
}

C2105115Parser::Type_specifierContext* C2105115Parser::type_specifier() {
  Type_specifierContext *_localctx = _tracker.createInstance<Type_specifierContext>(_ctx, getState());
  enterRule(_localctx, 18, C2105115Parser::RuleType_specifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(172);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105115Parser::INT: {
        enterOuterAlt(_localctx, 1);
        setState(166);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken = match(C2105115Parser::INT);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->name_line =  "INT";
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getText();
                    currentTypeSpecifier = "INT"; // Store the current type
                    writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->intToken->getLine()) + ": type_specifier : " + _localctx->name_line);
        			writeIntoparserLogFile("");
                    writeIntoparserLogFile(_localctx->text);
                    writeIntoparserLogFile("");
                
        break;
      }

      case C2105115Parser::FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(168);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken = match(C2105115Parser::FLOAT);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->name_line =  "FLOAT";
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getText();
                    currentTypeSpecifier = "FLOAT"; // Store the current type
                    writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->floatToken->getLine()) + ": type_specifier : " + _localctx->name_line);
        			writeIntoparserLogFile("");
                    writeIntoparserLogFile(_localctx->text);
                    writeIntoparserLogFile("");
                
        break;
      }

      case C2105115Parser::VOID: {
        enterOuterAlt(_localctx, 3);
        setState(170);
        antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken = match(C2105115Parser::VOID);

                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->name_line =  "VOID";
                    antlrcpp::downCast<Type_specifierContext *>(_localctx)->text =  antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getText();
                    currentTypeSpecifier = "VOID"; // Store the current type
                    writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Type_specifierContext *>(_localctx)->voidToken->getLine()) + ": type_specifier : " + _localctx->name_line);
        			writeIntoparserLogFile("");
                    writeIntoparserLogFile(_localctx->text);
                    writeIntoparserLogFile("");
                
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Declaration_listContext ------------------------------------------------------------------

C2105115Parser::Declaration_listContext::Declaration_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105115Parser::Declaration_listContext::ID() {
  return getToken(C2105115Parser::ID, 0);
}

tree::TerminalNode* C2105115Parser::Declaration_listContext::LTHIRD() {
  return getToken(C2105115Parser::LTHIRD, 0);
}

tree::TerminalNode* C2105115Parser::Declaration_listContext::RTHIRD() {
  return getToken(C2105115Parser::RTHIRD, 0);
}

tree::TerminalNode* C2105115Parser::Declaration_listContext::CONST_INT() {
  return getToken(C2105115Parser::CONST_INT, 0);
}

C2105115Parser::Declaration_listContext* C2105115Parser::Declaration_listContext::declaration_list() {
  return getRuleContext<C2105115Parser::Declaration_listContext>(0);
}

tree::TerminalNode* C2105115Parser::Declaration_listContext::COMMA() {
  return getToken(C2105115Parser::COMMA, 0);
}


size_t C2105115Parser::Declaration_listContext::getRuleIndex() const {
  return C2105115Parser::RuleDeclaration_list;
}

void C2105115Parser::Declaration_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration_list(this);
}

void C2105115Parser::Declaration_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration_list(this);
}


C2105115Parser::Declaration_listContext* C2105115Parser::declaration_list() {
   return declaration_list(0);
}

C2105115Parser::Declaration_listContext* C2105115Parser::declaration_list(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105115Parser::Declaration_listContext *_localctx = _tracker.createInstance<Declaration_listContext>(_ctx, parentState);
  C2105115Parser::Declaration_listContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 20;
  enterRecursionRule(_localctx, 20, C2105115Parser::RuleDeclaration_list, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(182);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
    case 1: {
      setState(175);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C2105115Parser::ID);

       		      antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText();
       		      // Insert ID into symbol table with current type
       		      bool inserted = symbolTable.insert(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText(), currentTypeSpecifier, parserLogFile);
       		      if (!inserted) {
       		          writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText());
       		          writeIntoErrorFile("");
                        syntaxErrorCount++;
       		      }
       		      writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": declaration_list : ID");
       		      writeIntoparserLogFile("");
      			  writeIntoparserLogFile(_localctx->text);
      			  writeIntoparserLogFile("");
       		     
       		  
      break;
    }

    case 2: {
      setState(177);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C2105115Parser::ID);
      setState(178);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken = match(C2105115Parser::LTHIRD);
      setState(179);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci = match(C2105115Parser::CONST_INT);
      setState(180);
      antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken = match(C2105115Parser::RTHIRD);

       		      antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken->getText();
       		      // Insert array ID into symbol table with current type + array notation
       		      std::string arrayType = currentTypeSpecifier + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci->getText() + "]";
       		      bool inserted = symbolTable.insert(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText(), arrayType , parserLogFile);
       		      if (!inserted) {
       		          writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText());
       		          writeIntoErrorFile("");
                        syntaxErrorCount++;
       		      }
       		      writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": declaration_list : ID LTHIRD CONST_INT RTHIRD");
       		      writeIntoparserLogFile("");
      			  writeIntoparserLogFile(_localctx->text);
      			  writeIntoparserLogFile("");
       		    
       		  
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(197);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(195);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(184);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(185);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->cm = match(C2105115Parser::COMMA);
          setState(186);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C2105115Parser::ID);

                     		      antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->text + antlrcpp::downCast<Declaration_listContext *>(_localctx)->cm->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText();
                     		      // Insert ID into symbol table with current type
                     		      bool inserted = symbolTable.insert(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText(), currentTypeSpecifier , parserLogFile);
                     		      if (!inserted) {
                     		          writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText());
                                      writeIntoErrorFile("");
                     		          syntaxErrorCount++;
                     		      }
                     		      writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": declaration_list : declaration_list COMMA ID");
                     		      writeIntoparserLogFile("");
                    			  writeIntoparserLogFile(_localctx->text);
                    			  writeIntoparserLogFile("");
                     		      
                     		  
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<Declaration_listContext>(parentContext, parentState);
          _localctx->dl = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleDeclaration_list);
          setState(188);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(189);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->cm = match(C2105115Parser::COMMA);
          setState(190);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->id = match(C2105115Parser::ID);
          setState(191);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken = match(C2105115Parser::LTHIRD);
          setState(192);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci = match(C2105115Parser::CONST_INT);
          setState(193);
          antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken = match(C2105115Parser::RTHIRD);

                                cout<<"test1"<<endl;
                     		      antlrcpp::downCast<Declaration_listContext *>(_localctx)->text =  antlrcpp::downCast<Declaration_listContext *>(_localctx)->dl->text + antlrcpp::downCast<Declaration_listContext *>(_localctx)->cm->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->lthirdToken->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci->getText() + antlrcpp::downCast<Declaration_listContext *>(_localctx)->rthirdToken->getText();
                     		      // Insert array ID into symbol table with current type + array notation
                     		      std::string arrayType = currentTypeSpecifier + "[" + antlrcpp::downCast<Declaration_listContext *>(_localctx)->ci->getText() + "]";
                     		      bool inserted = symbolTable.insert(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText(), arrayType, parserLogFile);
                     		      if (!inserted) {
                     		          writeIntoErrorFile("Error at line " + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": Multiple declaration of " + antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getText());
                     		          writeIntoErrorFile("");
                                      syntaxErrorCount++;
                     		      }
                     		      writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Declaration_listContext *>(_localctx)->id->getLine()) + ": declaration_list : declaration_list COMMA ID LTHIRD CONST_INT RTHIRD");
                     		      writeIntoparserLogFile("");
                    			  writeIntoparserLogFile(_localctx->text);
                    			  writeIntoparserLogFile("");
                                cout<<"test2"<<endl;
                     		      
                     		  
          break;
        }

        default:
          break;
        } 
      }
      setState(199);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementsContext ------------------------------------------------------------------

C2105115Parser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::StatementContext* C2105115Parser::StatementsContext::statement() {
  return getRuleContext<C2105115Parser::StatementContext>(0);
}

C2105115Parser::StatementsContext* C2105115Parser::StatementsContext::statements() {
  return getRuleContext<C2105115Parser::StatementsContext>(0);
}


size_t C2105115Parser::StatementsContext::getRuleIndex() const {
  return C2105115Parser::RuleStatements;
}

void C2105115Parser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void C2105115Parser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
}


C2105115Parser::StatementsContext* C2105115Parser::statements() {
   return statements(0);
}

C2105115Parser::StatementsContext* C2105115Parser::statements(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105115Parser::StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, parentState);
  C2105115Parser::StatementsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 22;
  enterRecursionRule(_localctx, 22, C2105115Parser::RuleStatements, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(201);
    antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

                antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->s->text;
                writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<StatementsContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementsContext *>(_localctx)->s->start) : nullptr)->getLine()) + ": statements : statement");
                writeIntoparserLogFile("");
                writeIntoparserLogFile(_localctx->text);
                writeIntoparserLogFile("");
            
    _ctx->stop = _input->LT(-1);
    setState(210);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<StatementsContext>(parentContext, parentState);
        _localctx->ss = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleStatements);
        setState(204);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(205);
        antlrcpp::downCast<StatementsContext *>(_localctx)->s = statement();

                              antlrcpp::downCast<StatementsContext *>(_localctx)->text =  antlrcpp::downCast<StatementsContext *>(_localctx)->ss->text + "\n" + antlrcpp::downCast<StatementsContext *>(_localctx)->s->text;
                              writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<StatementsContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementsContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statements : statements statement");
                              writeIntoparserLogFile("");
                              writeIntoparserLogFile(_localctx->text);
                              writeIntoparserLogFile("");
                           
      }
      setState(212);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

C2105115Parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::Var_declarationContext* C2105115Parser::StatementContext::var_declaration() {
  return getRuleContext<C2105115Parser::Var_declarationContext>(0);
}

std::vector<C2105115Parser::Expression_statementContext *> C2105115Parser::StatementContext::expression_statement() {
  return getRuleContexts<C2105115Parser::Expression_statementContext>();
}

C2105115Parser::Expression_statementContext* C2105115Parser::StatementContext::expression_statement(size_t i) {
  return getRuleContext<C2105115Parser::Expression_statementContext>(i);
}

C2105115Parser::Compound_statementContext* C2105115Parser::StatementContext::compound_statement() {
  return getRuleContext<C2105115Parser::Compound_statementContext>(0);
}

tree::TerminalNode* C2105115Parser::StatementContext::FOR() {
  return getToken(C2105115Parser::FOR, 0);
}

tree::TerminalNode* C2105115Parser::StatementContext::LPAREN() {
  return getToken(C2105115Parser::LPAREN, 0);
}

C2105115Parser::ExpressionContext* C2105115Parser::StatementContext::expression() {
  return getRuleContext<C2105115Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105115Parser::StatementContext::RPAREN() {
  return getToken(C2105115Parser::RPAREN, 0);
}

std::vector<C2105115Parser::StatementContext *> C2105115Parser::StatementContext::statement() {
  return getRuleContexts<C2105115Parser::StatementContext>();
}

C2105115Parser::StatementContext* C2105115Parser::StatementContext::statement(size_t i) {
  return getRuleContext<C2105115Parser::StatementContext>(i);
}

tree::TerminalNode* C2105115Parser::StatementContext::IF() {
  return getToken(C2105115Parser::IF, 0);
}

tree::TerminalNode* C2105115Parser::StatementContext::ELSE() {
  return getToken(C2105115Parser::ELSE, 0);
}

tree::TerminalNode* C2105115Parser::StatementContext::WHILE() {
  return getToken(C2105115Parser::WHILE, 0);
}

tree::TerminalNode* C2105115Parser::StatementContext::PRINTLN() {
  return getToken(C2105115Parser::PRINTLN, 0);
}

tree::TerminalNode* C2105115Parser::StatementContext::ID() {
  return getToken(C2105115Parser::ID, 0);
}

tree::TerminalNode* C2105115Parser::StatementContext::SEMICOLON() {
  return getToken(C2105115Parser::SEMICOLON, 0);
}

tree::TerminalNode* C2105115Parser::StatementContext::RETURN() {
  return getToken(C2105115Parser::RETURN, 0);
}


size_t C2105115Parser::StatementContext::getRuleIndex() const {
  return C2105115Parser::RuleStatement;
}

void C2105115Parser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void C2105115Parser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

C2105115Parser::StatementContext* C2105115Parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 24, C2105115Parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(265);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(213);
      antlrcpp::downCast<StatementContext *>(_localctx)->v = var_declaration();

                  antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->v->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->v->stop) : nullptr)->getLine()) + ": statement : var_declaration");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(216);
      antlrcpp::downCast<StatementContext *>(_localctx)->es = expression_statement();

                  antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->es->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->es != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->es->stop) : nullptr)->getLine()) + ": statement : expression_statement");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(219);
      antlrcpp::downCast<StatementContext *>(_localctx)->c = compound_statement();

                  antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->c->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->c != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->c->stop) : nullptr)->getLine()) + ": statement : compound_statement");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(222);
      antlrcpp::downCast<StatementContext *>(_localctx)->f = match(C2105115Parser::FOR);
      setState(223);
      antlrcpp::downCast<StatementContext *>(_localctx)->lp = match(C2105115Parser::LPAREN);
      setState(224);
      antlrcpp::downCast<StatementContext *>(_localctx)->e1 = expression_statement();
      setState(225);
      antlrcpp::downCast<StatementContext *>(_localctx)->e2 = expression_statement();
      setState(226);
      antlrcpp::downCast<StatementContext *>(_localctx)->exp = expression();
      setState(227);
      antlrcpp::downCast<StatementContext *>(_localctx)->rp = match(C2105115Parser::RPAREN);
      setState(228);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

                  antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->f->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->e1->text + antlrcpp::downCast<StatementContext *>(_localctx)->e2->text + antlrcpp::downCast<StatementContext *>(_localctx)->exp->text + antlrcpp::downCast<StatementContext *>(_localctx)->rp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(231);
      antlrcpp::downCast<StatementContext *>(_localctx)->i = match(C2105115Parser::IF);
      setState(232);
      antlrcpp::downCast<StatementContext *>(_localctx)->lp = match(C2105115Parser::LPAREN);
      setState(233);
      antlrcpp::downCast<StatementContext *>(_localctx)->exp = expression();
      setState(234);
      antlrcpp::downCast<StatementContext *>(_localctx)->rp = match(C2105115Parser::RPAREN);
      setState(235);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

                  antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->i->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->exp->text + antlrcpp::downCast<StatementContext *>(_localctx)->rp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statement : IF LPAREN expression RPAREN statement");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(238);
      antlrcpp::downCast<StatementContext *>(_localctx)->i = match(C2105115Parser::IF);
      setState(239);
      antlrcpp::downCast<StatementContext *>(_localctx)->lp = match(C2105115Parser::LPAREN);
      setState(240);
      antlrcpp::downCast<StatementContext *>(_localctx)->exp = expression();
      setState(241);
      antlrcpp::downCast<StatementContext *>(_localctx)->rp = match(C2105115Parser::RPAREN);
      setState(242);
      antlrcpp::downCast<StatementContext *>(_localctx)->s1 = statement();
      setState(243);
      antlrcpp::downCast<StatementContext *>(_localctx)->el = match(C2105115Parser::ELSE);
      setState(244);
      antlrcpp::downCast<StatementContext *>(_localctx)->s2 = statement();

                  antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->i->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->exp->text + antlrcpp::downCast<StatementContext *>(_localctx)->rp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s1->text + " " + antlrcpp::downCast<StatementContext *>(_localctx)->el->getText() + " " + antlrcpp::downCast<StatementContext *>(_localctx)->s2->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s2 != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s2->stop) : nullptr)->getLine()) + ": statement : IF LPAREN expression RPAREN statement ELSE statement");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(247);
      antlrcpp::downCast<StatementContext *>(_localctx)->w = match(C2105115Parser::WHILE);
      setState(248);
      antlrcpp::downCast<StatementContext *>(_localctx)->lp = match(C2105115Parser::LPAREN);
      setState(249);
      antlrcpp::downCast<StatementContext *>(_localctx)->exp = expression();
      setState(250);
      antlrcpp::downCast<StatementContext *>(_localctx)->rp = match(C2105115Parser::RPAREN);
      setState(251);
      antlrcpp::downCast<StatementContext *>(_localctx)->s = statement();

                  antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->w->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->exp->text + antlrcpp::downCast<StatementContext *>(_localctx)->rp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->s->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<StatementContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<StatementContext *>(_localctx)->s->stop) : nullptr)->getLine()) + ": statement : WHILE LPAREN expression RPAREN statement");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(254);
      antlrcpp::downCast<StatementContext *>(_localctx)->p = match(C2105115Parser::PRINTLN);
      setState(255);
      antlrcpp::downCast<StatementContext *>(_localctx)->lp = match(C2105115Parser::LPAREN);
      setState(256);
      antlrcpp::downCast<StatementContext *>(_localctx)->id = match(C2105115Parser::ID);
      setState(257);
      antlrcpp::downCast<StatementContext *>(_localctx)->rp = match(C2105115Parser::RPAREN);
      setState(258);
      antlrcpp::downCast<StatementContext *>(_localctx)->sm = match(C2105115Parser::SEMICOLON);

                  cout << "Printf" << endl;
                  antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->p->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->lp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->id->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->rp->getText() + antlrcpp::downCast<StatementContext *>(_localctx)->sm->getText();
                  writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->sm->getLine()) + ": statement : PRINTLN LPAREN ID RPAREN SEMICOLON");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(260);
      antlrcpp::downCast<StatementContext *>(_localctx)->r = match(C2105115Parser::RETURN);
      setState(261);
      antlrcpp::downCast<StatementContext *>(_localctx)->exp = expression();
      setState(262);
      antlrcpp::downCast<StatementContext *>(_localctx)->sm = match(C2105115Parser::SEMICOLON);

                  antlrcpp::downCast<StatementContext *>(_localctx)->text =  antlrcpp::downCast<StatementContext *>(_localctx)->r->getText() + " " + antlrcpp::downCast<StatementContext *>(_localctx)->exp->text + antlrcpp::downCast<StatementContext *>(_localctx)->sm->getText();
                  writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<StatementContext *>(_localctx)->sm->getLine()) + ": statement : RETURN expression SEMICOLON");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Expression_statementContext ------------------------------------------------------------------

C2105115Parser::Expression_statementContext::Expression_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105115Parser::Expression_statementContext::SEMICOLON() {
  return getToken(C2105115Parser::SEMICOLON, 0);
}

C2105115Parser::ExpressionContext* C2105115Parser::Expression_statementContext::expression() {
  return getRuleContext<C2105115Parser::ExpressionContext>(0);
}


size_t C2105115Parser::Expression_statementContext::getRuleIndex() const {
  return C2105115Parser::RuleExpression_statement;
}

void C2105115Parser::Expression_statementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression_statement(this);
}

void C2105115Parser::Expression_statementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression_statement(this);
}

C2105115Parser::Expression_statementContext* C2105115Parser::expression_statement() {
  Expression_statementContext *_localctx = _tracker.createInstance<Expression_statementContext>(_ctx, getState());
  enterRule(_localctx, 26, C2105115Parser::RuleExpression_statement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(273);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105115Parser::SEMICOLON: {
        enterOuterAlt(_localctx, 1);
        setState(267);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->s = match(C2105115Parser::SEMICOLON);

                    antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->s->getText();
                    writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Expression_statementContext *>(_localctx)->s->getLine()) + ": expression_statement : SEMICOLON");
                    writeIntoparserLogFile("");
                    writeIntoparserLogFile(_localctx->text);
                    writeIntoparserLogFile("");
                
        break;
      }

      case C2105115Parser::LPAREN:
      case C2105115Parser::ADDOP:
      case C2105115Parser::NOT:
      case C2105115Parser::ID:
      case C2105115Parser::CONST_INT:
      case C2105115Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 2);
        setState(269);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->e = expression();
        setState(270);
        antlrcpp::downCast<Expression_statementContext *>(_localctx)->s = match(C2105115Parser::SEMICOLON);

                    antlrcpp::downCast<Expression_statementContext *>(_localctx)->text =  antlrcpp::downCast<Expression_statementContext *>(_localctx)->e->text + antlrcpp::downCast<Expression_statementContext *>(_localctx)->s->getText();
                    writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<Expression_statementContext *>(_localctx)->e != nullptr ? (antlrcpp::downCast<Expression_statementContext *>(_localctx)->e->start) : nullptr)->getLine()) + ": expression_statement : expression SEMICOLON");
                    writeIntoparserLogFile("");
                    writeIntoparserLogFile(_localctx->text);
                    writeIntoparserLogFile("");
                
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

C2105115Parser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105115Parser::VariableContext::ID() {
  return getToken(C2105115Parser::ID, 0);
}

tree::TerminalNode* C2105115Parser::VariableContext::LTHIRD() {
  return getToken(C2105115Parser::LTHIRD, 0);
}

C2105115Parser::ExpressionContext* C2105115Parser::VariableContext::expression() {
  return getRuleContext<C2105115Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105115Parser::VariableContext::RTHIRD() {
  return getToken(C2105115Parser::RTHIRD, 0);
}


size_t C2105115Parser::VariableContext::getRuleIndex() const {
  return C2105115Parser::RuleVariable;
}

void C2105115Parser::VariableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVariable(this);
}

void C2105115Parser::VariableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVariable(this);
}

C2105115Parser::VariableContext* C2105115Parser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 28, C2105115Parser::RuleVariable);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(283);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(275);
      antlrcpp::downCast<VariableContext *>(_localctx)->id = match(C2105115Parser::ID);

                  antlrcpp::downCast<VariableContext *>(_localctx)->text =  antlrcpp::downCast<VariableContext *>(_localctx)->id->getText();
                  writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": variable : ID");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(277);
      antlrcpp::downCast<VariableContext *>(_localctx)->id = match(C2105115Parser::ID);
      setState(278);
      antlrcpp::downCast<VariableContext *>(_localctx)->l = match(C2105115Parser::LTHIRD);
      setState(279);
      antlrcpp::downCast<VariableContext *>(_localctx)->e = expression();
      setState(280);
      antlrcpp::downCast<VariableContext *>(_localctx)->r = match(C2105115Parser::RTHIRD);

                  antlrcpp::downCast<VariableContext *>(_localctx)->text =  antlrcpp::downCast<VariableContext *>(_localctx)->id->getText() + antlrcpp::downCast<VariableContext *>(_localctx)->l->getText() + antlrcpp::downCast<VariableContext *>(_localctx)->e->text + antlrcpp::downCast<VariableContext *>(_localctx)->r->getText();
                  writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<VariableContext *>(_localctx)->id->getLine()) + ": variable : ID LTHIRD expression RTHIRD");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

C2105115Parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::Logic_expressionContext* C2105115Parser::ExpressionContext::logic_expression() {
  return getRuleContext<C2105115Parser::Logic_expressionContext>(0);
}

C2105115Parser::VariableContext* C2105115Parser::ExpressionContext::variable() {
  return getRuleContext<C2105115Parser::VariableContext>(0);
}

tree::TerminalNode* C2105115Parser::ExpressionContext::ASSIGNOP() {
  return getToken(C2105115Parser::ASSIGNOP, 0);
}


size_t C2105115Parser::ExpressionContext::getRuleIndex() const {
  return C2105115Parser::RuleExpression;
}

void C2105115Parser::ExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpression(this);
}

void C2105115Parser::ExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpression(this);
}

C2105115Parser::ExpressionContext* C2105115Parser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 30, C2105115Parser::RuleExpression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(293);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(285);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->l = logic_expression();

                   antlrcpp::downCast<ExpressionContext *>(_localctx)->text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->l->text;
                   writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->l->start) : nullptr)->getLine()) + ": expression : logic_expression");
                   writeIntoparserLogFile("");
                   writeIntoparserLogFile(_localctx->text);
                   writeIntoparserLogFile("");
               
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(288);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->v = variable();
      setState(289);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->a = match(C2105115Parser::ASSIGNOP);
      setState(290);
      antlrcpp::downCast<ExpressionContext *>(_localctx)->l = logic_expression();

                   antlrcpp::downCast<ExpressionContext *>(_localctx)->text =  antlrcpp::downCast<ExpressionContext *>(_localctx)->v->text + antlrcpp::downCast<ExpressionContext *>(_localctx)->a->getText() + antlrcpp::downCast<ExpressionContext *>(_localctx)->l->text;
                   writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<ExpressionContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<ExpressionContext *>(_localctx)->v->start) : nullptr)->getLine()) + ": expression : variable ASSIGNOP logic_expression");
                   writeIntoparserLogFile("");
                   writeIntoparserLogFile(_localctx->text);
                   writeIntoparserLogFile("");
               
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Logic_expressionContext ------------------------------------------------------------------

C2105115Parser::Logic_expressionContext::Logic_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105115Parser::Rel_expressionContext *> C2105115Parser::Logic_expressionContext::rel_expression() {
  return getRuleContexts<C2105115Parser::Rel_expressionContext>();
}

C2105115Parser::Rel_expressionContext* C2105115Parser::Logic_expressionContext::rel_expression(size_t i) {
  return getRuleContext<C2105115Parser::Rel_expressionContext>(i);
}

tree::TerminalNode* C2105115Parser::Logic_expressionContext::LOGICOP() {
  return getToken(C2105115Parser::LOGICOP, 0);
}


size_t C2105115Parser::Logic_expressionContext::getRuleIndex() const {
  return C2105115Parser::RuleLogic_expression;
}

void C2105115Parser::Logic_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogic_expression(this);
}

void C2105115Parser::Logic_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogic_expression(this);
}

C2105115Parser::Logic_expressionContext* C2105115Parser::logic_expression() {
  Logic_expressionContext *_localctx = _tracker.createInstance<Logic_expressionContext>(_ctx, getState());
  enterRule(_localctx, 32, C2105115Parser::RuleLogic_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(303);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(295);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r = rel_expression();

                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r != nullptr ? (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r->start) : nullptr)->getLine()) + ": logic_expression : rel_expression");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(298);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1 = rel_expression();
      setState(299);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->l = match(C2105115Parser::LOGICOP);
      setState(300);
      antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r2 = rel_expression();

                  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->text + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->l->getText() + antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r2->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1 != nullptr ? (antlrcpp::downCast<Logic_expressionContext *>(_localctx)->r1->start) : nullptr)->getLine()) + ": logic_expression : rel_expression LOGICOP rel_expression");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Rel_expressionContext ------------------------------------------------------------------

C2105115Parser::Rel_expressionContext::Rel_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<C2105115Parser::Simple_expressionContext *> C2105115Parser::Rel_expressionContext::simple_expression() {
  return getRuleContexts<C2105115Parser::Simple_expressionContext>();
}

C2105115Parser::Simple_expressionContext* C2105115Parser::Rel_expressionContext::simple_expression(size_t i) {
  return getRuleContext<C2105115Parser::Simple_expressionContext>(i);
}

tree::TerminalNode* C2105115Parser::Rel_expressionContext::RELOP() {
  return getToken(C2105115Parser::RELOP, 0);
}


size_t C2105115Parser::Rel_expressionContext::getRuleIndex() const {
  return C2105115Parser::RuleRel_expression;
}

void C2105115Parser::Rel_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRel_expression(this);
}

void C2105115Parser::Rel_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRel_expression(this);
}

C2105115Parser::Rel_expressionContext* C2105115Parser::rel_expression() {
  Rel_expressionContext *_localctx = _tracker.createInstance<Rel_expressionContext>(_ctx, getState());
  enterRule(_localctx, 34, C2105115Parser::RuleRel_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(313);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(305);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s = simple_expression(0);

                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s->start) : nullptr)->getLine()) + ": rel_expression : simple_expression");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(308);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s1 = simple_expression(0);
      setState(309);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->r = match(C2105115Parser::RELOP);
      setState(310);
      antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s2 = simple_expression(0);

                  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s1->text + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->r->getText() + antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s2->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s1 != nullptr ? (antlrcpp::downCast<Rel_expressionContext *>(_localctx)->s1->start) : nullptr)->getLine()) + ": rel_expression : simple_expression RELOP simple_expression");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

C2105115Parser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::TermContext* C2105115Parser::Simple_expressionContext::term() {
  return getRuleContext<C2105115Parser::TermContext>(0);
}

C2105115Parser::Simple_expressionContext* C2105115Parser::Simple_expressionContext::simple_expression() {
  return getRuleContext<C2105115Parser::Simple_expressionContext>(0);
}

tree::TerminalNode* C2105115Parser::Simple_expressionContext::ADDOP() {
  return getToken(C2105115Parser::ADDOP, 0);
}


size_t C2105115Parser::Simple_expressionContext::getRuleIndex() const {
  return C2105115Parser::RuleSimple_expression;
}

void C2105115Parser::Simple_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimple_expression(this);
}

void C2105115Parser::Simple_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimple_expression(this);
}


C2105115Parser::Simple_expressionContext* C2105115Parser::simple_expression() {
   return simple_expression(0);
}

C2105115Parser::Simple_expressionContext* C2105115Parser::simple_expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105115Parser::Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, parentState);
  C2105115Parser::Simple_expressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 36;
  enterRecursionRule(_localctx, 36, C2105115Parser::RuleSimple_expression, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(316);
    antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text;
                writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->start) : nullptr)->getLine()) + ": simple_expression : term");
                writeIntoparserLogFile("");
                writeIntoparserLogFile(_localctx->text);
                writeIntoparserLogFile("");
            
    _ctx->stop = _input->LT(-1);
    setState(326);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<Simple_expressionContext>(parentContext, parentState);
        _localctx->s = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleSimple_expression);
        setState(319);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(320);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->a = match(C2105115Parser::ADDOP);
        setState(321);
        antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t = term(0);

                              antlrcpp::downCast<Simple_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->text + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->a->getText() + antlrcpp::downCast<Simple_expressionContext *>(_localctx)->t->text;
                              writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s != nullptr ? (antlrcpp::downCast<Simple_expressionContext *>(_localctx)->s->start) : nullptr)->getLine()) + ": simple_expression : simple_expression ADDOP term");
                              writeIntoparserLogFile("");
                              writeIntoparserLogFile(_localctx->text);
                              writeIntoparserLogFile("");
                           
      }
      setState(328);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

C2105115Parser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::Unary_expressionContext* C2105115Parser::TermContext::unary_expression() {
  return getRuleContext<C2105115Parser::Unary_expressionContext>(0);
}

C2105115Parser::TermContext* C2105115Parser::TermContext::term() {
  return getRuleContext<C2105115Parser::TermContext>(0);
}

tree::TerminalNode* C2105115Parser::TermContext::MULOP() {
  return getToken(C2105115Parser::MULOP, 0);
}


size_t C2105115Parser::TermContext::getRuleIndex() const {
  return C2105115Parser::RuleTerm;
}

void C2105115Parser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void C2105115Parser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


C2105115Parser::TermContext* C2105115Parser::term() {
   return term(0);
}

C2105115Parser::TermContext* C2105115Parser::term(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105115Parser::TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, parentState);
  C2105115Parser::TermContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 38;
  enterRecursionRule(_localctx, 38, C2105115Parser::RuleTerm, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(330);
    antlrcpp::downCast<TermContext *>(_localctx)->u = unary_expression();

                antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->u->text;
                writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<TermContext *>(_localctx)->u != nullptr ? (antlrcpp::downCast<TermContext *>(_localctx)->u->start) : nullptr)->getLine()) + ": term : unary_expression");
                writeIntoparserLogFile("");
                writeIntoparserLogFile(_localctx->text);
                writeIntoparserLogFile("");
            
    _ctx->stop = _input->LT(-1);
    setState(340);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<TermContext>(parentContext, parentState);
        _localctx->t = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleTerm);
        setState(333);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(334);
        antlrcpp::downCast<TermContext *>(_localctx)->m = match(C2105115Parser::MULOP);
        setState(335);
        antlrcpp::downCast<TermContext *>(_localctx)->u = unary_expression();

                              antlrcpp::downCast<TermContext *>(_localctx)->text =  antlrcpp::downCast<TermContext *>(_localctx)->t->text + antlrcpp::downCast<TermContext *>(_localctx)->m->getText() + antlrcpp::downCast<TermContext *>(_localctx)->u->text;
                              writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<TermContext *>(_localctx)->t != nullptr ? (antlrcpp::downCast<TermContext *>(_localctx)->t->start) : nullptr)->getLine()) + ": term : term MULOP unary_expression");
                              writeIntoparserLogFile("");
                              writeIntoparserLogFile(_localctx->text);
                              writeIntoparserLogFile("");
                           
      }
      setState(342);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Unary_expressionContext ------------------------------------------------------------------

C2105115Parser::Unary_expressionContext::Unary_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* C2105115Parser::Unary_expressionContext::ADDOP() {
  return getToken(C2105115Parser::ADDOP, 0);
}

C2105115Parser::Unary_expressionContext* C2105115Parser::Unary_expressionContext::unary_expression() {
  return getRuleContext<C2105115Parser::Unary_expressionContext>(0);
}

tree::TerminalNode* C2105115Parser::Unary_expressionContext::NOT() {
  return getToken(C2105115Parser::NOT, 0);
}

C2105115Parser::FactorContext* C2105115Parser::Unary_expressionContext::factor() {
  return getRuleContext<C2105115Parser::FactorContext>(0);
}


size_t C2105115Parser::Unary_expressionContext::getRuleIndex() const {
  return C2105115Parser::RuleUnary_expression;
}

void C2105115Parser::Unary_expressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_expression(this);
}

void C2105115Parser::Unary_expressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_expression(this);
}

C2105115Parser::Unary_expressionContext* C2105115Parser::unary_expression() {
  Unary_expressionContext *_localctx = _tracker.createInstance<Unary_expressionContext>(_ctx, getState());
  enterRule(_localctx, 40, C2105115Parser::RuleUnary_expression);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(354);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105115Parser::ADDOP: {
        enterOuterAlt(_localctx, 1);
        setState(343);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->a = match(C2105115Parser::ADDOP);
        setState(344);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u = unary_expression();

                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->a->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u->text;
                    writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->a->getLine()) + ": unary_expression : ADDOP unary_expression");
                    writeIntoparserLogFile("");
                    writeIntoparserLogFile(_localctx->text);
                    writeIntoparserLogFile("");
                
        break;
      }

      case C2105115Parser::NOT: {
        enterOuterAlt(_localctx, 2);
        setState(347);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->n = match(C2105115Parser::NOT);
        setState(348);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u = unary_expression();

                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->n->getText() + antlrcpp::downCast<Unary_expressionContext *>(_localctx)->u->text;
                    writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<Unary_expressionContext *>(_localctx)->n->getLine()) + ": unary_expression : NOT unary_expression");
                    writeIntoparserLogFile("");
                    writeIntoparserLogFile(_localctx->text);
                    writeIntoparserLogFile("");
                
        break;
      }

      case C2105115Parser::LPAREN:
      case C2105115Parser::ID:
      case C2105115Parser::CONST_INT:
      case C2105115Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 3);
        setState(351);
        antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f = factor();

                    antlrcpp::downCast<Unary_expressionContext *>(_localctx)->text =  antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->text;
                    writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f != nullptr ? (antlrcpp::downCast<Unary_expressionContext *>(_localctx)->f->start) : nullptr)->getLine()) + ": unary_expression : factor");
                    writeIntoparserLogFile("");
                    writeIntoparserLogFile(_localctx->text);
                    writeIntoparserLogFile("");
                
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

C2105115Parser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::VariableContext* C2105115Parser::FactorContext::variable() {
  return getRuleContext<C2105115Parser::VariableContext>(0);
}

tree::TerminalNode* C2105115Parser::FactorContext::ID() {
  return getToken(C2105115Parser::ID, 0);
}

tree::TerminalNode* C2105115Parser::FactorContext::LPAREN() {
  return getToken(C2105115Parser::LPAREN, 0);
}

C2105115Parser::Argument_listContext* C2105115Parser::FactorContext::argument_list() {
  return getRuleContext<C2105115Parser::Argument_listContext>(0);
}

tree::TerminalNode* C2105115Parser::FactorContext::RPAREN() {
  return getToken(C2105115Parser::RPAREN, 0);
}

C2105115Parser::ExpressionContext* C2105115Parser::FactorContext::expression() {
  return getRuleContext<C2105115Parser::ExpressionContext>(0);
}

tree::TerminalNode* C2105115Parser::FactorContext::CONST_INT() {
  return getToken(C2105115Parser::CONST_INT, 0);
}

tree::TerminalNode* C2105115Parser::FactorContext::CONST_FLOAT() {
  return getToken(C2105115Parser::CONST_FLOAT, 0);
}

tree::TerminalNode* C2105115Parser::FactorContext::INCOP() {
  return getToken(C2105115Parser::INCOP, 0);
}

tree::TerminalNode* C2105115Parser::FactorContext::DECOP() {
  return getToken(C2105115Parser::DECOP, 0);
}


size_t C2105115Parser::FactorContext::getRuleIndex() const {
  return C2105115Parser::RuleFactor;
}

void C2105115Parser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void C2105115Parser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}

C2105115Parser::FactorContext* C2105115Parser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 42, C2105115Parser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(382);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 23, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(356);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();

                  antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text;
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<FactorContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<FactorContext *>(_localctx)->v->start) : nullptr)->getLine()) + ": factor : variable");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(359);
      antlrcpp::downCast<FactorContext *>(_localctx)->id = match(C2105115Parser::ID);
      setState(360);
      antlrcpp::downCast<FactorContext *>(_localctx)->lp = match(C2105115Parser::LPAREN);
      setState(361);
      antlrcpp::downCast<FactorContext *>(_localctx)->a = argument_list();
      setState(362);
      antlrcpp::downCast<FactorContext *>(_localctx)->rp = match(C2105115Parser::RPAREN);

                  antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->id->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->lp->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->a->text + antlrcpp::downCast<FactorContext *>(_localctx)->rp->getText();
                  writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->id->getLine()) + ": factor : ID LPAREN argument_list RPAREN");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(365);
      antlrcpp::downCast<FactorContext *>(_localctx)->lp = match(C2105115Parser::LPAREN);
      setState(366);
      antlrcpp::downCast<FactorContext *>(_localctx)->e = expression();
      setState(367);
      antlrcpp::downCast<FactorContext *>(_localctx)->rp = match(C2105115Parser::RPAREN);

                  antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->lp->getText() + antlrcpp::downCast<FactorContext *>(_localctx)->e->text + antlrcpp::downCast<FactorContext *>(_localctx)->rp->getText();
                  writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->lp->getLine()) + ": factor : LPAREN expression RPAREN");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(370);
      antlrcpp::downCast<FactorContext *>(_localctx)->ci = match(C2105115Parser::CONST_INT);

                  antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->ci->getText();
                  writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->ci->getLine()) + ": factor : CONST_INT");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(372);
      antlrcpp::downCast<FactorContext *>(_localctx)->cf = match(C2105115Parser::CONST_FLOAT);

                  antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->cf->getText();
                  writeIntoparserLogFile(std::string("Line ") + std::to_string(antlrcpp::downCast<FactorContext *>(_localctx)->cf->getLine()) + ": factor : CONST_FLOAT");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(374);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(375);
      antlrcpp::downCast<FactorContext *>(_localctx)->ic = match(C2105115Parser::INCOP);

                  antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text + antlrcpp::downCast<FactorContext *>(_localctx)->ic->getText();
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<FactorContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<FactorContext *>(_localctx)->v->start) : nullptr)->getLine()) + ": factor : variable INCOP");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(378);
      antlrcpp::downCast<FactorContext *>(_localctx)->v = variable();
      setState(379);
      antlrcpp::downCast<FactorContext *>(_localctx)->dc = match(C2105115Parser::DECOP);

                  antlrcpp::downCast<FactorContext *>(_localctx)->text =  antlrcpp::downCast<FactorContext *>(_localctx)->v->text + antlrcpp::downCast<FactorContext *>(_localctx)->dc->getText();
                  writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<FactorContext *>(_localctx)->v != nullptr ? (antlrcpp::downCast<FactorContext *>(_localctx)->v->start) : nullptr)->getLine()) + ": factor : variable DECOP");
                  writeIntoparserLogFile("");
                  writeIntoparserLogFile(_localctx->text);
                  writeIntoparserLogFile("");
              
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Argument_listContext ------------------------------------------------------------------

C2105115Parser::Argument_listContext::Argument_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::ArgumentsContext* C2105115Parser::Argument_listContext::arguments() {
  return getRuleContext<C2105115Parser::ArgumentsContext>(0);
}


size_t C2105115Parser::Argument_listContext::getRuleIndex() const {
  return C2105115Parser::RuleArgument_list;
}

void C2105115Parser::Argument_listContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgument_list(this);
}

void C2105115Parser::Argument_listContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgument_list(this);
}

C2105115Parser::Argument_listContext* C2105115Parser::argument_list() {
  Argument_listContext *_localctx = _tracker.createInstance<Argument_listContext>(_ctx, getState());
  enterRule(_localctx, 44, C2105115Parser::RuleArgument_list);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(388);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case C2105115Parser::LPAREN:
      case C2105115Parser::ADDOP:
      case C2105115Parser::NOT:
      case C2105115Parser::ID:
      case C2105115Parser::CONST_INT:
      case C2105115Parser::CONST_FLOAT: {
        enterOuterAlt(_localctx, 1);
        setState(384);
        antlrcpp::downCast<Argument_listContext *>(_localctx)->a = arguments(0);

                    antlrcpp::downCast<Argument_listContext *>(_localctx)->text =  antlrcpp::downCast<Argument_listContext *>(_localctx)->a->text;
                    writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<Argument_listContext *>(_localctx)->a != nullptr ? (antlrcpp::downCast<Argument_listContext *>(_localctx)->a->start) : nullptr)->getLine()) + ": argument_list : arguments");
                    writeIntoparserLogFile("");
                    writeIntoparserLogFile(_localctx->text);
                    writeIntoparserLogFile("");
                
        break;
      }

      case C2105115Parser::RPAREN: {
        enterOuterAlt(_localctx, 2);

                    antlrcpp::downCast<Argument_listContext *>(_localctx)->text =  "";
                
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

C2105115Parser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

C2105115Parser::Logic_expressionContext* C2105115Parser::ArgumentsContext::logic_expression() {
  return getRuleContext<C2105115Parser::Logic_expressionContext>(0);
}

C2105115Parser::ArgumentsContext* C2105115Parser::ArgumentsContext::arguments() {
  return getRuleContext<C2105115Parser::ArgumentsContext>(0);
}

tree::TerminalNode* C2105115Parser::ArgumentsContext::COMMA() {
  return getToken(C2105115Parser::COMMA, 0);
}


size_t C2105115Parser::ArgumentsContext::getRuleIndex() const {
  return C2105115Parser::RuleArguments;
}

void C2105115Parser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void C2105115Parser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<C2105115ParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}


C2105115Parser::ArgumentsContext* C2105115Parser::arguments() {
   return arguments(0);
}

C2105115Parser::ArgumentsContext* C2105115Parser::arguments(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  C2105115Parser::ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, parentState);
  C2105115Parser::ArgumentsContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, C2105115Parser::RuleArguments, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(391);
    antlrcpp::downCast<ArgumentsContext *>(_localctx)->l = logic_expression();

                antlrcpp::downCast<ArgumentsContext *>(_localctx)->text =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->text;
                writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->l != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->start) : nullptr)->getLine()) + ": arguments : logic_expression");
                writeIntoparserLogFile("");
                writeIntoparserLogFile(_localctx->text);
                writeIntoparserLogFile("");
            
    _ctx->stop = _input->LT(-1);
    setState(401);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<ArgumentsContext>(parentContext, parentState);
        _localctx->a = previousContext;
        pushNewRecursionContext(_localctx, startState, RuleArguments);
        setState(394);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(395);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->c = match(C2105115Parser::COMMA);
        setState(396);
        antlrcpp::downCast<ArgumentsContext *>(_localctx)->l = logic_expression();

                              antlrcpp::downCast<ArgumentsContext *>(_localctx)->text =  antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->text + antlrcpp::downCast<ArgumentsContext *>(_localctx)->c->getText() + antlrcpp::downCast<ArgumentsContext *>(_localctx)->l->text;
                              writeIntoparserLogFile(std::string("Line ") + std::to_string((antlrcpp::downCast<ArgumentsContext *>(_localctx)->a != nullptr ? (antlrcpp::downCast<ArgumentsContext *>(_localctx)->a->start) : nullptr)->getLine()) + ": arguments : arguments COMMA logic_expression");
                              writeIntoparserLogFile("");
                              writeIntoparserLogFile(_localctx->text);
                              writeIntoparserLogFile("");
                           
      }
      setState(403);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool C2105115Parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return programSempred(antlrcpp::downCast<ProgramContext *>(context), predicateIndex);
    case 5: return parameter_listSempred(antlrcpp::downCast<Parameter_listContext *>(context), predicateIndex);
    case 10: return declaration_listSempred(antlrcpp::downCast<Declaration_listContext *>(context), predicateIndex);
    case 11: return statementsSempred(antlrcpp::downCast<StatementsContext *>(context), predicateIndex);
    case 18: return simple_expressionSempred(antlrcpp::downCast<Simple_expressionContext *>(context), predicateIndex);
    case 19: return termSempred(antlrcpp::downCast<TermContext *>(context), predicateIndex);
    case 23: return argumentsSempred(antlrcpp::downCast<ArgumentsContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool C2105115Parser::programSempred(ProgramContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

bool C2105115Parser::parameter_listSempred(Parameter_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool C2105115Parser::declaration_listSempred(Declaration_listContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 3: return precpred(_ctx, 4);
    case 4: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool C2105115Parser::statementsSempred(StatementsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105115Parser::simple_expressionSempred(Simple_expressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 6: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105115Parser::termSempred(TermContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 7: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool C2105115Parser::argumentsSempred(ArgumentsContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 8: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void C2105115Parser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  c2105115parserParserInitialize();
#else
  ::antlr4::internal::call_once(c2105115parserParserOnceFlag, c2105115parserParserInitialize);
#endif
}
