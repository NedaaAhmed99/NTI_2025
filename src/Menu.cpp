#include "User_Repository.h"
#include "Transaction_Repository.h"
#include "Transaction_Service.h"
#include "User_Entity.h"
#include "Application.h"
#include "User_Entity.h"
#include "Application.h"
#include "Menu_Manager.h"
#include "Main_Menu.h"
#include "Menu.h"
#include <iostream>
#include <iomanip>
#include "Login_Service.h"
// ========== Login_menu ==========
Login_menu::Login_menu(MenuManager *mgr) : Menu(mgr) {}

void Login_menu::Menu_Display()
{
    int count =0, flag =0;
    
        do{
            system("clear");
                setColor(3);

    std::cout <<"\t============================================================================\n";
    std::cout << "\t=================================== LOGIN ==================================\n";
    std::cout <<"\t============================================================================\n\n\n\n";
    setColor(4);
    if(flag==1) //if username or password not correct
        std::cout << "\tInvalid Username or Password, Try Again\n";

    std::string username;
    std::string password;
    std::cout << "\tPleas, Enter Your Name: ";
        setColor(0);
    std::cin >> username;
        setColor(4);
    std::cout << "\tPleas, Enter Your Password: ";
        setColor(0);
    std::cin >> password;

    auto app = m_MenuManager->GetApp();
    auto loginserv = app->GetLoginService();
    
    auto user = loginserv->Login(username, password);
    if (user)
    {
        app->SetCurrentUser(std::move(user));
        std::cout << "\tWelcome," << app->GetCurrentUser()->getUsername() << "\n";
            flag =0;
        m_MenuManager->ChangeMenu(new Options_menu(m_MenuManager));
    
    }
    else
    {
        flag =1;
        count++;
        system("clear");
              std::cout << "\tProve Your Acount\n";

    }
}
    while(count <3 && flag ==1);
   if (count == 3)
   exit(0);

}


// ========== Welcome_menu ==========
Welcome_menu::Welcome_menu(MenuManager *mgr) : Menu(mgr) {}

void Welcome_menu::Menu_Display()
{

    system("clear");
    setColor(4);
    std::cout <<"\t====================================================================================\n";
   setColor(3);
    std::cout << R"(
        NNN    NN TTTTTTTT TTTTTTTT     WW     WW  AAAAA  LL     LL     EEEEEEE TTTTTTTT 
        NNNN   NN    TT       TT        WW     WW AA   AA LL     LL     EE         TT   
        NN NN  NN    TT       TT        WW  W  WW AAAAAAA LL     LL     EEEEE      TT
        NN  NN NN    TT       TT        WW WWW wW AA   AA LL     LL     EE         TT  
        NN   NNNN    TT    TTTTTTTT      WWW WWW  AA   AA LLLLLL LLLLLL EEEEEEE TTTTTTTT
        )";
    setColor(4);
    std::cout <<"\n\t=====================================WELCOME========================================\n";

    setColor(4);
    std::cout << "\n\tFor Login Pleas press (1)\n";
    std::cout << "\tFor Exit Pleas press press (2)\n";

    int choice = getChoice(1, 2);
    if (choice == 1)
    {
        m_MenuManager->ChangeMenu(new Login_menu(m_MenuManager));
    }
    else
    {
        std::cout << "\tThank you and let's see you again\n";
        exit(0);
    }
}

// ========== Options_menu ==========
Options_menu::Options_menu(MenuManager *mgr) : Menu(mgr) {}

void Options_menu::Menu_Display()
{
        system("clear");
        setColor(3);
    std::cout <<"\t=============================================================================\n";
    std::cout <<"\t=================================== Options =================================\n";
    std::cout <<"\t=============================================================================\n\n\n\n";
    
  
    std::cout << "\t1. Account\n";
    std::cout << "\t2. Transfer\n";
    std::cout << "\t3. Payment\n";
    std::cout << "\t4. Back\n";
    std::cout << "\t5. Exit\n";
    setColor(4);
    int choice = getChoice(1, 5);
    switch (choice)
    {
    case 1:
        m_MenuManager->ChangeMenu(new Account_menu(m_MenuManager));
        break;
    case 2:
        m_MenuManager->ChangeMenu(new Transfer_menu(m_MenuManager));
        break;
    case 3:
        m_MenuManager->ChangeMenu(new Payment_menu(m_MenuManager));
        break;
    case 4:
        m_MenuManager->GetApp()->SetCurrentUser(nullptr);
        m_MenuManager->ChangeMenu(new Welcome_menu(m_MenuManager));
        break;
    case 5:
    exit(0);
    break;
    }
}

// ========== Account_menu ==========
Account_menu::Account_menu(MenuManager *mgr) : Menu(mgr) {}

void Account_menu::Menu_Display()
{
            system("clear");
            setColor(3);
    std::cout <<"\t============================================================================\n";
    std::cout <<"\t=================================== Acount =================================\n";
    std::cout <<"\t============================================================================\n\n\n\n";
    
    std::cout << "\t1. Check Balance\n";
    std::cout << "\t2. Transaction History\n";
    std::cout << "\t3. Change Password\n";
    std::cout << "\t4. Back\n";
    std::cout << "\t5. Exit\n";


    setColor(4);
    int choice = getChoice(1, 4);
    switch (choice)
    {
    case 1:
        checkBalance();
        break;
    case 2:
        showTransactionHistory();
        break;
    case 3:
        changePassword();
        break;
    case 4:
        m_MenuManager->ChangeMenu(new Options_menu(m_MenuManager));
        break;
        case 5:
        exit(0);
         break;

    }
}

void Account_menu::checkBalance()
{
    Application *app = m_MenuManager->GetApp();
    auto user = app->GetCurrentUser();
    setColor(4);
    std::cout << "\tYour balance: " << user->getBalance() << std::endl;
}

void Account_menu::showTransactionHistory()
{
    auto app = m_MenuManager->GetApp();
    auto user = app->GetCurrentUser();
    auto transactionrepo = app->GetTransactionRepository();
    auto transactions = transactionrepo->GetUserTransactions(user->getId(), 10);
        setColor(3);
    std::cout <<"\t============================================================================\n";
    std::cout <<"\t============================= ALl Your Transacion ==========================\n";
    std::cout <<"\t============================================================================\n\n\n\n";
        setColor(4);

    for (auto &t : transactions)
    {
        std::cout << "\tID: " << t.getId()
                  << ", From: " << t.getUserId()
                  << ", To: " << t.getTargetUserId()
                  << ", Amount: " << t.getAmount()
                  << ", Time: " << t.getDate() << "\n";
    }
}

void Account_menu::changePassword()
{
        setColor(4);
    auto app = m_MenuManager->GetApp();
    auto user = app->GetCurrentUser();
    std::string newPass;
    std::cout << "\tEnter your new password: ";
    std::cin >> newPass;
    user->setPassword(newPass);
    auto userrepo = app->GetUserRepository();
    userrepo->Update(user->getId(), *user);
    std::cout << "\tPassword updated successfully.\n";
}

// ========== Transfer_menu ==========
Transfer_menu::Transfer_menu(MenuManager *mgr) : Menu(mgr) {}

void Transfer_menu::Menu_Display()
{
            system("clear");
            setColor(3);
    std::cout <<"\t============================================================================\n";
    std::cout <<"\t====================================Transfer Money==========================\n";
    std::cout <<"\t============================================================================\n\n\n\n";
        setColor(4);
    std::cout << "\t1. Transfer money\n";
    std::cout << "\t2. Back\n";

    int choice = getChoice(1, 3);
    switch (choice)
    {
    case 1:
        transferToWallet();
        break;
    case 2:
        m_MenuManager->ChangeMenu(new Options_menu(m_MenuManager));
        break;
    }
}

void Transfer_menu::transferToWallet()
{
    
    int targetId;
    double amount;
    std::cout << "\tEnter target user ID: ";
    std::cin >> targetId;
    std::cout << "\tEnter amount: ";
    std::cin >> amount;

    auto app = m_MenuManager->GetApp();
    app->GetTransactionService()->Transfer(app->GetCurrentUser()->getId(), targetId, amount);
    std::cout << "\tTransfer successful.\n";
}

// ========== Payment_menu ==========
Payment_menu::Payment_menu(MenuManager *mgr) : Menu(mgr) {}

void Payment_menu::Menu_Display()
{
            system("clear");
          setColor(3);
    std::cout <<"\t============================================================================\n";
    std::cout <<"\t======================================Payment===============================\n";
    std::cout <<"\t============================================================================\n\n\n\n";
        setColor(4);
    std::cout << "\t1. Pay Bills\n";
    std::cout << "\t2. Recharge Mobile\n";
    std::cout << "\t3. Back\n";

    int choice = getChoice(1, 3);
    switch (choice)
    {
    case 1:
        payBills();
        break;
    case 2:
        rechargeMobile();
        break;
    case 3:
        m_MenuManager->ChangeMenu(new Options_menu(m_MenuManager));
        break;
    }
}

void Payment_menu::payBills()
{
    setColor(4);
    double amount;
    std::cout << "\tEnter bill amount: ";
    std::cin >> amount;
    std::cout << "\tPaid " << amount << " for bills.\n";
}

void Payment_menu::rechargeMobile()
{
    double amount;
    std::string phone;
        setColor(4);
    std::cout << "\tEnter phone number: ";  
      setColor(0);
    std::cin >> phone;
        setColor(4);
    std::cout << "\tEnter recharge amount: ";
        setColor(0);
    std::cin >> amount;
        setColor(4);
    std::cout << "\tRecharged " << phone << " with " << amount << ".\n";
}
