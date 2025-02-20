//header files
#include "yahtzee_lib.h"

//function to initalize the random number generator
void initializePlayer()
{
    //seeds random generator 
    srand(time(NULL));
}

//function that validates a lowercase character input, ensuring it is either 'y' or 'n'
char getChoice()
{
    char choice;
    do 
    {

	// Ask the user to enter a choice
	    // function: printf
	printf("Enter 'y' to continue or 'n' to stop: ");

        // Read a single character input
	    // function: scanf
	scanf(" %c", &choice);
        // Convert the input character to lowercase for consistent comparison
        choice = tolower(choice);
   
    	// Repeat until input is valid	
    }while (choice != 'y' && choice != 'n'); 
    
    return choice;
}

//function to roll a dice by generating a random number between 1 and 6 
int rollDice()
{
    //generate a random roll
    return rand() % NUM_SIDES + 1;
    
}

//functions given an array of dice counts how many times the dice has the number 1-6 
void countNumber(const int dice[], int counts[])
{
    //iterate through counts array 
    for (int i = 0; i < NUM_SIDES; i++)
    {
	//set counts array to 0
	counts[i] = 0;
    }
    
    //count each dice number 
    for (int i = 0; i < NUM_DICE; i++)
    {
	//check for count
	if (dice[i] >= 1 && dice[i] <= NUM_SIDES) 
	{
	   //increment for respective dice count 
	   counts[dice[i] - 1]++; 
	}
    }
}

//function given array of dice, checks if the numbers in the dice form a yahtzee
bool isYahtzee(const int dice[])
{
    //iterate through index in dice array starting from 1 
    for (int i = 1; i < NUM_DICE; i++)
    {
	//check if the current dice index is not equal to the index at 0 since this would not be a yahtzee
	if (dice[i] != dice[0])
	{
	    return false;
	}
    }
    return true;

}

//function that checks if there is a four of a kind
bool isFourOfAKind(const int counts[])
{
    //iterate through index in counts array 
    for (int i = 0; i < NUM_SIDES; i++)
    {
	//checks if any of the arrays return 4
	if (counts[i] == 4)
	{
	    return true;
	}
    }
    return false;	
}

//function that checks if there are two of the same number
bool hasTwoEqual(const int counts[])
{
    //iterate through index in count array 
    for (int i = 0; i < NUM_SIDES; i++)
    {
	//check if any of the index values are equal to two
	if (counts[i] == 2)
	{
	    return true;
	}
    }
    return false;
}

//function that checks if three numbers are equal 
bool hasThreeEqual(const int counts[])
{
    //iterate through index in count array 
    for (int i = 0; i < NUM_SIDES; i++)
    {
	//check if any of the index values are equal to three
	if (counts[i] == 3)
	{
	    return true;
	}
    }
    return false;
}

//function that checks if there is a full house
bool isFullHouse(const int counts[])
{
    //checks if there is a count with three and two 
    if (hasThreeEqual(counts) && hasTwoEqual(counts))
    {
	return true;
    }
    return false;
}

//function that checks if there is a large straight 
bool isLargeStraight(const int counts[])
{
    // Look for a sequence of 5 consecutive numbers (1-2-3-4-5 or 2-3-4-5-6)
    for (int i = 0; i <= NUM_SIDES - 5; i++) 
    {
        // Check if there are five consecutive numbers
        if (counts[i] && counts[i + 1] && counts[i + 2] && counts[i + 3] && counts[i + 4]) 
        {
            return true;
        }
    }
    return false;
}


//function that checks if there is a small straight 
bool isSmallStraight(const int counts[])
{
    // Look for a sequence of 4 consecutive numbers (1-2-3-4, 2-3-4-5, or 3-4-5-6)
    for (int i = 0; i <= NUM_SIDES - 4; i++) 
    {
        // Check if there are four consecutive numbers
        if (counts[i] && counts[i + 1] && counts[i + 2] && counts[i + 3]) 
        {
            return true;
        }
    }
    return false;
}


//function that checks which of the plays was achieved 
int decidePlay(const int dice[]) 
{
    // Declare an array to store the counts of each dice value (1 to 6)
    int counts[NUM_SIDES] = {0};

    // Count the frequency of each number in the dice array
    countNumber(dice, counts);

    //checks for play 
    if (isYahtzee(dice))
    {
        return YAHTZEE;
    }
    if (isLargeStraight(counts))
    {
        return L_STRAIGHT;
    }
    if (isSmallStraight(counts))
    {
        return S_STRAIGHT;
    }
    if (isFullHouse(counts))
    {
        return FULL_HOUSE;
    }
    if (isFourOfAKind(counts))
    {
        return FOUR_OF_A_KIND;
    }
    if (hasThreeEqual(counts))
    {
        return THREE_OF_A_KIND;
    }

    return NO_PLAY;
}
