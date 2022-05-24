#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    vector<pair<int, int>> v;

    for(int i=0; i < priorities.size(); i++)
        v.push_back(pair<int, int>(priorities[i], i));
    
    for(int i=0; i < v.size(); i++)
    {
        int max=v[i].first; 
        int idx=0;
        for(int j=i; j < v.size(); j++)
            if(max < v[j].first)
            {
                max = v[j].first;
                idx = abs(i-j);
            }

        for(int j=0; j < idx; j++)
        {
            int fir = v[i].first;
            int sec = v[i].second;
            v.erase(v.begin()+i);
            v.push_back(pair<int, int>(fir, sec));
        }
    }
    int answer = 0;
    for(int i=0; i < v.size(); i++)
        if(v[i].second == location)
            answer = i+1;
       
    return answer;
}
// 4 5 6 1 2 3
int main()
{
    vector<int> v = {3,1,4,1,5,9,2};
    cout << solution(v, 0) << endl;
    return 0;
}