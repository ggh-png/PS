#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 주어진 알파벳에서 모음 2개 이상 추출 
int n, r;

string mo = "aeiou";
// 비밀번호를 만들 알파벳 모음 
vector<char> tmp_v;
// 조합 
vector<char> v;
vector<char> mo_v;
vector<char> ja_v;
vector<char> vv;
bool visited[130];
bool visited2[130];


// 모음 개수, 뽑힌 알파뱃의 총 개수 
void combi(int idx)
{
    if(tmp_v.size() == r)
    {
        for(auto &el : tmp_v)
            cout << el;
        cout << endl;
        return;
    }
    for(int i=idx; i < v.size(); i++)
    {
        if(!visited2[v[i]])
        {
            visited2[v[i]] = 1;
            tmp_v.push_back(v[i]);
            combi(idx + 1);
            tmp_v.pop_back();
            visited2[v[i]] = 0;
        }
    }
}



void make_arr(int idx)
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
        else
        {
            //v.clear();
            return;
        }
    }
    // 조건을 만족하지 못한 경우 
    for(int i=idx+1; i < r; i++)    
    {  
        v.push_back(vv[i]);
        make_arr(i);
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
    make_arr(-1);

    //cout << vv.size() << endl;
    return 0;
}