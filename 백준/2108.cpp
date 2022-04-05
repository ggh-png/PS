#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int num, tmp;
    // 평균
    double mean = 0;
    // 중앙, 최빈, 범위
    int median, mode, range;

    vector<int> arr;
    vector<int> count(8001, 0);
    cin >> num;
    for(int i=0; i < num; i++)
    {
        cin >> tmp;
        arr.push_back(tmp);
        count[tmp + 4000] += 1;
        mean += tmp;
    }
    // 산술평균 
    mean = floor(mean/num + 0.5);
    // 중앙 값
    sort(arr.begin(), arr.end());
    median = arr[num/2];
    // 범위 값
    range = arr.back() - arr.front();
    // 최빈값
    int max = -999999; 
    vector<int> temp; 
    for(int i=0; i < count.size(); i++)
        if(count[i] > max)
            max = count[i];
    
    for(int i=0; i < count.size(); i++)
        if(count[i] == max)
            temp.push_back(i - 4000);
    // 최빈값이 하나일 경우 
    if(temp.size() == 1)
        mode = temp[0];
    // 여러개일 경우
    // 최빈값 중 두번째로 작은 값을 최빈값으로 지정   
    else
    {
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        mode = temp[1];
    }

    cout << mean << '\n';
    cout << median << '\n';
    cout <<  mode << '\n';
    cout << range << '\n';
    return 0;
}