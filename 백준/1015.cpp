#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int arr[num];
    int ans[num];

    for(int i=0; i < num; i++)
        cin >> arr[i];

    for(int i=0; i < num; i++)
    {
        int cnt = 0;
        for(int j = 0; j < num; j++)
        {
            if(arr[i] > arr[j] && i != j)
                cnt++;
            else if(arr[i] == arr[j] && i != j && i > j)
                cnt++;
        }
        ans[i] = cnt;
    }
    
    for(auto &el : ans)
        cout << el << " ";
    cout << endl;
    
    return 0;
}
