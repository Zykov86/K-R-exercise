/*
File: solution.c

Author: Sergey Zykov
Date: Aug 15, 2016
 */

#include <stdio.h>

int main()
{

	float celsius , fahr;
	printf("\n");
	for (fahr = 300 ; fahr >= 0 ; fahr = fahr - 20) {
		celsius = 5.0 * (fahr - 32 ) / 9;
		printf("%5.0f \t %10.1f \n " , fahr , celsius );
	}
	return 0;
}
