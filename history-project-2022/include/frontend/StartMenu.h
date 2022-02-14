#pragma once

#include <iostream>
#include <Windows.h>
#include <conio.h>

#include "FrontEnd.h"
#include "MainMenu.h"
#include "AllEvents.h"
#include "CreateEvent.h"
#include "UpdateEvent.h"
#include "SearchEvent.h"
#include "DeleteEvent.h"

int activeItemStart = 0;
int startMenuItemColor[] = { 11, 11, 11, 11, 11 };
char keyPressedStart;
bool inStartMenu = true;

void mainMenu();

void printStartMenu()
{
    setColor(11);
    printLogo();
    printBorder();
    printSoldiers();

    startMenuItemColor[0] = 11;
    startMenuItemColor[1] = 11;
    startMenuItemColor[2] = 11;
    startMenuItemColor[3] = 11;
    startMenuItemColor[4] = 11;

    startMenuItemColor[activeItemStart] = 14;

    goToCoordinates(95, 15); setColor(startMenuItemColor[0]); std::cout << " Show all events ";
    goToCoordinates(95, 16); setColor(startMenuItemColor[1]); std::cout << " Create event ";
    goToCoordinates(95, 17); setColor(startMenuItemColor[2]); std::cout << " Update event ";
    goToCoordinates(95, 18); setColor(startMenuItemColor[3]); std::cout << " Search event ";
    goToCoordinates(95, 19); setColor(startMenuItemColor[4]); std::cout << " Delete event ";
}

void processStartMenuInput(char keyPressedStart)
{
    switch (keyPressedStart)
    {
    case(KEY_UP):
        activeItemStart = (activeItemStart + 4) % 5;
        break;

    case(KEY_DOWN):
        activeItemStart = (activeItemStart + 1) % 5;
        break;

    case(KEY_ESC):
        inStartMenu = false;
        break;

    case(KEY_ENTER):
        switch (activeItemStart)
        {
        case(0):
            printAllEvents();
            break;

        case(1):
            printCreateEvent();
            break;

        case(2):
            printUpdateEvent();
            break;

        case(3):
            printSearchEvent();
            break;

        case(4):
            printDeleteEvent();
            break;

        default:
            break;
        }
        break;

    default:
        break;
    }
}

void startMenu()
{
    system("CLS");
    inStartMenu = true;

    while (inStartMenu)
    {
        printStartMenu();

        keyPressedStart = _getch();

        processStartMenuInput(keyPressedStart);
    }
    
    system("CLS");
    mainMenu();
}