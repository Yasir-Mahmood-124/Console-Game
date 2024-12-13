#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
using namespace std;

//....Funtion Prototypes....
void printWorld();
void moveCar_left();
void moveCar_right();
void moveCar_up();
void moveCar_down();
void gravity();
void calculate_score();
void print_score();
char menu(char option);
void Loadmaze();
void gotoxy(int x, int y);
void clear_screen();
void gravity2();
void gravity3();
void gravity4();
void print_life();
void calculate_life();
void game_initialization();
//...Function Prototypes End...

//...Data Structure...
char world[15][50] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '#'},
    {'#', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', '#'},
    {'#', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', '.', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '.', ' ', '#'},
    {'#', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', ' ', '.', '.', ' ', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}};

//...Position of the Car....
int carX;
int carY;

//...Postion of the enemys...
int enemyX;
int enemyY;

int enemyX2;
int enemyY2;

int enemyX3;
int enemyY3;

int enemyX4;
int enemyY4;

int score;
int life;
bool win;
//...Data structure end...

//....MAIN STARTS....
main()
{
    while (true) // Loop for the Main Menu
    {
        void Loadmaze();
        char option;
        option = menu(option);

        if (option == '1')
        {
            game_initialization();
            bool game_running = true;
            system("cls");
            printWorld();

            gotoxy(carX, carY);
            cout << 'C';

            gotoxy(enemyX, enemyY);
            cout << '_';

            gotoxy(enemyX2, enemyY2);
            cout << '_';

            while (game_running) //Loop for game starting.....
            {
                Sleep(100);

                if (GetAsyncKeyState(VK_LEFT))
                {
                    moveCar_left(); //Funtion to move car left
                }

                if (GetAsyncKeyState(VK_RIGHT))
                {
                    moveCar_right(); //Funtion to move car right
                }

                if (GetAsyncKeyState(VK_UP))
                {
                    moveCar_up();  //Funtion to move car up
                }

                if (GetAsyncKeyState(VK_DOWN))
                {
                    moveCar_down(); //Funtion to move car down
                }

                //....Conditions for calculate the life....

                if (carX == enemyX && carY == enemyY)
                {
                    calculate_life();
                    if (life == 0)
                    {
                        print_life();
                        gotoxy(18, 51);
                        cout << "Game Over";
                        break;
                    }
                }

                if (carX == enemyX2 && carY == enemyY2)
                {
                    calculate_life();
                    if (life == 0)
                    {
                        print_life();
                        gotoxy(18, 51);
                        cout << "Game over.";
                        break;
                    }
                }

                if (carX == enemyX3 && carY == enemyY3)
                {
                    calculate_life();
                    if (life == 0)
                    {
                        print_life();
                        gotoxy(18, 51);
                        cout << "Game over.";
                        break;
                    }
                }

                if (carX == enemyX4 && carY == enemyY4)
                {
                    calculate_life();
                    if (life == 0)
                    {
                        print_life();
                        gotoxy(18, 51);
                        cout << "Game over.";
                        break;
                    }
                }

                gravity();
                gravity2();
                gravity3();
                gravity4();
                print_score();
                print_life();
                cout << endl;

                if (score == 100)
                {
                    win = true;
                    cout << "--------------------------------------------" << endl;
                    cout << "---     Congrats You Won the Game        ---" << endl;
                    cout << "--------------------------------------------" << endl;
                    break;
                }
            }
        }

        else if (option == '2')
        {
            cout << "1). Move car in all four directions with the help of arrow keys." << endl;
            cout << "2). keep the car away from the hurdles or enemies." << endl;
            cout << "3). Eat the food pallets placed in the gaming world" << endl;
            cout << "4). Eat 200 food pallets to win the game." << endl;
            clear_screen();
        }

        else if (option == '3')
        {
            cout << "THANKS FOR PLAYING THE GAME" << endl;
            break;
        }

        else
        {
            cout<<"Invalid Option."<<endl;
            cout<<"Please select the right option."<<endl;
        }
    }
} //....Main Ends...

//...Funtions Implementation...

void printWorld()
{
    for (int a = 0; a < 15; a++)
    {

        for (int b = 0; b < 50; b++)
        {
            cout << world[a][b];
        }
        cout << endl;
    }
}

void moveCar_left()
{
    if (world[carX][carY - 1] == ' ' || world[carX][carY - 1] == '.')
    {
        gotoxy(carX, carY);
        cout << ' ';

        if (world[carX][carY - 1] == '.')
        {
            calculate_score();
        }

        carY = carY - 1;
        gotoxy(carX, carY);
        cout << 'C';
    }
}

void moveCar_right()
{
    if (world[carX][carY + 1] == ' ' || world[carX][carY + 1] == '.')
    {
        gotoxy(carX, carY);
        cout << ' ';

        if (world[carX][carY + 1] == '.')
        {
            calculate_score();
        }

        carY = carY + 1;
        gotoxy(carX, carY);
        cout << 'C';
    }
}

void moveCar_up()
{
    if (world[carX - 1][carY] == ' ' || world[carX - 1][carY] == '.')
    {
        gotoxy(carX, carY);
        cout << ' ';

        if (world[carX - 1][carY] == '.')
        {
            calculate_score();
        }

        carX = carX - 1;
        gotoxy(carX, carY);
        cout << 'C';
    }
}

void moveCar_down()
{
    if (world[carX + 1][carY] == ' ' || world[carX + 1][carY] == '.')
    {
        gotoxy(carX, carY);
        cout << ' ';

        if (world[carX + 1][carY] == '.')
        {
            calculate_score();
        }

        carX = carX + 1;
        gotoxy(carX, carY);
        cout << 'C';
    }
}

void gravity()
{
    if (world[enemyX][enemyY] == ' ' || world[enemyX][enemyY] == '.')
    {
        gotoxy(enemyX, enemyY);
        cout << '.';
        enemyX = enemyX + 1;
        gotoxy(enemyX, enemyY);
        cout << '_';
    }
    if (world[enemyX + 1][enemyY] == '#')
    {
        gotoxy(enemyX, enemyY);
        cout << ' ';
        enemyX = 1;
        enemyY = 10;
    }
}

void gravity2()
{
    if (world[enemyX2][enemyY2] == ' ' || world[enemyX2][enemyY2] == '.')
    {
        gotoxy(enemyX2, enemyY2);
        cout << '.';
        enemyX2 = enemyX2 + 1;
        gotoxy(enemyX2, enemyY2);
        cout << '_';
    }
    if (world[enemyX2 + 1][enemyY2] == '#')
    {
        gotoxy(enemyX2, enemyY2);
        cout << ' ';
        enemyX2 = 1;
        enemyY2 = 20;
    }
}

void gravity3()
{
    if (world[enemyX3][enemyY3] == ' ' || world[enemyX3][enemyY3] == '.')
    {
        
        gotoxy(enemyX3, enemyY3);
        cout << '.';
        enemyX3 = enemyX3 + 1;
        gotoxy(enemyX3, enemyY3);
        cout << '_';
    }
    if (world[enemyX3 + 1][enemyY3] == '#')
    {
        gotoxy(enemyX3, enemyY3);
        cout << ' ';
        enemyX3 = 1;
        enemyY3 = 30;
    }
}

void gravity4()
{
    if (world[enemyX4][enemyY4] == ' ' || world[enemyX4][enemyY4] == '.')
    {
        gotoxy(enemyX4, enemyY4);
        cout << '.';
        enemyX4 = enemyX4 + 1;
        gotoxy(enemyX4, enemyY4);
        cout << '_';
    }
    if (world[enemyX4 + 1][enemyY4] == '#')
    {
        gotoxy(enemyX4, enemyY4);
        cout << ' ';
        enemyX4 = 1;
        enemyY4 = 40;
    }
}



void calculate_score()
{

    score = score + 1;
}

void print_score()
{
    gotoxy(16, 51);
    cout << "Score:" << score;
}

void calculate_life()
{
    life = life - 1;
}

void print_life()
{
    gotoxy(17, 51);
    cout << "Life:" << life << endl;
}

char menu(char option)
{
    
    
    cout << "          MAIN MENU:       " << endl;
    cout << "           1) Play Game.    " << endl;
    cout << "           2) Instructions. " << endl;
    cout << "           3) Exit.         " << endl;
    cout << "Enter your option:";
    cin >> option;
    return option;
}

void game_initialization()
{
    carX = 13;
    carY = 24;
    enemyX = 1;
    enemyY = 10;
    enemyX2 = 1;
    enemyY2 = 20;
    enemyX3 = 1;
    enemyY3 = 30;
    enemyX4 = 1;
    enemyY4 = 40;
    score = 0;
    life = 3;
    win = false;
}

void Loadmaze()
{
    string line;
    fstream newfile;
    newfile.open("car.txt", ios::in);
    for (int i = 0; i < 15; i++)
    {
        getline(newfile, line);
        for (int j = 0; j < 50; j++)
        {
            world[i][j] = line[j];
        }
    }
    newfile.close();
}


void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = y;
    coordinates.Y = x;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void clear_screen()
{
    cout << "Press any key to continue..." << endl;
    getch();
    system("CLS");
}
