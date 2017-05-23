#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void  _displayMainMenu();
void  _getFastFoodInput();
bool  _validateMenuInput(char *input);
bool  _validateYearInput(char *input);
inline float _calculateFastFoodCharges(int year);

int main(int argc, char **argv)
{
    printf("----------------------------------------------------------------\n");
    printf("--          Welcome to the Fast Food Charges calculator       --\n");
    printf("--                 What would you like to do?                 --\n");
    printf("----------------------------------------------------------------\n\n");

    char buffer[256];
    bool isRunning = true;
    while(isRunning)
    {
        _displayMainMenu();
        printf("\n>> ");
        // Get input and remove trailing newline.
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strcspn(buffer, "\n")] = 0;

        // Validate input
        if(_validateMenuInput(buffer))
        {
            int menuChoice = atoi(buffer);
            switch(menuChoice)
            {
                case 1: 
                    _getFastFoodInput();
                    break;
                case 2: 
                    printf("Exiting program.\n");
                    isRunning = false;
                    break;
                default:
                    printf("Invalid input!\n");
            }
        }
        else
        {
            printf("Invalid input. Please try again.\n");
        }
    }

    return 0;
}

void _displayMainMenu()
{
    printf("1. Calculate fast food charges \n");
    printf("2. Exit program\n");
}

bool _validateMenuInput(char *input) 
{
    int length = strlen(input);
    if(length == 1) 
        return true;
    else 
        return false;
}

void _getFastFoodInput()
{
    char buffer[256];

    printf("Enter a year greater than or equal to 2005.\nAny year earlier will stop the program.\n");
    printf(">> ");

    // Get input from user
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    // Convert to integer
    int year = atoi(buffer);

    // If out of range, display error message and exit.
    if(year < 2005)
    {
        printf("Invalid year. Given year was before 2005. Exiting program.\n");
        exit(EXIT_FAILURE);
    }
    // Otherwise run the calculation and display to screen.
    else
    {
        float foodCosts = _calculateFastFoodCharges(year);
        printf("\nEstimated fast food charges: $%.2f billion.\n\n", foodCosts);
    }

    return;
}

inline float _calculateFastFoodCharges(int year)
{
    return (33.2 + (16.8 * (year - 2005)));
}
