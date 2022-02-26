#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void printVector(const vector<int>& vector_arr)
{
    cout << "[ ";
    for(auto &el : vector_arr)
        cout << el << ", ";

    cout << " ]" << endl;
}


vector<int> solution(vector<int>& array, vector<vector<int>>& commands) {
    vector<int> answer;
    vector<int> temp_vector;
    answer.resize(commands.size()); // 답지
    for(int i=0; i < commands.size(); i++)
    {
        int I = commands[i][0]-1;
        int J = commands[i][1]-1;
        int K = commands[i][2]-1;
        
        for(I; I <= J; I++)
        {
            temp_vector.push_back(array[I]);
        }
        sort(temp_vector.begin(), temp_vector.end());
        printVector(temp_vector);
        answer[i] = temp_vector[K];
        temp_vector.clear();
    }
    return answer;
}

int main()
{
    vector<int> array{1,5,2,6,3,7,4};
    vector<vector<int>> commands{{2,5,3},{4,4,1},{1,7,3}};
    printVector(solution(array, commands));
}