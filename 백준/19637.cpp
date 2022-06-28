#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> score(n);
    vector<string> ans(n);

    for(int i=0; i < n; i++)
        cin >> ans[i] >> score[i];

    vector<int> arr(m);
    for(int i=0; i < m; i++)
        cin >> arr[i];

    for(int i=0; i < m; i++)
    {
        int index = lower_bound(score.begin(), score.end(), arr[i]) - score.begin();
        cout << ans[index] << '\n';
    }
      
    return 0;
}