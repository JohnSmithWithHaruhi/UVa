#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
//#include <algorithm>
//#include <stdio.h>

using namespace std;

string change(vector<string> find, vector<string> replace, string str)
{
	for (int i = 0; i < find.size(); i++)
	{
		while(str.find(find[i])!=string::npos)
			str.replace(str.find(find[i]), find[i].size(), replace[i]);
	}

	return str;
}

int main() {

	int x;
	string temp,str;

	while (cin >> x && x != 0)
	{
		vector<string> find(x);
		vector<string> replace(x);
		getline(cin, temp);

		for (int i = 0; i < x; i++)
		{
			getline(cin, find[i]);
			getline(cin, replace[i]);
		}

		getline(cin, str);
		cout << change(find, replace, str) << endl;
	}

	return 0;
}
