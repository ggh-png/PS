#include<iostream>
using namespace std; 

int main()
{
    double a,b;
    cin >> a >> b;
    double c = a / b;
    cout.setf(ios::fixed);
    cout.precision(9);
    cout << c;
}