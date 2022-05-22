#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    int num;
    int answer=0;
    cin >> num;
    vector<int> v(num);
    for(int i=0; i < num; i++)
        cin >> v[i];
    
    vector<bool> arr(1001, 0);
    arr[0] = true;
    arr[1] = true;
    for(int i=2; i <= sqrt(1001); i++)
        if(!arr[i])
            for(int j=i+i; j <= 1001; j+=i)
                arr[j] = true;
                
    // false면 소수임. 
    for(auto &el : v)
        if(!arr[el])
            answer++;

    cout << answer << endl;
    return 0;
}