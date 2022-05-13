#include <iostream>
#include <string>
using namespace std;


int main()
{
    string str;
    getline(cin, str);
    
    int answer = 0;
    int temp=0;
    for(int i=0; i < str.size(); i++)
    {
        
        if(str[i] != 32)
            temp++;
        else if((str[i] == 32) && (temp != 0))
        {
            answer++;
            temp=0;
        }
    }
    if(temp != 0)
        answer++;
    cout << answer; 
    return 0;
}