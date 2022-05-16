#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    string str;
    int answer = 0;
    // 연속되는 중복값 제거 
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        bool flag = false;
        cin >> str;
        vector<int> v(26, 0);
        str.erase(unique(str.begin(), str.end()), str.end());

        for(int i=0; i < str.size(); i++) 
            v[str[i] - 97]++;
        
        for(auto &el : v)
            if(el >= 2)
                flag = true;

        if(!flag)
            answer++;
    }
    cout << answer;
    return 0;
}