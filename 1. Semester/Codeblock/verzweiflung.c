#include <stdio.h>

int main() {

    int zahl1;
    int mod = 0;
    int zahl3 = 0;
    int ergeb = 0;
    int count = 0;
    int zs = 0;

    scanf("%d", &zahl1);

    while (zahl3 < 3)
    {
        mod = zahl1 % 10;   /* erste Stelle der Zahl wird in var mod gespeichert */
        ergeb = ergeb + mod * pow(8, zahl3);    // var ergeb wird nun der Wert von ergeb plus mod mal 8 hoch zahl3 zugeteilt
        zahl1 = zahl1 / 10; // jetzt wird die zahl1 durch 10 dividiert um in der nächsten Schleife die nächste Stelle berechnen zu können
        zahl3++;
    }

    printf(": %d\n", ergeb); // das ergebnis wird ausgegebn in oktalzahl

    while (count <= 3)
    {
        zs += ergeb % 10; // Ziffernsumme ist gleich ergeb mod 10 (wieder wird erste Stelle errechnet durch modular fkt)
        ergeb /= 10; // ergeb wird nun der Wert "ergeb durch 10" zugeteilt
        count++; // durch count wiederholt sich die Schleife
    }

    printf("ZS: %d", zs); // Ziffernsumme wird ausgegeben

return 0;

}
