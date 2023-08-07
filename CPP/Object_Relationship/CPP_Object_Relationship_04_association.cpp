#include <iostream>
#include <vector>

using namespace std;

// 서로에 대한 참조
// friend 사용

class Patient
{
public:
	Patient(const string& name)
		: name(name)
	{}

	void AddDoctor(class Doctor* const doctor)
	{
		doctors.push_back(doctor);
	}

	void MeetDoctor();

private:
	string name;
	friend class Doctor;	// friend 선언으로 private 접근 가능
	vector<class Doctor*> doctors;

};

class Doctor
{
public:
	Doctor(const string& name)
		: name(name)
	{}

	void AddPatient(class Patient* const patient)
	{
		patients.push_back(patient);
	}

	void MeetPatient()
	{
		for (const auto& patient : patients)
		{
			cout << "Meet Patient : " << patient->name << endl;
		}
	}

private:
	string name;
	friend class Patient;
	vector<class Patient*> patients;
};

int main()
{
	Patient* p1 = new Patient("Kim");
	Patient* p2 = new Patient("Lee");
	Patient* p3 = new Patient("Park");

	Doctor* d1 = new Doctor("Doc. Lee");
	Doctor* d2 = new Doctor("Doc. Kim");

	// 서로에게 할당
	p1->AddDoctor(d1);
	d1->AddPatient(p1);

	p2->AddDoctor(d1);
	d1->AddPatient(p2);

	p3->AddDoctor(d2);
	d2->AddPatient(p3);

	p1->MeetDoctor();
	d1->MeetPatient();
	d2->MeetPatient();

	// 생성된 역순으로 해제,
	// 이미 해제된 포인터를 가르키는 허상포인터 현상이 일어날 수 있기 때문
	delete d2;
	delete d1;
	delete p3;
	delete p2;
	delete p1;

	return 0;
}

// 클래스 밖에 따로 만드는 이유, 정의 되지 않은 형식의 클래스 사용 현상을 해결하기 위해
void Patient::MeetDoctor()
{
	for (const auto& doctor : doctors)
	{
		cout << "Meet Doctor : " << doctor->name << endl;
	}
}
