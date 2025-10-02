#include "User_Csv_Repository.h"
#include <iostream>

#include <filesystem>
#include <fstream>

UserCsvRepository::UserCsvRepository(const std::string &path) : m_filePath(path)
{
    m_csvFile = CSVReader::ReadFile(m_filePath);
}

User UserCsvRepository::GetById(int id)
{
    for (size_t i = 0; i < m_csvFile.GetNumberOfRows(); i++)
    {
        CSVRow &row = m_csvFile[i];
        if (std::stoi(row[COLUMN_ID]) == id)
        {
            return User(
                std::stoi(row[COLUMN_ID]),
                row[COLUMN_USERNAME],
                row[COLUMN_PASSWORD],
                std::stod(row[COLUMN_BALANCE]),
                row[COLUMN_CREATED]);
        }
    }
    throw std::runtime_error("User not found");
}

std::unique_ptr<User> UserCsvRepository::GetByName(const std::string &name)
{
    for (size_t i = 0; i < m_csvFile.GetNumberOfRows(); i++)
    {
        CSVRow &row = m_csvFile[i];
        if (row[COLUMN_USERNAME] == name)
        {
            return std::make_unique<User>(
                std::stoi(row[COLUMN_ID]),
                row[COLUMN_USERNAME],
                row[COLUMN_PASSWORD],
                std::stod(row[COLUMN_BALANCE]),
                row[COLUMN_CREATED]);
        }
    }

    return nullptr;
}




User UserCsvRepository::AddUser(const User &newUser)
{
    CSVRow row;
    row.InsertValue(COLUMN_ID, std::to_string(newUser.getId()));
    row.InsertValue(COLUMN_USERNAME, newUser.getUsername());
    row.InsertValue(COLUMN_PASSWORD, newUser.getPassword());
    row.InsertValue(COLUMN_BALANCE, std::to_string(newUser.getBalance()));
    row.InsertValue(COLUMN_CREATED, newUser.getCreatedAt());

    m_csvFile.AppendRow(row);
    Sync();
    return newUser;
}

void UserCsvRepository::Update(int id, const User &updateUser)
{
    std::string idd = COLUMN_USERNAME;
    std::string username = COLUMN_USERNAME;
    std::string balance = COLUMN_BALANCE;
    std::string Password = COLUMN_PASSWORD;
    std::string date = COLUMN_CREATED;
    for (size_t i = 0; i < m_csvFile.GetNumberOfRows(); i++)
    {

        CSVRow &row = m_csvFile[i]; // not const reference
        if (std::stoi(row[COLUMN_ID]) == id)
        {   
            row[idd] = updateUser.getId();
            row[username] = updateUser.getUsername();
            row[Password] = updateUser.getPassword();
            row[balance] = std::to_string(updateUser.getBalance());
            row[date] = updateUser.getCreatedAt();
            Sync();
            
        }
    }
    throw std::runtime_error("User not found for update");
}

void UserCsvRepository::DeleteById(int id)
{
    for (size_t i = 0; i < m_csvFile.GetNumberOfRows(); i++)
    {
        CSVRow &row = m_csvFile[i];
        if (std::stoi(row[COLUMN_ID]) == id)
        {
            m_csvFile.DeleteRow(i);
            Sync();
            return;
        }
    }
    throw std::runtime_error("User not found for deletion");
}

std::vector<User> UserCsvRepository::getAll()
{
    std::vector<User> users;
    for (size_t i = 0; i < m_csvFile.GetNumberOfRows(); i++)
    {
        CSVRow &row = m_csvFile[i];
        users.push_back(User(
            std::stoi(row[COLUMN_ID]),
            row[COLUMN_USERNAME],
            row[COLUMN_PASSWORD],
            std::stod(row[COLUMN_BALANCE]),
            row[COLUMN_CREATED]));
    }
    return users;
}

void UserCsvRepository::Sync()
{
    try
    {
        CSVWriter::WriteFile(m_filePath, m_csvFile);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving CSV file: " << e.what() << std::endl;
        throw;
    }
}
