/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string  prefix = "";
		if (strs.empty()) return prefix;
		for (int i = 0; i < strs[0].size(); ++i)
		{	
			int k = 1;
			for (; k != strs.size()&&strs[k].size()>i; k++)
			{
				if (strs[0][i] != strs[k][i])
					return prefix;
			}
			if (k == strs.size())
				prefix += strs[0][i];
		}

	}

		
};





int main()
{
	vector<string> a = { "aca","cba" };
	Solution b;
	string c("");
	cout << c.size() << endl;
	cout << c.length() << endl;
	string Prefix = b.longestCommonPrefix(a);
	cout << "Prefix: " << Prefix << endl;
	system("pause");
	return 0;
}