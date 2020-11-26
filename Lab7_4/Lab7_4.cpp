#pragma warning(disable: 4996)  //*****************
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Введите имя входного файла" << endl;
	//string infile_name;   //--------------
	char infile_name[256]; //*************/
	//getline(cin, infile_name); //----------------
	cin.getline(infile_name,256);  //******************/
	ifstream fin(infile_name);

	cout << "Введите имя выходного файла" << endl;
	//string outfile_name;  //----------
	char outfile_name[256]; //************
	//getline(cin, outfile_name);   //-------------
	cin.getline(outfile_name, 256); //*************
	ofstream fout(outfile_name);

	if (!fin.is_open()) {
		cerr << "Error fin";
	}
	if (!fout.is_open()) {
		cerr << "Error fout";
	}

//	string cur_line;   //------------
//	string prev_line = ""; //------------
	
	char cur_line[256];               //**************
	char prev_line[256] = "";         //**************

	int counter = 0;
	int first_line = 0;
	int count_line = 1;


	//	while (!fin.eof())   //--------
	while (fin.getline(cur_line,256))   //******************
	{

		counter++;
		//cout << cur_line << endl;
		//if (cur_line == prev_line)   //----------------
		if (strcmp(cur_line, prev_line) == 0)  //***************** 
		{
			if (count_line == 1) {
				first_line = counter - 1;
			}
			count_line++;
		}
		else {
			if (count_line >= 2) {
				fout << "Строка \"" << prev_line << "\"" << " повторяется " << count_line << " раз начиная со строки " << first_line << endl;
				count_line = 1;
			}
		}
		//prev_line = cur_line;  //-----------------
		strcpy(prev_line, cur_line);  //запоминаем текущую строку //*********************
	}

	if (count_line >= 2) {
		fout << "Строка \"" << prev_line << "\"" << " повторяется " << count_line << " раз начиная со строки " << first_line << endl;
	}



	fin.close();
	fout.close();

	return 0;
}
