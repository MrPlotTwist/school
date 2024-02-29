#include <stdio.h>
#include <string.h>

int countcharacter(char* string, char character);


int main() {

    char string[] = "Hallo";
    char character = 'l';
    printf("%d\n", countcharacter(string, character)); // zählt die buchstabenanzahl von 'l' in 'Hallo'

return 0;
}

int countcharacter(char* string, char character)
{
    int counter = 0;
    for(int index = 0; string[index] != '\0' ; index++)
    {
        if (string[index] == character)
        {
            counter++; // counter erhöht sich wenn 'l' in 'Hallo' vorkommt
        }
    }
    return counter;
}
