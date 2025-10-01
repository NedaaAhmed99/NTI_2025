#include "Application.h"
#include "User_Repository.h"
#include "Transaction_Repository.h"
#include "User_Csv_Repository.h"
#include "Transaction_Csv_Repository.h"
#include "Login_Service.h"
#include "Transaction_Service.h"
#include "Menu_Manager.h"
#include "User_Entity.h"
#include"Menu.h"

Application::Application(const std::string &usersFile,
                         const std::string &transactionsFile)
    : m_currentUser(nullptr)
{
    m_userRepository = std::make_unique<UserCsvRepository>(usersFile);
    m_transactionRepository = std::make_unique<TransactionCsvRepository>(transactionsFile);

    m_loginService = std::make_unique<LoginService>(this);
    m_transactionService = std::make_unique<TransactionService>(
        m_userRepository.get(),m_transactionRepository.get());

    m_menuManager = std::make_unique<MenuManager>(this, new Welcome_menu(nullptr));

}





Application::~Application() = default;

void Application::Run()
{
    m_menuManager->Run();
}

// getters
UserRepository *Application::GetUserRepository() { return m_userRepository.get(); }
TransactionRepository *Application::GetTransactionRepository() { return m_transactionRepository.get(); }
LoginService *Application::GetLoginService() { return m_loginService.get(); }
TransactionService *Application::GetTransactionService() { return m_transactionService.get(); }
MenuManager *Application::GetMenuManager() { return m_menuManager.get(); }

// user management
User *Application::GetCurrentUser() { return m_currentUser.get(); }

void Application::SetCurrentUser(std::unique_ptr<User> user)
{
    m_currentUser = std::move(user);
}
