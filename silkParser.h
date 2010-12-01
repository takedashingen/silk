#include "silkLexer.h"

#define PARSE_AST

#ifdef PARSE_DIRECT
#define silkParse silkParserDirect
#define silkParserAlloc silkParserDirectAlloc
#define silkParserFree silkParserDirectFree
#endif

#ifdef PARSE_AST
#define silkParse silkParserAST
#define silkParserAlloc silkParserASTAlloc
#define silkParserFree silkParserASTFree
#endif

void silkParserDirect(void* parser, int yymajor, SilkToken* node);

void* silkParserDirectAlloc(void *(*mallocProc)(size_t));
void silkParserDirectFree(void *p, void (*freeProc)(void*));

void silkParserAST(void* parser, int yymajor, SilkToken* node);

void* silkParserASTAlloc(void *(*mallocProc)(size_t));
void silkParserASTFree(void *p, void (*freeProc)(void*));

typedef enum SilkASTNodeType {
	SILK_AST_INT,

	SILK_AST_PLUS,
	SILK_AST_MINUS,
	SILK_AST_MULTIPLY,
	SILK_AST_DIVIDE,
} SilkASTNodeType;

typedef struct SilkASTNode {
	SilkASTNodeType type;
	struct SilkASTNode* lhs;
	struct SilkASTNode* rhs;

	int val;
} SilkASTNode;
