#pragma once
class Lesson
{
public:

	string name = "";
	size_t lessonHours = 0;


	Lesson() = default;
	Lesson(string name, size_t lessonHours) : name(name), lessonHours(lessonHours) {}

};

ostream& operator<<(ostream& out, const Lesson& l)
{
	out << "Name: " << l.name << endl
		<< "Hours: " << l.lessonHours;

	return out;
}