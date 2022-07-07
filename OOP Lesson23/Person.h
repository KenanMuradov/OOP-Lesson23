#pragma once
class Person
{
protected:

	size_t _id = 0;
	string _name = "";
	string _surname = "";
	size_t _age = 0;

public:

	Person() = default;
	Person(size_t id,string name, string surname, size_t age);


	size_t id() const;
	string name() const;
	string surname() const ;
	size_t age() const;

	void show() const; 

};

// CONSTRUCTOR
Person::Person(size_t id,string name, string surname, size_t age)
	: _id(id), _name(name), _surname(surname), _age(age) {};

#pragma region GETTERS

size_t Person::id() const
{
	return _id;
}

string Person::name() const
{
	return _name;
}

string Person::surname() const
{
	return _surname;
}

size_t Person::age() const
{
	return _id;
}


#pragma endregion

// METHOD
void Person::show() const
{
	cout << "Id: " << _id << endl
		<< "Name: " << _name << endl
		<< "Surname: " << _surname << endl
		<< "Age: " << _age << endl;
}