/* подключение необходимых библиотек */
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fstream>
#include <string.h>
#include <iostream>

using namespace std;

int pros1, pros2, pros3, N;
void f1(int), f2(int), f0(int);

ofstream vivod;

int main()
{
    setlocale(LC_ALL, ".1251");
    vivod.open("vivod.txt");                    //Вывод в тхт
    cout << "N = ";
    cin >> N;
    setpgrp();
    pros1 = getpid();
    pros2 = fork();
    if (pros1 == 0)
    {                                           //первый процесс
        signal(SIGUSR2, f1);
        pros1 = getpid();
        pros2 = fork();
        if(pros2 == 0)
        {
            pros2 = getpid();
            signal(SIGUSR2, f2);
        }
    }

    else

    {                                            //Родительский процесс
        signal(SIGUSR2, SIG_IGN);
        signal(SIGUSR1, f0);
        kill(pros1, SIGUSR2);
        kill(pros2, SIGUSR2);
    }
    return 0;
}

void f1 (int signum)
{
    for (int i = 0; i < N; i++)
    vivod << "Pr1: " << i << endl;
    kill(pros1, SIGUSR1);
}

void f2 (int signum)
{
    for (int i = 0; i < N; i++)
    vivod << "Pr2: " << i << endl;
    kill(pros1, SIGUSR1);
}

void f0 (int signum)
{
    ifstream out("vivod.txt");                  //Вывод в тхт
    string x;
    while (out)
    {
        out >> x;
        cout << x << endl ;
    }
}