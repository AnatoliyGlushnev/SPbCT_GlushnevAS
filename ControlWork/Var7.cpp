#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std::string_literals;
using namespace std;
class Raspisanie 
{
public:
    int i = 0, j = 0;
    int formrasp() 
    {
        fstream MF;
        MF.open("data.txt");
        string svalka;
        while (MF.good()) 
        {
            getline(MF, svalka, '\n');
            i++;
        }
        MF.close();
        MF.open("data.txt");
        int a;
        bool n = true;
        string dat, day, pred, aud, zap = ",", per = "\n", time;
        cout << "Укажите нужный Вам день, например 'Понедельник': ";
        cin >> day;
        while (MF.good()) 
        {
            getline(MF, dat, ',');
            getline(MF, svalka, '\n');
        }
        MF.close();
    a:
        cout << "Введите время начала пары: ";
        cin >> time;
        cout << "Введите название дисциплины: ";
        cin >> pred;
        cout << "Введите номер аудитории: ";
        cin >> aud;
        MF.open("data.txt", std::ios::app);
        MF << per << day << zap << time << zap << pred << zap << aud;
        MF.close();
        return 0;
    };
    int coutraspdate() 
    {
        int n = 0;
        string dat, vremya, pred, aud, svalka, day;
        cout << "Укажите нужный Вам день, например 'Понедельник': ";
        cin >> day;
        fstream MF;
        MF.open("data.txt");
        while (MF.good()) 
        {
            getline(MF, dat, ',');
            if (dat == day) {
                getline(MF, vremya, ',');
                getline(MF, pred, ',');
                getline(MF, aud, '\n');
                cout << vremya << ":00" << " " << pred << " " << aud << " ауд." << "\n";
                n++;
            }
            else 
            {
                getline(MF, svalka, '\n');
            }
        }
        if (n == 0) 
        {
            cout << "На указанный день нет расписания\n";
        }
        return 0;
    }
    int coutrasp() {
        string dat, vremya, pred, aud;
        int i = 0;
        string week[6] = { "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота" };
        fstream MF;
        MF.open("data.txt");
        while (MF.good()) 
        {
            getline(MF, dat, ',');
            getline(MF, vremya, ',');
            getline(MF, pred, ',');
            getline(MF, aud, '\n');
            if (dat == week[0]) 
            {
                cout << "Понедельник\n";
                cout << vremya << ":00" << " " << pred << " " << aud << " ауд." << "\n";
            }
            if (dat == week[1]) 
            {
                cout << "Вторник\n";
                cout << vremya << ":00" << " " << pred << " " << aud << " ауд." << "\n";
            }
            if (dat == week[2]) 
            {
                cout << "Среда\n";
                cout << vremya << ":00" << " " << pred << " " << aud << " ауд." << "\n";
            }
            if (dat == week[3]) 
            {
                cout << "Четверг\n";
                cout << vremya << ":00" << " " << pred << " " << aud << " ауд." << "\n";
            }
            if (dat == week[4]) 
            {
                cout << "Пятница\n";
                cout << vremya << ":00" << " " << pred << " " << aud << " ауд." << "\n";
            }
            if (dat == week[5]) 
            {
                cout << "Суббота\n";
                cout << vremya << ":00" << " " << pred << " " << aud << " ауд." << "\n";
            }
        }
        MF.close();
        return 0;
    }
    int udal() 
    {
        string dat, vremya, pred, aud, zap = ",", per = "\n";
        int i = 1, j = 0, nomer, chisl = 0;
        fstream MF;
        MF.open("data.txt");
        fstream COPY;
        COPY.open("copy.txt");
        while (MF.good()) 
        {
            getline(MF, dat, ',');
            getline(MF, vremya, ',');
            getline(MF, pred, ',');
            getline(MF, aud, '\n');
            cout << i << ". " << dat << " " << vremya << ":00" << " " << pred << " " << aud << "\n";
            i++;
        }
        MF.close();
        MF.open("data.txt");
        cout << "Введите номер строки, которую надо удалить: ";
        cin >> nomer;
        i = 1;
        while (MF.good()) 
        {
            getline(MF, dat, ',');
            getline(MF, vremya, ',');
            getline(MF, pred, ',');
            getline(MF, aud, '\n');
            if (nomer == i) 
            {
                cout << "\nСтрока номер " << i << ". " << dat << " " << vremya << ":00" << " " << pred << " " << aud << " Удалена";
                chisl = 1;
            }
            else 
            {
                if (j == 0) 
                {
                    COPY << dat << zap << vremya << zap << pred << zap << aud;
                    j++;
                }
                else 
                {
                    COPY << per << dat << zap << vremya << zap << pred << zap << aud;

                }
            }
            i++;
        }
        MF.close();
        COPY.close();
        if (chisl == 0) 
        {
            cout << "Строки с таким номером нет\n";
        }
        else if (chisl == 1) {
            rename("data.txt", "copy1.txt");
            cout << "\n";
            rename("copy.txt", "data.txt");
            cout << "\n";
            rename("copy1.txt", "copy.txt");
            remove("copy.txt");
            ofstream oFile("copy.txt");
        }
        return 0;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, ".1251");
    Raspisanie raspisanie;
    int a = 0;
    cout << "Список команд:\n1 - добавить запись\n2 - посмотреть расписание на конкретный день\n3 - посмотреть всё расписание\n4 - удалить запись\n5 - завершить программу" << endl;
    while (a != 5)
    {
        cout << "\nКоманда:";
        cin >> a;
        switch (a)
        {
        case 1:
            raspisanie.formrasp();
            break;
        case 2:
            raspisanie.coutraspdate();
            break;

        case 3:
            raspisanie.coutrasp();
            break;
        case 4:
            raspisanie.udal();
            break;
        case 5:
            break;
        default:
            cout << "Введено некорректное значение" << endl;
            break;
        }
    }
}
