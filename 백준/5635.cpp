#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student
{
public:
    string m_name;
    int m_years, m_month, m_days;

    Student(string name, int years, int month, int days)
    {
        this->m_name = name;
        this->m_years = years;
        this->m_month = month;
        this->m_days = days;
    }
    bool operator < (Student &student)
    {
        if(this->m_years == student.m_years)
        {
            if(this->m_month == student.m_month)
                return  this->m_days < student.m_days;
            else
                return this->m_month < student.m_month;
        }
        else
            return this->m_years < student.m_years;
    }
};

int main()
{
    int num;
    string name;
    int years, month, days; 
    
    cin >> num;
    vector<Student> v;
    for(int i=0; i < num; i++)
    {
        cin >> name >> days >> month >> years;
        Student stu(name, years, month, days);
        v.push_back(stu);
    }

    sort(v.rbegin(), v.rend());

    cout << v[0].m_name << endl << v[num-1].m_name;
    return 0;
}