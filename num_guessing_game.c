// I will import 4 libraries that will be used in my program. #include <stdlib.h> allows us to
// generate a random number, #include <time.h> allows us to create a time stamp everytime the program is run,
// #include <stdio.h> allows us to use the input output statements, #include <limits.h> allows us to find
// the maximum value for data types. I used srand((unsigned)time(&t)) to create a time stamp everytime I run
// the program so that I can get random results when I used rand().I will use a while loop to loop through the different options until the user selects 3
// to quit the program. I will use a switch statement to carry out the different tasks depending on what option
// the user selects.If the user selects 1, then a random number will be generated
// and the user will have to guess the number until the user guesses it correctly and this is done using a while loop which will loop until won == 1.
//If the user does not guess correctly then the program will explain if the
// guessed number was too high or too low. This was done using these else if statements:
// else if (guessNumber < randomNumber) and else if (guessNumber > randomNumber). /If the user selects 2 the user can change the range of the generated number up to INT_MAX.

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <limits.h>
int main()
{
    time_t t;
    short option;
    int guessNumber;
    int maxNumber = 10;
    int randomNumber;
    char won = 0;

    while (option != 3)
    {
        srand((unsigned)time(&t));
        printf("Press 1 to play a game\nPress 2 to change the max number\nPress 3 to quit\n");
        scanf("%hi", &option);
        switch (option)
        {
        case 1:
            randomNumber = (rand() % maxNumber) + 1;
            while (won != 1)
            {
                printf("Guess the number:\n");
                scanf("%u", &guessNumber);
                if (guessNumber == randomNumber)
                {
                    printf("YOU WON!!!\n");
                    won = 1;
                    break;
                }
                else if (guessNumber > randomNumber)
                {
                    printf("You guess is high\n");
                }
                else if (guessNumber < randomNumber)
                {
                    printf("You guess is low\n");
                }
            }
            won = 0;
            break;

        case 2:
            printf("The max value the number can be set to: %d (DO NOT GO OVER MAX VALUE OR ENTER A NEGATIVE NUMBER!!)\n", INT_MAX);
            scanf("%u", &maxNumber);
            randomNumber = (rand() % maxNumber) + 1;
            break;
        case 3:
            printf("Thank you for playing!\n");
            option = 3;
            break;
        }
    }
    return 0;
}
