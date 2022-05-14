#include <iostream>
#include <string>

using namespace std;


int main()
{

    string str;
    int answer=0;

    cin >> str;
    for(auto &el : str)
    {
        if(el >= 65 && el <= 67)
            answer += 3;
        else if(el >= 68 && el <= 70)
            answer += 4;
        else if(el >= 71 && el <= 73)
            answer += 5;
        else if(el >= 74 && el <= 76)
            answer += 6;
        else if(el >= 77 && el <= 79)
            answer += 7;
        else if(el >= 80 && el <= 83)
            answer += 8;
        else if(el >= 84 && el <= 86)
            answer += 9;
        else if(el >= 87 && el <= 90)
            answer += 10;
    }
    cout << answer;
    return 0;
}