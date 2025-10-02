#include "Login_Service.h"
#include "User_Repository.h"   
#include "User_Entity.h"
#include "Application.h"
#include<iostream>
#include <stdexcept>
#include"Time_Strings.h"

LoginService::LoginService(Application* application)
    : m_application(application), m_userRepo(application->GetUserRepository()) {}

 int LoginService::generateUserId()
    {
        auto users = m_userRepo->getAll();
        int maxId = 0;
        for (auto &u : users)
        {
            if (u.getId() > maxId)
                maxId = u.getId();
        }
        return maxId + 1;
    }




std::unique_ptr<User> LoginService::Register(std::string username, std::string password)
{
   
    auto users = m_userRepo->getAll();
    for (auto &u : users)
    {
        if (u.getUsername() == username)
        {
            throw std::runtime_error("Username already exist");
        }
    }
    
auto now = std::chrono::system_clock::now();
std::string str = std::format("{:%Y-%m-%d %H:%M:%S}", now);

    User* newUser = new User(generateUserId(),username, password,0.0, str);
     m_userRepo->AddUser(*newUser); //take object 
}


std::unique_ptr<User> LoginService::Login(const std::string& username, const std::string& password) {
    auto user = m_userRepo->GetByName(username);


    if (user && (user->getPassword() == password)) {
                  std::cout<<"password passed";

        return user;
    }
   return nullptr;
}

