#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "FrontEnd.h"
#include "StartMenu.h"
#include "HelpMenu.h"
#include "ExitMenu.h"

int activeItemMain = 0;
int mainMenuItemColor[] = { 11, 11, 11 };
char keyPressedMain;
bool inMainMenu = true;

void printMainMenu() 
{
    setFullScreen();
    setColor(11);
    printLogo();
    printBorder();

    mainMenuItemColor[0] = 11;
    mainMenuItemColor[1] = 11;
    mainMenuItemColor[2] = 11;

    mainMenuItemColor[activeItemMain] = 14;

    goToCoordinates(95, 15); setColor(mainMenuItemColor[0]); std::cout << " Start ";
    goToCoordinates(95, 16); setColor(mainMenuItemColor[1]); std::cout << " Help ";
    goToCoordinates(95, 17); setColor(mainMenuItemColor[2]); std::cout << " Exit ";
}

void processMainMenuInput(char keyPressedMain) 
{
    switch (keyPressedMain) 
    {
        case(KEY_UP):
            activeItemMain = (activeItemMain + 2) % 3;
            break;

        case(KEY_DOWN):
            activeItemMain = (activeItemMain + 1) % 3;
            break;

        case(KEY_ESC):
            inMainMenu = false;
            break;

        case(KEY_ENTER):
            switch (activeItemMain)
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

        keyPressedMain = _getch();

        processMainMenuInput(keyPressedMain);
    }

    printExit();
    setCursor(true);
    setColor(15);
}