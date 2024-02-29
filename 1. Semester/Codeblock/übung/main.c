#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int x, c, y;
char a;

int xhochy(x, y, xhochy)
{
    scanf("%d\n%d", &x, &y);
    double xy = pow(x, y);
    printf("\n%.lf", xy );

    return pow(x, y);
}

int fakx(x, c, fak)
{
    fak = 1;
    scanf("%d", &x, &c);
    c = x;

    while(c > 1 && x > 1)
    {
        --c;
        fak = fak * (x * c);
        x = x - 2;
        --c;
    }
    return fak;
}

int faky(y, c, fak)
{
    fak = 1;
    scanf("%d", &y, &c);
    c = y;

    while(c > 1 && y > 1)
    {
        --c;
        fak = fak * (y * c);
        y = y - 2;
        --c;
    }
    return fak;
}

int xhochyfak(x, y, xhochy, c, fak)
{
    scanf("%d\n%d", &x, &y);
    double xy = pow(x, y);

    fak = 1;
    y = xy;
    c = y;

    while(c > 1 && y > 1)
    {
        --c;
        fak = fak * (y * c);
        y = y - 2;
        --c;
}
    printf("%d", fak);
    return fak;
}

char eingabe(a)
{
    scanf("%c", &a);

}
int main()
{
    double xy;
    int ergebx, ergeby, fak = 1;
    char a;

    eingabe(a);

    if (a == "a")
    {
    xhochy(x, y, xy);
    }
    else if (a == "b")
    {
    ergebx = fakx(x, c, fak);
    ergeby = faky(y, c, fak);
    printf("%d", ergebx + ergeby);
    }
    else if (a == "c")
    {
    xhochyfak(x, y, xhochy, c, fak);
    }

    return 0;
}
