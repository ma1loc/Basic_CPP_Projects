#include "Account.hpp"
# include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
    std::cout << "[19920104_091532] ";
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

void Account::displayAccountsInfos()
{
	Account::_displayTimestamp();

	std::cout << "accounts:" << Account::getNbAccounts() << ';'
			<< "total:" << Account::getTotalAmount() << ';'
			<< "deposits:" << Account::getNbDeposits() << ';'
			<< "withdrawals:" << Account::getNbWithdrawals()
			<< std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	p_amount;

	p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			<< "p_amount:" << p_amount << ';'
			<< "deposit:" << deposit << ';'
			<< "amount:" << _amount << ';'
			<< "nb_deposits:" << _nbDeposits
			<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
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
			<< "amount:" << _amount << ';'
			<< "nb_withdrawals:" << _nbWithdrawals
			<< std::endl;
	
	return (true);
}
int		Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			<< "amount:" << _amount << ';'
			<< "deposits:" << _nbDeposits << ';'
			<< "withdrawals:" << _nbWithdrawals
			<< std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ';'
			<< "amount:" << _amount << ';'
			<< "closed" << std::endl;
}
