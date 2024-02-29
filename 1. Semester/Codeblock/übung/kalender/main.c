#include <stdio.h>
#include <stdlib.h>

int numbermonth(int daysinmonth);
int startingday(int firstday);
int kalender(int daysinmonth, int firstday);

int main()
{
    int daysinmonth, firstday;
    numbermonth(daysinmonth);
    startingday(firstday);
    kalender(daysinmonth, firstday);
    return 0;
}

int numbermonth(int daysinmonth)
{
    scanf("%d", &daysinmonth);
    printf("number of days in month: %d\n", daysinmonth);
    return daysinmonth;
}

int startingday(int firstday)
{
    scanf("%d", &firstday);
    printf("starting day of week (1=Monday, 7=Sunday): %d", firstday);
}

int kalender(int daysinmonth, int firstday)
{
    for(firstday == 1; firstday <= 31; ++firstday)
    {
        if (firstday >= 1)
        {
            printf("%d ", firstday);
            if (firstday == 5 && daysinmonth % 5 == 1)
            {
                printf("%d\n", firstday);
            }
        }
    }
}
