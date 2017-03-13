/*Given an array of integers, return indices of the two numbers
such that they add up to a specific target.
You may assume that each input would have exactly one solution, 
and you may not use the same element twice.
Example:
Given nums = [2, 7, 11, 15], target = 9,
Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		int i,j,temp;
		vector<int>Result(2);
		for(i=0;i!=nums.size();i++)
		{
			temp=target-nums[i];
			for(j=0;j!=nums.size();j++)
				if(temp==nums[j]&&i!=j)
				{
					Result[0]=i;
					Result[1]=j;
					return Result;

				}

		}
		return  Result;
	}
};

int main()
{
	vector<int>a(3);
	a[0]=3;
	a[1]=2;
	a[2]=4;
	
	int target=6;
	Solution v;
	vector<int>re=v.twoSum(a,target);
	for(vector<int>::iterator iter=re.begin();iter!=re.end();iter++)
		cout<<*iter<<endl;
	return 0;
}