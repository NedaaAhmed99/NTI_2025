#pragma once

#include <memory>
#include <map>
#include <string>

class Application;
class Menu;


class MenuManager
{
public:
    MenuManager(Application* app,Menu* menu);

    void ChangeMenu(Menu* menu);
    void Run();
    Application* GetApp();


private:
    Application* m_app;
    
    Menu* m_currentMenu;
};
