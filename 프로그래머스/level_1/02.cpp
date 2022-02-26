#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

string solution (vector<string> participant, vector<string> completion)
{
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for(int i=0; i<participant.size(); ++i)
    {
        if(participant[i] != completion[i])
            return participant[i];
        //cout << participant[i] << " ";
    }
    for(auto el : participant)
        cout << el << " ";
    cout << endl;
    return participant[participant.size() - 1];

}

int main()
{
    vector<string> participant = {"mislav", "stanko", "mislav", "ana"};           //참가자 
	vector<string> completion = {"stanko", "ana", "mislav"};                   //완주자 

    cout << solution(participant, completion) << endl;
    return 0;
}