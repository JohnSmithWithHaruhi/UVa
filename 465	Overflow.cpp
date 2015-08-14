#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <sstream>

using namespace std;

int main() 
{	
	const int max_int = 2147483647;
	double a, b;
	char x;

	string str;
	while (getline(cin, str) && str[0] != EOF)
	{
		cout << str << endl;
		istringstream is(str);
		is >> a >> x >> b;
	
		if (a > max_int) cout << "first number too big" << endl;
		if (b > max_int) cout << "second number too big" << endl;
		if (x == '+' && a + b > max_int || x == '*' && a*b >= max_int) cout << "result too big" << endl;
	}
	return 0;
}
