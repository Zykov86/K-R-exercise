#include <stdio.h>

#define MAXCAT 20
#define IN 1
#define OUT 0

/*print histogram of worlds' length */
int main(){
    /*initialize variables*/
    int c , status , charCount , i , j;
    int keeper[MAXCAT];
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
    /* print output */
    for (i = 0 ; i < MAXCAT ; ++i) {
        for (j = 1 ; j <= keeper[i] ; ++j)
            printf("\\");
        printf("\n");
    }
    return 0;
}