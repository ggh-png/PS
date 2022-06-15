#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int answer[num];
    for(int j=0; j < num; j++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int arr[3] = {a, b, c};
        int ans;
        int max = 0;
        if(a == b && b == c && c == a)
            ans = a * 1000 + 10000;
        else if(a == b && b != c && c != a)
            ans = a * 100 + 1000;
        else if(a != b && b == c && c != a)
            ans = b * 100 + 1000;
        else if(a != b && b != c && c == a)
            ans = c * 100 + 1000;
        else if(a != b && b != c && c != a)
        {
            for(int i=0; i < 3; i++)
                if(arr[i] > max)
                    max = arr[i];
            ans = max * 100;
        }
        answer[j] = ans;
    }
    int max = 0;
    for(int i=0; i < num; i++)
        if(answer[i] > max)
            max = answer[i];
    
    cout << max << endl;
    return 0;
}