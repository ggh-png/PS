#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num; 
    cin >> num;
    for(int i=0; i < num; i++)
    {
        string str;
        int answer = 0;
        cin >> str;
        int cnt = 0;
        for(auto &el : str)
        {
            if(el == 'X')
                cnt = 0;
            else
            {
                cnt++;
                answer += cnt;
            }
        }
        cout << answer << '\n';
    }
    return 0;
}