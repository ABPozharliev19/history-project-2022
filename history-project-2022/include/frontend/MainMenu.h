#pragma once

#include <iostream>
#include <Windows.h>

void setColor(int color)
{
    if (STD_OUTPUT_HANDLE) 
    {
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

void setFullScreen() 
{
    SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
}

void printLogo()
{
    setColor(11);
    goToCoordinates(22, 7);     std::cout << "____    ____  ___   ____    ____ ____    ____  __        ______   .__   __.";
    goToCoordinates(22, 8);     std::cout << "\\   \\  /   / /   \\  \\   \\  /   / \\   \\  /   / |  |      /  __  \\  |  \\ |  |";
    goToCoordinates(22, 9);     std::cout << " \\   \\/   / /  ^  \\  \\   \\/   /   \\   \\/   /  |  |     |  |  |  | |   \\|  |";
    goToCoordinates(22, 10);    std::cout << "  \\      / /  /_\\  \\  \\      /     \\_    _/   |  |     |  |  |  | |  . `  |";
    goToCoordinates(22, 11);    std::cout << "   \\    / /  _____  \\  \\    /        |  |     |  `----.|  `--'  | |  |\\   |";
    goToCoordinates(22, 12);    std::cout << "    \\__/ /__/     \\__\\  \\__/         |__|     |_______| \\______/  |__| \\__|";
}