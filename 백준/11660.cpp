#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[1050][1050];
int psum[1060][1060];



int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    cin >> n >> m;
    for(int i=1; i <= n; i++)
        for(int j=1; j <= n; j++)
        {
            cin >> arr[i][j];
            psum[i][j] = psum[i][j-1] + arr[i][j];
        }
    for(int i=0; i < m; i++)
    {
        int x1, x2, y1, y2;
        int ans = 0;
        cin >> y1 >> x1 >> y2 >> x2;
        
        for(int j=y1; j <= y2; j++)
            ans += psum[j][x2] - psum[j][x1-1];
            
        cout << ans << '\n';
    }
}