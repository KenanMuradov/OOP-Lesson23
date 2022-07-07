#pragma once
class Student : public Person
{
private:

	static size_t _staticId;
	string _speciality = "";
	mutable short _score = 0;
	size_t _scholarship = 0;
	BankCard _card;
	
	
public:
	vector<Exam*> exams;

	Student() = default;
	Student(string name, string surname, size_t age, string speciality, size_t scholarship, BankCard card);

	string speciality() const;
	short score() const;
	size_t scholarship() const;
	BankCard card() const;
	short findScore() const;

	void showBalance();

	friend ostream& operator<<(ostream& out, const Student& s);
};
// FIELD
size_t Student::_staticId;

// CONSTRUCTOR
Student::Student(string name, string surname, size_t age, string speciality, size_t scholarship, BankCard card)
	: Person(++_staticId, name, surname, age), _speciality(speciality), _scholarship(scholarship), _card(card) {}


// OPERATOR
ostream& operator<<(ostream& out, const Student& s)
{
	s.show();
	out << "Speciality: " << s._speciality << endl
		<< "Score: " << s.findScore() << endl
		<< "Scholarship: " << s._scholarship << endl
		<< "\tCard Info\n" << s._card;

	return out;
}


#pragma region GETTERS
 
string Student::speciality() const
{
	return _speciality;
}

short Student::score() const
{
	return _score;
}

size_t Student::scholarship() const
{
	return _scholarship;
}

BankCard Student::card() const
{
	return _card;
}


#pragma endregion




// METHODS
void Student::showBalance()  
{
	cout << _card.balance();
}


short Student::findScore() const
{
	size_t sum = 0;
	for (size_t i = 0; i < exams.size(); i++)
		sum += exams[i]->point();
	
	_score = sum / exams.size();

	return _score;
}
