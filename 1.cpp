// Two Sum
// Optimal Approach
// Time COmplexity: O(n);
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution{
    public:
    vector<int> twoSum(vector<int> arr, int n, int target){
        unordered_map<int, int>prefixSum;
        int sum = 0;
        int a, b;
        for(int i=0; i<n; i++) {
            sum = target - arr[i];
            if(prefixSum.find(sum) != prefixSum.end()){
                a = prefixSum[sum];
                b = i;
                break;
            }
            prefixSum[arr[i]] = i;
        }
        return {a, b};
    }
};
int main() {
    int n, val, target;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cout << "Enter target: ";
    cin >> target;
    Solution obj1;
    vector<int> res = obj1.twoSum(arr, n, target);
    cout << res[0] << " " << res[1] << endl;
}