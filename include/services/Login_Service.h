#pragma once
#include <memory>
#include <string>

class Application;
class UserRepository;
class User;

class LoginService {
private:
    UserRepository* m_userRepo;
    Application* m_application;

    int generateUserId();

public:
    LoginService(Application* application);

    std::unique_ptr<User> Register(const std::string username, const std::string password);
    std::unique_ptr<User> Login(const std::string& username, const std::string& password);
};
