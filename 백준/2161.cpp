#include <iostream>
#include <queue>

using namespace std;


int main()
{
    int num;
    
    cin >> num;

    queue<int> q;

    for(int i=1; i <= num; i++)
        q.push(i);

    while(q.size() != 0)
    {
        cout << q.front() << " ";
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << endl;
    return 0;
}