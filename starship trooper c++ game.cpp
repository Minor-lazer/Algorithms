#include<iostream>
#include<conio.h>
#include<ctime>
using namespace std;
#define SCREEN_HEIGHT 40
#define SCREEN_WIDTH 50

using namespace std;

//INITIAL DECLARATIONS
bool run = true;
int shipLeft = SCREEN_WIDTH/2, shipMid = shipLeft+1, shipRight = shipMid+1, shipTop = shipMid;
int missile_X[100];
int missile_Y[100];
int score = 0;
int kills = 0;
int alien_X[100];
int alien_Y[100];

int index = 0;

//FUNCTION DECLARATIONS

bool iNjinMissile(int,int);
bool iNjinAlien(int,int);
void removeAlienNMissile(int,int);

//UTILITY FUNCTIONS
void printScreen()
{

    cout<<"\n\n\n\t\t\tSCORE : "<<(score/10)+kills<<endl;;
    cout<<"\t\t\tKILLS : "<<kills<<endl<<endl;
	for(int i=0;i<SCREEN_HEIGHT;++i)
	{
		cout<<"#";

		for(int j=0;j<SCREEN_WIDTH-2;++j)
		{
			if(i==0 || i==SCREEN_HEIGHT-1)
			{
				cout<<"#";
			}

			else if(i==SCREEN_HEIGHT-2 && (j==shipLeft || j==shipMid || j==shipRight))
			{
				cout<<"^";
				if(iNjinAlien(i,j))
                {
                    run = false;
                }
			}

			else if(i==SCREEN_HEIGHT-3 && j==shipMid)
			{
				cout<<"^";
			}

			else if(iNjinAlien(i,j))
            {
                cout<<"O";
                if(iNjinMissile(i,j))
                {
                    removeAlienNMissile(i,j);
                    kills++;
                }

                continue;
            }

			else if(iNjinMissile(i,j))
			{
				cout<<"*";
			}

			else
			{
				cout<<" ";
			}
		}

		cout<<"#\n";
	}

}

void removeAlienNMissile(int i, int j)
{
    for(int k=0;k<100;++k)
    {
        if(alien_X[k]==j && alien_Y[k]==i)
        {
            alien_Y[k]=-10;
        }

        if(missile_X[k]==j && missile_Y[k]==i)
        {
            missile_Y[k]= -SCREEN_HEIGHT;
        }
    }
}


bool iNjinAlien(int i, int j)
{
    for(int k=0;k<100;++k)
    {
		if(j==alien_X[k] &&  i==alien_Y[k])
        {
            return true;
        }

	}

	return false;
}
void moveMissileUp()
{
		for(int k=0;k<100;++k)
		{
			missile_Y[k]--;
		}
}

bool iNjinMissile(int i, int j)
{
    for(int k=0;k<100;++k)
	{
		if(j==missile_X[k] &&  i==missile_Y[k])
        {
            return true;
        }

	}

	return false;

}



void moveShootShip(char c)
{
	switch(c)
	{
		case 'a' :
		{
			shipLeft--;
			shipMid--;
			shipRight--;
			shipTop--;
		}

		break;

		case 'A' :
		{
			shipLeft--;
			shipMid--;
			shipRight--;
			shipTop--;
		}
		break;

		case 'd' :
		{
			shipLeft++;
			shipMid++;
			shipRight++;
			shipTop++;
		}

		break;

		case 'D' :
		{
			shipLeft++;
			shipMid++;
			shipRight++;
			shipTop++;
		}

		break;

		case ' ' :
        {

            missile_Y[index] = SCREEN_HEIGHT-4;
            missile_X[index] = shipTop;
            index++;
        }
         break;

	}
}

void moveAliensDown()
{
   for(int k=0;k<100;++k)
    {
        alien_Y[k]++;
    }

}

void setAlienPos()
{
    for(int k=0;k<100;++k)
    {
        alien_X[k] = rand()%(SCREEN_WIDTH-2)+1;
        alien_Y[k] = (k*3)*-1;
    }
}

void instructions()
{
    cout<<"\n\n\n\t\t\t           WELCOME TO STARSHIP TROOPERS";
    cout<<"\n\n\n\t\t\t1. TURN ON FULL SCREEN";
    cout<<"\n\n\n\t\t\t2. DO NOT COLLIDE WITH ALIEN SHIP";
    cout<<"\n\n\n\t\t\t3. PRESS SPACEBAR TO SHOOT";
    cout<<"\n\n\n\t\t\t4.PRESS 'a' TO MOVE LEFT AND 'd' TO MOVE RIGHT"<<endl;
    system("pause");
    system("cls");

}

//DRIVER METHOD
int main(void)
{
    srand(time(0));
    setAlienPos();
    instructions();

	while(run)
	{
	    score++;

	    if(alien_Y[87]==SCREEN_HEIGHT-1)
        {
            setAlienPos();
        }
		printScreen();

		if(kbhit())
		{
			moveShootShip(getch());
		}

		moveMissileUp();
		moveAliensDown();
		system("cls");
	}


    cout<<"\n\n\n\t\t\tYOU COLLIDED WITH AN ALIEN SHIP, YOU LOSE";
    cout<<"\n\n\n\t\t\tTOTAL SCORE : "<<score;
    cout<<"\n\n\n\t\t\tTOTAL KILLS : "<<kills<<"       ";

    char c;
    cin>>c;

	return 0;
}
