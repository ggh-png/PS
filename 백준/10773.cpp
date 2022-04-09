#include <iostream>
#include <vector>

using namespace std;
// 0이 들어오면 최근에 입력한 수를 지운다. 
// answer은 스택에 쌇인 수를 모두 더한 것이다. 


int main()
{
    vector<int> VectorStack;
    int num; 
    int answer = 0;
    cin >> num;
    for(int i=0; i < num; i++)
    {
        int temp;
        cin >> temp;
        if(temp == 0)
            VectorStack.pop_back();
        else 
            VectorStack.push_back(temp);
    }
    for(auto el : VectorStack)
        answer += el;
    cout << answer << endl;
    return 0;
}