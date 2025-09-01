#include "Account.hpp"
# include <iostream>

// 4
// static and non-static in class
// constractor and deconstractor
// const member function
// #pragma once: it prevents duplicate definitions.

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

Account::Account(int initial_deposit)
{
    _accountIndex = _nbAccounts;
    _amount = initial_deposit;
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += _amount;

    _displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			<< "amount:" << _amount << ';'
			<< "created" << std::endl;
}

void displayAccountsInfos()
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ';'
			<< "total:" << Account::getTotalAmount() << ';'
			<< "deposits:" << Account::getNbDeposits() << ';'
			<< "withdrawals:" << Account::getNbWithdrawals()
			<< std::endl;
}

// [19920104_091532] index:5; //
// p_amount:0; //
// deposit:23;
// amount:23;
// nb_deposits:1
void	Account::makeDeposit(int deposit) // << in
{
	int	p_amount;

	p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	// is the p_amount = deposit
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			<< "p_amount:" << p_amount << ';'
			<< "deposit:" << deposit << ';'
			<< "amount:" << _amount << ';'
			<< "nb_deposits" << _nbDeposits
			<< std::endl;
}

// [19920104_091532] index:4;p_amount:1321;withdrawal:76
// amount:1245;nb_withdrawals:1
// [19920104_091532] index:5;p_amount:23;withdrawal:refused
bool	Account::makeWithdrawal(int withdrawal) // >> out
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			<< "p_amount:" << _amount << ';'
			<< "withdrawal:";
	if (withdrawal > _amount)
		return (std::cout << "refused" << std::endl ,false);

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << withdrawal << ';'
			<< "amount:" << _amount
			<< "nb_withdrawals" << _nbWithdrawals
			<< std::endl;
	
	return (true);
}
int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	// working on it
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
	<< "amount:" << _amount << ';'
	<< "closed" << std::endl;
}

// 42 + 54 + 957 + 432 1234 + 0 + 754 + 16576

int main()
{
    // Account::_displayTimestamp();
}