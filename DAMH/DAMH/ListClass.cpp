#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <fstream>
#include"ConsoleProcess.h"
#include "Course_function.h"

using namespace std;

const string csv_tail = ".csv";

struct Database {
	string No;
	string ID;
	string name;
	string Birth;
	string sex;
	string IDsocial;
};

Database Imput()
{
	Database data;
	gotoxy(53, 14);
	cout << "IMPUT INFORMATION STUDENT" << endl;
	cin.ignore();
	gotoxy(58, 15);
	cout << "Mssv:";
	getline(cin, data.ID);
	gotoxy(58, 16);
	cout << "Name:";
	getline(cin, data.name);
	gotoxy(58, 17);
	cout << "Birth:";
	getline(cin, data.Birth);
	gotoxy(58, 18);
	cout << "Sex:";
	getline(cin, data.sex);
	gotoxy(58, 19);
	cout << "IDsocial:";
	getline(cin, data.IDsocial);
	return data;
}

void CreateNewClass()
{
	string name;
	system("cls");
	textBgColor(1, 10);
	printtext("   ______    __       ____         _____   _____ ", 40, 4);
	printtext("  / ____/   / /      / /\\ \\      / ____/  / ___/ ", 40, 5);
	printtext(" / /       / /      / /__\\ \\     \\ \\      \\ \\    ", 40, 6);
	printtext("/ /___    / /____  / /____\\ \\   __\\ \\    __\\ \\   ", 40, 7);
	printtext("\\____/   /______/ /_/      \\_\\ /____/   /____/   ", 40, 8);
	printtext("                                                 ", 40, 9);
	string Year;
	gotoxy(34, 12);
	textBgColor(5, 15);
	cin.ignore();
	cout << "Enter School Year That You Want To Create New Class:";
	getline(cin, Year);
	fstream fs;
	fs.open("file_save//year.csv", ios::in);
	bool checkYear = false;
	string tempYear;
	while (!fs.eof())
	{
		getline(fs, tempYear);
		if (Year == tempYear)
		{
			checkYear = true;
		}
	}
	if (checkYear == false)
	{
		gotoxy(40, 14);
		cout << "SCHOOL YEAR DON'T EXIT!! PLEASE TRY AGAIN" << endl;
	}
	if (checkYear == true)
	{ 
		gotoxy(43, 14);
		cout << "Enter Name Of Class(Ex:20CTT1,..): ";
		getline(cin, name);
		fstream file1;
		bool check = true;
		file1.open("file_save//SchoolYear//" + Year + "//Class_Infor.csv", ios::in);
		string NameClass;
		while (!file1.eof())
		{
			getline(file1, NameClass);
			if (name == NameClass)
			{
				check = false;
			}
		}
		if (check == false)
		{
			gotoxy(40, 16);
			cout << "CLASS EXIT! PLEASE TRY AGAIN" << endl;
		}
		if (check == true)
		{
			string FileName = "file_save//SchoolYear//" + Year + "//" + name + csv_tail;
			fstream f1;
			f1.open(FileName, ios::out);
			f1 << "No" << "," << "ID" << "," << "Name" << "," << "Birth" << "," << "Sex" << "," << "IDSocial" << endl;
			f1.close();
			fstream file;
			file.open("file_save//SchoolYear//" + Year + "//Class_Infor.csv", ios::app);
			file << name << endl;
			file.close();
			gotoxy(38, 16);
			cout << "CREATE CLASS SUCCESSFUL,PRESS ENTER TO BACK TO MENU !!!" << endl;
		}
	}
	
}


void ViewListClasses()
{
	textBgColor(1, 10);
	printtext("   ______    __       ____         _____   _____ ", 40, 4);
	printtext("  / ____/   / /      / /\\ \\      / ____/  / ___/ ", 40, 5);
	printtext(" / /       / /      / /__\\ \\     \\ \\      \\ \\    ", 40, 6);
	printtext("/ /___    / /____  / /____\\ \\   __\\ \\    __\\ \\   ", 40, 7);
	printtext("\\____/   /______/ /_/      \\_\\ /____/   /____/   ", 40, 8);
	printtext("                                                 ", 40, 9);
	textBgColor(5, 15);
	fstream f;
	string selection;
	gotoxy(50, 10);
	cout << "VIEW LIST CLASS IN SCHOOL YEAR";
	gotoxy(45, 12);
	cin.ignore();
	cout << "Please Select School Year: ";
	getline(cin, selection);
	fstream file;
	string year;
	bool check = false;
	file.open("file_save//year.csv", ios::in);
	while (!file.eof())
	{
		getline(file, year);
		if (selection == year)
		{
			check = true;
		}
	}
	if (check == false)
	{
		textBgColor(10, 11);
		gotoxy(45, 14);
		cout << "Your Selection Is Fail" << endl;
	}
	else
	{
		gotoxy(44, 14);
		cout << "===== LIST CLASSES IN " << selection << " =======" << endl;
		f.open("file_save//SchoolYear//" + selection + "//Class_Infor.csv", ios::in);
		int i = 15;
		while (!f.eof())
		{
			string NameClass;
			f >> NameClass;
			gotoxy(61, i);
			cout << NameClass << endl;
			i++;
		}
		cout << endl;
		f.close();
	}
}

void MenuViewListClass()
{
	textBgColor(1, 10);
	printtext("   ______    __       ____         _____   _____ ", 40, 4);
	printtext("  / ____/   / /      / /\\ \\      / ____/  / ___/ ", 40, 5);
	printtext(" / /       / /      / /__\\ \\     \\ \\      \\ \\    ", 40, 6);
	printtext("/ /___    / /____  / /____\\ \\   __\\ \\    __\\ \\   ", 40, 7);
	printtext("\\____/   /______/ /_/      \\_\\ /____/   /____/   ", 40, 8);
	printtext("                                                 ", 40, 9);
	textBgColor(5, 15);
	gotoxy(40, 12);
	cout << "1. Create New Class In School Year" << endl;
	gotoxy(40, 14);
	cout << "2. View List Classes In School Year" << endl;
	gotoxy(40, 16);
	cout << "3. Exit" << endl;
}



int RunMenuViewListClass()
{
	char ch;
	while (true)
	{

		int command;
		MenuViewListClass();
		gotoxy(40, 18);
		cout << "Please Select Your Command: ";
		cin >> command;
		switch (command)
		{
			case 1:
			{
				system("cls");
				CreateNewClass();
				system("pause");
				system("cls");
				break;
			}
			case 2:
			{
				system("cls");
				ViewListClasses();
				system("pause");
				system("cls");
				break;
			}
			case 3:
			{
				textBgColor(10, 11);
				printtext("YOU WANT TO EXIT, PRESS ENTER TO BACK TO MENU !!!", 40, 20);
				ch = _getch();
				textBgColor(0, 15);
				return 0;
			}
		}
	}
}



