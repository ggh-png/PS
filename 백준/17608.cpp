#include <iostream>
#include <stack>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int arr[num];
    for(int i=0; i < num; i++)
        cin >> arr[i];
    
    int tmp = arr[num-1];
    int ans = 1;
    stack<int> s;
    s.push(arr[num-1]);
    for(int i=num-1; i >= 0; i--)
        if(s.top() < arr[i])
            s.push(arr[i]);
    

    cout << s.size() << endl;
    return 0;
}