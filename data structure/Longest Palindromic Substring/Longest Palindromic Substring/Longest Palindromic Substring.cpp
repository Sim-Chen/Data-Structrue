#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Solution {
public:
	string longestPalindrome_dp_way(string s) {

		string longest;

		int n = s.size();
		if (n<=1) return s;

		//Construct a matrix, and consdier matrix[i][j] as s[i] -> s[j] is Palindrome or not.

		//using char or int could cause the `Memory Limit Error`
		//vector< vector<char> > matrix (n, vector<char>(n));

		//using bool type could cause the `Time Limit Error`
		vector< vector<bool> > matrix (n, vector<bool>(n));

		// Dynamic Programming 
		//   1) if i == j, then matrix[i][j] = true;
		//   2) if i != j, then matrix[i][j] = (s[i]==s[j] && matrix[i+1][j-1])
		for (int i=n-1; i>=0; i--){
			for (int j=i; j<n; j++){
				// The following if statement can be broken to 
				//   1) i==j, matrix[i][j] = true
				//   2) the length from i to j is 2 or 3, then, check s[i] == s[j]
				//   3) the length from i to j > 3, then, check s[i]==s[j] && matrix[i+1][j-1]
				if ( i==j || (s[i]==s[j] && (j-i<2 || matrix[i+1][j-1]) ) )  {
					matrix[i][j] = true;
					if (longest.size() < j-i+1){
						longest = s.substr(i, j-i+1);
					}
				}
			}
		}

		return longest;
	}
	
	string IsPalidrome(string s,int startPos)
	{
		int Mid=(s.length()/2);
		string Str=s.substr(startPos,s.length()-startPos);
		string s2;
		string s1=Str.substr(0,Mid);
		if(s.length()%2==0)
			for(string::size_type i=Str.size()-1;i>=Mid;--i)
				 s2+=Str[i];
		else
			for(string::size_type i=Str.size()-1;i>Mid;--i)
				 s2+=Str[i];
		if(s1==s2)
			return Str;
		else
			return "";
	}
};
int main()
{
	string s="babad";
	Solution T;
	/*string s3="abc";
	
		cout<<T.findPalindrome(s3,0,1)<<endl;*/
	string s2=T.longestPalindrome_dp_way(s);
	cout<<s2<<endl;
	
	return 0;
}