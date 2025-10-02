#pragma once
#include <string>

//enum TransactionType { DEPOSIT, WITHDRAW, TRANSFER };   I will complete it after training 
//add type in private data and so on

class Transaction {
private:
    int m_id;
    int m_userId;
    int m_targetuserId;   
    double m_amount;
    std::string m_date;

public:
    Transaction(int id, int userid, int targetid, double amount, std::string date);
~Transaction();

    // Getters
int getId() const;
int getUserId() const ;
int getTargetUserId() const ;
double getAmount() const ;
std::string getDate() const ;



    // Setters
    void setFromUserId(int userid) ;
    void setToUserId(int targetid) ;
    void setAmount(double amount);
    void setTimestamp(const std::string& date);
};

