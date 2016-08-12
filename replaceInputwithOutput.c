#include <stdio.h>

main()
{
	int c;
	while ( ( c = getchar() ) != EOF ) {
		if (c == '\t')
			printf("\\t");
		if (c == '\\')
			printf("\\");
		if (c == '\b')
			printf("\\b");
		if (c != '\t' && c != '\\' && c != '\b')
			putchar(c);
	}		
}