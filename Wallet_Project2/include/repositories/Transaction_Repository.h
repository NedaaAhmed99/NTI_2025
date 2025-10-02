#pragma once
#include "Transaction_Entity.h"
class TransactionRepository
{
    public:
    virtual Transaction GetByID(int id)=0;
    virtual std::vector<Transaction> GetUserTransactions(int userId,int TransactionNum = 10)=0;
    virtual void Insert(const Transaction& transaction)=0;
    virtual void Update(int id, const Transaction& transaction)=0;
    virtual void DeleteById(int id)=0;
    virtual std::vector<Transaction> getAll()=0;
    virtual void Sync()=0;
    virtual ~TransactionRepository() {}

};  



