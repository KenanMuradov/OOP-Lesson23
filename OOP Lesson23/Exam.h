#pragma once
class Exam
{
private:

	Lesson _lesson;
	size_t _point = 0;

public:

	Exam() = default;
	Exam(Lesson lesson, size_t point);

	Lesson lesson();
	size_t point();

};

// CONSTRUCTOR
Exam::Exam(Lesson lesson, size_t point) : _lesson(lesson), _point(point) {};


#pragma region GETTERS

Lesson Exam::lesson()
{
	return _lesson;
}

size_t Exam::point()
{
	return _point;
}

#pragma endregion
