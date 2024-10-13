// 718. Maximum Length of Repeated Subarray
#include <iostream>
#include <vector>
using namespace std;

// 718. Maximum Length of Repeated Subarray
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        // Tabulation
        return tabulation(nums1, nums2);
        // Memoization
        // return memoization(nums1, nums2);
    }

private:
    // DP Tabulation
    int tabulation(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int maxLen = 0;
        vector<vector<int>>dp(n1+1, vector<int>(n2+1));
        for(int i=0; i<n1; i++)
            dp[i][0] = 0;
        for(int j=0; j<n2; j++)
            dp[0][j] = 0;
        for(int i=1; i<=n1; i++) {
            for(int j=1; j<=n2; j++) {
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                    maxLen = max(maxLen, dp[i][j]);
                }
                else
                    dp[i][j] = 0;
            }
        }
        return maxLen;
    }

    // Dp memoization
    int memo(vector<int> &n1, vector<int> &n2, int i, int j, int &maxLen, vector<vector<int>> &dp) {
        if(i<0 || j<0) 
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        if(n1[i] == n2[j]) {
            dp[i][j] = 1+memo(n1, n2, i-1, j-1, maxLen, dp);
            maxLen = max(maxLen, dp[i][j]);
        }
        else
            dp[i][j] = 0;
        return dp[i][j];
    }
    int memoization(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int maxLen = 0;
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        for(int i=0; i<n1; i++) {
            for(int j=0; j<n2; j++)
                memo(nums1, nums2, i, j, maxLen, dp);
        }
        return maxLen;
    }
};

int main() {
    int n1, n2;
    cout << "Enter size of arr1: ";
    cin >> n1;
    vector<int>arr1(n1);
    cout << "Enter elements in arr1: ";
    for(int i=0; i<n1; i++)
        cin >> arr1[i];
    cout << "Enter size of arr2: ";
    cin >> n2;
    vector<int>arr2(n2);
    cout << "Enter elements in arr2: ";
    for(int j=0; j<n2; j++) 
        cin >> arr2[j];
    Solution s1;
    cout << s1.findLength(arr1, arr2);
}