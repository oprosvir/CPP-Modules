/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oprosvir <oprosvir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 10:59:24 by oprosvir          #+#    #+#             */
/*   Updated: 2025/05/07 13:41:32 by oprosvir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

// static member initialization
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// getters
int	Account::getNbAccounts(void) { return _nbAccounts; }
int	Account::getTotalAmount(void) { return _totalAmount; }
int	Account::getNbDeposits(void) { return _totalNbDeposits; }
int	Account::getNbWithdrawals(void) { return _totalNbWithdrawals; }
int	Account::checkAmount(void) const { return _amount; }

//  displays a timestamp of the current date and time followed by a space
//	format : [YEARMONTHDAY_HOURMINSEC]
void Account::_displayTimestamp( void )
{
    std::time_t currentTime = std::time(NULL);
    std::tm* timeInfo = std::localtime(&currentTime);
    char buffer[19];
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeInfo);
    std::cout << buffer;
}

// constructor
Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), _amount(initial_deposit),
	  _nbDeposits(0), _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:"   << _accountIndex
			  << ";amount:" << _amount
			  << ";created" << std::endl;
}

// destructor
Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:"   << _accountIndex
			  << ";amount:" << _amount
			  << ";closed"  << std::endl;
}

// add requested amount to account
// print account info before and after deposit
void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";deposit:" << deposit
			  << ";amount:" << _amount
			  << ";nb_deposits:" << _nbDeposits
			  << std::endl;
}

// subtract req amount from the account, if possible (not negative)
// print account information before and after the withdrawal
bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";p_amount:" << _amount;

	if (withdrawal > _amount) {
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << ";withdrawal:" << withdrawal
			  << ";amount:" << _amount
			  << ";nb_withdrawals:" << _nbWithdrawals
			  << std::endl;
	return true;
}

// displays account information for this instance of account
void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
			  << ";amount:" << _amount
			  << ";deposits:" << _nbDeposits
			  << ";withdrawals:" << _nbWithdrawals
			  << std::endl;
}

// displays information for all instances
void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts
			  << ";total:" << _totalAmount
			  << ";deposits:" << _totalNbDeposits
			  << ";withdrawals:" << _totalNbWithdrawals
			  << std::endl;
}
