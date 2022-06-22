#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int &a, int &b)
{
    return a > b;
}

int main()
{
    int num;
    cin >> num;
    int arr[num];
    for(int i=0; i < num; i++)
        cin >> arr[i];
    // 내림차순 정렬 
    sort(arr, arr + num, compare);

    int answer = 0;
    for(int i=0; i < num; i++)
    {
        int sum = arr[i] * (i+1);
        
        if(answer <= sum)
            answer = sum;
    }
    cout << answer << endl;
    return 0;
}