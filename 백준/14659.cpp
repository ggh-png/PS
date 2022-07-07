#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int arr[num];
    for(int i=0; i < num; i++)
        cin >> arr[i];
    int max = 0;
    for(int i=0; i < num; i++)
    {
        int cnt=0;
        for(int j=i+1; j < num; j++)
        {
            if(arr[i] > arr[j])
                cnt++;
            else
                break;
        }
        if(max < cnt)
            max = cnt;
    }
    cout << max << endl;
    return 0;
}