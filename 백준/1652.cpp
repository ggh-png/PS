#include <iostream>
#include <vector>

using namespace std;

int num;
char map[104][104];
int ans1 = 0;
int ans2 = 0;
int main()
{
    cin >> num;
    for(int i=0; i < num; i++)
        for(int j=0; j < num; j++)
            cin >> map[i][j];

    // 가로     
    for(int i=0; i < num; i++)
    {
        int cnt = 0;
        bool flag = 1;
        for(int j=0; j < num; j++)
        {
            if(map[i][j] == '.' && flag)
                cnt++;
            if(map[i][j] == 'X')
            {
                cnt = 0;
                flag = 1;
            }
            if(cnt >= 2 && flag)
            {
                ans1++; 
                flag = 0;
                cnt = 0;
            }
        }
    }
    

    // 가로     
    for(int i=0; i < num; i++)
    {
        int cnt = 0;
        bool flag = 1;
        for(int j=0; j < num; j++)
        {
            if(map[j][i] == '.' && flag)
                cnt++;
            if(map[j][i] == 'X')
            {
                cnt = 0;
                flag = 1;
            }
            if(cnt >= 2 && flag)
            {
                ans2++; 
                flag = 0;
                cnt = 0;
            }
        }
    }
    

    cout << ans1 << " " << ans2 << endl;
    return 0;
}
// 5
// ..X..
// ..X..
// ..X..
// ..X..
// ..X..