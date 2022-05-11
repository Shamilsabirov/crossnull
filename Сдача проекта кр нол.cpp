// Сдача проекта кр нол.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <windows.h>
using namespace std;


//вывод ит поле изменённое
void createPole1(char array[10][10]) {
    cout << "0 1 2 3 4 5 6 7 8 9 " << endl;
    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 10; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
//создаёт поле
void createPole(char array[10][10]) {
    cout << "0 1 2 3 4 5 6 7 8 9 " << endl;
    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 10; j++)
        {
            array[i][j] = '.';
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

bool checkWin(const char(*)[10]);
void checkComp( char(*) [10], bool&);



int main()
{

    /* setlocale(LC_ALL, "rus");*/
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));
    char array[10][10];
    createPole(array);
    int x, counter = 0;
    
    bool flag = false;
    
    while (true)
    {
        bool flag1 = false;
        cout << "введите позицию:" << endl;
        cin >> x;
        

        for (int i = 9; i >= 0; i--)
        {
            if (array[i][x] == '.')
            {
                array[i][x] = 'x';
                break;
            }
            else  continue;
        }
        counter++;
        
        if (counter >= 4) flag = checkWin(array);
        if (counter >= 3) checkComp(array,flag1);
        if (flag)
        {
            system("cls");
            createPole1(array);
            cout << "you Win!";
            break;
        }

        if (flag1)
        {
            system("cls");
            createPole1(array);
            continue;
        }

        else
        { 
        for (int i = 9; i >= 0; i--)
        {
            int k = 0;
            for (int j = 0; j <= 9; j++)
            {
            if (array[i][j] == '.') k++;
            }
            if (k == 0) continue;
            int n;
            n = rand() % 10;
            
            while(x == n || array[i][n] != '.')
            { 
                n = rand() % 10;
            }
            
            array[i][n] = 'o';
            
            break;
        }
        }
        if (counter >= 4)
        {
            flag = checkWin(array);
        }
        if(flag)
        { 


        system("cls");
        createPole1(array);
        cout << "comp Win!";
        break;
        }
        system("cls");
        createPole1(array);
    }
    return 0;
    
}


bool checkWin(const char(*mas)[10])
{
    int c = 0;
    int k = 0;
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < 10; j++)
        {
            if (mas[i][j] == 'x')
            {
                k++;
                c = 0;
            }
            else if (mas[i][j] == 'o')
            {
                
                k = 0;
                c++;

            }
            else
            {
                c = 0;
                k = 0;
            }
            if (k == 4)return true;
            if (c == 4)
            {
                cout << "comp win";
                return true;
            }
        }
        k = 0;
        c = 0;
        for (int s = 9; s >= 0; s--)
        {
            if (mas[s][9 - i] == 'x')
            {
                k++;
                c = 0;
            }
            else if (mas[s][9 - i] == 'o')
            {
                k = 0;
                c++;
            }
            else
            {
                k = 0;
                c = 0;
            }
            if (k == 4)return true;
            if (c == 4)
            {
                cout << "comp win";
                return true;
            }
        }
        k = 0;
        c = 0;
    }
    return false;
}

void checkComp( char(*arr)[10], bool &fl)
{
    int k = 0;
    for (int i = 9; i >= 0; i--)
    {
        for (int j = 0; j < 10; j++)
        {
            if (arr[i][j] == 'x')++k;
            else k = 0;
            if (k == 3  )
            {
                
                if (j != 9 &&  arr[i][j + 1] == '.')//проверяем свободные клетки справа 
                { 
                    fl = true;//нашёл 3 x(отменяет выполнение рандомного нолика-ход компа)
                    arr[i][j + 1] = 'o';
                    return;
                }
                else if (j != 0 && arr[i][j - 3] == '.')//и слева
                {
                    fl = true;
                    arr[i][j - 3] = 'o';
                    return;
                }
            }
        }
        k = 0;
        for (int s = 9; s >= 0; s--)
        {
            
            if (arr[s][9 - i] == 'x')++k;
            else k = 0;
            if (k == 3)
            {
                if (s != 0 && arr[s - 1][9 - i] == '.')
                {
                    fl = true;
                    arr[s - 1][9 - i] = 'o';
                    return;
                }
                else if (s != 9 && arr[s + 3][i] == '.')
                {
                    fl = true;
                    arr[s + 3][9 - i] = 'o';
                    return;
                }
            }
            
        }
       
    }
    
}