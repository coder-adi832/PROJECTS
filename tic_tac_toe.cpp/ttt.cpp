#include <iostream>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int gameover = 1;

void genrate_matrix()
{
    std::string s = "                                                                                 ";
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
void input()
{
    if (kbhit())
    {
        char ch = getch();
        if (ch == 'x')
        {
            gameover = 0;
        }
    }
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
                input();
                Sleep(500);
            }
        std::cout << "Do you want to play more(y/n) : ";
        std::cin >> ch;
    } while (ch == 'y');
}