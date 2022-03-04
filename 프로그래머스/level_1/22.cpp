#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) 
{
    vector<int> answer;
    bool flag_1 = true;
    bool flag_2 = true;
    int i = n;
    int j = 1;

    while (flag_1)
    {
        if(m%i==0 && n%i==0)
        {
            answer.push_back(i);
            flag_1 = false;            
        }
        i--;
    }
    
    while (flag_2)
    {
        if((n * j)%m==0)
        {
            answer.push_back(j*n);
            flag_2 = false;            
        }
        j++;
    }

    return answer;
}

int main()
{
    int n = 3;
    int m = 12;
    solution(n, m);
    return 0;
}