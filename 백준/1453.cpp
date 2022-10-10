#include <iostream>

using namespace std;

bool arr[101];

int main()
{
    int ans = 0;
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int tmp;
        cin >> tmp;
        if(arr[tmp])
            ans++;
        else
            arr[tmp] = 1;
    }
    cout << ans << endl;
    return 0;
}