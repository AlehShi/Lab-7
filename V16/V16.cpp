#include <iostream>
#include <fstream>

using namespace std;
int main()
{
	setlocale(LC_ALL, "russian");
	ifstream fin("in.txt");
	ofstream fout("out.txt");

	// проверки открытия файлов
	if (!fin.is_open()) {
		cerr << "Error fin";
	}
	if (!fout.is_open()) {
		cerr << "Error fout";
	}

	char line[500]; 
	int i;
	int c=0; //это чтобы перед первой строкой перенос не делать
	while (fin.getline(line, 500)) 
	{
		if (c>0) fout << "\n"; //это перенос строк добавить 
		c = 1;
		for (i = strlen(line); i >0 ; i--) //ищем пробел с конца строки
		{
			if (line[i]==' ') //если нашли
			{
				cout << line[i + 1]<<endl;
				int Space1 = 0;
				for (int k =0; k < strlen(line); k++)  //начинаем выводит в out
				{  
					
					if (line[k]!=' ' & Space1==0 ) //пока не встретим пробел вставляем символ после найденного с конца пробела
					{
						fout << line[i+1];
					}
					else
					{
						fout << line[k];   //иначе просто копим line
						Space1 = 1;
					}
					
				}
				break; //если с конца нашли пробел то дальше искать не надо
			}

		}

	}
	//закрыли файлы
	fin.close();
	fout.close();
	return 0;
}
