#include <stdio.h>


#define IN  1
#define OUT 0

main()
{	
	int c , state;
	state = IN;
	while ( (c = getchar() ) != EOF) {
	if ( c == '\t' || c == '\n' || c == ' ')
		if (state == IN)
		;
		else {
			putchar('\n');
			state = IN;
		}
	else {
		putchar(c);
		state = OUT; 
		}
	}
}