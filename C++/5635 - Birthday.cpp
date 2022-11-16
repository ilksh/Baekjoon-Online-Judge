#include<bits/stdc++.h>
using namespace std;

typedef struct Person {
    string name;
    int day;
    int month;
    int year;
} Person;

vector<Person>info;

// step 1) if P1 and P2 born in a same year > compare the month
// step 2) if P1 and P2 born in a same month > compare the day
// step 3) compare the day
bool cmp(Person P1, Person P2)
{
    // step 1
    if (P1.year == P2.year)
    {
        if (P1.month == P2.month)   // step 2
            return P1.day > P2.day; // step 3
        return P1.month > P2.month;
    }
    return P1.year > P2.year;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    for(int i = 0 ; i < n ; ++i)
    {
        string name;
        int dd, mm, yyyy;
        cin >> name >> dd >> mm >> yyyy;
        Person person {name, dd, mm, yyyy};
        info.push_back(person);
    }
    
    sort(info.begin(), info.end(), cmp);
    cout << info[0].name << endl;
    cout << info[n-1].name << endl;
    
    return 0;
}
