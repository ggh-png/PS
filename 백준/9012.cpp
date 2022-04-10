#include <iostream>
#include <vector>

using namespace std;

// (( )) (( ))
// 왼 오른의 비율을 따져 결과값 표츌 


int main()
{
    int num; 
    vector<string> OrderList; // input
    vector<string> answer;    // output
    cin >> num;    
    for(int i=0; i < num; i++)
    {
        string temp; 
        cin >> temp;
        OrderList.push_back(temp);
    }
    for(int i=0; i < OrderList.size(); i++)
    {
        int tmp = 0;
        for(int j=0; j < OrderList[i].size(); j++)
        {
            tmp += OrderList[i][j] == '(' ? 1 : -1;
            if(tmp < 0)
                break;
        }
        string result = tmp == 0 ? "YES" : "NO";
        answer.push_back(result);
    }
    for(auto el : answer)
        cout << el << endl; 
}