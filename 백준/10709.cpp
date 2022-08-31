#include <iostream>

using namespace std;

// map 
int map[104][104];

int n, m;

int main()
{
    cin >> n >> m;
    for(int i=0; i < n; i++)
        fill(map[i], map[i] + m, -1);
    for(int i=0; i < n; i++)
    {
        string str;
        cin >> str;
        for(int j=0; j < m; j++)   // 구름이면
            if(str[j] == 'c')
            {
                map[i][j] = 0;
                for(int k=j+1; k < m; k++)
                    map[i][k] = map[i][k-1] + 1; 
            }
    }
    for(int i=0; i < n; i++)
    {
        for(int j=0; j < m; j++)
            cout << map[i][j] << " ";
        cout << endl;
    }
    return 0;
}
