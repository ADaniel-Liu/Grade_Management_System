// Grade_Management_System.cpp : �������̨Ӧ�ó������ڵ㡣
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
		cout << "-------ѧ���γ�ϵͳ----------\n"
			<< "1.����ѧ����Ϣ\n"
			<< "2.��ѯ�γ������߷�\n"
			<< "3.��ѯѧ���ɼ�\n";
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
			cout << "����ɹ���" << endl;
			system("pause");
			break;
		}
		case 2:
		{
			int max = -1, min = 200;
			int imax = 0, imin = 0;
			if (pscg.empty())
			{
				cout << "ϵͳ��û��ѧ����Ϣ����������ѧ����Ϣ��" << endl;
				system("pause");
				break;
			}
			cout << "��������Ҫ��ѯ�Ŀ�Ŀ��";
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
				cout << "û���ҵ��ÿ�Ŀ�ķ�����Ϣ��" << endl;
			}
			else
			{
				cout << seekcourse << "��Ŀ������͵ģ�\n";
				pscg[imin]->Display();
				cout << endl;
				cout << seekcourse << "��Ŀ������ߵģ�\n";
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
				cout << "ϵͳ��û��ѧ����Ϣ����������ѧ����Ϣ��" << endl;
				system("pause");
				break;
			}
			string mname;
			cout << "������ѧ��������" << endl;
			cin >> mname;
			for (int i = 0; i<pscg.size(); i++)
			{
				if (pscg[i]->Getname() == mname)
				{
					pscg[i]->Display();
					cout << endl;
				}
				else if (i == pscg.size() - 1)
					cout << "ϵͳ���޴�ѧ����Ϣ��" << endl;
			}
			system("pause");
			break;
		}
			}
	}
	return 0;
}

