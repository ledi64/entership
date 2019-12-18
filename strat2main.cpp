#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int main()
{
    int field[10][10] = {0};

    int i, j;

    for(i=0; i<10; i++)
    {
        for(j=0; j<10; j++)
        {
            printf("%d ", field[i][j]);
        }
        printf("\n");
    }

    int x, y;

    x = 0;
    y = 0;

    int shots = 0;

    while (shots < 100)
    {
        if(field[x][y] == 0)
        {
            field[x][y] = 1;
            shots++;
        }
        else
        {
            x = rand() % 10;
            y = rand() % 10;
        }

        cout << "Shots: " << shots << endl;
    }

    cout << endl << "Feld abgeklappert" << endl << endl;

    int a, b;

    for(a=0; a<10; a++)
    {
        for(b=0; b<10; b++)
        {
            cout << field[a][b] << " ";
        }
        cout << endl;
    }

    return 0;
}
