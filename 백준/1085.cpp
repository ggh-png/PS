#include <iostream>
#include <vector>

using namespace std;

// 현 위치, 직사각형의 위치 

int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;

    int min_x = abs(x-w) > x ? x : abs(x-w);
    int min_y = abs(y-h) > y ? y : abs(y-h);
    int min = min_x > min_y ? min_y : min_x;
    cout << min << '\n';
    
    return 0;
}