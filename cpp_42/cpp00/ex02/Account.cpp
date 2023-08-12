/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuikim <yuikim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 15:06:05 by yuikim            #+#    #+#             */
/*   Updated: 2023/08/01 15:06:06 by yuikim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <ctime>
#include <iostream>
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts() {
	return Account::_nbAccounts;
}

int Account::getTotalAmount() {
	return Account::_totalAmount;
}

int Account::getNbDeposits() {
	return Account::_totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return Account::_totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits:" << _totalNbDeposits
		<< ";withdrawals:" << _totalNbWithdrawals << "\n";
}

void Account::_displayTimestamp(void) {
    time_t    now;
    char    buffer[16];

    time(&now);
    strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", localtime(&now));
	std::cout << "[" << buffer << "]";
}

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	
	std::cout << " index:" << _accountIndex
			<< ";amount:" << _amount
			<< ";created" << "\n";
}

Account::~Account() {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << "\n";
}

void Account::makeDeposit(int deposit) {
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index" << _accountIndex 
		<< ";p_amount:" << _amount - deposit
		<< ";depsoit:" << deposit
		<< ";amount: " << _amount
		<< ";nb_deposits" << _nbDeposits << "\n";
}

bool Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";p_amount:" << _amount;
	if (checkAmount() - withdrawal >= 0) {
		_amount-= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ";withdrawal:" << withdrawal
			<< ";amount:" << _amount
			<< ";nb_withdrawals:" << _nbWithdrawals << "\n";
		return true;
	}
	std::cout << ";withdrawal:refused" << "\n";
	return false;
}

int Account::checkAmount(void) const{
	return _amount;
}

void Account::displayStatus(void) const{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals << "\n";
}