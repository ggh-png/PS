#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

//vector<vector<bool>> reportList; // 신고횟수  [0 1 0 1][0 0 0 1][1 1 0 0][0 0 0 0]


void splitAndEnterReportList(vector<string> id_list, vector<string> report, int k)
{
    // split
    vector<string> temp;
    string stringBuffer;
    vector<vector<bool>> reportList(id_list.size(), vector<bool>(id_list.size()));
    vector<int> reportSate(id_list.size());

    temp.clear(); // 초기화

    istringstream ss(report[0]);
    while (getline(ss, stringBuffer, ' '))
        temp.push_back(stringBuffer);
    //"temp[0] = muzi, tem[1] = frodo"
    // 신고자 무지, 신고대상 프로도 

    if(temp[0] == id_list[0]) // 신고자를 id리스트에서 찾으면 
    {
        reportList[0][1] = true; // reportList[][]에 저장 (신고 리스트 등록)
        reportSate[1] += 1;   // reportSate에 스택 업 (신고 현황 업데이트)
        for(auto el : reportSate)
        {
            cout << el << " ";
        }
        cout << endl;
    }   
}

// vector<int> solution(vector<string> id_list, vector<string> report, int k)
// {
//     splitAndEnterReportList(id_list, report, k);
//     for(auto &el : repor)
// }


int main()

{
    vector<string> id_list{"muzi", "frodo", "apeach", "neo"};
    vector<string> report{"muzi frodo"};
    int k = 2;

    //solution(id_list, report, k);
    splitAndEnterReportList(id_list, report, k);
    //cout << "asda" << endl;
    return 0;    

}