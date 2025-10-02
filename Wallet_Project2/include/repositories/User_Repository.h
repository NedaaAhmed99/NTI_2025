#pragma once
#include "User_Entity.h"
#include <vector>
#include <memory>
class UserRepository
{
public:
    virtual User GetById(int id) = 0;
    virtual std::unique_ptr<User> GetByName(const std::string& name) = 0;
    virtual User AddUser(const User& newUser) = 0;
    virtual void Update(int id, const User& updateUser) = 0;
    virtual void DeleteById(int id) = 0;
    virtual std::vector<User> getAll() = 0;
    virtual void Sync() = 0;

    virtual ~UserRepository() {}

    
};
