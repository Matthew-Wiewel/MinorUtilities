#include <stdio.h>

#define TRUE 1
#define FALSE 0

int main()
{
	unsigned int val;
	int readAnotherVal = TRUE;
	char response;

	//loop that keep reading value and printing it in the various formats
	while(readAnotherVal)
	{
		printf("\nPlease enter the value: ");
		scanf("%i",&val); //%i allows hex, decimal, or octal
				//whereas %d, %x, and %o are specific
		
		printf("\nValue in Hex: %x", val);
		printf("\nValue in Decimal: %d", val);
		printf("\nValue in Octal: %o", val);

		printf("\nWould you like to another value? (Y/N): ");
		scanf(" %c", &response); //self-note: leading whitespace is necessary
					//other '\n' from previous response is picked up

		if(response == 'N' || response == 'n')
			readAnotherVal = FALSE;
	}

	return 0;
}

