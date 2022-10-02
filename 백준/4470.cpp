#include <iostream>

using namespace std;


int main()
{
    int num;
    cin >> num;
    cin.ignore();
    for(int i=1; i <= num; i++)
    {
        string str;
        getline(cin, str);
        cout << i << ". " << str << endl; 
    }
    return 0;
}