#include <iostream>
#include <vector>

using namespace std;

int n, m;

int arr[100005];
int psum[100006];

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i <= n; i++)
    {
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
    }
    for(int i=0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << psum[b] - psum[a-1] << '\n';
    }
    return 0;
}