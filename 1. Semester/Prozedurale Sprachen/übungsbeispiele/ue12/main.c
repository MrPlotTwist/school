#include <stdio.h>
#include <stdlib.h>
#define anz 10

double praemien(double betraege[], int anzahl, double grenze, double praemie);
int eingabe(double betraege[], double max);
double sum(double betraege[], int anzahl);

int main()
{
    double arr[anz] = {0};
    double grenze, praemie, gesamt;
    int n;

    n = eingabe(arr, anz); // eingabe() passt
    printf("Untergrenze: ");
    scanf("%lf", &grenze);
    printf("Praemie: ");
    scanf("%lf", &praemie);

    printf("Summe vor Praemien: %.2f\n", sum(arr, n)); // sum sollte passen
    gesamt = praemien(arr, n, grenze, praemie); // prämie passt
    printf("Praemien gesamt: %.2f\n", gesamt);
    printf("Summe nach Praemien: %.2f\n", sum(arr, n));

    return 0;
}

double praemien(double betraege[], int anzahl, double grenze, double praemie)
{
    double zahl;
    int i;
    double prem;

    prem = praemie;
    praemie = 0;
    //printf("%dhilfe", anzahl);
    i = anzahl;

    if (grenze == 0 && i < 10)
    {
        praemie = praemie - prem;
    }

    for (; anzahl > 0; --anzahl)
    {
        zahl = betraege[anzahl];

        if (zahl >= grenze)
        {
            printf("%lf", praemie);
            praemie = praemie + prem;
        }
    }
    anzahl = i;
    printf("%lf", praemie);
    //printf("%ddf", anzahl); //anzahl auslesen
    betraege[anzahl] = praemie;
    //printf("%lf", praemie); // prämie auslesen
    //printf("%lf", betraege[anzahl]);
    return betraege[anzahl];
}

int eingabe(double betraege[], double max)
{
    int counter = 0, i = 0;
    while (max >= 0 && i < 10)
    {
        ++counter;
        printf("Zahl %d: ", counter);
        scanf("%lf", &max);
        betraege[i] = max;
        ++i;
    }
    return i;
}

double sum(double betraege[], int anzahl)
{
    double zahl, sum = 0;

    for (; anzahl >= 0; --anzahl)
    {
        zahl = betraege[anzahl];
        printf("%lf\n", zahl); // array auslesen
        if (zahl <= 0)
        {
            betraege[anzahl] = 0;
            zahl = 0;
        }
        sum += zahl;
    }
    return sum;
}
