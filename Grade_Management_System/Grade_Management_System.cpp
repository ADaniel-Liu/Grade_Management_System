// Grade_Management_System.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include "Student.h"
using namespace std;

int main()
{
	vector<StudentCourseGarde*> pscg;

	while (1)
	{
		system("cls");
		cout << "-------学生课程系统----------\n"
			<< "1.输入学生信息\n"
			<< "2.查询课程最低最高分\n"
			<< "3.查询学生成绩\n";
		int num;
		cin >> num;
		switch (num)
		{
		case 1:
		{
			StudentCourseGarde* p;
			int quit = 1;
			p = new StudentCourseGarde;
			p->Inputstudent();
			p->InputCourse();
			pscg.push_back(p);
			cout << "输入成功。" << endl;
			system("pause");
			break;
		}
		case 2:
		{
			int max = -1, min = 200;
			int imax = 0, imin = 0;
			if (pscg.empty())
			{
				cout << "系统内没有学生信息，请先输入学生信息！" << endl;
				system("pause");
				break;
			}
			cout << "请输入想要查询的科目：";
			string seekcourse;
			cin >> seekcourse;

			for (int i = 0; i<pscg.size(); i++)
			{
				for (int j = 0; j<pscg[i]->GetCourse().size(); j++)
				{
					if (pscg[i]->GetCourse()[j].Getcourse() == seekcourse)
					{
						if (pscg[i]->GetCourse()[j].Getgarde()<min)
						{
							min = pscg[i]->GetCourse()[j].Getgarde();
							imin = i;
						}
						if (pscg[i]->GetCourse()[j].Getgarde()>max)
						{
							max = pscg[i]->GetCourse()[j].Getgarde();
							imax = i;
						}
					}
				}
			}
			if (min == 200 && max == -1)
			{
				cout << "没有找到该科目的分数信息！" << endl;
			}
			else
			{
				cout << seekcourse << "科目分数最低的：\n";
				pscg[imin]->Display();
				cout << endl;
				cout << seekcourse << "科目分数最高的：\n";
				pscg[imax]->Display();
				cout << endl;
			}
			system("pause");
			break;
		}

		case 3:
		{
			if (pscg.empty())
			{
				cout << "系统内没有学生信息，请先输入学生信息！" << endl;
				system("pause");
				break;
			}
			string mname;
			cout << "请输入学生姓名：" << endl;
			cin >> mname;
			for (int i = 0; i<pscg.size(); i++)
			{
				if (pscg[i]->Getname() == mname)
				{
					pscg[i]->Display();
					cout << endl;
				}
				else if (i == pscg.size() - 1)
					cout << "系统内无此学生信息！" << endl;
			}
			system("pause");
			break;
		}
			}
	}
	return 0;
}

