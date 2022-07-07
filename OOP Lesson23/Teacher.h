#pragma once
class Teacher : public Person
{
private:
	vector<Group*> _groups;
	static size_t _staticId;
	string _department = "";
	size_t _salary = 0;
	BankCard _card;

public:

	Teacher() = default;
	Teacher(string name, string surname, size_t age, string department, size_t salary, BankCard card);

	void addGroup(Group* group);
	void showBalance();

	friend ostream& operator<<(ostream& out, const Teacher& t);
};
// FIELD

size_t Teacher::_staticId = 0;

// CONSTRUCTOR
Teacher::Teacher(string name, string surname, size_t age, string department, size_t salary, BankCard card)
	:Person(++_staticId,name,surname,age), _department(department), _salary(salary), _card(card) {};

// OPERATOR

ostream& operator<<(ostream& out, const Teacher& t)
{
	t.show();
	out << "Department: " << t._department << endl
		<< "Salary: " << t._salary << endl
		<< "\tCard Info\n" << t._card << endl
		<< "\n\tGroups\n";

	for (size_t i = 0; i < t._groups.size(); i++)
	{
		out << t._groups[i]->name() << endl;
	}

	return out;
}

// METHODS
void Teacher::addGroup(Group* group)
{
	if (group == nullptr)
		throw exception("Unidentified Group");

	_groups.push_back(group);
}

void Teacher::showBalance()
{
	cout << _card.balance();
}