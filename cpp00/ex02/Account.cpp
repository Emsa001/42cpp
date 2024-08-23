/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: escura <escura@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:51:51 by escura            #+#    #+#             */
/*   Updated: 2024/07/06 16:43:56 by escura           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
    _amount = initial_deposit;
    _totalAmount += _amount;
    _accountIndex = _nbAccounts++; 
    _nbDeposits = 0;
    _nbWithdrawals = 0;

    _displayTimestamp();
    std::cout 
        << " index:" << _accountIndex 
        << ";amount:" << checkAmount()
        << ";created" 
        << std::endl;
}

Account::~Account() {
    _displayTimestamp();
    std::cout 
        << " index:" << _accountIndex 
        << ";amount:" << checkAmount() 
        << ";closed" 
        << std::endl;
    
    _nbAccounts--;
}

void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout 
        << " index:" << _accountIndex
        << ";p_amount:" << checkAmount()
        << ";deposit:" << deposit
        << ";amount:" << (_amount += deposit)
        << ";nb_deposits:" << (_nbDeposits += 1)
        << std::endl;
    
    _totalAmount += deposit;
    _totalNbDeposits++;
}

bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout 
        << " index:" << _accountIndex
        << ";p_amount:" << checkAmount();

    if(checkAmount() < withdrawal){
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }

    std::cout 
        << ";withdrawal:" << withdrawal
        << ";amount:" << (_amount -= withdrawal)
        << ";nb_withdrawals:" << (_nbWithdrawals += 1)
        << std::endl;
    
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    return true;
}

void Account::displayAccountsInfos(){
    _displayTimestamp();
    std::cout 
        << " accounts:" << getNbAccounts() 
        << ";total:" << getTotalAmount() 
        << ";deposits:" << getNbDeposits() 
        << ";withdrawals:" << getNbWithdrawals() 
        << std::endl;
}

void Account::displayStatus() const {
    _displayTimestamp();
    std::cout 
        << " index:" << _accountIndex 
        << ";amount:" << checkAmount() 
        << ";deposits:" << _nbDeposits 
        << ";withdrawals:" << _nbWithdrawals 
        << std::endl;
}

void Account::_displayTimestamp(void) {
    std::time_t t = std::time(NULL);
    std::tm* now = std::localtime(&t);

    std::stringstream ss;

    ss << (now->tm_year + 1900);
    if (now->tm_mon + 1 < 10) ss << '0';
    ss << (now->tm_mon + 1);
    if (now->tm_mday < 10) ss << '0';
    ss << now->tm_mday;
    
    ss << '_';
    
    if (now->tm_hour < 10) ss << '0';
    ss << now->tm_hour;
    if (now->tm_min < 10) ss << '0';
    ss << now->tm_min;
    if (now->tm_sec < 10) ss << '0';
    ss << now->tm_sec;

    std::cout << "[" << ss.str() << "]";
}

int Account::checkAmount() const {
    return _amount;
}

int Account::getNbAccounts() {
    return _nbAccounts;
}

int Account::getTotalAmount() {
    return _totalAmount;
}

int Account::getNbDeposits() {
    return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
    return _totalNbWithdrawals;
}
