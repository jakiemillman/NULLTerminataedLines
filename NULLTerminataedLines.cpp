// NULLTerminataedLines.cpp
#include <iostream>
#include <Windows.h>
using namespace std;

int StrLeght(const char* str);
void ToUpper(char str[]);
void ToLower (char str[]);
void shrink(char str[]);
bool is_palindrome(const char str[]);
bool is_int_number(const char str[]);
int  to_int_number(const char str[]);
bool is_bin_number(const char str[]);

int main()
{
    setlocale(LC_ALL, "");
    //char str[]{ 'H','e','l','l','o',0 };
    //cout << str << endl;
    //char str[] = "Hello";
    //cout << str << endl;
    //cout << sizeof(str) << endl;
    const int n = 50;
    char str[n]{};
    int leght;
    bool result = true;
    bool result1 = true;
    bool result2 = true;
    int number;
    cout << "Введите строку: "; //cin >> str; 
    SetConsoleCP(1251);
    cin.getline(str,n);
    SetConsoleCP(866);
    cout << str << endl;
    leght = StrLeght(str);
    cout << leght << endl;
    ToUpper(str);
    cout << str << endl;
    ToLower(str);
    cout << str << endl;
    shrink(str);
    cout << str << endl;
    result = is_palindrome(str);
    if (result)cout << "Строка является полиндромом" << endl;
    else cout << "Строка не является полиндромом" << endl;
    result1 = is_int_number(str);
    if (result1)cout << "Строка является 10-м числом"<<endl;
    else cout << "Строка не является 10-м числом" << endl;
    cout << to_int_number(str)<<endl;
    result2 = is_bin_number(str);
    if (result2)cout << "Строка является 2-м числом" << endl;
    else cout << "Строка не является 2-м числом" << endl;


    
}

int StrLeght(const char* str)
{ 
    int i = 0;
    while (str[i])i++;
    return i;
}

void ToUpper(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        if(str[i]>'a' && str[i] <'z')str[i] -= 32;
        if (str[i] > 'а' && str[i] < 'я')str[i] -= 32;
    }
}

void ToLower(char str[])
{
    for (int i = 0; str[i]; i++)
    {
        if (str[i] > 'A' && str[i] < 'Z')str[i] += 32;
        if (str[i] > 'А' && str[i] < 'Я')str[i] += 32;
    }
    
}

void shrink(char str[])
{
    int i = 0;
    int n = 20;
    while (i < n - 1)
    {
        if (str[i] == ' ' && str[i + 1] == ' ')
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                str[j] = str[j + 1];
            }
        }
        else
        {
            i++;
        }
    }

   
}

bool is_palindrome(const char str[])
{
    int n = StrLeght(str);
    int m = n;
    for (int i = 0; i < n; i++)
    {
        if (n % 2 == 0)
        {
            for (int j = 0; j < m / 2; j++)
            {
                if (str[j] == str[--n])
                {
                    if (j == m / 2-1)
                    {
                        return true;
                    }
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            for (int j = 0; j < m / 2; j++)
            {

                if (str[j] == str[--n])
                {
                    if (j == m / 2-1)
                    {
                        return true;
                    }
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        
    }
    
}

bool is_int_number(const char str[])
{
    int n= StrLeght(str);
    for (int i = 0; i < n; i++)
    {
        if (str[i]<='9' && str[i]>='0')
        {
            if (i == n - 1)
            {
                return true;
            }
            continue;
        }
        else
        {
            return false;
        }
        
    }
}

int to_int_number(const char str[])
{
    int digit = 0;
    int number = 0;
    int n = StrLeght(str); 
    for (int i = 0; i < n; i++)
    {
        digit = (int)str[i] - (int)'0';
        number =number*10 + digit;
    }
    return number;   
}

bool is_bin_number(const char str[])
{
    int n = StrLeght(str);
    for (int i = 0; i < n; i++)
    {
        if (str[i] == '0' || str[i] =='1')
        {
            if (i == n - 1)
            {
                return true;
            }
            continue;
        }
        else
        {
            return false;
        }

    }
}
