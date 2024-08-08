// 167. Two Sum II - Input Array Is Sorted
// Using Constant Space; 1 based indexing
// Time Complexity: O(n), Space = O(1);
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
    vector<int> twoSum(vector<int> arr, int target) {
        int left = 0, right = arr.size() -1;
        int sum = 0;
        while(left < right){
            sum = arr[left] + arr[right];
            if(sum == target)
                break;
            else if(sum >target)
                right--;
            else 
                left++;
        }
        return {left+1, right+1};
    }
};
int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int>arr(n);
    cout << "Enter elements: ";
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << "Enter target: ";
    cin >> target;
    Solution obj1;
    vector<int>res = obj1.twoSum(arr, target);
    cout << res[0] << " " << res[1];
}