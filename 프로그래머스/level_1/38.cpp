#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> arr(n+1, 0);
    arr[0] = arr[1] = true; // true 면 소수아님 
    for(int i=2; i <= sqrt(n); i++)
    {
        if(arr[i]) //소수가 아님 넘김
            continue;
        for(int j = i + i; j <= n; j += i)
            arr[j] = true;
    }
    for(auto el : arr)
        answer += (el == 0) ? true : false;    
    return answer;
}