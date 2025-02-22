// I want to make a program that finds a value using a scanf and pointers
#include <stdio.h>
int* findValue(int* num1, int* num2, int* sum)
{
    *sum = *num1 + *num2;

    return sum;
}

int main()
{
    //int vars
    int number1 = 5;
    int number2 = 6;
    int sum;
    findValue(&number1, &number2, &sum);
    printf("%d + %d = %d", number1, number2, sum);
}

