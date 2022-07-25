#include <iostream>
#include <set>

using namespace std;

int main()
{
    string str;
    
    cin >> str;

    set<string> strSet;

    for(int i=0; i < str.size(); i++)
    {
        string tmp="";
        for(int j=i; j < str.size(); j++)
        {
            tmp += str[j];
            strSet.insert(tmp);
        }
    }
    cout << strSet.size() << endl;
    return 0;
}