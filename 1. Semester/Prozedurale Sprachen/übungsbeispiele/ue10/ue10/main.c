#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pos = 1, pos1 = 1, poscounter = 1, winner;

    while (1)
    {
        printf(":");
        scanf("%d", &pos);
        ++poscounter;
               if (pos == 0)
       {
           break;
       }
       if (pos1 == pos || pos1 >= pos)
            {
            pos1 += 1;
            printf("position #1: %d\nnew leader: #%d\n", pos1, poscounter);
            }
            winner = poscounter;
       else if (pos <= pos1)
        {
            pos1 += 1;
            printf("position #1: %d\n", pos1);

        }
        //(pos1 == pos || pos1 > pos) ? pos1 += 1, printf(" position #1: %d\nnew leader: #%d\n", pos1, poscounter), winner = poscounter : printf("position #1: %d\n", pos1);
       //(pos == pos1) ? printf("position #1: %d\nnew leader: #%d\n", poscounter, poscounter) : printf("position #1: %d\n", poscounter);
    }

    printf("final position #1: %d\n", pos1);
    printf("winner: #%d", winner);

    return 0;
}

// (time < 18) ? printf("Good day.") : printf("Good evening.");
