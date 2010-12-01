#include "silkLexer.h"
#include "silkParser.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEBUG_PRINT(x, ...) printf(x, __VA_ARGS__);

void parseTest(void* parser)
{
	SilkToken* node = malloc(sizeof(*node));

	node->type = INT;
	node->val = 5;
	silkParserDirect(parser, node->type, node); 

	node = malloc(sizeof(*node));
	node->type = PLUS;
	node->val = 0;
	silkParse(parser, node->type, node); 

	node = malloc(sizeof(*node));
	node->type = PLUS;
	node->val = 7;
	silkParse(parser, node->type, node); 
}

void acceptToken(void* parser, SilkTokenType type)
{
 	SilkToken* node = malloc(sizeof(*node));
 	
 	node->type = type;
 	node->val = 0;
 	silkParse(parser, node->type, node);
}

void lexAndParseTest(void* parser, char* str)
{
	char* cursor = str;
	char* token;
	//char* marker = 0;
#define YYCTYPE         char
#define YYCURSOR        cursor
#define YYLIMIT         (str+strlen(str)+1)
#define YYMARKER        marker
#define YYFILL(n)		{ printf("OOD\n"); break; }

	while(1)
	{
		token = cursor;
/*!re2c
 	re2c:indent:top = 2;

 	[0-9]*	{
		SilkToken* node = malloc(sizeof(*node));
 		node->type = INT;
 		node->val = atoi(token);
 		DEBUG_PRINT("%d\n", node->val);
 		silkParse(parser, node->type, node);
 		continue;
	}
 	"*"		{ acceptToken(parser, MULTIPLY); continue; }
 	"/"		{ acceptToken(parser, DIVIDE); continue; }
 	"+"		{ acceptToken(parser, PLUS); continue; }
 	"-"		{ acceptToken(parser, MINUS); continue; }
 	"\000"	{ printf("testing\n"); break; }
 	"\n"	{ printf("nl\n"); break; }
 	[^]		{ printf("syntax error\n"); break; }
*/
	}
}

