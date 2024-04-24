#include <bits/stdc++.h>
using namespace std;

vector<string> days;
map<string, int> mp;

int convertHourtoSecond(string s)
{
    return stoi(s.substr(0,2))*3600 +stoi(s.substr(3,2))*60+stoi(s.substr(6,2));
}

pair<int, string> convertSecondtoHour(string time, string duration)
{
    string s = "";
    int time_second = convertHourtoSecond(time);
    time_second += stoi(duration);
    int day = time_second / 86400;
    time_second -= day * 86400;
    int hour = time_second / 3600;
    if(hour < 10) s += "0" + to_string(hour) + ":";
    else s += to_string(hour) + ":";
    time_second -= hour * 3600;
    int minute = time_second / 60;
    if(minute < 10) s += "0" + to_string(minute) + ":";
    else s += to_string(minute) + ":";
    int second = time_second -= minute * 60;
    if(second < 10) s += "0" + to_string(second);
    else s += to_string(second);
//    string s = to_string(hour) + ":" + to_string(minute) + ":" + to_string(second);
    return {day, s};
}

int main()
{
    int i = 0;
    string s;
    getline(cin, s);
    while(s != "*") {
        days.push_back(s);
        mp[s] = i;
        i++;
        getline(cin,s);
    }
    getline(cin, s);
    while(s != "***") {
        string day, time, duration;
        stringstream ss(s);
        ss >> day >> time >> duration;
        pair<int,string> res = convertSecondtoHour(time, duration);
        cout << days[mp[day]+res.first] << " " << res.second << "\n";
        getline(cin, s);
    }

    return 0;
}
