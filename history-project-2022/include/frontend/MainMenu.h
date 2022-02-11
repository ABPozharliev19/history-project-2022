#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "StartMenu.h"
#include "HelpMenu.h"
#include "ExitMenu.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ENTER 0x0d

int activeItem = 0;
int mainMenuItemColor[] = { 11, 11, 11 };
char keyPressed;
bool inMainMenu = true;

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
    goToCoordinates(50, 23);    std::cout << "------------------------------------------------------------------------------------------------------------";
}

void printMainMenu() 
{
    setFullScreen();
    setColor(11);
    printLogo();
    printBorder();

    mainMenuItemColor[0] = 11;
    mainMenuItemColor[1] = 11;
    mainMenuItemColor[2] = 11;

    mainMenuItemColor[activeItem] = 14;

    goToCoordinates(95, 15); setColor(mainMenuItemColor[0]); std::cout << " Start ";
    goToCoordinates(95, 16); setColor(mainMenuItemColor[1]); std::cout << " Help ";
    goToCoordinates(95, 17); setColor(mainMenuItemColor[2]); std::cout << " Exit ";
}

void processMainMenuInput(char keyPressed) 
{
    switch (keyPressed) 
    {
        case(KEY_UP):
            activeItem = (activeItem + 3) % 4;
            break;

        case(KEY_DOWN):
            activeItem = (activeItem + 1) % 4;
            break;

        case(KEY_ESC):
            inMainMenu = false;
            break;

        case(KEY_ENTER):
            switch (activeItem)
            {
                case(0):
                    printStart();
                    break;

                case(1):
                    printHelp();
                    break;

                case(2):
                    printExit();
                    break;

                default:
                    break;
            }
            break;

        default:
            break;
    }
}

void mainMenu()
{
    setCursor(false);
    inMainMenu = true;

    while (inMainMenu)
    {
        printMainMenu();

        keyPressed = _getch();

        processMainMenuInput(keyPressed);
    }

    printExit();
    setCursor(true);
    setColor(15);
}