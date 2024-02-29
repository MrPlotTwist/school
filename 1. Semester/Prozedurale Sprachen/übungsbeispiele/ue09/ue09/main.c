#include <stdio.h>
int main() {

    double max = 0, summe = 0, min = 10000000000, z1, avg;
    int count = 0;
    char cntsumme = ':';
    char cnt = ' ';
    char cnt2 = ':';

    scanf("%lf", &z1);
            if (z1 <= 0)
    {
        printf(": no number entered");
    }
    else
    {

    for(;z1 > 0; ++count)
    {
        summe = summe + z1;
        //printf("summe: %.2lf", summe);
        max = (max <= z1) ?z1 :max;
        //printf("max: %.2lf", max);
        min = (min >= z1) ?z1 :min;
        //printf("min: %.2lf", min);
        scanf("%lf", &z1);
        cntsumme = cntsumme + cnt + cnt2;
    }

    avg = summe / count;

        printf("%ccnt: %d\n", cntsumme, count);

    printf("min: %.2lf\n", min);
    printf("max: %.2lf\n", max);
    printf("avg: %.2lf\n", avg);
    //printf("summe: %.2lf\n", summe);
    }



return 0;
}
