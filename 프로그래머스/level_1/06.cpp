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
    vector<vector<bool>> reportList(id_list.size(), vector<bool>(id_list.size()));
    vector<int> reportSate(id_list.size());
    vector<int> answer(id_list.size(), 0);
    vector<int> list(id_list.size(), 0);

    for(int i=0; i <= id_list.size(); i++)
    {
        temp.clear(); // 초기화
        istringstream ss(report[i]);
        while (getline(ss, stringBuffer, ' '))
            temp.push_back(stringBuffer);
        //"temp[0] = muzi, tem[1] = frodo"
        // 신고자 무지, 신고대상 프로도 

        for(int j=0; j < id_list.size(); j++)
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



    for(int i=0; i < id_list.size(); i++)
    {
        for(int j=0; j < id_list.size(); j++)
        {
            if(reportList[i][j]) // 중복일 경우 3번 투표해도 1번으로 
                reportSate[j] += 1; 
        }
    }

    for(int i=0; i < id_list.size(); i++)
    {
        if(reportSate[i] >= limit)
        {
            list.push_back(i);
        }
    }

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

    return answer;
}




int main()

{
    vector<string> id_list{"con", "ryan"};
    vector<string> report{ "ryan con", "ryan con", "ryan con", "ryan con"};
    int k = 3;

    //solution(id_list, report, k);
    solution(id_list, report, k);
    //cout << "asda" << endl;
    return 0;    

}
