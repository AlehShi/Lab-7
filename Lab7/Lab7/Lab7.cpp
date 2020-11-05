#define _CRT_SECURE_NO_WARNINGS //это если ругается  типо небезопасно
#include <iostream>
#include <string>
using namespace std; //определяем пространство имен, чтобы не писать полный путь std::cout (но полный путь загадочнее :) )

int main()
{
    FILE* f_input;
    FILE* f_output;
    char fileNameIn[256];
    char fileNameOut[256];

    cout << "Enter the name of the input file:" << "\n"  ;
    cin >>  fileNameIn  ;
    cout << "\nInput file: " << fileNameIn << "\n";
    cout << "Enter the name of the output file:" << "\n";
    cin >> fileNameOut ;
    cout << "\nOutput file: " << fileNameOut << "\n";

    if ((f_input = fopen(fileNameIn, "rt")) != NULL)
    {
        //тут работаем с открытым файлом
                    fclose(f_input);
    }

    else 
    {
    // а тут пишем если файл не выбрали,(например по кнопе отмена
    cout << "Do not open file "<< fileNameIn << endl;
    }

    return 0;
}