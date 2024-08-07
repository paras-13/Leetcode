// Subarray Sum equals K (Count number of subarray with some k)
// Time Complexity: O(n)
// Space Complexity: O(n)
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution {
    public:
    int subarraySum(int arr[], int k, int n){
        unordered_map<int, int>prefixSum;
        int count = 0;
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += arr[i];
            if(sum == k)
                count++;
            if(prefixSum.find(sum - k) != prefixSum.end())
                count += prefixSum[sum-k];
            prefixSum[sum]++;
        }
        return count;
    }
};
int main() {
    int n, k;
    cout << "Enter number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements: ";
    for(int i=0; i<n; i++) 
        cin >> arr[i];

    cout << "Enter k: ";
    cin >> k;
    Solution obj1;
    cout << obj1.subarraySum(arr, k, n);
}