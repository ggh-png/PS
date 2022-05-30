#include <iostream>

using namespace std;

int main()
{   // 가격, 개수, 가진 돈 
    int K, N, M;
    cin >> K >> N >> M;
    int answer = (M - (K * N)) >= 0 ? 0 : abs(M - (K * N));
    cout << answer;
    return 0;
}