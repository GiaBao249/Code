#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string s;
	getline(cin, s);
	stack<char> st;
	int res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '[')
			st.push(s[i]);
		else
		{
			if (st.empty())
				continue;
			else
			{
				st.pop();
				res += 2;
			}
		}
	}
	cout << res << endl;
}