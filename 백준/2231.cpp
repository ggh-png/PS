#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
    int num;
    cin >> num;
    // 10 
    int cnt = num;
    vector<int> v;
    while(cnt > 0)
    {
        cnt--;
        int temp = cnt;
        string str = to_string(cnt);
        for(auto &el : str)
            temp += el - 48;
        
        if(temp == num)
            v.push_back(cnt);
    }
    if(!v.empty())
        cout << v.back();
    else
        cout << "0";
    return 0;
}

