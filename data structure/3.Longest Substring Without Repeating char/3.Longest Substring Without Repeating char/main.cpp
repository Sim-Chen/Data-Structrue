/*Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. */

#include<iostream>
#include<string>
#include <vector>
using namespace std;
class Solution
{
public:
		int lengthOfLongestSubstring(string s)
	{
		vector<int> vec(256,-1);//≥ı ºªØ
			int maxlen=0;
			int startPos=-1;
		for(string::size_type i=0;i!=s.length();++i)
		{
			if(vec[s[i]]!=-1&&startPos<vec[s[i]])
				startPos=vec[s[i]];
			if(i-startPos>maxlen)
				maxlen=i-startPos;
			vec[s[i]]=i;
		}
		return maxlen;

	}
};

int main()
{
	string s1="abcabcda";
	Solution A;
	int num=A.lengthOfLongestSubstring(s1);
	cout<<num<<endl;
}