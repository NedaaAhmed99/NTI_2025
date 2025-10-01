#pragma once
#include <string>

class User {
private:
    int m_id;
    std::string m_username;
    std::string m_password;
    double m_balance;
    std::string m_date;

public:
    User(int id, std::string username, std::string password, double balance, std::string date);
        ~User();
   // Getters
int getId() const;
std::string getUsername() const ;
std::string getPassword() const;
double getBalance() const ;
std::string getCreatedAt() const ;
    // Setters
    void setUsername(std::string name) ;
    void setPassword(std::string pass) ;
    void setBalance(double balance) ;
};

