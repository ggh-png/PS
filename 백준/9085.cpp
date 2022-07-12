#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int n;
        cin >> n;
        int answer = 0;
        for(int i=0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            answer += tmp;
        }
        cout << answer << endl;
    }
    return 0;
}