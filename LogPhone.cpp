#include <bits/stdc++.h>
using namespace std;

bool checkPhoneNumber(string s) {
	if(s.length() != 10) return false;
	for(auto ch : s)
		if(ch < '0' || ch > '9') return false;
	return true;
}

int convertTime(string s){
	return stoi(s.substr(0,2))*3600 +stoi(s.substr(3,2))*60+stoi(s.substr(6,2));
}

int main() {
	ios_base::sync_with_stdio(false);
	
	int num_valid_phone = 0, sum_phone = 0;
	map<string, int> num_from_phone;
	map<string, int> sum_time_phone;
	string s;
	bool check = true;
	
	getline(cin, s);
	while(s != "#") {
		string from_number, to_number, from_time, end_time, date, call;
		stringstream ss(s);
		ss >> call >> from_number >> to_number >> date >> from_time >> end_time;
		sum_phone++;
		if(check) {
			if(!checkPhoneNumber(from_number) || !checkPhoneNumber(to_number)) check = false;
		}
		num_from_phone[from_number]++;
		sum_time_phone[from_number] += convertTime(end_time) - convertTime(from_time);
		
		getline(cin, s);
	}
	
	getline(cin, s);
	while(s != "#") {
		string command, phone;
		stringstream ss(s);
		ss >> command >> phone;
		if(command == "?check_phone_number") {
			if(check) cout << "1" << endl;
			else cout << "0" << endl;
		}
		else if(command == "?number_calls_from") cout << num_from_phone[phone] << endl;
		else if(command == "?number_total_calls") cout << sum_phone << endl;
		else if(command == "?count_time_calls_from") cout << sum_time_phone[phone] << endl;
		
		getline(cin, s);
	}
	
	return 0;
}