#include <queue>
#include <iostream>

using namespace std;


priority_queue<int, vector<int>, greater<int>> pq;

// 우선순위 큐에 데이터 삽입
int main()
{
    int num;
    cin >> num;

    for(int i=0; i < num; i++)
    {
        int tmp;
        cin >> tmp;
        pq.push(tmp);
    }
    int sum=0;
    while(pq.size() > 1)
    {
        int a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();
        sum += a + b;
        pq.push(a + b);
    }
    cout << sum;
    return 0;

}