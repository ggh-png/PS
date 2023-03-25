#include <iostream>

using namespace std;

int arr[10];
int num;
int ans = -987654321;
void permutation(int n, int r, int depth)
{
    if(depth == r)
    {
        int sum = 0;
        for(int i=0; i < n-1; i++)
            sum += abs(arr[i] - arr[i+1]); 
        ans = ans < sum ? sum : ans;
    }
    for(int i=depth; i < r; i++)
    {
        swap(arr[i], arr[depth]);
        permutation(n, r, depth + 1);
        swap(arr[i], arr[depth]);
    }
}


int main()
{
    cin >> num;
    for(int i=0; i < num; i++)
        cin >> arr[i]; 
    permutation(num, num, 0);
    cout << ans << endl;
    return 0;
}