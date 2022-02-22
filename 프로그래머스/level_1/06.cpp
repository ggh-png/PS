#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


vector<int> solution(vector<string> id_list, vector<string> report, int limit)
{
    // split
    vector<string> temp;
    string stringBuffer;
    vector<vector<bool>> reportList(report.size(), vector<bool>(id_list.size()));
    vector<int> reportSate(id_list.size());
    vector<int> answer(id_list.size(), 0);
    vector<int> list(id_list.size(), 0);

    for(int i=0; i < report.size(); i++)
    {
        temp.clear(); // 초기화
        istringstream ss(report[i]);
        while (getline(ss, stringBuffer, ' '))
            temp.push_back(stringBuffer);
        //"temp[0] = muzi, tem[1] = frodo"
        // 신고자 무지, 신고대상 프로도 

        for(int j=0; j < report.size(); j++)
        {
            if(temp[0] == id_list[j]) // 신고자를 id리스트에서 찾으면 
           {// j = reporter, k = report
                for(int k=0; k < id_list.size(); k++)
                {
                    if(temp[1] == id_list[k]) // 신고대상 
                    {
                        reportList[j][k] = true; // reportList[][]에 저장 (신고 리스트 등록)
                    }
                }
            }
        }
    }


//  신고 횟수 누적 
    for(int i=0; i < report.size(); i++)
    {
        for(int j=0; j < id_list.size(); j++)
        {
            if(reportList[i][j]) // 중복일 경우 3번 투표해도 1번으로 
                reportSate[j] += 1; 
        }
    }

// 정지된 신고대상을 신고한 사람의 아이디를 찾음 

    for(int i=0; i < id_list.size(); i++)
    {
        if(reportSate[i] >= limit) // 20211 
        {
            list.push_back(i);  // N번째 아이디의 주소 02
        }
    }
// 신고자에게 메일 발송 

    for(int i = 0; i < id_list.size(); i++)
    {
        for(auto el : list)
        {
            if(reportList[i][el])
            {
                answer[i] += 1;
            }
        }
    }


for(int i=0; i < report.size(); i++)
{
    for(int j=0; j < id_list.size(); j++)
    {
        cout << reportList[i][j] << " ";
    }
    cout << endl;
}

cout << endl << endl << "test" << endl << endl;  
    for(auto el : answer)
    {
        cout << el << " ";
    }
    cout << endl;
 
    return answer;


}




int main()

{
    // vector<string> id_list{"muzi", "frodo", "apeach", "neo"};
    // vector<string> report{"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    // int k = 2;

    vector<string> id_list{"con", "ryan"};
    vector<string> report{"ryan con", "ryan con", "ryan con", "ryan con"};
    int k = 3;


    //solution(id_list, report, k);
    solution(id_list, report, k);
    //cout << "asda" << endl;
    return 0;    

}
