#include <stdio.h>
//function to swap two numbers 
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to reverse a string in place
char reverse_string(char *str)
{
    //set case for if str is 0 
    if (str == NULL) return 0;

    //set two pointers start and end equal to the start of the string 
    char *start = str;
    char *end = str;

    //loop to make the end equal to the last valid index
    while (*end)
    {
	end++;
    }
    //set end to last valid character
    end--;

    //loop to swap characters while start of string is less than end 
    while (start < end)
    {
	//set temporary variable to hold start
	int temp = *start;
	*start = *end;
	*end = temp;

	start++;
	end--;

    }
    
}


int main()
{
    //first function test
    int x;
    int  y;
    
    printf("Input 1: ");
    scanf("%d", &x);
    printf("Input 2: ");
    scanf("%d", &y);
    
    printf("before the swap %d and %d\n", x, y);
    swap(&x, &y);
    printf("after the swap %d and %d\n", x, y);

    //second function test
    char str[] = "Hello World";
    printf("String before being swaped: %s\n", str);

    reverse_string(str);
    printf("String after being swaped: %s\n", str);
}

