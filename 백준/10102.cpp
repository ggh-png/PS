#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    string str;
    cin >> str;
    int a=0, b=0;
    for(auto &el : str)
    {
        if(el == 'A')
            a++;
        else
            b++;
    }
    string answer;
    if(a > b)
        answer = "A";
    else if(a < b)
        answer = "B";
    else
        answer = "Tie";
        
    cout << answer << endl;
    return 0;
}