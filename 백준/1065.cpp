#include <iostream>
#include <string>

using namespace std;

int main()
{
    string num;
    cin >> num;
    int cnt = 99;
    if(num.size() < 3)
        cout << num;
    else
    {
        for(int i=100; i <= stoi(num); i++)
        {   
            
            string str = to_string(i);
            if((str[0] - str[1]) == (str[1] - str[2]))
                cnt++;
        }
        cout << cnt;
    }
    return 0;
}