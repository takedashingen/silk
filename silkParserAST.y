%name silkParserAST

%token_type {SilkToken*}
%type op {SilkASTNode*}
%token_destructor { free($$); }

%left PLUS MINUS.
%left DIVIDE MULTIPLY.


%include {
	#include "silkLexer.h"
	#include "silkParser.h"

    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
}

%syntax_error {
  printf("Syntax error!\n");
}

program ::= op(A).   { printf("Result=%d\n", A->val); }

op(A) ::= op(B) MINUS  op(C).
    {
    	A = malloc(sizeof(*A));
    	A->type = SILK_AST_MINUS;
    	A->lhs = B;
    	A->rhs = C;
    }
op(A) ::= op(B) PLUS  op(C).
    {
    	A = malloc(sizeof(*A));
    	A->type = SILK_AST_PLUS;
    	A->lhs = B;
    	A->rhs = C;
    	printf("%p:%d = %p:%d + %p:%d\n", A, A->val, B, B->val, C, C->val);
    }
op(A) ::= op(B) MULTIPLY  op(C).
    {
    	A = malloc(sizeof(*A));
    	A->type = SILK_AST_MULTIPLY;
    	A->lhs = B;
    	A->rhs = C;
	}
op(A) ::= op(B) DIVIDE op(C).
    {
    	A = malloc(sizeof(*A));
    	A->type = SILK_AST_DIVIDE;
    	A->lhs = B;
    	A->rhs = C;
    }

op(A) ::= INT(B).
    {
    	A = malloc(sizeof(*A));
    	A->type = SILK_AST_INT;
        A->val = B->val;
        printf("%p:%d = %p:%d\n", A, A->val, B, B->val);
    }
