#include <iostream> 
using namespace std;

int main()
{
    int arr[3];
    
    for(int i=0; i < 3; i++)
        cin >> arr[i];
        

    for(int i=0; i < 3; i++)
    {
        int max = 0;
        int idx = i;
        for(int j=i; j < 3; j++)
            if(max < arr[j])
            {
                max = arr[j];
                idx = j;
            }
        swap(arr[i], arr[idx]);
    }
    cout << arr[1];
    

    return 0;
}