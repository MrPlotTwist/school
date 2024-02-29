#include <stdio.h>
#include <stdlib.h>

void Test_1();
void Test_2();
void Test_3();
void Test_4();
void Test_5();
void Test_6();

int encode(int h, int m);
int read();
int hours(int t);
int minutes(int t);
int add(int t1, int t2);
void print(int t);
int total_minutes(int t);


int main() {
    /* Input */

    /* List of all available tests */
    void (*tests[])() = { Test_1, Test_2, Test_3, Test_4, Test_5, Test_6 };
    int num_of_tests = (int)(sizeof(tests) / sizeof(void (*)()));

    /* Read test number */
    printf("Test #: ");
    scanf("%d", &num);

    /* Check valid range */
    if (num >= 1 && num <= num_of_tests) {
        /* Call the selected test */
        printf("Executing Test_%d.\n", num);
        tests[num - 1]();
    } else {
        /* Print error */
        printf("Invalid test number!");
    }

    return 0;
}

void Test_1()
{
    int h, m;
    printf("h: ");
    scanf("%d", &h);
    printf("m: ");
    scanf("%d", &m);
    printf("encoded: %04d", encode(h, m));
}

void Test_2()
{
    printf("read: %04d", read());
}

void Test_3() {
    int t;
    printf("hours: %02d\n", hours(t = read()));
    printf("minutes: %02d\n", minutes(t));
}

void Test_4() {
    print(read());
}

void Test_5() {
    int t1 = read();
    int t2 = read();
    printf("add: ");
    print(t1);
    printf(" + ");
    print(t2);
    printf(" = ");
    print(add(t1, t2));
}

void Test_6() {
    int t = read();
    printf("read: %d\n", total_minutes(t));
}

int encode(h,m)
{
    h = 100* h;
    m = 1* m;
    return h + m;
}

int read()
{
    int h, m;
    printf("hours: ");
    scanf("%d", &h);
    printf("minutes: ");
    scanf("%d", &m);
    h = 100* h;
    m = 1* m;
    return h + m;

}

int hours(t)
{
    t /= 100;
    return t;
}

int minutes(t)
{
    t = t % 100;
    return t;
}

int add(t1, t2)
{
    int ges;
    ges = t1 + t2;
    if (ges > 2400)
    {
        ges = ges - 2400;
    }
    if ((t1 % 100) + (t2 % 100) > 60)
    {
        ges = (ges - 60) + 100;
    }
    return ges;
}

void print(int t)
{
    int h, m;
    h = hours(t);
    m = minutes(t);
    printf("%02d:%02d", h, m);
}

int total_minutes(t)
{
    int h, m;
    h = hours(t);
    m = minutes(t);
    m = h * 60 + m;
    return m;
}

