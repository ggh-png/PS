#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class st
{
public:
    int num;
    int point;
};

bool compare1(st a, st b)
{
    if(a.num == b.num)
        return a.point > b.point;
    return a.num < b.num;
}
bool compare2(st a, st b)
{
    if(a.num == b.num)
        return a.point < b.point;
    return a.num < b.num;
}
int main() {
    int n, s, p;
    std::vector<st> scores;

    std::cin >> n >> s >> p;
    
    for (int i = 0; i < n; i++) {
        st score;
        std::cin >> score.num;
        score.point = 0;
        scores.push_back(score);
    }
    
    // 등수 리스트가 비어있는 경우
    if (scores.empty()) {
        std::cout << "1" << std::endl;
        return 0;
    }
    
    // 등수 리스트가 최대 인원 수에 도달한 경우
 
    st ss;
    ss.num = s;
    ss.point = 1;
    scores.push_back(ss);
    std::sort(scores.rbegin(), scores.rend(), compare1);

    int rank1, rank2;
    for(int i=0; i < scores.size(); i++)
        if(scores[i].point)
        {
            rank1 = i;
            break;
        }
    std::sort(scores.rbegin(), scores.rend(), compare2);
    for(int i=0; i < scores.size(); i++)
        if(scores[i].point)
        {
            rank2 = i;
            break;
        }
    if(rank1+1 > p)
        cout << -1 << endl;
    else
        cout << rank2+1 << endl;
    
    return 0;
}
