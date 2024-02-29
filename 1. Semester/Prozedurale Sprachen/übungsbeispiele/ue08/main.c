#include <stdio.h>
#include <stdlib.h>



int main()
{
    int numbermonth, numberday, i;
    printf("number of days in month: ");
    scanf("%d", &numbermonth);
    printf("starting day of week (1=Monday, 7=Sunday): ");
    scanf("%d", &numberday);
    printf("\n");

    for (i = 1; i != numbermonth + 1; ++i)
    {

    switch(numberday % 7)
    {
case 0:
    if (i == 1)
    {
        printf("                  ");
    }
    if (i < 10)
    {
    printf(" %d ", i);
    }
    if (i >= 10)
    {
        printf("%d ", i);
    }
    if (i % 7 == 1)
    {
        printf("\n");
    }
    break;
case 1:
    if (i < 10)
    {
    printf(" %d ", i);
    }
    if (i >= 10)
    {
        printf("%d ", i);
    }
    if (i % 7 == 0)
    {
        printf("\n");
    }
    break;
case 2:
    if (i == 1)
    {
        printf("   ");
    }
    if (i < 10)
    {
    printf(" %d ", i);
    }
    if (i >= 10)
    {
        printf("%d ", i);
    }
    if (i % 7 == 6 && i > 2)
    {
        printf("\n");
    }
    break;
case 3:
    if (i == 1)
    {
        printf("      ");
    }
    if (i < 10)
    {
    printf(" %d ", i);
    }
    if (i >= 10)
    {
        printf("%d ", i);
    }
    if (i % 7 == 5)
    {
        printf("\n");
    }
    break;
case 4:
    if (i == 1)
    {
        printf("         ");
    }
    if (i < 10)
    {
    printf(" %d ", i);
    }
    if (i >= 10)
    {
        printf("%d ", i);
    }
    if (i % 7 == 4)
    {
        printf("\n");
    }
    break;
case 5:
    if (i == 1)
    {
        printf("            ");
    }
    if (i < 10)
    {
    printf(" %d ", i);
    }
    if (i >= 10)
    {
        printf("%d ", i);
    }
    if (i % 7 == 3)
    {
        printf("\n");
    }
    break;
case 6:
    if (i == 1)
    {
        printf("               ");
    }
    if (i < 10)
    {
    printf(" %d ", i);
    }
    if (i >= 10)
    {
        printf("%d ", i);
    }
    if (i % 7 == 2)
    {
        printf("\n");
    }
    break;

    }
    }
    return 0;
}
