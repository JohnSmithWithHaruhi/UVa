#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <set>
#include <algorithm>  

using namespace std;

int main()
{	
	set<string> words;
	set<string>::iterator it;

	string temp;
	while (getline(cin, temp))
	{
		vector<string> str(200);
		int count = 0;
		for (int i = 0; i < temp.size(); i++)
		{
			if (!isalpha(temp[i]))
				temp[i] = ' ';
			else if (temp[i] >= 'A' && temp[i] <= 'Z')
				temp[i] += 32;
		}

		for (int i = 0; i < temp.size(); i++)
		{
			if ((i == 0 && isalpha(temp[i])) || (temp[i - 1] == ' ' && isalpha(temp[i])))
			{
				while (temp[i] != ' ' && i < temp.size())
				{
					str[count].push_back(temp[i]);
					i++;
				}
				count++;
			}
		}

		for (int i = 0; i < str.size(); i++)
		{
			if (!str[i].empty())
				words.insert(str[i]);
			else
				break;
		}
	}

	for (it = words.begin(); it != words.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}
