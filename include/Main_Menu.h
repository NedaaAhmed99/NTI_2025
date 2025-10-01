#pragma once
#include<iostream>
class Application;
class MenuManager;

class Menu {
public:
    Menu( MenuManager* manager)
        : /*m_app(app),*/ m_MenuManager(manager) {}
    virtual ~Menu() {}

   void setColor(int color)
{
    switch (color)
    {
    case 1:
        std::cout << "\033[31m";
        break; // Red
    case 2:
        std::cout << "\033[32m";
        break; // Green
    case 3:
        std::cout << "\033[33m";
        break; // Yellow
    case 4:
        std::cout << "\033[34m";
        break; // Blue
    case 5:
        std::cout << "\033[35m";
        break; // Magenta
    case 6:
        std::cout << "\033[36m";
        break; // Cyan
    case 7:
        std::cout << "\033[37m";
        break; // White
    default:
        std::cout << "\033[0m";
        break; // Reset
    }
}

int getChoice(int min, int max)
{
    int choice;
    for (int i = 0; i < 3; i++)
    {
        std::cout << "\tEnter choice (" << min << "-" << max << "): ";
        std::cin >> choice;
        if (choice >= min && choice <= max)
            return choice;

        std::cout << "\tInvalid choice, try again!\n";
        
    }
    return -1;
}

    virtual void Menu_Display() = 0;
protected:
   // Application* m_app;
    MenuManager* m_MenuManager;
};
