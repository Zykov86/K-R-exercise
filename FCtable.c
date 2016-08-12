#include <stdio.h>

main() /* doing some stuff */
{
	
	float celsius , fahr;

	for (fahr = 0 ; fahr <= 300 ; fahr = fahr + 20) {
		celsius = 5.0 * (fahr - 32 ) / 9;
		printf("%7.0f \t %7.1f \n " , fahr , celsius );
	}
}