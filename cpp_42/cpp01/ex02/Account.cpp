#include "Account.hpp"
#include <ctime>
#include <iostream>
int	_nbAccounts;
int	_totalAmount;
int	_totalNbDeposits;
int	_totalNbWithdrawals;

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
	std::cout << "accounts:" << _nbAccounts
		<< ";total:" << _totalAmount
		<< ";deposits" << _totalNbDeposits
		<< ";withdrawls" << _totalNbWithdrawals << '\n';
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
			<< ";created" << '\n';
}

Account::~Account() {
	;
}

void Account::makeDeposit(int deposit) {

}

bool makeWithdrawl(int withdrawal) {

}

int Account::checkAmount(void) const{
	return _amount;
}

void Account::displayStatus(void) const{
	
}