#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    string min_a = a, min_b = b;
    string max_a = a, max_b = b;
    
    for(int i=0; i < a.size(); i++)
    {
        if(a[i] == '6')
            min_a[i] = '5';
    
        if(a[i] == '5')
            max_a[i] = '6';
    }
    for(int i=0; i < b.size(); i++)
    {
        if(b[i] == '6')
            min_b[i] = '5';
        if(b[i] == '5')
            max_b[i] = '6';
    }
    
    int max = stoi(max_a) + stoi(max_b);
    int min = stoi(min_a) + stoi(min_b);
    cout << min << endl << max << endl;
    return 0;
}