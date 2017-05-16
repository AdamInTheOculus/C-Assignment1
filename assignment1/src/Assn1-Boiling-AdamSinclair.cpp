#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void _promptMainMenu();
bool _isSingleCharacter(char *input);

int main()
{
    // Predefined space for input buffer
    char buffer[256];
    bool isRunning = true;

    while(isRunning) {
        // Get user input
        _promptMainMenu();
        fgets(buffer, sizeof(buffer), stdin);

        // Omit newline from string
        buffer[strcspn(buffer, "\n")] = 0;

        // Validate user input
        if(_isSingleCharacter(buffer))
        {
            // int atoi() returns 0 if not an integer ...
            int menuChoice = atoi(buffer);
            switch(menuChoice)
            {
                case 1:
                    printf("You selected 'Celcius'.\n");
                    break;
                case 2:
                    printf("You selected 'Fahrenheit'.\n");
                    break;
                case 3:
                    printf("You selected 'Kelvin'.\n");
                    break;
                case 4:
                    printf("Exiting program.\n");
                    isRunning = false;
                    break;
                default:
                    printf("Invalid input!\n");
            }
        }
        else 
        {
            printf("Invalid input!\n");
        }
    }

    return 0;
}

void _promptMainMenu() 
{
    printf("----------------------------------------------------------\n");
    printf("--          Welcome to the Temp/Boiling program!        --\n");
    printf("-- Please select the degree type you would like to use: --\n");
    printf("----------------------------------------------------------\n");
    printf("\n1. Celcius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    printf("4. Exit program\n");
    printf("\n>> ");
}

// Ensure input is only a single character
bool _isSingleCharacter(char *input)
{
    int length = strlen(input);
    if(length == 1) 
        return true;
    else 
        return false;
}
