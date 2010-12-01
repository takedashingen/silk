#pragma once

#include "silkParserDirect.h"
#include "silkParserAST.h"

#include <stddef.h>

typedef enum SilkTokenType {
	SILK_TOK_INT = INT,

	SILK_TOK_PLUS = PLUS,
	SILK_TOK_MINUS = MINUS,
	SILK_TOK_MULTIPLY = MULTIPLY,
	SILK_TOK_DIVIDE = DIVIDE,
} SilkTokenType;

typedef struct SilkToken {
	SilkTokenType type;

	int val;
} SilkToken;

void parseTest(void* parser);
void lexAndParseTest(void* parser, char* str);
