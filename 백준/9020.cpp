#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    vector<bool> arr(10001, 0);
    arr[0] = true;
    arr[1] = true;
    // 소수 추출
    for(int i=0; i <= sqrt(10001); i++)
        if(!arr[i])
            for(int j=i+i; j <= 10001; j+=i)
                arr[j] = true;
                
    vector<int> v;
    for(int i=0; i <= 10001; i++)
        if(!arr[i])
            v.push_back(i);
    int num;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int N;
        cin >> N;
        int a, b;
        for(int j=0; j < v.size(); j++)
            for(int k=j; k < v.size(); k++)
                if((N-v[j]) == v[k])
                {
                    a = v[j];
                    b = v[k];
                    break;
                }   
        cout << a << " " << b << '\n';
    }
    return 0;
}