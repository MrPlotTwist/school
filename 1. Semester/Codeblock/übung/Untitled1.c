#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int noten(zs, erste, zweite, dritte)
{
    zweite = erste / 10;
    dritte = erste / 100;

    if (erste > 999)
    {
        printf("Noten: Erwarte genau 3 Noten!");
    }
    else if (zs == 3)
    {
        printf("Ausgezeichneter Erfolg!");
    }
    else if (zs == 4)
    {
        printf("Noten: Guter Erfolg!");
    }
    else if ((zs > 4 && erste % 10 == 5) || (zweite % 10 == 5) || (dritte % 10 == 5))
    {
        printf("Nicht bestanden.");
    }
    else if (erste % 10 > 5)
    {
        printf("Noten: Dritte Note muss zwischen 1 und 5 liegen!");
    }
    else if (zweite % 10 > 5)
    {
        printf("Noten: Zweite Note muss zwischen 1 und 5 liegen!");
    }
    else if (dritte % 10 > 5)
    {
        printf("Noten: Erste Note muss zwischen 1 und 5 liegen!");
    }
    else if (zs > 4 && erste % 10 < 5)
    {
        printf("Bestanden.");
    }
}

int zsumme(int count, int zs, int erste)
{
    count = 0;
    zs = 0;
    while (count <= 3)
    {
        zs += erste % 10;
        erste /= 10;
        count++;
    }
    return zs;
}

int main ()
{
    int erste, zweite, dritte, count = 0, zs = 0;
    scanf("%d", &erste);
    zweite = erste / 10;
    dritte = erste / 100;
    zs = zsumme(count, zs, erste);
    noten(zs, erste, zweite, dritte);
    return 0;
}
