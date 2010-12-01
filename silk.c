#include <stdlib.h>
#include <stdio.h>

#include "silkParser.h"
#include "silkLexer.h"

int main(int argc, char* argv[])
{
	void* parser = silkParserAlloc(malloc);
	char buf[128];

	while(fgets(buf, 128, stdin))
	{
		lexAndParseTest(parser, buf);
		silkParse(parser, 0, 0);
	}

	//lexAndParseTest(parser);

	//Parse(parser, 0, 0);
	silkParserFree(parser, free);
	
	printf("finished\n");
	return 0;
}
