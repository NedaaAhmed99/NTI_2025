#include "Menu_Manager.h"
#include "Application.h"
#include "Main_Menu.h"
#include <iostream>

MenuManager::MenuManager(Application* app, Menu* menu): m_app(app), m_currentMenu(menu)
{
   /*m_currentMenu = new Menu(this, m_app);*/
}

void MenuManager::ChangeMenu(Menu* menu)
{
    if (m_currentMenu) {
        delete m_currentMenu;
    }
    m_currentMenu = menu;
}

void MenuManager::Run()
{
    
    while (true && m_currentMenu)
    {
        m_currentMenu->Menu_Display();
    }

    throw std::runtime_error("there is no current menu");

}

Application* MenuManager::GetApp() { return m_app; }
