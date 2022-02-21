#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


void splitAndEnterReportList(vector<string> id_list, vector<string> report, int limit)
{
    // split
    vector<string> temp;
    string stringBuffer;
    vector<vector<bool>> reportList(id_list.size(), vector<bool>(id_list.size()));
    vector<int> reportSate(id_list.size());
    vector<int> answer(id_list.size(), 0);

    for(int i=0; i <= id_list.size(); i++)
    {
        temp.clear(); // 초기화
        istringstream ss(report[i]);
        while (getline(ss, stringBuffer, ' '))
            temp.push_back(stringBuffer);
        //"temp[0] = muzi, tem[1] = frodo"
        // 신고자 무지, 신고대상 프로도 

        for(int j=0; j < id_list.size(); j++)
            if(temp[0] == id_list[j]) // 신고자를 id리스트에서 찾으면 
           {// j = reporter, k = report
                for(int k=0; k < id_list.size(); k++)
                {
                    if(temp[1] == id_list[k]) // 신고대상 
                    {
                        reportList[j][k] = true; // reportList[][]에 저장 (신고 리스트 등록)
                        reportSate[k] += 1;   // reportSate에 스택 업 (신고 현황 업데이트)
                        answer[j] += (reportSate[k] >= limit) ? 1 : 0;  
                    }



                    // else if(reportSate[k] >= 2)//신고가 누적되면
                    // {
                    //     answer[j] += 1; // 메일발송 
                    //     //break;
                    // }
                }
            }
            // --------------------------------------------------
    }
// 신고상황 출력   
    for(auto el : reportSate)
    {
        cout << el << " ";
    }
s
// 신고 기록 출력
    cout << endl << endl << "reportList" << endl << endl;

    for(int i=0; i < id_list.size(); i++)
    {
        for(int j=0; j < id_list.size(); j++)
        {
            cout << reportList[i][j] << " ";
            
        }
        cout << endl; 
    }

    for(auto &el : answer)
    {
        cout << el << " ";
    }
    cout << endl;
}

// vector<int> solution(vector<string> id_list, vector<string> report, int k)
// {
//     splitAndEnterReportList(id_list, report, k);
//     for(auto &el : repor)
// }


int main()

{
    vector<string> id_list{"muzi", "frodo", "apeach", "neo"};
    vector<string> report{ "muzi frodo","apeach frodo","frodo neo",
		"muzi neo","apeach muzi" };
    int k = 2;

    //solution(id_list, report, k);
    splitAndEnterReportList(id_list, report, k);
    //cout << "asda" << endl;
    return 0;    

}