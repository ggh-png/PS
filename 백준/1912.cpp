#include <iostream>
#include <vector>

using namespace std;

int arr[100004];
int num;
int ans = -987654321;

int main()
{
    cin >> num;
    for(int i=1; i <= num; i++)
    {
        cin >> arr[i];
        if(arr[i-1] > 0)
            arr[i] += arr[i-1];
    }
    for(int i=1; i <= num; i++)
        ans = max(arr[i], ans);
    cout << ans << endl;

    return 0;
}