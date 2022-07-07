#pragma once
class BankCard
{
private:

	static size_t _staticId;
	size_t _id = 0;
	string _longCode = "";
	string _password = "";
	string _cvv = 0;
	size_t _balance = 0;
	size_t _expiredMonth = 0;
	size_t _expiredYear = 0;

public:

	BankCard() = default;
	BankCard(string longCode, string password, string cvv, size_t balance, size_t expiredMonth, size_t expiredYear);

	size_t id();
	string longCode();
	string password();
	size_t balance();
	size_t expiredMonth();
	size_t expiredYear();

	void addToBalance(size_t money);
	void getCash(size_t money);

	friend ostream& operator<<(ostream& out, const BankCard& card);

};

// FIELD

size_t BankCard::_staticId = 0;

// CONSTRUCTOR
BankCard::BankCard(string longCode, string password, string cvv, size_t balance, size_t expiredMonth, size_t expiredYear)
	: _id(++_staticId), _longCode(longCode), _password(password), _cvv(cvv), _balance(balance), _expiredMonth(expiredMonth), _expiredYear(expiredYear) {}


// OPERATOR
ostream& operator<<(ostream& out, const BankCard& card)
{
	out << "Id: " << card._id << endl
		<< "Balance: " << card._balance << endl
		<< "Expired Date: " << card._expiredMonth << '/' << card._expiredYear;

	return out;
}

#pragma region GETTERS

size_t BankCard::id()
{
	return _id;
}

string BankCard::longCode()
{
	return _longCode;
}

string BankCard::password()
{
	return _password;
}

size_t BankCard::balance()
{
	return _balance;
}

size_t BankCard::expiredMonth()
{
	return _expiredMonth;
}

size_t BankCard::expiredYear()
{
	return _expiredYear;
}

#pragma endregion
