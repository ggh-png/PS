#include <iostream>
#include <string>
#include <deque>
using namespace std; 
/* 
test case num 
order 
test resource
*/
int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int num;
    cin >> num;

    deque<string> answer;
    for(int i=0; i < num; i++)
    {
        string OrderList;
        string tmp="";
        int N;
        deque<int> L;
        string gb;
        cin >> OrderList >> N >> gb;
        // 리스트 추출
        // [1,2,3,4] -> 1 2 3 4
        for(int j=1; j < gb.size()-1; j++)
        {
            if(gb[j] != ',')
            {
                if(gb[j+1] == ']')
                {
                    tmp += gb[j];
                    L.push_back(stoi(tmp));
                }
                else  
                    tmp += gb[j];
            }
            else
                if(tmp != "")
                {
                    L.push_back(stoi(tmp));
                    tmp = "";
                }
        }
        // 명령어 처리 
        // 매번마다 reverse를 해주면 시간초과가 발생하기에
        // 덱의 특성을 이용한다. 
        int R_count = 0;
        bool err = false;
        for(auto &el : OrderList)
        {
            if(!L.empty() && el == 'R')
                R_count++;  
            else if(!L.empty() && el == 'D')
            {
                if(R_count%2 == 0)
                    L.pop_front();
                else
                    L.pop_back();
            }
            // 에러가 발생하는 경우 
            else if(L.empty() && el == 'D')
            {
                err = true;
                answer.push_back("error");
                break;
            }
        }
        if(!L.empty())
        {
            string temp = "[";
            if(R_count%2 == 0)
            {
                while(!L.empty())
                {
                    temp += to_string(L.front()) + ","; 
                    L.pop_front();
                }
                temp.pop_back();
                temp += "]";
                answer.push_back(temp);
            }
            else
            {
                while(!L.empty())
                {
                    temp += to_string(L.back()) + ","; 
                    L.pop_back();
                }

                temp.pop_back();
                temp += "]";
                answer.push_back(temp);
            }
        }
        else if(L.empty() && err == false)
            answer.push_back("[]");
        else
            continue;
    }
    while(!answer.empty())
    {
        cout << answer.front() << '\n';
        answer.pop_front();
    }
    return 0;
}