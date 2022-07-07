#pragma once
class Bank
{
private:

	vector<BankCard*> cards;
	string _name = "";
	string _address = "";

public:

	Bank() = default;
	Bank(string name, string address);

	void addCard(BankCard* newCard) throw(exception);
	const BankCard* getCardById(size_t id);
	void showAllCards();

	friend ostream& operator<<(ostream& out, const Bank& b);
};
// CONSTRUCTOR
Bank::Bank(string name, string address) : _name(name), _address(address) {};


// OPERATORS
ostream& operator<<(ostream& out, const Bank& b)
{
	out << "Name: " << b._name << endl
		<< "Address: " << b._address;

	return out;
}



#pragma region METHODS

void Bank::addCard(BankCard* newCard) throw(exception)
{
	if (newCard == nullptr)
		throw exception("Unidentified Card");

	cards.push_back(newCard);
}

const BankCard* Bank::getCardById(size_t id)
{
	for (size_t i = 0; i < cards.size(); i++)
	{
		if (cards[i]->id() == id)
			return cards[i];
	}

	return nullptr;
}

void Bank::showAllCards()
{
	cout << "=======CARDS=======" << endl;
	for (size_t i = 0; i < cards.size(); i++)
	{
		cout << *cards[i] << endl;
	}
}

#pragma endregion
