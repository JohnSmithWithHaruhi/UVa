#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool is_decode(vector<string> words)
{
	for (int i = 0; i < words.size() - 1; i++)
	{
		int len;
		len = words[i].size() > words[i + 1].size() ? words[i+1].size() : words[i].size();
		for (int j = 0; j < len; j++)
		{
			if (words[i][j] != words[i + 1][j])
				break;

			else if (j == len -1)
				return 0;
		}
	}
	return 1;
}

int main() {

	int count = 1;
	string str;

	while (getline(cin,str) && str[0] != EOF) 
	{
		vector<string> words;
		words.push_back(str);
		while (getline(cin, str) && str != "9")
		{
			words.push_back(str);
		}

		sort(words.begin(), words.end());

		if (is_decode(words))
			printf("Set %d is immediately decodable\n", count++);
		else
			printf("Set %d is not immediately decodable\n", count++);
	}
	return 0;
}
