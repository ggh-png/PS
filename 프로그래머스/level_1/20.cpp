#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    long long int temp = num;
    long long int answer = 0;
    int count = 0;
    while (true)
    {
        if(count == 500)
            return -1;

        else if(temp == 1)
            return count;
        
        temp = (temp%2 == 0) ?  temp/2 : temp*3 + 1;
        count++;
    }
    
    return answer;
}


int main()
{
    int num = 6;
    solution(num);
    return 0;
}