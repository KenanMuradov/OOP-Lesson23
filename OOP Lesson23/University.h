#pragma once
class University
{
private:

	vector<Teacher*> teachers;
	vector<Student*> students;
	string _name="";

public:

	University() = default;
	University(string name) : _name(name) {}

	void addTeacher(Teacher* t);
	void addStudent(Student* s);

	size_t getUniversityScore();
	void showAllStudents();

	friend ostream& operator<<(ostream& out, const University& u);

};

// OPERATOR

ostream& operator<<(ostream& out, const University& u)
{
	out << "Name: " << u._name << endl
		<< "Teachers count: " << u.teachers.size() << endl
		<< "Students count: " << u.students.size() << endl;

	return out;
}



#pragma region METHODS

void University::addTeacher(Teacher* t)
{
	if (t == nullptr)
		throw exception("Teacher not found");

	teachers.push_back(t);
}

void University::addStudent(Student* s)
{
	if (s == nullptr)
		throw exception("Teacher not found");

	students.push_back(s);
}

size_t University::getUniversityScore()
{
	size_t sum = 0;

	for (size_t i = 0; i < students.size(); i++)
		sum += students[i]->findScore();

	return sum / students.size();
}

void University::showAllStudents()
{
	cout << "\n\tStudents\n";
	for (size_t i = 0; i < students.size(); i++)
		cout << *students[i] << endl;
}

#pragma endregion



