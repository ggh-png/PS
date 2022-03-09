#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int p=0;
    int y=0;
    for(auto el : s)
    {
        if(el == 80 || el == 112)
            p += 1;
        else if(el == 89 || el == 121)
            y += 1;
    }
    return !(p-y);
} 