// header files
#include "yahtzee_lib.h"

// main program
int main()
{
    // initialize program
        // initialize the random number generator
            // function: initializePlayer
    initializePlayer();
        // declare variable to hold the dice
    int dice[NUM_DICE];

        // declare the variable to store the user's choice
    char choice;
        // inialize the variable that stores the play
    int play = NO_PLAY;

        // print a title
    printf("\nWelcome to Simple Yahtzee!\n");
    printf("==========================\n\n");

    // begin game
        // prompt the user for the play
            // function: printf
    printf("Do you want to roll the dice (y/n): ");
        // wait for user input
            // function: getChoice
    choice = getChoice();

        // TODO 1: create a loop that runs while the user wants to continue
    while (choice == 'y') 
    {	
            // TODO 2: roll the dice to fill the array of dice
	for (int i = 0; i < NUM_DICE; i++)
	{
	    dice[i] = rollDice();
	}	    
            // TODO 3: print the dice
		//function printf
	printf("Dice Rolled: ");
	    //loop through dice array to print out numbers
	for (int i = 0; i < NUM_DICE; i++)
	{
	    //print number in array 
	    printf("%d ", dice[i]);
	}
	printf("\n");

            // TODO 4: call the function decidePlay and store the result in
            //         the play variable
	play = decidePlay(dice);
            // TODO 5: evaluate the play variable and print the appropriate 
            //         message
        switch (play)
	{
	    case YAHTZEE:
                printf("You got a Yahtzee!\n");
                break;
            case L_STRAIGHT:
                printf("You got a Large Straight!\n");
                break;
            case S_STRAIGHT:
                printf("You got a Small Straight!\n");
                break;
            case FULL_HOUSE:
                printf("You got a Full House!\n");
                break;
            case FOUR_OF_A_KIND:
                printf("You got a Four of a Kind!\n");
                break;
            case THREE_OF_A_KIND:
                printf("You got a Three of a Kind!\n");
                break;
            default:
                printf("No valid play found.\n");
                break;
        }

        // prompt the user for continuing
            // function: printf
        printf("\nPlay again? (y/n): ");
        // Read the choice
            // function: getChoice
        choice = getChoice();
    
    // END OF TODO 1: loop
    }
    // End program
        // print a message
            // function: printf
    printf("\nThanks for playing Yahtzee!\n");
        // return success
    return 0;
}
