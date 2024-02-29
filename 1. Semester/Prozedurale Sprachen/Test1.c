#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*enum Type{
    Termin_mit_Freunden, // f
    Geschaeftlicher_Termin, // b
    Pause // p
};
struct appointment {enum Type type; int time; int duration};
//void printAppointments(struct appointment * schedule, int length);
void Test(struct appointment); */

int main()
{
    conversion[] = {{"Termin mit Freunden"}, {"Geschaeftlicher Termin"}, {"Pause"}};
    printf("%s", conversion[0]);
    return 0;
}
