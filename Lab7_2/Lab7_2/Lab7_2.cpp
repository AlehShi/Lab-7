//#pragma warning(disable: 4996) //это если ругается  типо небезопасно

#include <iostream>
#include <fstream>  //файловые потоки
#include <string>
using namespace std; //определяем пространство имен, чтобы не писать полный путь std::cout (но полный путь загадочнее :) )

int main()
{
    struct OutputResult
    {
        string repeatingLine;
        int countLine;
        int lineNumber;
    };   // структура для записи результата в выходной файл
    OutputResult* rec = new OutputResult;

    int counter = 0; //счетчик строк
    int counterLines = 0; //количество повторяющихся строк
    int lineNumber = 0;   //Номер строки с которой повтор

    //строки текущая и предыдущая
    string currentLine;
    string oldLine="";

    // сами файлы
    ifstream f_input; //на чтение
    ofstream f_output; //на запись
    ofstream f_output2; //на запись


    //их имена
    string fileNameIn;
    string fileNameOut;

    //вводим имена файлов
    cout << "Enter the name of the input file:" << endl;
    cin >> fileNameIn;
    cout << "\nInput file: " << fileNameIn << endl;

    cout << "Enter the name of the output file:" << endl;
    cin >> fileNameOut;
    cout << "\nOutput file: " << fileNameOut << endl;

    //открываем файлы потоки
    f_input.open(fileNameIn);
    f_output.open(fileNameOut, ios::binary);//бинарный чтобы структуру записать
    f_output2.open("out.txt");



    while (getline(f_input, currentLine))
    {
        counter++;
        cout <<"Line "<<counter<<":'"<<currentLine <<"'"<< endl; //выводим посмотреть -для отладки например
        if (currentLine == oldLine)  //если строка равна предыдущей то
        {
            if (counterLines == 0)
            {
                lineNumber = counter - 1; //если это первый повтор то запоминаем номер первой строки повтора
            }
            counterLines++; //увеличиваем счетчик повторов - не забываем что он с 0!!!!
        }
        else
        {
            //тут надо записать в файл строку oldLine, counterLines, lineNumber если у нас повтор т.е. counterLines>0
            //можно отдельно а можно как в примере-структурой outputResult
            if (counterLines > 0)
            {

                cout << "'" << oldLine << "'" << " repeats " << counterLines + 1 << " times from line " << lineNumber << endl;
                rec->repeatingLine = oldLine;
                rec->countLine = counterLines + 1;
                rec->lineNumber = lineNumber;

                //f_output << rec<< endl;//тут что-то не тое......

                const char* ss;//это можно и заранее объявить- вверху

                ss= (char*)&rec; //write принимает const char* поэтопу преобразуем
                f_output.write(ss, sizeof(OutputResult));
                // или без переменной сразу f_output.write((char*)&rec, sizeof(OutputResult));


                /*
                а это в текстовик для проверки просто в поток как cout<<      -
                т.к. выходной файл сами выдумывам можно просто данные построчно вывести если совсем элементарно,
                но если потом данные считывать не надо то можно украсивить
                */
                f_output2 << "String '"<< oldLine<< "' repeats "<< (counterLines + 1)<< " times from line "<< lineNumber<<endl;

                // обнуляем наши счетчики
                counterLines = 0;
                lineNumber = 0;
            }
        }
        oldLine = currentLine;  //запоминаем текущую строку
    }


    f_output.close();
    f_input.close();
    f_output2.close();
    return 0;
}
