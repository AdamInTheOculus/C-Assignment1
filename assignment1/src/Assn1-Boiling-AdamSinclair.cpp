#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void _promptMainMenu();
bool _isSingleCharacter(char *input);
void _promptTemperatureMenu(char const* temperatureType);
void _getTemperature(char const *temperatureType);
void _displaySubstance(char const *temperatureType, float temperature);
void _displayCelciusSubstance(float temperature);
void _displayFahrenheitSubstance(float temperature);
void _displayKelvinSubstance(float temperature);
inline float celciusToFahrenheit(float value);
inline float celciusToKelvin(float value);

#define WATER_CELCIUS 100
#define MERCURY_CELCIUS 357
#define COPPER_CELCIUS 1187
#define SILVER_CELCIUS 2193
#define GOLD_CELCIUS 2660

int main()
{
    // Predefined space for input buffer
    char buffer[256];
    bool isRunning = true;

    printf("----------------------------------------------------------\n");
    printf("--          Welcome to the Temp/Boiling program!        --\n");
    printf("-- Please select the degree type you would like to use: --\n");
    printf("----------------------------------------------------------\n");

    while(isRunning) 
    {
        _promptMainMenu();

        // Get user input
        printf("\n>> ");
        fgets(buffer, sizeof(buffer), stdin);

        // Omit newline from string
        buffer[strcspn(buffer, "\n")] = 0;

        if(_isSingleCharacter(buffer))
        {
            // int atoi() returns 0 if not an integer ...
            int menuChoice = atoi(buffer);
            switch(menuChoice)
            {
                case 1:
                    _getTemperature("Celcius");
                    break;
                case 2:
                    _getTemperature("Fahrenheit");
                    break;
                case 3:
                    _getTemperature("Kelvin");
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
    printf("\n1. Celcius\n");
    printf("2. Fahrenheit\n");
    printf("3. Kelvin\n");
    printf("4. Exit program\n");
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

void _promptTemperatureMenu(char const *temperatureType) 
{
    if(temperatureType == NULL)
    {
        printf("_promptTemperatureMenu() error: Argument given is NULL.");
        return;
    }

    printf("------------------------------------------------------\n");
    printf("--                   %s selected!              --\n", temperatureType);
    printf("--  Select the observed boiling point, in %s:  --\n", temperatureType);
    printf("------------------------------------------------------\n");
}

void _getTemperature(char const *temperatureType)
{
    if(temperatureType == NULL)
    {
        printf("_getTemperature() error: Argument given is NULL.");
        return;
    }

    _promptTemperatureMenu(temperatureType);
    
    // Get input from user
    char buffer[256];
    printf(">> ");
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;

    // Convert input to number
    const float temperature = atof(buffer);
    if(temperature <= 0)
    {
        printf("Substance unknown.\n\n");
        return;
    }
    else 
    {
        _displaySubstance(temperatureType, temperature);
        return;
    }

}

void _displaySubstance(char const *temperatureType, float temperature)
{
    if(temperatureType == NULL || temperature <= 0)
    {
        printf("_displaySubstance() error: Argument given is NULL or non-positive.");
        return;
    }

    if(strcmp(temperatureType, "Celcius") == 0)
    {
        _displayCelciusSubstance(temperature);
    }
    else if(strcmp(temperatureType, "Fahrenheit") == 0)
    {
        _displayFahrenheitSubstance(temperature);
    }
    else if(strcmp(temperatureType, "Kelvin") == 0)
    {
        _displayKelvinSubstance(temperature);
    }
    else 
    {
        printf("_displaySubstance() error: Invalid temperatureType [%s]. Exiting function.\n", temperatureType);
    }

    return;
}

void _displayCelciusSubstance(float temperature)
{

    // Water
    if(temperature >= (WATER_CELCIUS - (0.05 * WATER_CELCIUS)) && temperature <= (WATER_CELCIUS + (0.05 * WATER_CELCIUS)))
    {
        printf("Identified substance: WATER.\n\n");
    }
    // Mercury
    else if(temperature >= (MERCURY_CELCIUS - (0.05 * MERCURY_CELCIUS)) && temperature <= (MERCURY_CELCIUS + (0.05 * MERCURY_CELCIUS)))
    {
        printf("Identified substance: MERCURY.\n\n");
    }
    // Copper
    else if(temperature >= (COPPER_CELCIUS - (0.05 * COPPER_CELCIUS)) && temperature <= (COPPER_CELCIUS + (0.05 * COPPER_CELCIUS)))
    {
        printf("Identified substance: COPPER.\n\n");
    }
    // Silver
    else if(temperature >= (SILVER_CELCIUS - (0.05 * SILVER_CELCIUS)) && temperature <= (SILVER_CELCIUS + (0.05 * SILVER_CELCIUS)))
    {
        printf("Identified substance: SILVER.\n\n");
    }
    // Gold
    else if(temperature >= (GOLD_CELCIUS - (0.05 * GOLD_CELCIUS)) && temperature <= (GOLD_CELCIUS + (0.05 * GOLD_CELCIUS)))
    {
        printf("Identified substance: GOLD.\n\n");
    }
    else
    {
        printf("Substance unknown.\n\n");
    }

    return;
}

void _displayFahrenheitSubstance(float temperature)
{
    const float WATER = celciusToFahrenheit(WATER_CELCIUS), 
                MERCURY = celciusToFahrenheit(MERCURY_CELCIUS), 
                COPPER = celciusToFahrenheit(COPPER_CELCIUS), 
                SILVER = celciusToFahrenheit(SILVER_CELCIUS),
                GOLD = celciusToFahrenheit(GOLD_CELCIUS)
    ;

    // Water
    if(temperature >= (WATER - (0.05 * WATER)) && temperature <= (WATER + (0.05 * WATER)))
    {
        printf("Identified substance: WATER.\n\n");
    }
    // Mercury
    else if(temperature >= (MERCURY - (0.05 * MERCURY)) && temperature <= (MERCURY + (0.05 * MERCURY)))
    {
        printf("Identified substance: MERCURY.\n\n");
    }
    // Copper
    else if(temperature >= (COPPER - (0.05 * COPPER)) && temperature <= (COPPER + (0.05 * COPPER)))
    {
        printf("Identified substance: COPPER.\n\n");
    }
    // Silver
    else if(temperature >= (SILVER - (0.05 * SILVER)) && temperature <= (SILVER + (0.05 * SILVER)))
    {
        printf("Identified substance: SILVER.\n\n");
    }
    // Gold
    else if(temperature >= (GOLD - (0.05 * GOLD)) && temperature <= (GOLD + (0.05 * GOLD)))
    {
        printf("Identified substance: GOLD.\n\n");
    }
    else
    {
        printf("Substance unknown.\n\n");
    }

    return;
}

void _displayKelvinSubstance(float temperature)
{
    const float WATER = celciusToKelvin(WATER_CELCIUS), 
                MERCURY = celciusToKelvin(MERCURY_CELCIUS), 
                COPPER = celciusToKelvin(COPPER_CELCIUS), 
                SILVER = celciusToKelvin(SILVER_CELCIUS),
                GOLD = celciusToKelvin(GOLD_CELCIUS)
    ;

    // Water
    if(temperature >= (WATER - (0.05 * WATER)) && temperature <= (WATER + (0.05 * WATER)))
    {
        printf("Identified substance: WATER.\n\n");
    }
    // Mercury
    else if(temperature >= (MERCURY - (0.05 * MERCURY)) && temperature <= (MERCURY + (0.05 * MERCURY)))
    {
        printf("Identified substance: MERCURY.\n\n");
    }
    // Copper
    else if(temperature >= (COPPER - (0.05 * COPPER)) && temperature <= (COPPER + (0.05 * COPPER)))
    {
        printf("Identified substance: COPPER.\n\n");
    }
    // Silver
    else if(temperature >= (SILVER - (0.05 * SILVER)) && temperature <= (SILVER + (0.05 * SILVER)))
    {
        printf("Identified substance: SILVER.\n\n");
    }
    // Gold
    else if(temperature >= (GOLD - (0.05 * GOLD)) && temperature <= (GOLD + (0.05 * GOLD)))
    {
        printf("Identified substance: GOLD.\n\n");
    }
    else
    {
        printf("Substance unknown.\n\n");
    }

    return;
}

inline float celciusToFahrenheit(float value)
{
    return (value * 1.8) + 32;
}

inline float celciusToKelvin(float value)
{
    return value + 273.15;
}
