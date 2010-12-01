frkz: silk.c silkParserDirect.c silkParserAST.c silkLexer.c silkLexer.h silkParser.h
	clear
	gcc -g -Wall silkParserAST.c silkParserDirect.c silkLexer.c silk.c -o silk

silkParserDirect.c: silkParserDirect.y
	lemon -q silkParserDirect.y

silkParserAST.c: silkParserAST.y
	lemon -q silkParserAST.y

silkLexer.c: silkLexer.re
	re2c -o silkLexer.c silkLexer.re

clean:
	rm silk silkLexer.c silkParserDirect.c silkParserDirect.h silkParserAST.c silkParserAST.h
