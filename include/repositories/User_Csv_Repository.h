#pragma once
#include "User_Entity.h"
#include "Csv_Files.h"
#include <string>
#include <vector>
#include <stdexcept>
#include"User_Repository.h"



class UserCsvRepository : public UserRepository
{
private:
    std::string m_filePath;
    CSVFile m_csvFile;

const std::string COLUMN_ID       = "id";
const std::string COLUMN_USERNAME = "username";
const std::string COLUMN_PASSWORD = "password";
const std::string COLUMN_BALANCE  = "balance";
const std::string COLUMN_CREATED  = "created";


public:
    UserCsvRepository(const std::string& filePath);

    User GetById(int id) override;
   std::unique_ptr<User> GetByName(const std::string& name) override;
    User AddUser(const User& newUser) override;
    void Update(int id, const User& updateUser) override;
    void DeleteById(int id) override;
    std::vector<User> getAll() override;
    void Sync() override;
};
