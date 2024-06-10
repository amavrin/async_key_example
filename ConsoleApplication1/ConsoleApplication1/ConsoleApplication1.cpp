#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

const int ARROW = 224;
const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;

const int center_x = 60;
const int center_y = 15;

const int stat_x = 100;
const int stat_y = 25;

void put_symb(int x, int y)
{
    static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    static int count = 0;
    std::cout.flush();
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(hOut, coord);
    _putch('*');
    count++;
    coord = { (SHORT)stat_x, (SHORT)stat_y };
    SetConsoleCursorPosition(hOut, coord);
    cout << count;
    SetConsoleCursorPosition(hOut, coord);
}

void draw()
{
    bool move = false;
    int x = center_x;
    int y = center_y;
    put_symb(x, y);
    while (true)
    {
        bool pressed = _kbhit();
        if (pressed)
        {
            int key = _getch();
            // cout << "key " << key << endl;
            if (key == ARROW)
            {
                move = true;
                continue;
            }
            if (!move) continue;
            switch (key)
            {
            case UP:
                y--;
                break;
            case DOWN:
                y++;
                break;
            case LEFT:
                x--;
                break;
            case RIGHT:
                x++;
                break;
            default:
                // cout << "unknown key";
                ;
            }
            put_symb(x, y);
        }
        Sleep(50);
    }
}

int main()
{
    draw();
}