// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <algorithm>
#include <functional>
#include <vector>

void	subjectTest(void)
{
	int const	amounts[] = {42, 54, 957, 432, 1234, 0, 754, 16576};
	int const	d[] = {5, 765, 564, 2, 87, 23, 9, 20};
	int const	w[] = {321, 34, 657, 4, 76, 275, 657, 7654};

	typedef std::vector<Account::t> accounts_t;
	typedef std::vector<int> ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;
	size_t const amounts_size(sizeof(amounts) / sizeof(int));
	accounts_t accounts(amounts, amounts + amounts_size);
	accounts_t::iterator acc_begin = accounts.begin();
	accounts_t::iterator acc_end = accounts.end();
	size_t const d_size(sizeof(d) / sizeof(int));
	ints_t deposits(d, d + d_size);
	ints_t::iterator dep_begin = deposits.begin();
	ints_t::iterator dep_end = deposits.end();
	size_t const w_size(sizeof(w) / sizeof(int));
	ints_t withdrawals(w, w + w_size);
	ints_t::iterator wit_begin = withdrawals.begin();
	ints_t::iterator wit_end = withdrawals.end();
	Account::displayAccountsInfos();
	std::for_each(acc_begin, acc_end,
		std::mem_fun_ref(&Account::displayStatus));
	for (acc_int_t it(acc_begin, dep_begin); it.first != acc_end
		&& it.second != dep_end; ++(it.first), ++(it.second))
	{
		(*(it.first)).makeDeposit(*(it.second));
	}
	Account::displayAccountsInfos();
	std::for_each(acc_begin, acc_end,
		std::mem_fun_ref(&Account::displayStatus));
	for (acc_int_t it(acc_begin, wit_begin); it.first != acc_end
		&& it.second != wit_end; ++(it.first), ++(it.second))
	{
		(*(it.first)).makeWithdrawal(*(it.second));
	}
	Account::displayAccountsInfos();
	std::for_each(acc_begin, acc_end,
		std::mem_fun_ref(&Account::displayStatus));
}

void myTest_1(void)
{
	Account spongebob(1000);
	Account patric(2000);
	std::cout << std::endl;

	Account::displayAccountsInfos();
	std::cout << std::endl;

	spongebob.makeDeposit(500);
	patric.makeDeposit(1000);
	std::cout << std::endl;

	spongebob.displayStatus();
	patric.displayStatus();
	std::cout << std::endl;

	patric.makeWithdrawal(500);
	patric.displayStatus();
	std::cout << std::endl;

	spongebob.makeWithdrawal(1500);
	spongebob.makeDeposit(1);
	std::cout << std::endl;

	Account::displayAccountsInfos();
	std::cout << std::endl;
}

void myTest_2(void)
{
	Account spongebob(2147483647);
	Account patric(-2147483648);
	std::cout << std::endl;

	Account::displayAccountsInfos();
	std::cout << std::endl;

	spongebob.makeDeposit(1);
	patric.makeWithdrawal(1);
	std::cout << std::endl;
}

int	main(void)
{
	subjectTest();
	// myTest_1();
	// myTest_2();
	return (0);
}

// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
