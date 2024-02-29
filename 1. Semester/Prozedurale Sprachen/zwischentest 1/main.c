#include <stdio.h>
#include <stdlib.h>

double steuerfrei(double a, double b, double c);
double einnahme(double betrag, double steuern, double gesamt, double guthaben, double profit); // fkt für versteurte einnahmen
double einnahme2(double betrag, double steuern, double gesamt, double guthaben, double profit); // fkt für steuern
double koste(double kosten, double guthaben); // kosten

int main()
{
    char eingabe;
    double betrag, profit = 0, steuern = 0;
    double guthaben = 100;
    double gesamt = 0;
    int ecount = 0, kostencounter = 0;
    double einnahmen = 0, geseinnahmen = 0, gesausgaben = 0, gesamtsteuern = 0;
    printf("\nGuthaben: %.2lf Euro", guthaben);

    while (eingabe != '=')
    {
    printf("\nTyp: ");
    scanf(" %c", &eingabe);
    if (eingabe == 's' || eingabe == 'k' || eingabe =='e')
    {
        printf("\nBetrag in Euro: ");
        scanf("%lf", &betrag);
    }
    else if (eingabe == '=')
    {
        break;
    }
        if (betrag < 0)
        {
        printf("\nDer Betrag kann nicht negativ sein.");
        printf("\nGuthaben: %.2lf Euro", guthaben);
        }
        else if (eingabe == 's')
        {
            ++ecount;
            geseinnahmen = geseinnahmen + betrag;
            guthaben = steuerfrei(guthaben, betrag, profit);
            printf("\nGuthaben: %.2lf Euro", guthaben);
        }
        else if (eingabe == 'e')
        {
            ++ecount;
            guthaben = einnahme(betrag, steuern, gesamt, guthaben, profit);
            einnahmen += guthaben;
            gesamt = einnahme2(betrag, steuern, gesamt, guthaben, profit);
            printf("\nGezahlte Steuern: %.2lf Euro", gesamt);
            printf("\nGuthaben: %.2lf Euro", guthaben);
            einnahmen = betrag - gesamt;
            geseinnahmen = geseinnahmen + einnahmen;
            gesamtsteuern += gesamt;
        }
        else if (eingabe == 'k')
        {
                ++kostencounter;
            if (betrag > guthaben)
                {
                    guthaben = koste(betrag, guthaben);
                    printf("\nGuthaben: %.2lf Euro", guthaben);
                   --kostencounter;
                }
            else
            {
                guthaben = koste(betrag, guthaben);
                printf("\nGuthaben: %.2lf Euro", guthaben);
                gesausgaben += betrag;
            }
        }
    }
        printf("\nRestguthaben: %.2lf Euro", guthaben);
        if (ecount == 0)
        {
        printf("\n%d Einnahmen mit durchschnittlichem Wert %.2lf Euro", ecount, geseinnahmen);
        }
        else
        {
        printf("\n%d Einnahmen mit durchschnittlichem Wert %.2lf Euro", ecount, geseinnahmen / ecount);
        }
        if (kostencounter == 0)
        {
        printf("\n%d Ausgaben mit durchschnittlichem Wert %.2lf Euro", kostencounter, gesausgaben);
        }
        else
        {
        printf("\n%d Ausgaben mit durchschnittlichem Wert %.2lf Euro", kostencounter, gesausgaben / kostencounter);
        }
    printf("\nGezahlte Steuern: %.2lf Euro", gesamtsteuern);
    return 0;
}

double steuerfrei(double a, double b, double c)
{
    c = a + b;
    return c;
}

double einnahme(double betrag, double steuern, double gesamt, double guthaben, double profit)
{
if (betrag > 200)
{
    steuern = 0 + 3 + 30;
    gesamt = betrag;
    betrag -= 200;
    betrag *= 0.4;
    steuern += betrag;
    profit = gesamt - steuern;
    profit += guthaben;
    return profit;
}

else if (betrag > 50 && betrag <= 200)
{
    steuern = 3;
    gesamt = betrag;
    betrag -= 50;
    betrag *= 0.2;
    steuern += betrag;
    profit = gesamt - steuern;
    profit += guthaben;
    return profit;
}

else if (betrag > 20 && betrag <= 50)
{
    steuern = 0;
    gesamt = betrag;
    betrag -= 20;
    betrag *= 0.1;
    steuern += betrag;
    profit = gesamt - steuern;
    profit += guthaben;
    return profit;
}

else if (betrag <= 20)
{
    steuern = 0;
    gesamt = betrag;
    steuern += betrag;
    profit = gesamt;
    profit += guthaben;
    return profit;
}
    return 0;
}


double einnahme2(double betrag, double steuern, double gesamt, double guthaben, double profit)
{
if (betrag > 200)
{
    steuern = 0 + 3 + 30;
    gesamt = betrag;
    betrag -= 200;
    betrag *= 0.4;
    steuern += betrag;
    profit = gesamt - steuern;
    profit += guthaben;
    gesamt = steuern;
    return gesamt;
}

else if (betrag > 50 && betrag <= 200)
{
    steuern = 3;
    gesamt = betrag;
    betrag -= 50;
    betrag *= 0.2;
    steuern += betrag;
    profit = gesamt - steuern;
    profit += guthaben;
    gesamt = steuern;
    return gesamt;
}
else if (betrag > 20 && betrag <= 50)
{
    steuern = 0;
    gesamt = betrag;
    betrag -= 20;
    betrag *= 0.1;
    steuern += betrag;
    profit = gesamt - steuern;
    profit += guthaben;
    gesamt = steuern;
    return gesamt;
}

else if (betrag <= 20)
{
    steuern = 0;
    gesamt = steuern;
    return gesamt;
}
    return 0;
}

double koste(double kosten, double guthaben)
{
    if (kosten > guthaben)
    {
        printf("\nDiese Kosten koennen nicht bezahlt werden.");
        return guthaben;
    }
    else if (guthaben > kosten)
    {
        guthaben = guthaben - kosten;
        return guthaben;
    }
    return 0;
}
