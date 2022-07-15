#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[8];
    for(int i=0; i < 8; i++)
        cin >> arr[i];

    int cntA=0;
    int cntB=0;
    for(int i=0; i < 7; i++)
    {
        if(arr[i] < arr[i+1])
            cntA++;
        else
            cntB++;
    }
    if(cntA == 7)
        cout << "ascending" << endl;
    else if(cntB == 7)
        cout << "descending" << endl;
    else
        cout << "mixed" << endl;

    return 0;
}