#include<iostream>
#include<vector>

using namespace std;


int main () {

	/*Concatenation -- */
	string s = "Abhishek";

	s += " Mundra";
	cout << s << "\n";	

    vector<string> family = {"Abhishek", "Reena", "Aaditri", "Ivaansh"};
	sort(family.begin(), family.end());

	for (const string& n : family) {	
			cout << n << " ";; 
	}

	cout <<"\n";

	return 1;
}
