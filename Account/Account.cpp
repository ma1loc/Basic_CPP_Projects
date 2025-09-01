#include "Account.hpp"
# include <iostream>

// 4
// static and non-static in class
// constractor and deconstractor

void Account::_displayTimestamp(void)
{
    std::cout << "[19920104_091532] " << std::endl;
}

int Account::getNbAccounts(void)
{
    return (Account::_nbAccounts);
}

int Account::getTotalAmount(void)
{
    return (Account::_totalAmount);
}

int Account::getNbDeposits(void)
{
    return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
    return (Account::_totalNbWithdrawals);
}

// void displayAccountsInfos()
// {}

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += _amount;

    _displayTimestamp();
}

int main()
{
    // Account::_displayTimestamp();
}