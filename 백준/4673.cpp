#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string n)
{
    int sum = stoi(n);
    for(auto &el : n)
        sum += el - 48;
    return sum;
}

int main()
{
    vector<bool> v(10000, false);
    for(int i=0; i < 10001; i++)
    {
        int temp = solution(to_string(i));

        if(temp <= 10000)
            v[temp] = true;
    }
    for(int i=0; i < v.size(); i++)
        if(!v[i])
            cout << i << '\n';

    return 0;
}