#include <stdio.h>

int main() {

 int zahl1, hold = 0, zahl2 = 0, stelle = 0;

 scanf("%d", &zahl1);

 while (zahl1)
 {
     hold = zahl1 % 10;
     stelle = stelle + hold * pow(8, zahl2);
     zahl1 = zahl1 / 10;
     zahl2++;
 }

 printf("\n%d", stelle);

return 0;

}
