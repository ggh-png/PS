#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 주어진 알파벳에서 모음 2개 이상 추출 
int n, r;

string mo = "aeiou";
// 조합 
vector<char> v;
vector<char> vv;


void combi(int idx)
{
    // 조건을 만족할 경우 
    if(v.size() == n)
    {
        int ja_cnt = 0;
        int mo_cnt = 0;
        for (auto &el : v)
        {
            bool flag = 1;
            for(int i=0; i < mo.size(); i++)
                if(el == mo[i])
                {
                    mo_cnt++;
                    flag = 0;
                    break;
                }
            if(flag)
                ja_cnt++;
        }
        if(mo_cnt >= 1 && ja_cnt >= 2)
        {
            for(auto &el : v)
                cout << el;
            cout << endl;
            //return;
        }
    }
    // 조건을 만족하지 못한 경우 
    for(int i=idx+1; i < r; i++)    
    {  
        v.push_back(vv[i]);
        combi(i);
        v.pop_back();
    } 
        return;
}



int main()
{
    cin >> n >> r;
    for(int i=0; i < r; i++)
    {
        char tmp;
        cin >> tmp;
        vv.push_back(tmp);
    }
    sort(vv.begin(), vv.end());
    combi(-1);
    return 0;
}