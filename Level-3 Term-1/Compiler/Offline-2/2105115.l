%option noyywrap

%{
    
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "2105115_SymbolTable.h"

using namespace std;
    
int line_count = 1;
int error_count = 0;

// Create a symbol table with 7 buckets
SymbolTable symbolTable(7);

// File pointers for output
FILE *logout;
FILE *tokenout;

%}

KEYWORD     "if"|"for"|"do"|"int"|"float"|"void"|"switch"|"default"|"else"|"while"|"break"|"char"|"double"|"return"|"case"|"continue"|"goto"|"long"|"short"|"static"|"unsigned"
ADDOP		"+"|"-"
MULOP       "*"|"/"|"%"
INCOP       "++"|"--"
RELOP       "<"|"<="|">"|">="|"=="|"!="
ASSIGNOP    "="
LOGICOP     "&&"|"||"
NOT         "!"
LPAREN      "("
RPAREN      ")"
LCURL       "{"
RCURL       "}"
LTHIRD      "["
RTHIRD      "]"
COMMA       ","
SEMICOLON   ";"


/* This pattern matches whitespace characters:
   - Space character ' '
   - Tab character '\t'
   - Form feed '\f'
   - Carriage return '\r'
   - Vertical tab '\v'
   When matched, these characters are ignored by the lexical analyzer
*/
WHITESPACE [ \t\f\r\v]+ 
BLANKLINE ^[ \t]*[\r]?\n
NEWLINE \r?\n
LETTER [a-zA-Z]
DIGIT [0-9]

/* doesn't include the trailing newline */
SINGLE_LINE_COMMENT_NO_NL "//"([^\n\\]|(\\[\n][ \t]*[^\n]))*

/* explicitly includes the trailing newline */
SINGLE_LINE_COMMENT {SINGLE_LINE_COMMENT_NO_NL}\n?

MULTI_LINE_COMMENT "/*"([^*]|\*+[^*/])*\*+"/"

/* Constants */
CONST_INT {DIGIT}+

/* Constants */

/* CONST_FLOAT pattern explanation:
   {DIGIT}+ : One or more digits for the integer part (mandatory)
   (\.{DIGIT}+)? : Optional decimal part:
      \. : A literal decimal point
      {DIGIT}+ : One or more digits after the decimal
      ? : Makes the entire decimal part optional
   ([Ee][+-]?{DIGIT}+)? : Optional exponential part:
      [Ee] : Either 'E' or 'e' for scientific notation
      [+-]? : Optional plus or minus sign
      {DIGIT}+ : One or more digits for the exponent
      ? : Makes the entire exponential part optional
   Examples: 123, 123.456, 1E10, 1.23E-4, 0.123E+5
*/
CONST_FLOAT {DIGIT}+(\.{DIGIT}+)?([Ee][+-]?{DIGIT}+)?

/* CONST_CHAR pattern explanation:
   ' : Opening single quote
   ( : Start of character alternatives group
      [^'\\\n] : Any single character EXCEPT:
         ' : single quote (would end the char constant)
         \ : backslash (used for escape sequences)
         \n : newline (invalid in char constant)
      | : OR
      \\['"?\\abfnrtv] : Escape sequences:
         \\ : Matches a literal backslash
         ['"?\\abfnrtv] : One of these characters after backslash:
            ' : single quote
            " : double quote
            ? : question mark
            \\ : backslash
            a : alert (bell)
            b : backspace
            f : form feed
            n : newline
            r : carriage return
            t : tab
            v : vertical tab
   ) : End of character alternatives group
   ' : Closing single quote
   Examples: 'a', '\n', '\t', '\'', '\\', '\a'
*/
CONST_CHAR '([^'\\\n]|\\['"?\\abfnrtv])'

/* String pattern:
   " : Opening double quote
   ( : Start of content group
     [^"\\\n] : Any character except double quote, backslash, or newline
     | : OR
     \\['"?\\abfnrtv] : Escape sequences (same as for char constants)
     | : OR
     \\\n[ \t]* : Line continuation (backslash followed by newline, followed by optional whitespace)
   )* : Zero or more of the content group
   " : Closing double quote
   Examples: "hello", "escape \"quotes\"", "special chars: \n\t", "multi-line\
   string"
*/
STRING \"([^"\\\n]|\\['"?\\abfnrtv]|\\\n[ \t]*)*\"

/* Identifiers */
/* Matches identifiers: starts with letter/underscore, followed by letters/digits/underscores
   Examples: variable, count_1, _temp, MyVariable */
ID [a-zA-Z_][a-zA-Z0-9_]*

/* Error patterns */
TOO_MANY_DECIMAL {DIGIT}+(\.{DIGIT}+)(\.{DIGIT}+)+
ILL_FORMED_NUMBER {DIGIT}+\.([Ee][+-]?{DIGIT}+)?|{DIGIT}+[Ee][+-]?|{DIGIT}+[Ee][+-]?{DIGIT}+\.{DIGIT}+
INVALID_SUFFIX {DIGIT}+{ID}
EMPTY_CHAR_CONST ''
MULTI_CHAR_CONST '([^'\\\n]|\\['"?\\abfnrtv]){2,}'
UNFINISHED_CHAR '([^'\\\n]|\\['"?\\abfnrtv])?
UNFINISHED_STRING \"([^"\\\n]|\\['"?\\abfnrtv]|\\\n[ \t]*)*\n
UNFINISHED_COMMENT "/*"([^*]|\*+[^*/])*

%%

{BLANKLINE} {
    line_count++; // Explicitly increment line count for blank lines
}

{WHITESPACE} { /* ignore whitespace */ }

{NEWLINE} { 
    line_count++; 
}

{SINGLE_LINE_COMMENT} {
    // Get the initial line count before processing
    int starting_line = line_count;
    
    // Count newlines in the comment text
    for(int i = 0; i < strlen(yytext); i++) {
        if(yytext[i] == '\n') {
            line_count++;
        }
    }
    
    // Remove the trailing newline for output if it exists
    char *comment = strdup(yytext);
    int len = strlen(comment);
    if(len > 0 && comment[len-1] == '\n') {
        comment[len-1] = '\0';
    }
    
    fprintf(logout, "Line no %d: Token <COMMENT> Lexeme %s found\n\n", starting_line, comment);
    free(comment);
}

{MULTI_LINE_COMMENT} {
    // Get the initial line count before processing
    int starting_line = line_count;
    
    /* Count newlines in multi-line comment */
    for(int i = 0; i < strlen(yytext); i++) {
        if(yytext[i] == '\n') {
            line_count++;
        }
    }
    
    fprintf(logout, "Line no %d: Token <COMMENT> Lexeme %s found\n\n", starting_line, yytext);
}

{KEYWORD} {
    // Convert keyword to uppercase for output
    char keyword_upper[100];
    strcpy(keyword_upper, yytext);
    for(int i = 0; i < strlen(keyword_upper); i++) {
        keyword_upper[i] = toupper(keyword_upper[i]);
    }
    fprintf(tokenout, "<%s> ", keyword_upper);
    fprintf(logout, "Line no %d: Token <%s> Lexeme %s found\n\n", line_count, keyword_upper, yytext);
}

{CONST_INT} {
    fprintf(tokenout, "<CONST_INT, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <CONST_INT> Lexeme %s found\n\n", line_count, yytext);
    
    bool inserted = symbolTable.insert(yytext, "CONST_INT", logout);
    
    // Only print the scope tables if insertion was successful
    if (inserted) {
        symbolTable.printAllScopeTables(logout);
        fprintf(logout, "\n");
    }
}

{CONST_FLOAT} {
    fprintf(tokenout, "<CONST_FLOAT, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <CONST_FLOAT> Lexeme %s found\n\n", line_count, yytext);
    
    // Insert CONST_FLOAT into symbol table, passing logout for error messages
    bool inserted = symbolTable.insert(yytext, "CONST_FLOAT", logout);
    
    // Only print the scope tables if insertion was successful
    if (inserted) {
        symbolTable.printAllScopeTables(logout);
        fprintf(logout, "\n");
    }
}

{CONST_CHAR} {
    char actual_char;
    
    // Remove the surrounding quotes and handle escape sequences
    if(yytext[1] == '\\') {
        switch(yytext[2]) {
            case 'n': actual_char = '\n'; break;
            case 't': actual_char = '\t'; break;
            case '\\': actual_char = '\\'; break;
            case '\'': actual_char = '\''; break;
            case 'a': actual_char = '\a'; break;
            case 'f': actual_char = '\f'; break;
            case 'r': actual_char = '\r'; break;
            case 'b': actual_char = '\b'; break;
            case 'v': actual_char = '\v'; break;
            case '0': actual_char = '\0'; break;
            default: actual_char = yytext[2];
        }
    } else {
        actual_char = yytext[1];
    }
    
    fprintf(tokenout, "<CONST_CHAR, %c> ", actual_char);
    fprintf(logout, "Line no %d: Token <CONST_CHAR> Lexeme %s found --> <CONST_CHAR, %c>\n\n", line_count, yytext, actual_char);
    
    // Insert CONST_CHAR into symbol table, passing logout for error messages
    bool inserted = symbolTable.insert(yytext, "CONST_CHAR", logout);
    
    // Only print the scope tables if insertion was successful
    if (inserted) {
        symbolTable.printAllScopeTables(logout);
        fprintf(logout, "\n");
    }
}

{STRING} {
    // Process the string to handle escape sequences
    char processedString[1000];
    int j = 0;
    
    // Store current line count before processing
    int starting_line = line_count;
    
    // Count newlines in string for line counting
    for(int i = 0; i < strlen(yytext); i++) {
        if(yytext[i] == '\n') line_count++;
    }
    
    // Skip the opening quote
    for(int i = 1; i < strlen(yytext) - 1; i++) {
        if(yytext[i] == '\\' && i+1 < strlen(yytext) - 1) {
            // Handle escape sequences
            i++;
            switch(yytext[i]) {
                case 'n': processedString[j++] = '\n'; break;
                case 't': processedString[j++] = '\t'; break;
                case '\\': processedString[j++] = '\\'; break;
                case '\"': processedString[j++] = '\"'; break;
                case '\'': processedString[j++] = '\''; break;
                case 'a': processedString[j++] = '\a'; break;
                case 'f': processedString[j++] = '\f'; break;
                case 'r': processedString[j++] = '\r'; break;
                case 'b': processedString[j++] = '\b'; break;
                case 'v': processedString[j++] = '\v'; break;
                case '0': processedString[j++] = '\0'; break;
                case '\n': 
                    // Line continuation - add 4 spaces as in expected output
                    processedString[j++] = ' ';
                    processedString[j++] = ' ';
                    processedString[j++] = ' ';
                    processedString[j++] = ' ';
                    // Skip whitespace at beginning of next line
                    while(i+1 < strlen(yytext) - 1 && (yytext[i+1] == ' ' || yytext[i+1] == '\t')) {
                        i++;
                    }
                    break;
                default: processedString[j++] = yytext[i];
            }
        } else if(yytext[i] == '\\' && yytext[i+1] == '\n') {
            // Skip line continuation
            i++;
            // Add 4 spaces as in expected output
            processedString[j++] = ' ';
            processedString[j++] = ' ';
            processedString[j++] = ' ';
            processedString[j++] = ' '; 
            // Skip any whitespace at the beginning of the next line
            while(i+1 < strlen(yytext) - 1 && (yytext[i+1] == ' ' || yytext[i+1] == '\t')) {
                i++;
            }
        } else {
            processedString[j++] = yytext[i];
        }
    }
    processedString[j] = '\0';
    
    // Output to token file
    fprintf(tokenout, "<STRING, %s> ", processedString);
    fprintf(logout, "Line no %d: Token <STRING> Lexeme %s found --> <STRING, %s>\n\n", starting_line, yytext, processedString);
}

{ID} {
    fprintf(tokenout, "<ID, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <ID> Lexeme %s found\n\n", line_count, yytext);
    
    // Insert ID into symbol table, passing logout for error messages
    bool inserted = symbolTable.insert(yytext, "ID", logout);
    
    // Only print the scope tables if insertion was successful
    if (inserted) {
        symbolTable.printAllScopeTables(logout);
        fprintf(logout, "\n");
    }
}

{ADDOP} {
    fprintf(tokenout, "<ADDOP, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <ADDOP> Lexeme %s found\n\n", line_count, yytext);
}

{MULOP} {
    fprintf(tokenout, "<MULOP, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <MULOP> Lexeme %s found\n\n", line_count, yytext);
}

{INCOP} {
    fprintf(tokenout, "<INCOP, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <INCOP> Lexeme %s found\n\n", line_count, yytext);
}

{RELOP} {
    fprintf(tokenout, "<RELOP, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <RELOP> Lexeme %s found\n\n", line_count, yytext);
}

{ASSIGNOP} {
    fprintf(tokenout, "<ASSIGNOP, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <ASSIGNOP> Lexeme %s found\n\n", line_count, yytext);
}

{LOGICOP} {
    fprintf(tokenout, "<LOGICOP, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <LOGICOP> Lexeme %s found\n\n", line_count, yytext);
}

{NOT} {
    fprintf(tokenout, "<NOT, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <NOT> Lexeme %s found\n\n", line_count, yytext);
}

{LPAREN} {
    fprintf(tokenout, "<LPAREN, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <LPAREN> Lexeme %s found\n\n", line_count, yytext);
}

{RPAREN} {
    fprintf(tokenout, "<RPAREN, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <RPAREN> Lexeme %s found\n\n", line_count, yytext);
}

{LCURL} {
    fprintf(tokenout, "<LCURL, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <LCURL> Lexeme %s found\n\n", line_count, yytext);
    symbolTable.enterScope(); // Enter a new scope when encountering a left curly brace
}

{RCURL} {
    fprintf(tokenout, "<RCURL, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <RCURL> Lexeme %s found\n\n", line_count, yytext);
    symbolTable.exitScope(); // Exit the current scope when encountering a right curly brace
}

{LTHIRD} {
    fprintf(tokenout, "<LTHIRD, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <LTHIRD> Lexeme %s found\n\n", line_count, yytext);
}

{RTHIRD} {
    fprintf(tokenout, "<RTHIRD, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <RTHIRD> Lexeme %s found\n\n", line_count, yytext);
}

{COMMA} {
    fprintf(tokenout, "<COMMA, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <COMMA> Lexeme %s found\n\n", line_count, yytext);
}

{SEMICOLON} {
    fprintf(tokenout, "<SEMICOLON, %s> ", yytext);
    fprintf(logout, "Line no %d: Token <SEMICOLON> Lexeme %s found\n\n", line_count, yytext);
}

{TOO_MANY_DECIMAL} {
    fprintf(logout, "Error at line no %d: Too many decimal points %s\n\n\n", line_count, yytext);
    error_count++;
}

{ILL_FORMED_NUMBER} {
    fprintf(logout, "Error at line no %d: Ill formed number %s\n\n\n", line_count, yytext);
    error_count++;
}

{INVALID_SUFFIX} {
    fprintf(logout, "Error at line no %d: Invalid prefix on ID or invalid suffix on Number %s\n\n", line_count, yytext);
    error_count++;
}

{EMPTY_CHAR_CONST} {
    fprintf(logout, "Error at line no %d: Empty character constant error %s\n\n\n", line_count, yytext);
    error_count++;
}

{MULTI_CHAR_CONST} {
    fprintf(logout, "Error at line no %d: Multi character constant error %s\n\n\n", line_count, yytext);
    error_count++;
}

{UNFINISHED_CHAR} {
    fprintf(logout, "Error at line no %d: Unterminated character %s\n\n\n", line_count, yytext);
    error_count++;
}

{UNFINISHED_STRING} {
    // Store starting line
    int starting_line = line_count;
    
    // Count newlines in the unfinished string
    for(int i = 0; i < strlen(yytext); i++) {
        if(yytext[i] == '\n') line_count++;
    }
    fprintf(logout, "Error at line no %d: Unterminated string %s\n", starting_line, yytext);
    error_count++;
}

{UNFINISHED_COMMENT} {
    // Store starting line
    int starting_line = line_count;
    
    // Count newlines in the unfinished comment
    for(int i = 0; i < strlen(yytext); i++) {
        if(yytext[i] == '\n') line_count++;
    }
    fprintf(logout, "Error at line no %d: Unterminated comment %s\n\n", starting_line, yytext);
    error_count++;
}

. {
    fprintf(logout, "Error at line no %d: Unrecognized character %s\n\n", line_count, yytext);
    error_count++;
}

%%

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Please provide input file name and try again\n");
        return 0;
    }
    
    FILE *fin = fopen(argv[1], "r");
    if(fin == NULL) {
        printf("Cannot open specified file\n");
        return 0;
    }
    
    logout = fopen("log.txt", "w");
    tokenout = fopen("token.txt", "w");
    
    yyin = fin;
    yylex();
    
    // Print all scope tables before the summary
    symbolTable.printAllScopeTables(logout);
    
    fprintf(logout, "\nTotal lines: %d\n", line_count);
    fprintf(logout, "Total errors: %d\n", error_count);
    
    fclose(yyin);
    fclose(tokenout);
    fclose(logout);
    return 0;
}
