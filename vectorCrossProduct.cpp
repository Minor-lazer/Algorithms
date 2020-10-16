    #include<time.h>

    #include<stdlib.h>

    #include<iostream>

    #include<math.h>

     

    using namespace std;

    const int LOW = 0;

    const int HIGH = 10;

    int main(int argc, char **argv)

    {

        time_t seconds;

        time(&seconds);

        srand((unsigned int) seconds);

     

        int u1, u2, u3, v1, v2, v3;

        u1 = rand() % (HIGH - LOW + 1) + LOW;

        u2 = rand() % (HIGH - LOW + 1) + LOW;

        u3 = rand() % (HIGH - LOW + 1) + LOW;

        v1 = rand() % (HIGH - LOW + 1) + LOW;

        v2 = rand() % (HIGH - LOW + 1) + LOW;

        v3 = rand() % (HIGH - LOW + 1) + LOW;

     

        int uvi, uvj, uvk;

        uvi = u2 * v3 - v2 * u3;

        uvj = v1 * u3 - u1 * v3;

        uvk = u1 * v2 - v1 * u2;

     

        cout << "The cross product of the 2 vectors \n u = " << u1 << "i + " << u2

                << "j + " << u3 << "k and \n v = " << u1 << "i + " << u2 << "j + "

                << u3 << "k \n ";

        cout << "u X v : " << uvi << "i +" << uvj << "j+ " << uvk << "k ";

        return 0;

    }