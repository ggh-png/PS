#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Score
{
public:
    int document;
    int meeting;
};

bool compare(Score a, Score b)
{
    return a.document < b.document;
}

int main()
{
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int n;
        cin >> n;
        vector<Score> v(n);
        for(int i=0; i < n; i++)
            cin >> v[i].document >> v[i].meeting;
        sort(v.begin(), v.end(), compare);

        int score = 99999999;
        int ans = 0;
        for(int  i=0; i < n; i++)
        {
            if(v[i].meeting < score)
            {
                ans++;
                score = v[i].meeting;
            }
        }
        cout << ans << endl;
    }
    return 0;
}