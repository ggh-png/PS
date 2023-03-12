#include <iostream>
#include <queue>

using namespace std;


priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int tmp;
        cin >> tmp;

        if(!tmp)
        {
            if(pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
            pq.push(tmp);
    }
    return 0;
}