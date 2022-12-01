#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class vita
{
public:
    int a=0, b=0, c=0, d=0, e=0;
};

class result
{
public:
    int a, b, c, d, e;
    string f;
};


int num;
vector<vita> v;
int q, w, e, r, t;
int limA, limB, limC, limD;

string ans = "";
vector<result> answer;

bool comapre(result a , result b)
{   // 금액이 같으면 사전순으로 정렬 
    if(a.e == b.e)
        return a.f > b.f;
    return a.e > b.e;
}


int main()
{
    cin >> num;
    cin >> limA >> limB >> limC >> limD;
    for(int i=0; i < num; i++)
    {
        cin >> q >> w >> e >> r >> t;
        v.push_back({q, w, e, r, t});
    }
    // 모든 경우의 수 
    // 6   64
    for(int i=0; i < (1 << num); i++)
    {
        vita lim;
        vector<int> N;
        for(int j=0; j < num; j++)
            if(i & (1 << j))
            {
                lim.a += v[j].a;
                lim.b += v[j].b;
                lim.c += v[j].c;
                lim.d += v[j].d;
                lim.e += v[j].e;
                // 비타민 번호 index 
                N.push_back(j+1);
                // limit 조건에 충족 하면 
                if(lim.a >= limA && lim.b >= limB && lim.c >= limC && lim.d >= limD)
                {
                    ans = "";
                    for(auto &el : N)
                        ans += to_string(el) + " ";
                    result tmp;
                    tmp.a = lim.a;
                    tmp.b = lim.b;
                    tmp.c = lim.c;
                    tmp.d = lim.d;
                    tmp.e = lim.e;
                    tmp.f = ans;
                    answer.push_back(tmp);
                }
            }
    }
    // 조건에 충족한 정답이 있다면 
    if(answer.size())
    {
        sort(answer.rbegin(), answer.rend(), comapre);
        cout << answer.front().e << endl << answer.front().f << endl;
    }
    else
        cout << -1 << endl;
    return 0;
}