/*std::string m_userName;
    std::string m_userPass;*/
#pragma once
#include <iostream>
#include <string>
#include <limits>
#include "User_Entity.h"
#include"Application.h"
#include"Main_Menu.h"

class MenuManager;
class Application;
class UserRepository;
class TransactionRepository;
class TransactionService;
class User;

// ===== Derived Menus =====
class Welcome_menu : public Menu {
public:
    Welcome_menu(MenuManager* mgr);
    void Menu_Display() override;
};

class Login_menu : public Menu {
    
public:
    Login_menu(MenuManager* mgr);
    void Menu_Display() override;
};

class Options_menu : public Menu {
public:
    Options_menu(MenuManager* mgr);
    void Menu_Display() override;

};

class Account_menu : public Menu {
public:
    Account_menu(MenuManager* mgr);
    void Menu_Display() override;
private:
    void checkBalance();
    void showTransactionHistory();
    void changePassword();
};

class Transfer_menu : public Menu {
public:
    Transfer_menu(MenuManager* mgr);
    void Menu_Display() override;
private:
    void transferToWallet();
    void transferToBank();
};

class Payment_menu : public Menu {
public:
    Payment_menu(MenuManager* mgr);
    void Menu_Display() override;
private:
    void payBills();
    void rechargeMobile();
};













/*#pragma once

#include <iostream>
#include <string>
#include"Application.h"
class MenuManager;
class Menu {
protected:
    MenuManager* m_MenuManager;

public:
    Menu(MenuManager* mgr);
    virtual ~Menu();
    void setColor(int color);
    virtual void Menu_Display() = 0; // Pure virtual
};


// ============ Derived menus ============
class Welcome_menu : public Menu {
public:
    Welcome_menu(MenuManager* mgr);
    void Menu_Display() override;
};

class Login_menu : public Menu {
    std::string m_user_name;
    std::string m_user_pass;
public:
    Login_menu(MenuManager* mgr);
    void Menu_Display() override;
};

class Options_menu : public Menu {
public:
    Options_menu(MenuManager* mgr);
    void Menu_Display() override;
};


//------------------Acount_ menu--------------
class Account_menu : public Menu
{
public:

    Account_menu(MenuManager* mgr);
    void Menu_Display() override;
private:
    void checkBalance();
    void showTransactionHistory();
    void changePassword();
};
//--------------------------------Transfe_menu----------------
class Transfer_menu: public Menu
 {
public:
    public:
    Transfer_menu(MenuManager* mgr);
    void Menu_Display() override;
private:
    void transferToWallet();
    void transferToBank();
};
//--------------Payment menu---------------
class Payment_menu : public Menu
{
public:
    Payment_menu(MenuManager* mgr);
    void Menu_Display() override;
private:
    void payBills();
    void rechargeMobile();
};
//------------Cash menu--------------
class Cash_menu:public Menu
 {
public:
   Cash_menu(MenuManager* mgr);
    void Menu_Display() override;
private:
    void cashIn();
    void cashOut();
};
*/