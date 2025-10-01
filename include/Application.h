#pragma once
#include <string>
#include <memory>

// forward declarations
class User;
class UserRepository;
class TransactionRepository;
class LoginService;
class TransactionService;
class MenuManager;


class Application
{
public:
    Application(const std::string& usersFile = "./users.csv",
                const std::string& transactionsFile = "./transactions.csv");
    ~Application();

    void Run();

    UserRepository* GetUserRepository();
    TransactionRepository* GetTransactionRepository();
    LoginService* GetLoginService();
    TransactionService* GetTransactionService();

    User* GetCurrentUser();
    void SetCurrentUser(std::unique_ptr<User> user);

    MenuManager* GetMenuManager();

private:
    std::unique_ptr<UserRepository> m_userRepository;
    std::unique_ptr<TransactionRepository> m_transactionRepository;
    std::unique_ptr<LoginService> m_loginService;
    std::unique_ptr<TransactionService> m_transactionService;
    std::unique_ptr<MenuManager> m_menuManager;

    std::unique_ptr<User> m_currentUser;
};
