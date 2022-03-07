#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    long long int answer = 0;
    bool flag = true;
    int temp_num = n;
    vector<int> temp;
    while (flag)
    {
        if(n >= 9)
        {
            temp.push_back(n%3);
            n /=3;
        }
        else
        {   
            if(n==1)
            {
                temp.push_back(n%3);
                flag = false;
                break;
            }
            temp.push_back(n%3);
            temp.push_back(n/3);
            flag = false;
        }
    }
    int start = temp.size()-1;
    for(int i=start; i >= 0; i--)
    {
        answer += pow(3, i) * temp[start-i];
    }
    return answer;
}

int main()
{
    int n = 8;
    solution(n);
    //test();
    return 0;
}
