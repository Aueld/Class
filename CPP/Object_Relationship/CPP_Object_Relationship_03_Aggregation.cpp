#include "CPP_Object_Relationship_03_lecture.h"

int main()
{
	using namespace std;
	
	Teacher t("Teacher");
	Student s1("Student1", 1);
	Student s2("Student2", 2);
	Student s3("Student3", 3);

	cout << "t  : " << &t << endl;
	cout << "s1 : " << &s1 << endl;
	cout << "s2 : " << &s2 << endl;
	cout << "s3 : " << &s3 << endl;
	cout << endl;

	{
		Lecture lec("C++ Language");
		lec.AssignmentTeacher(&t);
		lec.AssignmentStudent(&s1);
		lec.AssignmentStudent(&s2);
		lec.AssignmentStudent(&s3);
		lec.Print();
	}
	
	cout << "t  : " << &t << endl;
	cout << "s1 : " << &s1 << endl;
	cout << "s2 : " << &s2 << endl;
	cout << "s3 : " << &s3 << endl;
	cout << endl;

	return 0;
}
