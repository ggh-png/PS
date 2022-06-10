#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    string tmp="";
    int answer = 0;
    for(int i=0; i <= str.size(); i++)
    {
        if(str[i] == ' ' || i == str.size())
        {
            if(stoi(tmp) > 0) 
                answer++;
            tmp = "";
        }
        else
            tmp += str[i];    
    }
    cout << answer << endl;
    return 0;
}