#include <iostream>
#include <queue>

using namespace std;

/*
하단의 요소를 삭제, 첫 요소와 끝 요소의 스왑 
work flow
1 2 3 4
2 3 4
3 4 2
4 2 
2 4
4
*/

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int num;
    queue<int> q; 
    cin >> num;
    for(int i=1; i <= num; i++)
        q.push(i);
    // 1 2 3 4 
    while (!(q.size() == 1))
    {
        q.pop();
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
    cout << q.front() << '\n';
    
    return 0;
}