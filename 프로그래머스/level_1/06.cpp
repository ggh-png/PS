#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, int> user;
//vector<vector<bool>> reportList; // 신고횟수  [0 1 0 1][0 0 0 1][1 1 0 0][0 0 0 0]


void splitAndEnterReportList(vector<string> id_list, vector<string> report, int k)
{
   // split
   vector<string> temp;
   string stringBuffer;
   vector<vector<bool>> reportList(id_list.size(), vector<bool>(id_list.size()));

    for(int i=0; i < report.size(); i++)
    {
        temp.clear(); // 초기화
        // split
        istringstream ss(report[0]);
        while (getline(ss, stringBuffer, ' '))
            temp.push_back(stringBuffer);
        //"muzi frodo"
    }
    

    //reportList[][]에 저장
    
    for(int j=0; j < id_list.size(); j++)
    {   // reporter를 찾으면
        if(find(temp.begin(), temp.end(), id_list[j]) == temp.begin())
        // report 해라
        {
            //cout << "asdasdasd" << endl;
            for(int k=0; k < id_list.size(); k++)
            {
                if(find(temp.begin(), temp.end(), id_list[k]) != temp.end())
                    reportList[j][k] = 1;
            }
        } 
        
    }
    for(int j=0; j < id_list.size(); j++)
    {
        for(auto el : reportList[0])
            cout << el << " ";
        cout << endl;
    }



    //cout << temp[0] << " " <<  temp[1] << endl;

}



int main()

{
    vector<string> id_list{"muzi", "frodo", "apeach", "neo"};
    vector<string> report{"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
    int k = 2;

    //solution(id_list, report, k);
    splitAndEnterReportList(id_list, report, k);
    cout << "asda" << endl;
    return 0;    

}