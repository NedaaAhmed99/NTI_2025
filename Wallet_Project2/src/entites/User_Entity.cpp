#include "User_Entity.h"
#include <string>
#include <iostream>

User::User(int id, std::string name, std::string password, double balance, std::string date)
{
   m_id = id;
   m_username = name;
   m_balance = balance;
   m_password = password;
}
User::~User()
{
}
int User::getId() const
{
   return m_id;
}
std::string User::getUsername() const
{
   return m_username;
}
std::string User::getPassword() const
{
   return m_password;
}

double User::getBalance() const
{
   return m_balance;
}
std::string User::getCreatedAt() const
{
   return m_date;
}

// Setter
void User::setUsername(std::string name)
{
   m_username = name;
}
void User::setPassword(std::string pass)
{
   m_password = pass;
}
void User::setBalance(double b)
{
   m_balance = b;
}