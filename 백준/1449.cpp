#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main()
{
    // 구멍의 개수, 테이프의 길이 
    // 구멍의 위치
    // 구멍을 막기위한 최소의 테이프의 개수를 구하여라. 
    int num, L;
    cin >> num >> L;
    vector<int> x(num);
    for(int i=0; i < num; i++)
        cin >> x[i];
    
    // 오름차순 정렬 
    // 1 2 5 6 8
    // L 2
    // answer 3
    // a - b + 1 == 구멍의 크기

    sort(x.begin(), x.end());
    // 구멍의 크기
    int answer = 0;
    
    while(!x.empty())
    {
        int len  = L; // 테잎 길이 
        int idx  = 0;
        int temp = 0;
        while(temp <= len) // 구멍의 크기가 테잎의 길이보다 길어지면 
        {
            temp = x[idx] - x[0] + 1;
            idx++;
            if(idx == x.size())
                break;
        }
        answer++; // 구멍 크기를 막고, 테잎의 개수 증가 
        if(temp > len)
            x.erase(x.begin(), x.begin() + idx - 1);
        else if(idx == x.size() && temp <= len)
            x.clear();  

    }
    cout << answer << endl; 

    return 0;
}