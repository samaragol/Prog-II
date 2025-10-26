#include "temperature_conversor.h"
#include <stdio.h>

int main()
{
    float temp;
    char base, convert;

    scanf("%f ", &temp);
    scanf("%c %c", &base, &convert);

    printf("Temperature: ");
    
    if (base == 'c')
    {
        if (convert == 'k')
        {
            printf("%.2fK", convert_temperature(temp, convert_celsius_to_kelvin));
        }
        else
        {
            printf("%.2fFº", convert_temperature(temp, convert_celsius_to_fahrenheit));
        }
    }
    else if (base == 'k')
    {
        if (convert == 'c')
        {
            printf("%.2fCº", convert_temperature(temp, convert_kelvin_to_celsius));
        }
        else
        {
            printf("%.2fFº", convert_temperature(temp, convert_kelvin_to_fahrenheit));
        }
    }
    else
    {
        if (convert == 'c')
        {
            printf("%.2fCº", convert_temperature(temp, convert_fahrenheit_to_celsius));
        }
        else
        {
            printf("%.2fK", convert_temperature(temp, convert_fahrenheit_to_kelvin));

        }
    }

    return 0;
}