#include<iostream>
#include<string>
#include<algorithm>
using namespace std; 


string solution(int num)
{
    string temp = to_string(num);
    sort(temp.rbegin(), temp.rend());
    return temp;
}


int main()
{
    int num;
    cin >> num;
    cout << solution(num) << endl;
    return 0; 
}