#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
    string str;
    getline(cin, str);
    
    vector<int> v;
    string temp = "";
    for(int i=0; i <= str.size(); i++)
    {
        if(i == str.size() || str[i] == ' ')
        {
            v.push_back(stoi(temp));
            temp = "";
        }
        temp += str[i];
    }
    string answer = "Good";
    for(int i=1; i < v.size(); i++)
    {
        if(v[i-1] > v[i])
        {
            answer = "Bad";
            break;
        }
    }
    cout << answer << endl;

    return 0;
}