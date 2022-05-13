#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main()
{
    int A, B, C;

    cin >> A >> B >> C;
    string answer = to_string(A * B * C);
    vector<int> cnt(10, 0);
    for(auto &el : answer)
        cnt[el - 48]++;
    
    for(auto &el : cnt)
        cout << el << '\n';


    return 0;
}