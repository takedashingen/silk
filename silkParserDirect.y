%name silkParserDirect

%token_type {SilkToken*}
%token_destructor { free($$); }

%left PLUS MINUS.
%left DIVIDE MULTIPLY.

%include {
	#include "silkLexer.h"

    #include <stdio.h>
    #include <stdlib.h>
    #include <assert.h>
}

%syntax_error {
  printf("Syntax error!\n");
}

program ::= expr(A).   { printf("Result=%d\n", A->val); }

expr(A) ::= expr(B) MINUS  expr(C).
    {
    	A = malloc(sizeof(*A));
    	A->val = B->val - C->val;
    }
expr(A) ::= expr(B) PLUS  expr(C).
    {
    	A = malloc(sizeof(*A));
    	A->val = B->val + C->val;
    	printf("%p:%d = %p:%d + %p:%d\n", A, A->val, B, B->val, C, C->val);
    }
expr(A) ::= expr(B) MULTIPLY  expr(C).
    {
    	A = malloc(sizeof(*A));
		A->val = B->val * C->val;
	}
expr(A) ::= expr(B) DIVIDE expr(C).
    {
    	A = malloc(sizeof(*A));
        if(C->val != 0)
            A->val = B->val / C->val;
        else
            printf("divide by zero\n");
    }

expr(A) ::= INT(B).
    {
    	A = malloc(sizeof(*A));
        A->val = B->val;
        printf("%p:%d = %p:%d\n", A, A->val, B, B->val);
    }
