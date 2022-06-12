#include <iostream>

using namespace std;


// 5분 1분 10초
int main()
{
    int num;
    cin >> num;
    int fmin=0, omin=0, tsec=0; 
    fmin += num / 300;
    num %= 300;
    omin += num / 60;
    num %= 60;
    tsec += num / 10;
    num %= 10;

    if(num == 0)
        cout << fmin << " " << omin << " " << tsec << endl;
    else
        cout << "-1";

    return 0;
}
