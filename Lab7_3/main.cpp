#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
	setlocale(LC_ALL, "russian");

	cout << "Введите имя входного файла" << endl;
	string infile_name;
	getline(cin, infile_name);
	ifstream fin(infile_name);

	cout << "Введите имя выходного файла" << endl;
	string outfile_name;
	getline(cin, outfile_name);
	ofstream fout(outfile_name);

	if (!fin.is_open()) {
		cerr << "Error fin";
	}
	if (!fout.is_open()) {
		cerr << "Error fout";
	}

	string cur_line;

	string prev_line = "";
	int counter=0;
	int first_line=0;
	int count_line=1;


//	while (!fin.eof())
	while (getline(fin, cur_line)) 
	{
	    
		counter++;
		//cout << cur_line << endl;
		if (cur_line == prev_line) {
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
		prev_line = cur_line;
	}

	if (count_line >= 2) {
		fout << "Строка \"" << prev_line << "\"" << " повторяется " << count_line << " раз начиная со строки " << first_line << endl;
	}



	fin.close();
	fout.close();

	return 0;
}
