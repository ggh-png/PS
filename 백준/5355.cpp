#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        string str;
        vector<char> v;
        double answer = 0;
        double tmp;
        cin >> tmp;
        getline(cin, str);
        for(auto &el : str)
            if(el != ' ')
                v.push_back(el);
        answer = tmp;
        for(auto &el : v)
        {
            if(el == '@')
                answer *=3;
            else if(el == '%')
                answer +=5;
            else if(el == '#')
                answer -=7;
        }
        cout << fixed;
        cout.precision(2);
        cout << answer << endl;
    }
    return 0;
}