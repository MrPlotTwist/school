/* Mein erstes C Programm */
#include <stdio.h>
int main() {

    int max = 0,maxsum, minsum, summe = 0, min = 10000, z1;
    int count =0;


        while (count < 5)
        {
        scanf("%d", &z1);

        summe = summe + z1;
        max = (max <= z1) ?z1 :max;
        min = (min >= z1) ?z1 :min;

        count++;
        }

        minsum = summe - max;
        maxsum = summe - min;

        printf("minimum sum: %d", minsum);
        printf("maximum sum: %d", maxsum);


return 0;
}
