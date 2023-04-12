/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoel <yoel@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:21:43 by yoel              #+#    #+#             */
/*   Updated: 2023/04/12 13:57:43 by yoel             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp(void)
{
	time_t t = time(0);
	struct tm * now = localtime( & t );

	std::cout << '[' << (now->tm_year + 1900)
	<< std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
	<< std::setw(2) << std::setfill('0') << now->tm_mday
	<< '_'
	<< std::setw(2) << std::setfill('0') << now->tm_hour
	<< std::setw(2) << std::setfill('0') << now->tm_min
	<< std::setw(2) << std::setfill('0') << now->tm_sec << "] ";
	// std::cout << "[19920104_091532] ";
}

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_nbAccounts++;
	_totalAmount += _amount;
	// _totalNbDeposits = _nbDeposits = 0;
	// _totalNbWithdrawals = _nbWithdrawals = 0;
	_accountIndex = _nbAccounts - 1;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" 
			  << _amount << ";" << "created\n";
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";" << "amount:" 
			  << _amount << ";" << "closed\n";
}

int Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";"
			  << "total:" << _totalAmount << ";"
			  << "deposits:" << _totalNbDeposits << ";"
			  << "withdrawals:" << _totalNbWithdrawals << "\n";
}

void Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";"
			  << "deposit:" << deposit << ";";
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << _amount << ";"
			  << "nb_deposits:" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "p_amount:" << _amount << ";" << "withdrawal:";
	if (withdrawal > _amount)
		return (std::cout << "refused\n", false);
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << withdrawal << ";"
			  << "amount:" << _amount << ";"
			  << "nb_withdrawals:" << _nbWithdrawals << "\n";
	return (true);
}

int	 Account::checkAmount( void ) const
{
	return (_amount);
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";"
			  << "amount:" << _amount << ";"
			  << "deposits:" << _nbDeposits << ";"
			  << "withdrawals:" << _nbWithdrawals << "\n";
}