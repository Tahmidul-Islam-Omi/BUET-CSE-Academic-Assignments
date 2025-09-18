java -jar /usr/local/lib/antlr-4.13.2-complete.jar -Dlanguage=Cpp C2105115Lexer.g4
java -jar /usr/local/lib/antlr-4.13.2-complete.jar -Dlanguage=Cpp C2105115Parser.g4
g++ -std=c++17 -w -I/usr/local/include/antlr4-runtime -c C2105115Lexer.cpp C2105115Parser.cpp Ctester.cpp SymbolInfo.cpp ScopeTable.cpp SymbolTable.cpp
g++ -std=c++17 -w -no-pie C2105115Lexer.o C2105115Parser.o Ctester.o SymbolInfo.o ScopeTable.o SymbolTable.o -L/usr/local/lib/ -lantlr4-runtime -o Ctester.out -pthread
LD_LIBRARY_PATH=/usr/local/lib ./Ctester.out $1