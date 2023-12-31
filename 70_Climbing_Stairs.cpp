/*  Leetcode Solution
Ques:- You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. 
In how many distinct ways can you climb to the top?

Approach: Number of distinct ways is just a sum of series of fibonacci series upto that number.

Time  Complexity: O(n)
Space Complexity: O(1)
*/

class Solution
{
public:
    int climbStairs(int n)
    {
        int first=0, second=1, third;
        if(n == 1) return 1;
        else
        {
            for(int i=0; i<n; i++)
            {
                third = first+second;
                first=second;
                second=third;
            }
            return third;
        }
    }
};