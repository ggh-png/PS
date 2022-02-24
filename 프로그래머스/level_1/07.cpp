#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;

    for(int i=0; i < absolutes.size(); i++)
    {
        if(signs[i] == false)
        {
            absolutes[i] = absolutes[i] * (-1);
        }
        answer = answer + absolutes[i];

    }
        
    return answer;
}




int main()
{

    vector<int> absolutes {4,7,12};
    vector<bool> signs {true,false,true};

    
    cout << solution(absolutes, signs) << endl;

    return 0;
}