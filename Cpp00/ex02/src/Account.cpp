# include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp(void)
{
	time_t	date = time(NULL);

	tm* timeNow = localtime(&date);

	char buffer[20];
	strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeNow);
	std::cout << buffer;
}

Account::Account(int initialDeposit)
{
	_amount = initialDeposit;

	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initialDeposit;
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created"
				<< std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed"
				<< std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}
void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout	<< "accounts:" << _nbAccounts << ";"
				<< "total:" << _totalAmount << ";"
				<< "deposits:" << _totalNbDeposits << ";"
				<< "withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

void	Account::displayStatus()const
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals
				<< std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount <<  ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << _amount + deposit << ";"
				<< "nb_deposits:" << _nbDeposits + 1
				<< std::endl;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (checkAmount() >= withdrawal)
	{
		std::cout	<< "index:" << _accountIndex << ";"
					<< "p_amount:" << _amount <<  ";"
					<< "withdrawal:" << withdrawal << ";"
					<< "amount:" << _amount - withdrawal << ";"
					<< "nb_withdrawals:" << _nbWithdrawals + 1
					<< std::endl;
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		return (true);
	}
	else
	{
		std::cout	<< "index:" << _accountIndex << ";"
					<< "p_amount:" << _amount <<  ";"
					<< "withdrawal:" << "refused"
					<< std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

