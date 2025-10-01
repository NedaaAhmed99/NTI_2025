#include "Transaction_Entity.h"

Transaction::Transaction(int id, int sourceUserId, int desUserId, double amount, std::string date)
    : m_id(id), m_userId(sourceUserId), m_targetuserId(desUserId), m_amount(amount), m_date(date) {}

Transaction::~Transaction() {}

int Transaction::getId() const
{
  return m_id;
}

int Transaction::getUserId() const
{
  return m_userId;
}

int Transaction::getTargetUserId() const
{
  return m_targetuserId;
}

double Transaction::getAmount() const
{
  return m_amount;
}

std::string Transaction::getDate() const
{

  return m_date;
}

void Transaction::setFromUserId(int userid)
{
  m_userId = userid;
}
void Transaction::setToUserId(int targetid)
{
  m_targetuserId = targetid;
}
void Transaction::setAmount(double amount)
{
  m_amount = amount;
}
void Transaction::setTimestamp(const std::string &date)
{
  m_date = date;
}