#include <iostream>
#include <vector>
using namespace std;


// 1 7 19 37 61 91
//  6 12 18 24 30
int main()
{
    int num, answer=1;
    int N = 1;
    vector<int> v;
    cin >> num;
    int six = 0;
    while(N <= num && num != 1)
    {
        six += 6;
        N += six;
        v.push_back(N);
        answer++;
    }
    
    cout << answer;
    return 0;
}