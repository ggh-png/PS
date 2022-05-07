#include <iostream>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    long long int num;
    int cnt = 1;
    long long int temp= 0;
    cin >> num;
    while (num > temp)
    {
        cnt++;
        temp += cnt;
    }
    cout << --cnt << endl;
    return 0;
}