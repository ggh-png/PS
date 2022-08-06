#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;
    int arr[5]={0};
    for(int i=0; i < num; i++)
    {
        int x, y;
        cin >> x >> y;

        if(x > 0 && y > 0)
            arr[0]++;
        else if(x < 0 && y > 0)
            arr[1]++;
        else if(x < 0 && y < 0)
            arr[2]++;
        else if(x > 0 && y < 0)
            arr[3]++;
        else
            arr[4]++;
     }
    
    for(int i=1; i <= 4; i++)
        cout << "Q" << i << ": " << arr[i-1] << '\n';
    cout << "AXIS: " << arr[4] << '\n';
    return 0;
}
