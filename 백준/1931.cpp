#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// first는 second보다 크면 안댐 
class Meeting
{
public:
    int open;
    int close;
};

bool compare(Meeting a, Meeting b)
{
    if(a.close == b.close)
        return a.open < b.open;
    return a.close < b.close;
}

int main()
{
    int num;
    cin >> num;
    vector<Meeting> v(num);
    
    for(int i=0; i < num; i++)
        cin >> v[i].open >> v[i].close;
    
    sort(v.begin(), v.end(), compare);
	int time=0,cnt=0;
	for(auto &el : v)
		if(time <= el.open)
        {
			time = el.close;
			cnt++;
		}
	
    cout << cnt;
    return 0;
}