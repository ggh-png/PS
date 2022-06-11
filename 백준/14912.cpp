#include <iostream>
#include <string>

using namespace std;

int main()
{
    int num, N;
    cin >> num >> N;
    int answer = 0;
    for(int i=1; i <= num; i++)
    {
        string str = to_string(i);
        for(auto &el : str)
            if((el-48) == N)
                answer++;
    }
    cout << answer << endl;

    return 0;
}