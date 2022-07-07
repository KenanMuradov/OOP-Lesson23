#pragma once
class Group
{
private:

	vector<Student*> _students;
	string _name = "";
	
public:

	vector<Lesson*> lessons;

	Group() = default;
	Group(string name);

	string name() const;

	void addStudent(Student* student);
	void removeStudentById(size_t id);

	friend ostream& operator<<(ostream& out, const Group& g);

};

// CONSTRUCTOR
Group::Group(string name) : _name(name){}

// OPERATOR
ostream& operator<<(ostream& out, const Group& g)
{
	out << "Name: " << g._name << endl
		<< "\tStudents Info\n";
	for (size_t i = 0; i < g._students.size(); i++)
	{
		out << *g._students[i] << endl << endl;;
	}

	out << "\n\tLessons info\n";
	for (size_t i = 0; i < g.lessons.size(); i++)
	{
		out << *g.lessons[i] << endl << endl;
	}

	return out;
}

// GETTER
string Group::name() const { return _name; }

#pragma region METHODS

void Group::addStudent(Student* student)
{
	if (student == nullptr)
		throw exception("Unidentified student");

	_students.push_back(student);
}

void Group::removeStudentById(size_t id)
{
	for (size_t i = 0; i < _students.size(); i++)
	{
		if (_students[i]->id() == id)
		{
			_students.erase(_students.begin() + i);
			return;
		}
	}

	throw exception("Student not found");
}

#pragma endregion