#pragma once

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ENTER 0x0d

HistoryEvents eventManager;

void setColor(int color)
{
    if (STD_OUTPUT_HANDLE) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }
}

void goToCoordinates(int x, int y)
{
    COORD position;
    position.X = x;
    position.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void setCursor(bool visible)
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = visible;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void setFullScreen()
{
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void printLogo()
{
    goToCoordinates(68, 7);     std::cout << "____    ____  ___   ____    ____ ____    ____  __        ______   .__   __.";
    goToCoordinates(68, 8);     std::cout << "\\   \\  /   / /   \\  \\   \\  /   / \\   \\  /   / |  |      /  __  \\  |  \\ |  |";
    goToCoordinates(68, 9);     std::cout << " \\   \\/   / /  ^  \\  \\   \\/   /   \\   \\/   /  |  |     |  |  |  | |   \\|  |";
    goToCoordinates(68, 10);    std::cout << "  \\      / /  /_\\  \\  \\      /     \\_    _/   |  |     |  |  |  | |  . `  |";
    goToCoordinates(68, 11);    std::cout << "   \\    / /  _____  \\  \\    /        |  |     |  `----.|  `--'  | |  |\\   |";
    goToCoordinates(68, 12);    std::cout << "    \\__/ /__/     \\__\\  \\__/         |__|     |_______| \\______/  |__| \\__|";
}

void printBorder()
{
    goToCoordinates(50, 5);    std::cout << "------------------------------------------------------------------------------------------------------------";
    goToCoordinates(50, 6);    std::cout << "|";    goToCoordinates(157, 6);    std::cout << "|";
    goToCoordinates(50, 7);    std::cout << "|";    goToCoordinates(157, 7);    std::cout << "|";
    goToCoordinates(50, 8);    std::cout << "|";    goToCoordinates(157, 8);    std::cout << "|";
    goToCoordinates(50, 9);    std::cout << "|";    goToCoordinates(157, 9);    std::cout << "|";
    goToCoordinates(50, 10);    std::cout << "|";    goToCoordinates(157, 10);    std::cout << "|";
    goToCoordinates(50, 11);    std::cout << "|";    goToCoordinates(157, 11);    std::cout << "|";
    goToCoordinates(50, 12);    std::cout << "|";    goToCoordinates(157, 12);    std::cout << "|";
    goToCoordinates(50, 13);    std::cout << "|";    goToCoordinates(157, 13);    std::cout << "|";
    goToCoordinates(50, 14);    std::cout << "|";    goToCoordinates(157, 14);    std::cout << "|";
    goToCoordinates(50, 15);    std::cout << "|";    goToCoordinates(157, 15);    std::cout << "|";
    goToCoordinates(50, 16);    std::cout << "|";    goToCoordinates(157, 16);    std::cout << "|";
    goToCoordinates(50, 17);    std::cout << "|";    goToCoordinates(157, 17);    std::cout << "|";
    goToCoordinates(50, 18);    std::cout << "|";    goToCoordinates(157, 18);    std::cout << "|";
    goToCoordinates(50, 19);    std::cout << "|";    goToCoordinates(157, 19);    std::cout << "|";
    goToCoordinates(50, 20);    std::cout << "|";    goToCoordinates(157, 20);    std::cout << "|";
    goToCoordinates(50, 21);    std::cout << "|";    goToCoordinates(157, 21);    std::cout << "|";
    goToCoordinates(50, 22);    std::cout << "|";    goToCoordinates(157, 22);    std::cout << "|";
    goToCoordinates(50, 23);    std::cout << "|";    goToCoordinates(157, 23);    std::cout << "|";
    goToCoordinates(50, 24);    std::cout << "|";    goToCoordinates(157, 24);    std::cout << "|";
    goToCoordinates(50, 25);    std::cout << "|";    goToCoordinates(157, 25);    std::cout << "|";
    goToCoordinates(50, 26);    std::cout << "|";    goToCoordinates(157, 26);    std::cout << "|";
    goToCoordinates(50, 27);    std::cout << "|";    goToCoordinates(157, 27);    std::cout << "|";
    goToCoordinates(50, 28);    std::cout << "|";    goToCoordinates(157, 28);    std::cout << "|";
    goToCoordinates(50, 29);    std::cout << "|";    goToCoordinates(157, 29);    std::cout << "|";
    goToCoordinates(50, 30);    std::cout << "------------------------------------------------------------------------------------------------------------";
}

void printSoldiers()
{
    goToCoordinates(10, 8);    std::cout << "   |\\                |\\";                   goToCoordinates(167, 8);    std::cout << "   |\\                |\\";
    goToCoordinates(10, 9);    std::cout << "   || .---.          || .---.";               goToCoordinates(167, 9);    std::cout << "   || .---.          || .---.";
    goToCoordinates(10, 10);    std::cout << "   ||/_____\\         ||/_____\\";           goToCoordinates(167, 10);    std::cout << "   ||/_____\\         ||/_____\\";
    goToCoordinates(10, 11);    std::cout << "   ||( '.' )         ||( '.' )";             goToCoordinates(167, 11);    std::cout << "   ||( '.' )         ||( '.' )";
    goToCoordinates(10, 12);    std::cout << "   || \\_-_/_         || \\_-_/_";           goToCoordinates(167, 12);    std::cout << "   || \\_-_/_         || \\_-_/_";
    goToCoordinates(10, 13);    std::cout << "   :-\"`'V'/ / -.       :-\"`'V'//-.";       goToCoordinates(167, 13);    std::cout << "   :-\"`'V'/ / -.       :-\"`'V'//-.";
    goToCoordinates(10, 14);    std::cout << "  / ,   |// , `\\    / ,   |// , `\\";       goToCoordinates(167, 14);    std::cout << "  / ,   |// , `\\    / ,   |// , `\\";
    goToCoordinates(10, 15);    std::cout << " / /|Ll //Ll|| |   / /|Ll //Ll|| |";         goToCoordinates(167, 15);    std::cout << " / /|Ll //Ll|| |   / /|Ll //Ll|| |";
    goToCoordinates(10, 16);    std::cout << "/_/||__//   || |  /_/||__//   || |";         goToCoordinates(167, 16);    std::cout << "/_/||__//   || |  /_/||__//   || |";
    goToCoordinates(10, 17);    std::cout << "\\ \\/---|[]==|| |  \\ \\/---|[]==|| |";     goToCoordinates(167, 17);    std::cout << "\\ \\/---|[]==|| |  \\ \\/---|[]==|| |";
    goToCoordinates(10, 18);    std::cout << " \\/\\__/ |   \\| |   \\/\\__/ |   \\| |";   goToCoordinates(167, 18);    std::cout << " \\/\\__/ |   \\| |   \\/\\__/ |   \\| |";
    goToCoordinates(10, 19);    std::cout << " /\\|_   | Ll_\\ |   /|/_   | Ll_\\ |";      goToCoordinates(167, 19);    std::cout << " /\\|_   | Ll_\\ |   /|/_   | Ll_\\ |";
    goToCoordinates(10, 20);    std::cout << " `--|`^\"\"\"^`||_|   `--|`^\"\"\"^`||_|";   goToCoordinates(167, 20);    std::cout << " `--|`^\"\"\"^`||_|   `--|`^\"\"\"^`||_|";
    goToCoordinates(10, 21);    std::cout << "    |   |   ||/       |   |   ||/";          goToCoordinates(167, 21);    std::cout << "    |   |   ||/       |   |   ||/";
    goToCoordinates(10, 22);    std::cout << "    |   |   |         |   |   |";            goToCoordinates(167, 22);    std::cout << "    |   |   |         |   |   |";
    goToCoordinates(10, 23);    std::cout << "    |   |   |         |   |   |";            goToCoordinates(167, 23);    std::cout << "    |   |   |         |   |   |";
    goToCoordinates(10, 24);    std::cout << "    |   |   |         |   |   |";            goToCoordinates(167, 24);    std::cout << "    |   |   |         |   |   |";
    goToCoordinates(10, 25);    std::cout << "    L___l___J         L___l___J";            goToCoordinates(167, 25);    std::cout << "    L___l___J         L___l___J";
    goToCoordinates(10, 26);    std::cout << "     |_ | _|           |_ | _|";             goToCoordinates(167, 26);    std::cout << "     |_ | _|           |_ | _|";
    goToCoordinates(10, 27);    std::cout << "    (___|___)         (___|___)";            goToCoordinates(167, 27);    std::cout << "    (___|___)         (___|___)";
    goToCoordinates(10, 28);    std::cout << "     ^^^ ^^^           ^^^ ^^^";             goToCoordinates(167, 28);    std::cout << "     ^^^ ^^^           ^^^ ^^^";

}