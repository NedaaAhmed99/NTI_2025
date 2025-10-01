#include "Transaction_Csv_Repository.h"
#include <string>
#include <iostream>
#include <filesystem>
#include <fstream>

TransactionCsvRepository::TransactionCsvRepository(const std::string &filePath)
    : m_filePath(filePath)
{

    m_csvFile = CSVReader::ReadFile(m_filePath);


}

void TransactionCsvRepository::Sync()
{
    try
    {
        CSVWriter::WriteFile(m_filePath, m_csvFile);
    }
    catch (const std::exception &e)
    {
        std::cerr << "Error saving transactions CSV: " << e.what() << std::endl;
        throw;
    }
}

Transaction TransactionCsvRepository::GetByID(int id)
{

    for (size_t i = 0; i < m_csvFile.GetNumberOfRows(); i++)
    {
        CSVRow &row = m_csvFile[i];
        if (std::stoi(row[COLUMN_ID]) == id)
        {

            return Transaction{
                std::stoi(row[COLUMN_ID]),
                std::stoi(row[COLUMN_FROM]),
                std::stoi(row[COLUMN_TO]),
                std::stod(row[COLUMN_AMOUNT]),
                row[COLUMN_TIME]};
        }
    }
    throw std::runtime_error("Transaction not found");
}

std::vector<Transaction> TransactionCsvRepository::GetUserTransactions(int userId, int num)
{
    std::vector<Transaction> transactions;
    for (size_t i = 0; i < m_csvFile.GetNumberOfRows(); ++i)
    {
        CSVRow &row = m_csvFile[i];
        if (transactions.size() > num)
        {
            break;
        }

        if (std::stoi(row[COLUMN_FROM]) == userId || std::stoi(row[COLUMN_TO]) == userId)
        {
            transactions.push_back(Transaction{
                std::stoi(row[COLUMN_ID]),
                std::stoi(row[COLUMN_FROM]),
                std::stoi(row[COLUMN_TO]),
                std::stod(row[COLUMN_AMOUNT]),
                row[COLUMN_TIME]});
        }
    }
    return transactions;
}

void TransactionCsvRepository::Insert(const Transaction &transaction)
{
    CSVRow row;
    std::string id = COLUMN_ID;
    std::string From = COLUMN_FROM;
    std::string To = COLUMN_TO;
    std::string Amount = COLUMN_AMOUNT;
    std::string Time = COLUMN_TIME;

    row.InsertValue(id, std::to_string(transaction.getId()));
    row.InsertValue(From, std::to_string(transaction.getUserId()));
    row.InsertValue(To, std::to_string(transaction.getTargetUserId()));
    row.InsertValue(Amount, std::to_string(transaction.getAmount()));
    row.InsertValue(Time, transaction.getDate());

    m_csvFile.AppendRow(row);
    Sync();
}

void TransactionCsvRepository::Update(int id, const Transaction &transaction)
{

    std::string trans_id = COLUMN_ID;
    std::string amount = COLUMN_AMOUNT;
    std::string fromuser = COLUMN_FROM;
    std::string touser = COLUMN_TO;
    std::string date = COLUMN_TIME;

    auto rows = m_csvFile.GetHeaders();

    for (size_t i = 0; i < m_csvFile.GetNumberOfRows(); i++)
    {

        CSVRow &row = m_csvFile[i]; // not const reference
        if (std::stoi(row[COLUMN_ID]) == id)
        {
            row.InsertValue(COLUMN_AMOUNT, std::to_string(transaction.getAmount()));
            row.InsertValue(COLUMN_FROM, std::to_string(transaction.getUserId()));
            row.InsertValue(COLUMN_TO, std::to_string(transaction.getTargetUserId()));
            row.InsertValue(date, transaction.getDate());
            Sync();
            return;
        }
    }
    throw std::runtime_error("User not found for update");
}

void TransactionCsvRepository::DeleteById(int id)
{
    for (size_t i = 0; i < m_csvFile.GetNumberOfRows(); ++i)
    {
        CSVRow &row = m_csvFile[i];
        if (std::stoi(row[COLUMN_ID]) == id)
        {
            m_csvFile.DeleteRow(i);
            Sync();
            return;
        }
    }
    throw std::runtime_error("Transaction not found for deletion");
}

std::vector<Transaction> TransactionCsvRepository::getAll()
{
    std::vector<Transaction> transactions;
    for (size_t i = 0; i < m_csvFile.GetNumberOfRows(); ++i)
    {
        CSVRow &row = m_csvFile[i];
        transactions.push_back(Transaction(
            std::stoi(row[COLUMN_ID]),
            std::stoi(row[COLUMN_FROM]),
            std::stoi(row[COLUMN_TO]),
            std::stod(row[COLUMN_AMOUNT]),
            row[COLUMN_TIME]));
    }
    return transactions;
}