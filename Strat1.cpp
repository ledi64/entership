#include <iostream>
#include <string>

using namespace std;

void strat_gothrew()
{
    int x, y;
    x = 1;
    y = 1;

    while(y <= 10)
    {
        while (x <= 10)
        {
            cout << "X-Koordinate:  ";
            cout << x << endl;
            cout << "Y-Koordinate:  ";
            cout << y << endl << endl;

            x++;
        }
        //cout << "Check" << endl << endl;
        y++;
        x = 1;
    }

}



int main()
{
    strat_gothrew();

    return 0;
}
