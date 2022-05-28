#include <iostream>
#include <string>

using namespace std;

//  123,456 = 3

int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        string str;
        cin >> str;
        string a="", b="";
        for(int i=0; i < str.size(); i++)
        {   // a = 123 
            if(str[i] != ',')
                a += str[i];
            else
            {
                b = a;
                a="";
            }
        }
        cout << stoi(a) + stoi(b) << endl; 
    }
    return 0;
}