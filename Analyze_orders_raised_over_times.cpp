#include <bits/stdc++.h>
using namespace std;

int number_of_orders_raised = 0;
map<int,int> number_orders_at_time;
int number_orders_in_period[86405];

int convertTime(string s)
{
    return stoi(s.substr(0,2))*3600 + stoi(s.substr(3,2))*60 + stoi(s.substr(6,2));
}

void init()
{
    for(int i=0; i<86400; i++) number_orders_in_period[i] = 0;
}

int main()
{
    init();
    string s;
    getline(cin, s);
    while(s != "#") {
        string orderID, time;
        stringstream ss(s);
        ss >> orderID >> time;
        number_of_orders_raised++;
        int tmp = convertTime(time);
        number_orders_at_time[tmp]++;
        number_orders_in_period[tmp]++;
        getline(cin, s);
    }
    for(int i=1; i<86400; i++) number_orders_in_period[i] += number_orders_in_period[i-1];
    getline(cin, s);
    while(s != "###") {
        stringstream ss(s);
        string command, time1, time2;
        ss >> command >> time1 >> time2;
        if(command == "?number_orders") cout << number_of_orders_raised << "\n";
        else if(command == "?number_orders_in_period") cout << number_orders_in_period[convertTime(time2)] - number_orders_in_period[convertTime(time1)-1] << "\n";
        else if(command == "?number_orders_at_time") cout << number_orders_at_time[convertTime(time1)] << "\n";
        getline(cin, s);
    }

    return 0;
}
