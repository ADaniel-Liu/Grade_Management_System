#pragma once
#include <iostream> 
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

class Student
{
public:
	void Set(string inname, string insex, int inID)
	{
		name = inname;
		sex = insex;
		ID = inID;
	}
	string Getname() { return name; }
	void Display()
	{
		cout << setiosflags(ios::left)
			<< "������" << name << "\n"
			<< "�Ա�" << sex << "\n"
			<< "ѧ�ţ�" << ID << "\n";
	}
private:
	int ID;
	string name;
	string sex;
};

class Course
{
public:
	Course(string incourse, int ingarde) :course(incourse), garde(ingarde) {};
	string Getcourse() { return course; }
	int Getgarde() { return garde; }
	void Display()
	{
		cout << course << " " << garde << " ";
	}
private:
	string course;
	int garde;
};

class StudentCourseGarde
{
public:
	void Inputstudent()
	{
		cout << "�밴��ʽ���룺"
			<< "���� �Ա� ѧ��\n";
		string a;
		string b;
		int c;
		cin >> a >> b >> c;
		stu.Set(a, b, c);
	}

	void InputCourse()
	{
		int n;
		Course* p;
		cout << "�������ѧ���γ���Ŀ��";
		cin >> n;
		cout << "�밴��ʽ���룺"
			<< "�γ��� ���� �γ��� ����......\n";
		for (int i = 0; i<n; i++)
		{
			string a;
			int g;
			cin >> a >> g;
			p = new Course(a, g);
			gar.push_back(*p);
		}
	}

	string Getname() { return stu.Getname(); }
	vector<Course> GetCourse() { return gar; }
	void Display()
	{
		stu.Display();
		if (gar.empty())
			cout << "û�пγ���Ϣ��";
		else
		{
			cout << "�ɼ���";
			for (int i = 0; i<gar.size(); i++)
				gar[i].Display();
		}
		cout << endl;
	}
private:
	Student stu;
	vector<Course> gar;
};