/*
	Author: Bryce Monaco
	Written: 10/07/15
	Last Modified: 10/07/15
	
	This code is to complete the challege set in this thread:
		https://www.reddit.com/r/dailyprogrammer/comments/3nkanm/20151005_challenge_235_easy_ruthaaron_pairs/
	to test if two numbers, input by the user, are a Ruth-Aaron pair, where the sum of the prime factors of two consecutive numbers is equal (not counting 1 and the number)
	
	Make sure to compile with the C99 Standard (In Ubuntu the command would be "gcc Ruth-Aaron.c -o ruth -std=c99")
	
*/

#include <stdio.h>
#include <math.h>

int main (void) {
	
	int userNumberFirst = 0, userNumberSecond = 0;	//Used to store the two numbers input by the user
	
	while ((userNumberFirst + 1) != userNumberSecond) {
		printf("Enter two consecutive integers, least to greatest, separated with a space (ex. \"1 2\"): ");
		scanf("%d %d", &userNumberFirst, &userNumberSecond);
	
		if ((userNumberFirst + 1) == userNumberSecond) {	//To check if the numbers are consecutive and in order
			break;
			
		} else {
			printf("Invalid Input. Please ensure that your integers:\n\t-Are consecutive\n\t-Are in least to greatest order\n\t-Are separated with a space\n");
			
		}
	}
	
	int sumFirst = 0, sumSecond = 0;	//used to store the sum of the prime factors for each number
	
	printf("Prime factors of %d: ", userNumberFirst);
	
	for (int i = 2; i <= (userNumberFirst/2); i++) {
		if ((userNumberFirst % i) == 0) {	//Test if the number is an integer factor of the input
		
		int isPrime = 1; //A boolean value, assumed true until proven false
		
			for (int ii = 2; ii <= sqrt(i); ii++) {
				if ((i % ii) == 0) {
					isPrime = 0;
					break;
					
				}
			}
			
			if (i == 2) {	//2 needs a special treatment since it is an even number but also prime
				printf("%d", i);
				sumFirst += i;
			
			}else if (((i % 2) != 0) && (i != 2) && isPrime) {	//Test if the factor is an even number (not prime, except for 2)
				printf(", %d", i);
				sumFirst += i;
			}
		}
	}
	
	printf(" (Sum = %d)\n", sumFirst);
	
	printf("Prime factors of %d: ", userNumberSecond);
	
	for (int i = 2; i <= (userNumberSecond/2); i++) {
		if ((userNumberSecond % i) == 0) {	//Test if the number is an integer factor of the input
		
		int isPrime = 1; //A boolean value, assumed true until proven false
		
			for (int ii = 2; ii <= sqrt(i); ii++) {
				if ((i % ii) == 0) {
					isPrime = 0;
					break;
					
				}
			}
			
			if (i == 2) {	//2 needs a special treatment since it is an even number but also prime
				printf("%d", i);
				sumSecond += i;
			
			}else if (((i % 2) != 0) && (i != 2) && isPrime) {	//Test if the factor is an even number (not prime, except for 2)
				printf(", %d", i);
				sumSecond += i;
				
			}
		}
	}
	
	printf(" (Sum = %d)\n", sumSecond);
	
	if (sumFirst == sumSecond) {
		printf("%d and %d is a Ruth-Aaron pair!\n", userNumberFirst, userNumberSecond);
		
	} else {
		printf("%d and %d is not a Ruth-Aaron pair.\n", userNumberFirst, userNumberSecond);
	
	}
	
	return 0;
}

