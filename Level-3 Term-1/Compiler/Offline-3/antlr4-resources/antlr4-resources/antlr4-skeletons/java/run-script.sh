java -Xmx500M -cp "/usr/local/lib/antlr-4.13.2-complete.jar:$CLASSPATH" org.antlr.v4.Tool C2105115Lexer.g4 C2105115Parser.g4
javac -cp .:/usr/local/lib/antlr-4.13.2-complete.jar  C2105115*.java Main.java
java -cp .:/usr/local/lib/antlr-4.13.2-complete.jar Main $1