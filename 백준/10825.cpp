#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Student
{
public:
    string m_name;
    // 국 영 수 
    int m_k;
    int m_y;
    int m_s;

    Student(string &name, int &k, int &y, int &s)
    {
        this->m_name = name;
        this->m_k = k;
        this->m_y = y;
        this->m_s = s;
    }

    bool operator < (Student &stu)
    {
        if(this->m_k == stu.m_k)
        {
            if(this->m_y == stu.m_y)
            {
                if(this->m_s == stu.m_s)
                    return this->m_name < stu.m_name;
                return this->m_s > stu.m_s;
            }
            return this->m_y < stu.m_y;
        }
        return this->m_k > stu.m_k;
    }
};



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num;
    cin >> num;
    vector<Student> v;
    for(int i=0; i < num; i++)
    {
        string name;
        int k, y, s;
        cin >> name >> k >> y >> s;
        Student st = {name, k, y, s};
        v.push_back(st);
    }
    sort(v.begin(), v.end());

    for(auto &el : v)
        cout << el.m_name << '\n';
    return 0;
}