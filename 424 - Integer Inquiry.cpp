#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<int> plus_fun(vector<int> num, vector<int> plus)
{

	bool flag = 0;
	int dif = 0,temp;
	if (num.size() >= plus.size())
	{
		dif = num.size() - plus.size();
		for (int i = 0; i < num.size() - dif; i++)
		{
			num[i] = num[i] + plus[i];
		}

		for (int i = 0; i < num.size()-1; i++)
		{
			if (num[i] >= 10)
			{
				num[i] -= 10;
				num[i + 1] += 1;
			}
		}

		if (num[num.size()-1] >= 10)
		{
			num[num.size() - 1] -= 10;
			num.push_back(1);
		}

	}

	else
	{
		dif = plus.size() - num.size();
		for (int i = 0; i < plus.size() - dif; i++)
		{
			num[i] = num[i] + plus[i];
		}

		for (int i = plus.size() - dif; i < plus.size(); i++)
		{
			num.push_back(plus[i]);
		}

		for (int i = 0; i < num.size() - 1; i++)
		{
			if (num[i] >= 10)
			{
				num[i] -= 10;
				num[i + 1] += 1;
			}
		}

		if (num[num.size() - 1] >= 10)
		{
			num[num.size() - 1] -= 10;
			num.push_back(1);
		}
	}

	return num;

}

int main() {

	string str;
	getline(cin, str);
	vector<int> num(0, str.size());

	for (int i = str.size() - 1; i >= 0; i--)
	{
		num.push_back(str[i] - 48);
	}

	while (getline(cin, str) && str[0] != '0')
	{
		vector<int> plus(0, str.size());
		for (int i = str.size() - 1; i >= 0; i--)
		{
			plus.push_back(str[i] - 48);
		}

		num = plus_fun(num, plus);

	}

	for (int i = num.size() - 1; i >= 0; i--)
	{
		cout << num[i];
	}
	cout << endl;

	return 0;
}
