#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int x, y, w, z, c=1;

int gameover = 1;
int move = 0;
std::string s = "          1  2  3                    4  5  6                    7  8  9           ";
void genrate_matrix()
{

    int k = 0;
    for (int i = 0; i < 11; i++)
    {
        std::cout << "\t\t\t";
        if (i == 3 || i == 7)
        {
            std::cout << "- - - | - - - | - - -";
        }
        else
            for (int j = 0; j <= 20; j++)
            {
                if (j == 6 || j == 14)
                {
                    std::cout << "|";
                }
                else if (j % 2 == 0)
                {
                    std::cout << s[k++];
                }
                else
                {
                    std::cout << " ";
                }
            }
        std::cout << std::endl;
    }
}
void get_pos(){
    while (c > 0 && gameover)
    {
        
        // system("cls");
        mouse_event(MOUSEEVENTF_MOVE, x, y, w, z);
        POINT pt;
        GetCursorPos(&pt);
        x = pt.x;
        y = pt.y;
         if (GetAsyncKeyState(VK_LBUTTON))
         {
            if(x>=500&&x<=553&&y>=768&&y<=824){
                std::cout<<"player ";
                return;
            }
            else if(x>=562&&x<=624&&y>=768&&y<=824){
                std::cout<<"player ";
                return;
            }
            else if(x>=634&&x<=700&&y>=768&&y<=824){
                std::cout<<"player ";
                return;
            }
         }
        // std::cout << x << "," << y << std::endl;
        Sleep(100);
        x = 0;
        y = 0;
        if (kbhit())
    {
        char ch = getch();
        if (ch == 'x')
        {
            gameover = 0;
        }
    }
    }
}
void input(int player)
{
    std::cout << "Player " << player << " move ";
    if (kbhit())
    {
        char ch = getch();
        if (ch == 'x')
        {
            gameover = 0;
        }
    }

    

    get_pos();
}
int main()
{
    char ch = 'y';
    do
    {
        std::cout << "\t\tMENU\n1. Player v/s Player\n2. Player v/s Computer\n\n\tSelect your option : ";
        int t;
        std ::cin >> t;
        if (t == 1)
            while (gameover)
            {
                system("cls");
                genrate_matrix();
                if (move % 2)
                    input(2); // palyer two move
                else
                    input(1); // player one move
                Sleep(500);
            }
        std::cout << "\n\nDo you want to play more(y/n) : ";
        std::cin >> ch;
    } while (ch == 'y');
}