#include <iostream>
#include <windows.h>
int main()
{
    while (1)
    {
        if (GetAsyncKeyState(VK_LBUTTON))
            std::cout << "Take your finger off the mouse\n";
        Sleep(20);
        if (!GetAsyncKeyState(VK_LBUTTON))
            std::cout << "Place your finger on the mouse\n";
        Sleep(20);
    }
    return 0;
}