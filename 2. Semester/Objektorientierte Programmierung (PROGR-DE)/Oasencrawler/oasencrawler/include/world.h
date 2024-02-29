#ifndef WORLD_H
#define WORLD_H


class world
{
    public:
        world();
        void spielfeld(int charreihe, int charzeile, int prevcharreihe, int prevcharzeile);
        void setstartposition(); //setter
        int getcharrow() const; //getter
        int getcharcols() const; //getter
        int getprevcharrow() const; //getter
        int getprevcharcols() const; //getter
        int getrow() const; //getter
        int getcols() const; //getter
        void setfield(); //setter

    private:
        //spielfeld
        static const int row = 5;
        static const int cols = 5;
        char field[row][cols];

        //character position
        int charreihe;
        int charzeile;
        int prevcharreihe;
        int prevcharzeile;

        //Felder haben bestimmte Wahrscheinlichkeiten
        //Leere Felder 1-4
        int emptyposition;
        //Gefahren Felder 5-8
        int dangerposition;
        //Brunnen Felder 9
        int wellposition;
        //Relikte Felder 10
        int reliktposition;


};

#endif // WORLD_H
