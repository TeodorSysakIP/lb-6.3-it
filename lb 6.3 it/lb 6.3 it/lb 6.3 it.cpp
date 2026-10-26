

#include <iomanip>
#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;


bool IsNonIncreasing(int* a, const int size);

template <typename T>
bool IsNonIncreasing(T* a, const int size);


template <typename T>
void PrintArray(T* a, const int size, const int width);


int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    const int n = 8;

    int a[n] = { 9, 7, 7, 5, 4, 2, 2, 1 };
    PrintArray(a, n, 4);
    cout << "IsNonIncreasing(a, n)      = " << boolalpha << IsNonIncreasing(a, n) << endl;
    cout << "IsNonIncreasing<int>(a, n) = " << IsNonIncreasing<int>(a, n) << endl << endl;

    int b[n] = { 9, 7, 8, 5, 4, 2, 2, 1 };
    PrintArray(b, n, 4);
    cout << "IsNonIncreasing(b, n)      = " << IsNonIncreasing(b, n) << endl;
    cout << "IsNonIncreasing<int>(b, n) = " << IsNonIncreasing<int>(b, n) << endl << endl;

    double c[n] = { 9.5, 8.25, 8.25, 3.0, 2.5, 1.1, 0.0, -4.7 };
    PrintArray(c, n, 7);
    cout << "IsNonIncreasing<double>(c, n) = " << IsNonIncreasing<double>(c, n) << endl << endl;
    
    string d[n] = { "zeta", "yankee", "yankee", "delta", "charlie", "bravo", "alpha", "alpha" };
    PrintArray(d, n, 9);
    cout << "IsNonIncreasing<string>(d, n) = " << IsNonIncreasing<string>(d, n) << endl;

    return 0;
}



bool IsNonIncreasing(int* a, const int size)
{
    for (int i = 0; i < size - 1; i++)
        if (a[i] < a[i + 1])      
            return false;
    return true;
}

template <typename T>
bool IsNonIncreasing(T* a, const int size)
{
    for (int i = 0; i < size - 1; i++)
        if (a[i] < a[i + 1])
            return false;
    return true;
}

template <typename T>
void PrintArray(T* a, const int size, const int width)
{
    for (int i = 0; i < size; i++)
        cout << setw(width) << a[i];
    cout << endl;
}