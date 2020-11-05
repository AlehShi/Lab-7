//#define _CRT_SECURE_NO_WARNINGS //это если ругается  типо небезопасно

#pragma warning(disable: 4996)
#include <iostream>
//#include <cstdlib>
#include <string>
using namespace std; //определяем пространство имен, чтобы не писать полный путь std::cout (но полный путь загадочнее :) )

int main()
{
    struct OutputResult {
        string repeatingLine;
        int countLine;
        int lineNumber;
    };
    OutputResult* rec = new OutputResult;

    // сами файлы
    FILE* f_input;
    FILE* f_output;
    FILE* f_output2;// a тута текстовый для проверки просто

    // имена файлов 
    char fileNameIn[256];
    char fileNameOut[256];

    //вводим имена файлов
    cout << "Enter the name of the input file:" << endl;
    cin >>  fileNameIn  ;
    cout << "\nInput file: " << fileNameIn << endl;

    cout << "Enter the name of the output file:" << endl;
    cin >> fileNameOut ;
    cout << "\nOutput file: " << fileNameOut << endl;
    

    int counter=0; //счетчик строк
    int counterLines=0; //количество повторяющихся строк
    int lineNumber=0;   //Номер строки с которой повтор

    char strc_old[1000] ;

    bool foutFlag = false;
    bool foutFlag2 = false;
    //пробуем открыть текстовый файл на запись
    if ((f_output = fopen(fileNameOut, "w")) != NULL)
        {
        foutFlag = true;
        }

    if ((f_output2 = fopen("outtext.txt", "wt")) != NULL)
        {
        foutFlag2 = true;
        }



    //пробуем открыть текстовый файл на чтение
    if ((f_input = fopen(fileNameIn, "rt")) != NULL)
    {
        char str[1000];       //создаём строку(буфер для чтения) размером 1000.
        //char str2[1000];       //создаём строку(буфер для записи) размером 1000.
        while (!feof(f_input))    //пока не конец файла in ,мы исполняем цикл.
        {
            counter++;
          //  cout << counter;
          
            fgets(str, 1000, f_input); //Читаем строку из файла в стр.
            //s1 = str; // str у нас char присвоением неявно приводим к string
            if ( strcmp(str,strc_old)==0)  //если строка равна предыдущей то 
                //if (s1 == str_old)  //если строка равна предыдущей то 
            {
                if (counterLines == 0)   
                {
                    lineNumber = counter-1; //если это первый повтор то запоминаем номер первой строки повтора (я сначала тут лопухнулся... текущий номер ставил)
                }
                counterLines ++; //увеличиваем счетчик повторов - не забываем что он с 0!!!!
            }
            else
            {
                //тут наверное надо записать в файл строку str_old, counterLines, lineNumber если у нас повтор т.е. counterLines>0
                //можно отдельно а можно как в вашем примере-структурой outputResult
                if (counterLines > 0)
                {   

                    cout << "'" << strc_old << "'" << " repeats " << counterLines + 1 << " times from line " << lineNumber << endl;
                    rec->repeatingLine = strc_old;
                    rec->countLine = counterLines + 1;
                    rec->lineNumber = lineNumber;
                    fwrite(rec, sizeof(OutputResult), 1, f_output); //проверку на открытость забыл
                    
                    //а это в текстовик для проверки
                    fprintf(f_output2, "%s","String '");
                    fprintf(f_output2, "%s", strc_old);
                    fprintf(f_output2, "%s", "' repeats ");
                    fprintf(f_output2, "%d",(counterLines + 1));
                    fprintf(f_output2, "%s", " times from line ");
                    fprintf(f_output2, "%d", lineNumber);
                    fprintf(f_output2, "%s", "\n");

                    //fclose(f_output2);//не забываем закрыть файлик;
                  //  fputs(, f_output);
                    // обнуляем наши счетчики
                    counterLines = 0;
                    lineNumber = 0;
                }
            }
            
            strcpy(strc_old, str);  //запоминаем текущую строку
        }
        fclose(f_input);
    }

    else 
    {
    // а тут пишем если файл не открылся по какой-либо причине
    cout << "Do not open file "<< fileNameIn << endl;
    }

    if (foutFlag)
    { 
        fclose(f_output);//не забываем закрыть файлик;
    } 

    if (foutFlag2)
    {
        fclose(f_output2);//не забываем закрыть файлик;
    }


    return 0;
}