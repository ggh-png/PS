#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    char c;
    cin >> a >> c >> b;
    if(c == '*' && a.size() > b.size())
    {
        for(int i=0; i < b.size()-1; i++)
            a.push_back('0'); 
        cout << a << endl;
    }
    else if(c == '*' && a.size() <= b.size())
    {
        for(int i=0; i < a.size()-1; i++)
            b.push_back('0');         
        cout << b << endl;
    }   
    else if(c == '+' && a.size() > b.size())
    {
        a[a.size() - b.size()] = '1';
        cout << a << endl; 
    }
    else if(c == '+' && a.size() < b.size())
    {
        b[b.size() - a.size()] = '1';
        cout << b << endl;
    }
    else if(c == '+' && a.size() == b.size())
    {
        a[0] = '2';
        cout << a << endl;
    }

    return 0;
}