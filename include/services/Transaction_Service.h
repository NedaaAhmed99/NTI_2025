#pragma once
#include "User_Repository.h"
#include "Transaction_Repository.h"
#include "User_Entity.h"
#include "Transaction_Entity.h"
#include "Transaction_Csv_Repository.h"
#include "Time_Strings.h"
#include <vector>
#include <stdexcept>

class TransactionService
{
private:
    UserRepository *userRepo;
    TransactionRepository *transactionRepo;

public:
    TransactionService(UserRepository *uRepo, TransactionRepository *tRepo)
        : userRepo(uRepo), transactionRepo(tRepo) {}
    void Deposit(int userId, double amount)
    {
        if (amount <= 0)
            throw std::runtime_error("Amount must be positive");

        User user = userRepo->GetById(userId);
        user.setBalance(user.getBalance() + amount);
        userRepo->Update(userId, user);

        int txId = transactionRepo->getAll().size() + 1;
        auto now = std::chrono::system_clock::now();
        std::string str = std::format("{:%Y-%m-%d %H:%M:%S}", now);

        Transaction tx(txId, userId, userId, amount, str);
        transactionRepo->Insert(tx);
    }

    void Withdrawal(int userId, double amount)
    {
        if (amount <= 0)
            throw std::runtime_error("Amount must be positive");

        User user = userRepo->GetById(userId);
        if (user.getBalance() < amount)
            throw std::runtime_error("Insufficient balance");

        user.setBalance(user.getBalance() - amount);
        userRepo->Update(userId, user);

        int txId = transactionRepo->getAll().size() + 1;
        auto now = std::chrono::system_clock::now();
        std::string str = std::format("{:%Y-%m-%d %H:%M:%S}", now);

        Transaction tx(txId, userId, userId, amount, str);
        transactionRepo->Insert(tx);
    }

    void Transfer(int fromUserId, int toUserId, double amount)
    {
        if (amount <= 0)
            throw std::runtime_error("Amount must be positive");

        User fromUser = userRepo->GetById(fromUserId);
        User toUser = userRepo->GetById(toUserId);

        if (fromUser.getBalance() < amount)
            throw std::runtime_error("Insufficient balance");

        fromUser.setBalance(fromUser.getBalance() - amount);
        toUser.setBalance(toUser.getBalance() + amount);

        userRepo->Update(fromUserId, fromUser);
        userRepo->Update(toUserId, toUser);

        int txId = transactionRepo->getAll().size() + 1;
       
        auto now = std::chrono::system_clock::now();
        std::string str = std::format("{:%Y-%m-%d %H:%M:%S}", now);

        Transaction tx(txId, fromUserId, toUserId, amount, str);
        transactionRepo->Insert(tx);
    }

    std::vector<Transaction> GetUserTransactions(int userId)
    {
        return transactionRepo->GetUserTransactions(userId);
    }
};
