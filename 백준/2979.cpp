#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int arr[101] = {0};
    cin >> a >> b >> c;

    for(int i=0; i < 3; i++)
    {
        int in, out;
        cin >> in >> out;
        for(int j=in; j < out; j++)
            arr[j]++;
    }
    int answer = 0;
    for(auto &el : arr)
    {
        if(el == 1)
            answer += a;
        else if(el == 2)
            answer += b*2;
        else if(el == 3)
            answer += c*3;
    }
    cout << answer << endl;
    return 0;
}