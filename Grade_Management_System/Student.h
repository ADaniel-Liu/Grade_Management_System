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
			<< "姓名：" << name << "\n"
			<< "性别：" << sex << "\n"
			<< "学号：" << ID << "\n";
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
		cout << "请按格式输入："
			<< "姓名 性别 学号\n";
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
		cout << "请输入该学生课程数目：";
		cin >> n;
		cout << "请按格式输入："
			<< "课程名 分数 课程名 分数......\n";
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
			cout << "没有课程信息！";
		else
		{
			cout << "成绩：";
			for (int i = 0; i<gar.size(); i++)
				gar[i].Display();
		}
		cout << endl;
	}
private:
	Student stu;
	vector<Course> gar;
};