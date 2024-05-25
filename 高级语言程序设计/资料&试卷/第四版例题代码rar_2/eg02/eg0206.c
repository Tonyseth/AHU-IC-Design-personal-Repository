// Program: EG0206.C 
// Description: Convert Fahrenheit to Celsius
#include <stdio.h>

void main (void)
{
	int temperature;
	//float temperature;

	printf("Please input Fahrenheit temperature:");
	scanf("%d", &temperature);

	printf ("The Celsius temperature is %d\n", 5 / 9 * (temperature - 32));
	//printf("The Celsius temperature is %5.2f\n", 5.0 / 9 * (temperature - 32));
	// 	printf ("The Celsius temperature is %5.2f\n", 5 * (temperature - 32) / 9);
}
