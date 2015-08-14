#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<int> product(vector<int> num, vector<int> num2)
{
	vector<int> zero(1, 0);

	if (num[0] == 0 && num.size() == 1 || num2[0] == 0 && num2.size() == 1)
	{
		return zero;
	}

	int temp;
	vector<int> tempnum(num[num.size() - 1] * num2[num2.size() - 1] >= 10 ? num2.size() + num.size() : num2.size() + num.size() - 1);
	for (int i = 0; i < num2.size(); i++)
	{
		for (int j = 0; j < num.size(); j++)
		{
			tempnum[j+i] += num[j] * num2[i];
		}
	}

	for (int j = 0; j < tempnum.size() - 1; j++)
	{
		if (tempnum[j] >= 10)
		{
			temp = tempnum[j] / 10;
			tempnum[j] %= 10;
			tempnum[j + 1] += temp;
		}
	}

	if (tempnum[tempnum.size() - 1] >= 10)
	{
		temp = tempnum[tempnum.size() - 1] / 10;
		tempnum[tempnum.size() - 1] %= 10;
		tempnum.push_back(temp);
	}

	return tempnum;
}

int main() 
{
	string str;

	while (getline(cin, str) && str[0] != EOF)
	{
		vector<int> num;
		for (int i = str.size() - 1; i >= 0; i--)
		{
			num.push_back(str[i] - 48);
		}

		getline(cin, str);
		vector<int> num2;
		for (int i = str.size() - 1; i >= 0; i--)
		{
			num2.push_back(str[i] - 48);
		}

		num = product(num, num2);

		for (int i = num.size() - 1; i >= 0; i--)
		{
			cout << num[i];
		}
		cout << endl;
	}

	return 0;
}
