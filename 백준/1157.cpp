#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string str;
    vector<int> abc(26, 0);
    cin >> str;
    for(auto &el : str)
    {
        if(el < 97)
            abc[el + 32 - 97]++;
        else
            abc[el - 97]++;
    }
    int max=0, idx;
    char answer;
    for(int i=0; i < abc.size(); i++)
    {
        if(abc[i] > max)
        {
            max = abc[i];
            answer = i + 65;
        }
        else if(abc[i] == max)
            answer = '?';           
    }
    cout << answer << '\n';
    return 0;
}