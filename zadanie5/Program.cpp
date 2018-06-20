#include "stdafx.h"
#include "Program.h"


Program::Program()
{
}

Program::~Program()
{
}

void Program::LoadFile(string Name)
{
	string name;
	char data;
	name = "Files/" + Name + ".txt";
	fstream file1;
	bool done = false;
	file1.open(name.c_str());
	if (file1.is_open())
	{
		do
		{
			file1 >> data;
			if (data > 64 && data < 91)
				data += 32;
		
			if ((done && (data > 64 && data < 91)))
				Words[data] += 1;
			if (done && (data > 96 && data < 123))
				Words[data] += 1;
			
			if ((!done && (data > 64 && data < 91)) || (!done && (data > 96 && data < 123)))
			{
				Words.insert(pair <char, int>(data, 1));
				done = true;
			}
		} while (!file1.eof());
		passed = true;
	}
	else
	{
		cout << "\nError: Wrong format or file doesn't exist.\n";
	}

	file1.close();
}

void Program::Sort()
{
	double letters = 0;
	for (itr = Words.begin(); itr != Words.end(); ++itr)
	{
		letters += itr->second;
	}

	string name;
	char data1;
	double PL, EN, ESP, FR;
	double percentage1PL, percentage2PL,
	   	percentage1EN, percentage2EN,
		percentage1ESP, percentage2ESP,
		percentage1FR, percentage2FR;

	name = "Files/Keys.txt";
	fstream file1;
	bool done = false;
	file1.open(name.c_str());
	if (file1.is_open())
	{
		do
		{
			file1 >> data1;
			file1 >> PL;
			file1 >> EN;
			file1 >> ESP;
			file1 >> FR;
			percentage1PL = (Words[data1] * 100 / letters);
			
			if (percentage1PL < PL)
			{
				percentage2PL = percentage1PL / PL;
				PLChance[data1] = percentage2PL;
			}
			if ((Words[data1] * 100 / letters) > PL)
			{
				percentage2PL = PL / percentage1PL;
				PLChance[data1] = percentage2PL;
			}

			percentage1EN = (Words[data1] * 100 / letters);
		
			if (percentage1EN < EN)
			{
				percentage2EN = percentage1EN / EN;
				ENChance[data1] = percentage2EN;
			}
			if ((Words[data1] * 100 / letters) > EN)
			{
				percentage2EN = EN / percentage1EN;
				ENChance[data1] = percentage2EN;
			}

			percentage1ESP = (Words[data1] * 100 / letters);
			if (percentage1ESP < ESP)
			{
				percentage2ESP = percentage1ESP / ESP;
				ESPChance[data1] = percentage2ESP;
			}
			if ((Words[data1] * 100 / letters) > ESP)
			{
				percentage2ESP = ESP / percentage1ESP;
				ESPChance[data1] = percentage2ESP;
			}

			percentage1FR = (Words[data1] * 100 / letters);
			if (percentage1FR < FR)
			{
				percentage2FR = percentage1FR / FR;
				FRChance[data1] = percentage2FR;
			}
			if ((Words[data1] * 100 / letters) > FR)
			{
				percentage2FR = FR / percentage1FR;
				FRChance[data1] = percentage2FR;
			}

		} while (!file1.eof());

	}
	else
	{
		cout << "\nNie mozna wczytac.\n";
	}

	file1.close();
}

void Program::MakeKey(string Name)
{
	string name;
	char data;
	name = "Files/" + Name + ".txt";
	fstream file1, savefile;
	bool done = false;
	file1.open(name.c_str());
	if (file1.is_open())
	{
		do
		{
			file1 >> data;
			if (data > 64 && data < 91)
				data += 32;

			if ((done && (data > 64 && data < 91)))
				Words[data] += 1;
			if (done && (data > 96 && data < 123))
				Words[data] += 1;

			if ((!done && (data > 64 && data < 91)) || (!done && (data > 96 && data < 123)))
			{
				Words.insert(pair <char, int>(data, 1));
				done = true;
			}
		} while (!file1.eof());

	}
	else
	{
		cout << "\nError.\n";
	}
	system("pause");

	file1.close();

	
	savefile.open("Files/EN KEY.txt");

	if (savefile.is_open())
	{
		int letters = 0;
		for (itr = Words.begin(); itr != Words.end(); ++itr)
		{
			if (itr->second > 0)
				letters += itr->second;
		}
		
		for (itr = Words.begin(); itr != Words.end(); ++itr)
		{
			char a = itr->first;
			double b = itr->second;
			double value = 0;

			if (b > 0)
			{
				value = (b * 100) / letters;
				cout << b << " " << letters << " " << value;
				system("pause");
				savefile << a << " " << setprecision(3) << value << "\n";
			}
		}
	}
	else
	{
		cout << "\nError.\n";
	}

	system("pause");

	savefile.close();
}

void Program::Start()
{
	
	PLChance.insert(pair<char, double>('a', 0)); ENChance.insert(pair<char, double>('a', 0)); ESPChance.insert(pair<char, double>('a', 0)); FRChance.insert(pair<char, double>('a', 0));
	PLChance.insert(pair<char, double>('b', 0)); ENChance.insert(pair<char, double>('b', 0)); ESPChance.insert(pair<char, double>('b', 0)); FRChance.insert(pair<char, double>('b', 0));
	PLChance.insert(pair<char, double>('c', 0)); ENChance.insert(pair<char, double>('c', 0)); ESPChance.insert(pair<char, double>('c', 0)); FRChance.insert(pair<char, double>('c', 0));
	PLChance.insert(pair<char, double>('d', 0)); ENChance.insert(pair<char, double>('d', 0)); ESPChance.insert(pair<char, double>('d', 0)); FRChance.insert(pair<char, double>('d', 0));
	PLChance.insert(pair<char, double>('e', 0)); ENChance.insert(pair<char, double>('e', 0)); ESPChance.insert(pair<char, double>('e', 0)); FRChance.insert(pair<char, double>('e', 0));
	PLChance.insert(pair<char, double>('f', 0)); ENChance.insert(pair<char, double>('f', 0)); ESPChance.insert(pair<char, double>('f', 0)); FRChance.insert(pair<char, double>('f', 0));
	PLChance.insert(pair<char, double>('g', 0)); ENChance.insert(pair<char, double>('g', 0)); ESPChance.insert(pair<char, double>('g', 0)); FRChance.insert(pair<char, double>('g', 0));
	PLChance.insert(pair<char, double>('h', 0)); ENChance.insert(pair<char, double>('h', 0)); ESPChance.insert(pair<char, double>('h', 0)); FRChance.insert(pair<char, double>('h', 0));
	PLChance.insert(pair<char, double>('i', 0)); ENChance.insert(pair<char, double>('i', 0)); ESPChance.insert(pair<char, double>('i', 0)); FRChance.insert(pair<char, double>('i', 0));
	PLChance.insert(pair<char, double>('j', 0)); ENChance.insert(pair<char, double>('j', 0)); ESPChance.insert(pair<char, double>('j', 0)); FRChance.insert(pair<char, double>('j', 0));
	PLChance.insert(pair<char, double>('k', 0)); ENChance.insert(pair<char, double>('k', 0)); ESPChance.insert(pair<char, double>('k', 0)); FRChance.insert(pair<char, double>('k', 0));
	PLChance.insert(pair<char, double>('l', 0)); ENChance.insert(pair<char, double>('l', 0)); ESPChance.insert(pair<char, double>('l', 0)); FRChance.insert(pair<char, double>('l', 0));
	PLChance.insert(pair<char, double>('m', 0)); ENChance.insert(pair<char, double>('m', 0)); ESPChance.insert(pair<char, double>('m', 0)); FRChance.insert(pair<char, double>('m', 0));
	PLChance.insert(pair<char, double>('n', 0)); ENChance.insert(pair<char, double>('n', 0)); ESPChance.insert(pair<char, double>('n', 0)); FRChance.insert(pair<char, double>('n', 0));
	PLChance.insert(pair<char, double>('o', 0)); ENChance.insert(pair<char, double>('o', 0)); ESPChance.insert(pair<char, double>('o', 0)); FRChance.insert(pair<char, double>('o', 0));
	PLChance.insert(pair<char, double>('p', 0)); ENChance.insert(pair<char, double>('p', 0)); ESPChance.insert(pair<char, double>('p', 0)); FRChance.insert(pair<char, double>('p', 0));
	PLChance.insert(pair<char, double>('q', 0)); ENChance.insert(pair<char, double>('q', 0)); ESPChance.insert(pair<char, double>('q', 0)); FRChance.insert(pair<char, double>('q', 0));
	PLChance.insert(pair<char, double>('r', 0)); ENChance.insert(pair<char, double>('r', 0)); ESPChance.insert(pair<char, double>('r', 0)); FRChance.insert(pair<char, double>('r', 0));
	PLChance.insert(pair<char, double>('s', 0)); ENChance.insert(pair<char, double>('s', 0)); ESPChance.insert(pair<char, double>('s', 0)); FRChance.insert(pair<char, double>('s', 0));
	PLChance.insert(pair<char, double>('t', 0)); ENChance.insert(pair<char, double>('t', 0)); ESPChance.insert(pair<char, double>('t', 0)); FRChance.insert(pair<char, double>('t', 0));
	PLChance.insert(pair<char, double>('u', 0)); ENChance.insert(pair<char, double>('u', 0)); ESPChance.insert(pair<char, double>('u', 0)); FRChance.insert(pair<char, double>('u', 0));
	PLChance.insert(pair<char, double>('v', 0)); ENChance.insert(pair<char, double>('v', 0)); ESPChance.insert(pair<char, double>('v', 0)); FRChance.insert(pair<char, double>('v', 0));
	PLChance.insert(pair<char, double>('w', 0)); ENChance.insert(pair<char, double>('w', 0)); ESPChance.insert(pair<char, double>('w', 0)); FRChance.insert(pair<char, double>('w', 0));
	PLChance.insert(pair<char, double>('x', 0)); ENChance.insert(pair<char, double>('x', 0)); ESPChance.insert(pair<char, double>('x', 0)); FRChance.insert(pair<char, double>('x', 0));
	PLChance.insert(pair<char, double>('y', 0)); ENChance.insert(pair<char, double>('y', 0)); ESPChance.insert(pair<char, double>('y', 0)); FRChance.insert(pair<char, double>('y', 0));
	PLChance.insert(pair<char, double>('z', 0)); ENChance.insert(pair<char, double>('z', 0)); ESPChance.insert(pair<char, double>('z', 0)); FRChance.insert(pair<char, double>('z', 0));

	double PLPercentage = 0;
	double ENPercentage = 0;
	double ESPPercentage = 0;
	double FRPercentage = 0;
	double PLnumber = 0;
	double ENnumber = 0;
	double ESPnumber = 0;
	double FRnumber = 0;
	double PLsum = 0;
	double ENsum = 0;
	double ESPsum = 0;
	double FRsum = 0;
	
	string name;
	cout << "Enter a name of file: ";
	do
	{
		cin >> name;
		LoadFile(name);
	} while (!passed);

	cout << "\tKEY\tELEMENT\n";
	for (itr = Words.begin(); itr != Words.end(); ++itr)
	{
		cout << "\t" << itr->first << "\t" << itr->second << '\n';
	}

	Sort();
	cout << "\nCompatibility with key:\n\n";


	for (itr2 = PLChance.begin(); itr2 != PLChance.end(); ++itr2)
	{
		if (itr2->second > 0)
		{
			PLsum += itr2->second;
			PLnumber += 1;
		}
	}

	for (itr3 = ENChance.begin(); itr3 != ENChance.end(); ++itr3)
	{
		if (itr3->second > 0)
		{
			ENsum += itr3->second;
			ENnumber += 1;
		}
	}

	for (itr4 = ESPChance.begin(); itr4 != ESPChance.end(); ++itr4)
	{
		if (itr4->second > 0)
		{
			ESPsum += itr4->second;
			ESPnumber += 1;
		}
		
	}

	for (itr5 = FRChance.begin(); itr5 != FRChance.end(); ++itr5)
	{
		if (itr5->second > 0)
		{
			FRsum += itr5->second;
			FRnumber += 1;
		}
	}

	PLPercentage = (PLsum * 100) / PLnumber;
	ENPercentage = (ENsum * 100) / ENnumber;
	ESPPercentage = (ESPsum * 100) / ESPnumber;
	FRPercentage = (FRsum * 100) / FRnumber;
											
	cout << "\tKEY\tELEMENT\t\tKEY\tELEMENT\t\tKEY\tELEMENT\t\tKEY\tELEMENT\n";		
	for (itr2 = PLChance.begin(), itr3 = ENChance.begin(), itr4 = ESPChance.begin(), itr5 = FRChance.begin(); 
		itr2 != PLChance.end(), itr3 != ENChance.end(), itr4 != ESPChance.end(), itr5 != FRChance.end(); 
		++itr2, ++itr3, ++itr4, ++itr5)
	{
		cout << "\t" << itr2->first << "\t";
		if (itr2->second == 0) cout << "--" << " \t\t";
		else cout << fixed << setprecision(2) << itr2->second * 100 << " %\t\t";

		cout << itr3->first << "\t";
		if (itr3->second == 0) cout << "--" << " \t\t";
		else cout << fixed << setprecision(2) << itr3->second * 100 << " %\t\t";

		cout << itr4->first << "\t";
		if (itr4->second == 0) cout << "--" << " \t\t";
		else cout << fixed << setprecision(2) << itr4->second * 100 << " %\t\t";

		cout << itr5->first << "\t";
		if (itr5->second == 0) cout << "--" << " \n";
		else cout << fixed << setprecision(2) << itr5->second * 100 << " %\n";
	}

	cout << "\n\tPL : " << PLPercentage << " %\t\tEN: " << ENPercentage << "%\t\tESP: " << ESPPercentage << " %\t\tFR: " << FRPercentage << " %\n";

	system("pause");
	
}