#include <iostream>
using namespace std;

void task1()
{
    int n;
    int n1 = 0;
    int x = -1;
    cout << "Count of strings? ";
    cin >> n;
    while (n1 != n)
    {
        while (x != n1)
        {
            x++;
            cout << x;
        }
        x = -1;
        n1++;
        cout << "\n";
    }
    cout << "\n";
}

void task2()
{
    long double n;
    cout << "Number of string? ";
    cin >> n;
    long double m = 1;
    for (int i = 0; i < n; i++)
    {
        cout << m;
        cout << " ";
        m = m * (n - i) / (i + 1);
    }
    cout << m << endl;
}

void task3()
{
    int n = 1;
    int s = 0;
    int i = -1;
    while (n != 0)
    {
        cin >> n;
        s = s + n;
        i++;
    }
    cout << s / double(i) << endl;
}
int main()
{
    int choice = 0;
    while (true)
    {
        cout << "Choose exercise\n"
        << "1. Triangel\n"
        << "2. Binocular\n"
        << "3. Sred aref\n"
        << "4. Exit\n";
        cin >> choice;
        switch (choice)
        {
            case 1:
            
                task1();
                break;
                
            case 2:
            
                task2();
                break;
                
            case 3:
                
                cout << "\n";
                task3();
                break;
            
            default:
            
                cout << "Bye bye world!";
                return 0;
                
        }
    }
}
