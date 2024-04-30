#include <bits/stdc++.h>
using namespace std;
bool check_phone_number(string phone)
{
    if(phone.length() != 10) return false;
    for(int i=0; i<phone.length(); i++)
        if(!isdigit(phone[i])) return false;
    return true;
}

int convertTime(string s)
{
    return stoi(s.substr(0,2))*3600 +stoi(s.substr(3,2))*60+stoi(s.substr(6,2));
}

int main()
{
    ios_base::sync_with_stdio(false);

    int number_total_calls = 0;
    int check_phone = 1;
    map<string,int> number_calls_from;
    map<string,int> count_time_calls_from;


    string s;
    getline(cin, s);
    while(s != "#") {
        string call, from_number, to_number, date, from_time, end_time;
        stringstream ss(s);
        ss >> call >> from_number >> to_number >> date >> from_time >> end_time;
        number_total_calls++;
        if(check_phone) {
            if(!check_phone_number(from_number)) check_phone = 0;
            if(!check_phone_number(to_number)) check_phone = 0;
        }
        number_calls_from[from_number]++;
        count_time_calls_from[from_number] += convertTime(end_time) - convertTime(from_time);

        getline(cin,s);
    }
    getline(cin,s);
    while(s != "#") {
        string command, phone;
        stringstream ss(s);
        ss >> command >> phone;
        if(command == "?check_phone_number") printf("%d\n", check_phone);
        else if(command == "?number_calls_from") printf("%d\n", number_calls_from[phone]);
        else if(command == "?number_total_calls") printf("%d\n", number_total_calls);
        else if(command == "?count_time_calls_from") printf("%d\n", count_time_calls_from[phone]);

        getline(cin,s);
    }

    return 0;
}
