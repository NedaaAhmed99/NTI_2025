#pragma once
#include "User_Entity.h"
#include "Csv_Files.h"
#include"Transaction_Repository.h"
#include <string>
#include <vector>
#include <stdexcept>




class TransactionCsvRepository : public TransactionRepository
{
private:
    std::string m_filePath;
    CSVFile m_csvFile;

const std::string COLUMN_ID        = "id";
const std::string COLUMN_FROM       = "from_user_id";
const std::string COLUMN_TO         = "to_user_id";
const std::string COLUMN_AMOUNT     = "balance";
const std::string COLUMN_TIME  = "date";

public:
    TransactionCsvRepository(const std::string& filePath);

    Transaction GetByID(int id) override;
    std::vector<Transaction> GetUserTransactions(int userId, int number = 10) override;
    void Insert(const Transaction& transaction) override;
    void Update(int id, const Transaction& transaction) override;
    void DeleteById(int id) override;
    std::vector<Transaction> getAll()override;
    void Sync() override;
    virtual ~TransactionCsvRepository(){}


     
};

