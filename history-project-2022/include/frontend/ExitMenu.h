#pragma once

#include <iostream>
#include "FrontEnd.h"

void printExit()
{
    system("CLS");
    setColor(11);
    printLogo();
    printBorder();
    goToCoordinates(90, 15); setColor(14); std::cout << "Thank you for using our program.";
    goToCoordinates(95, 16); setColor(14); std::cout << "We hope you enjoyed it!\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    system("PAUSE");
    system("CLS");
}