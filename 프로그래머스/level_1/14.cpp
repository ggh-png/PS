#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = n + reserve.size();
    int tempLost = 0;
    vector<int> spare;
    answer -= lost.size();
    for(int i=0; i < lost.size(); i++)//여벌
    {
        if(lost[i] == 1)
        {
            spare.push_back(2);
            spare.push_back(1);
        }
        else if(lost[i] == n)
        {
            spare.push_back(n-1);
            spare.push_back(n);
        }
        else 
        {
            spare.push_back(lost[i]+1);
            spare.push_back(lost[i]-1);
            spare.push_back(lost[i]);  
        }
    }

    sort(spare.begin(), spare.end());
    spare.erase(unique(spare.begin(), spare.end()), spare.end());
    
    sort(reserve.begin(), reserve.end());


 
    for(int i=0; i < reserve.size(); i++)
        for(int j=0; j < spare.size(); j++)
            tempLost += reserve[i] == spare[j] ? 1 : 0;

    if(tempLost >= lost.size())
        tempLost = lost.size();
    answer += tempLost;
    cout << answer << endl;

    for(auto el : spare)
        cout << el << " ";
    cout << endl;

    cout << tempLost << endl;
    return answer;
}

int main()
{
    int n = 9;
    vector<int> lost{1, 3, 6, 9};
    vector<int> reserve{2, 8, 6};
    solution(n, lost, reserve);
    return 0;
}

