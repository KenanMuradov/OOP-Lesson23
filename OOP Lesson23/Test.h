#pragma once
void start()
{
#pragma region LESSONS
	Lesson l1("Biotechnology", 230);
	Lesson l2("Mathematics", 470);
	Lesson l3("Computer Science", 1000);
	Lesson l4("Chemistry", 480);
	Lesson l5("Physiotherapy", 125);
#pragma endregion

	

#pragma region BANK_CARDS
	BankCard b1("4485321524384", "5142", "427", 234, 12, 24);
	BankCard b2("5118882587665936", "9052", "690", 567, 9, 23);
	BankCard b3("491 72892 23288 458", "6054", "569", 234, 5, 23);
	BankCard b4("484445 784644 8456", "7554", "827", 234, 1, 23);
	BankCard b5("4485321524384", "3062", "118", 234, 8, 26);
	BankCard b6("67636433347246", "8905", "611", 234, 5, 23);
#pragma endregion


#pragma region BANK

	Bank bank("KepaBank", "KepaTown,street Max 2908");

	bank.addCard(&b1);
	bank.addCard(&b2);
	bank.addCard(&b3);
	bank.addCard(&b4);
	bank.addCard(&b5);
	bank.addCard(&b6);
#pragma endregion


#pragma region STUDENTS
	Student* s1 = new Student("Kenan", "Muradov", 17, "Programmer", 2900, b1);
	s1->exams.push_back(new Exam(l2, 98));
	s1->exams.push_back(new Exam(l3, 100));

	Student* s2 = new Student("Ali", "Shamilzade", 17, "Manager", 1300, b2);
	s2->exams.push_back(new Exam(l5, 89));
	s2->exams.push_back(new Exam(l4, 67));

	Student* s3 = new Student("Vasif", "Babazade", 18, "Cool Boy", 3100, b3);
	s3->exams.push_back(new Exam(l1, 51));
	s3->exams.push_back(new Exam(l2, 51));

	Student* s4 = new Student("Aydin", "Heshimli", 18, "Physics Teacher", 2200, b4);
	s4->exams.push_back(new Exam(l3, 17));
	s4->exams.push_back(new Exam(l5, 94));

	Student* s5 = new Student("Tural", "Heci-Nebili", 15, "IT specialist", 1400, b5);
	s5->exams.push_back(new Exam(l3, 17));
	s5->exams.push_back(new Exam(l5, 94));

#pragma endregion

#pragma region GROUPS
	Group* g1 = new Group("FBAS_4241");
	g1->lessons.push_back(&l1);
	g1->lessons.push_back(&l2);

	g1->addStudent(s1);
	g1->addStudent(s2);
	g1->addStudent(s3);

	Group* g2 = new Group("FBAS_4212");
	g2->lessons.push_back(&l3);
	g2->lessons.push_back(&l4);
	g2->lessons.push_back(&l5);

	g2->addStudent(s4);
	g2->addStudent(s5);
#pragma endregion

	Teacher* t=new Teacher("Tural", "Novruzov", 30, "Programming", 6000, b6);

	t->addGroup(g1);
	t->addGroup(g2);
	University university("Kepa University");
	university.addTeacher(t);

	university.addStudent(s1);
	university.addStudent(s2);
	university.addStudent(s3);
	university.addStudent(s4);
	university.addStudent(s5);


	cout << university;

	cout << university.getPayment();
}