#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <stack>

using namespace std;

class Solution {
public:
	string removeOuterParentheses(string S)
	{
		stack<char> temp;
		string ans;
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == ')')
			{
				temp.pop();
			}
			if (!temp.empty())
			{
				ans =+ S[i];
			}
			if (S[i] == '(')
			{
				temp.push(S[i]);
			}
		}

		return ans;
	}
};

int main()
{
	string str, ans;
	Solution res;
	cin >> str;
	ans = res.removeOuterParentheses(str);
	cout << ans;

	return 0;
}