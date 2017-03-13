/* Container With Most Water
Given n non-negative integers a1, a2, ..., an,
where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints
of line i is at (i, ai) and (i, 0). Find two lines, which
together with x-axis forms a container, such that the container
contains the most water.

Note: You may not slant the container and n is at least 2.
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size()<2) return 0;
		int Area = 0;
		int Area1 = 0;
		
		for (int i = 0; i != height.size() - 1; ++i)
		{
			bool  flag = false;
			for (int j = height.size() - 1; j != i; --j)
			{
				if (height[j]>=height[i])
				{
					Area = (Area>height[i] * (j - i)) ? Area : height[i] * (j - i);
					flag = true;
					break;
				}
				else
				{
					Area1 = (Area1>height[j] * (j - i)) ? Area1: height[j] * (j - i);
					if(flag)
						break;

				}
			}

		}
		return Area>Area1 ? Area : Area1;
	}
	
};


int main()
{
	vector<int> a;
	for (int i = 0; i != 150000; ++i)
		a.push_back(i + 1);
	
	Solution s;
	clock_t start_time = clock();
	int area = s.maxArea(a);
	clock_t end_time = clock();
	cout << "time: " << end_time - start_time << endl;
	cout << area << endl;
	system("pause");
	return 0;
}