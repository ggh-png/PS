#include <iostream>

using namespace std;

char map[101][101];
int num;

string quard(int y, int x, int size)
{
    if(size == 1)
        return string(1, map[y][x]);
    
    char tmp = map[y][x];
    string ret = "";
    for(int i=y; i < y + size; i++)
        for(int j=x; j < x + size; j++)
            if(tmp != map[i][j])
            {
                ret += '(';
                // 왼 위 
                ret += quard(y, x, size / 2);
                // 오 위
                ret += quard(y, x + size / 2, size / 2);
                // 왼 아래
                ret += quard(y + size / 2, x, size / 2);
                // 오른 아래
                ret += quard(y + size / 2, x + size / 2, size / 2);
                ret += ')';
                return ret;
            }
    return string(1, map[y][x]);
}

int main()
{
    cin >> num;
    for(int i=0; i < num; i++)
    {
        string str;
        cin >> str;
        for(int j=0; j < num; j++)
            map[i][j] = str[j];
    }
    cout << quard(0, 0, num) << endl;
    return 0;
}