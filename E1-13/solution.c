/*
File: solution.c

Author: Sergey Zykov
Date: Aug 15, 2016
 */

#include <stdio.h>

#define MAXCAT 20
#define IN 1
#define OUT 0

void stringConstr(int seq[]);

/*print histogram of words' length */
int main(void){
	/*initialize variables*/
	int c , status , charCount , i , j , max;
	int keeper[MAXCAT];
	int seq[MAXCAT];
	status = OUT;
	charCount = 0;
	for (i = 0 ; i < MAXCAT ; ++i)
		keeper[i] = 0;
	/*store number of words of different length in keeper*/
	while ( ( c = getchar() )!= EOF){
		if ((c == '\n' || c == '\t' || c == ' ') && status != OUT ) {
			status = OUT;
			if (charCount <= MAXCAT) {
				++keeper[charCount-1];
			}
			else
				++keeper[MAXCAT-1];
			charCount = 0;
		}
		else if ( (c == '\n' || c == '\t' || c == ' ') && status == OUT ) {
			;
		}
		else {
			status = IN;
			++charCount;
		}
	}
	/* print output vertically  */
	for (i = 0 ; i < MAXCAT ; ++i) {
		printf("%d\t",i+1);
		for (j = 1 ; j <= keeper[i] ; ++j)
			printf("o");
		printf("\n");
	}
	for ( i = 0 ; i < 3*MAXCAT ; ++i)
		printf("-");
	printf("\n");
	/*print output horizontally */
	/*find the height of the histogram*/
	max = 0;
	for (i = 0 ; i < MAXCAT ; ++i) {
		if (max < keeper[i])
			max = keeper[i];
	}
	/*print the histogram */
	for (i = max ; i >=1 ; --i){ /* i is the layer of the histogram */
		for (j = 0 ; j < MAXCAT ; ++j){
			if (keeper[j] >= i)
				seq[j] = 1;
			else
				seq[j] = 0;
		}
		stringConstr(seq);
	}
	printf("\n\n\n");
	for (i = 0 ; i < MAXCAT ; ++i)
		if (i+1 < 10)
			printf("%d  ",i+1);
		else
			printf("%d ",i+1);
	return 0;
}

void stringConstr(int seq[]) {
	/* print a line illustrating seq, where 'o' represents 1 and ' ' represents 0 */
	char str[MAXCAT];
	int i;
	for (i = 0; i < MAXCAT; ++i)
		if (seq[i] == 1)
			str[i] = 'o';
		else
			str[i] = ' ';
	for (i = 0; i < MAXCAT; ++i)
		printf("%c  ",str[i]);
	printf("\n");
}
