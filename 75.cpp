// 75. Sort Colors
#include <iostream>
#include <vector>
using namespace std;
//* Ques: Given an array of size N containing only 0s, 1s, and 2s; sort the array in ascending order.
// Time Complexity: O(n);
class Solution {
    public:
    void sortColors(vector<int> &nums) {
        /*
        ? Approach 1: Count number of 0s, 1s, and 2s; Overwrite array with the total number of 0's, then 1's and followed by 2's.
        int cz=0, co=0, ct=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)
                cz++;
            else if(nums[i] == 1)
                co++;
            else
                ct++;
        }
        for(int i=0; i<nums.size(); i++){
            if(cz){
                nums[i] = 0;
                cz--;
            }
            else if(co){
                nums[i] = 1;
                co--;
            }
            else 
                nums[i] = 2;
        }
        */
       //? Approach 2: Using two pointer approach...
        int beg = 0, end = nums.size()-1, mid = 0;
        while(mid <= end) {
            if(nums[mid] == 0){
                swap(nums[beg], nums[mid]);
                mid++;
                beg++;
            }
            else if(nums[mid] == 1)
                mid++;
            else{
                swap(nums[mid], nums[end]);
                end--;
            }
        }
    }
};
int main() {
    vector<int>nums = {1, 2, 1, 0, 0, 1, 2, 0, 1, 0, 1, 0, 1, 1, 0, 1};
    Solution obj1;
    obj1.sortColors(nums);
    for(int i=0; i<nums.size(); i++)
        cout << nums[i] << " ";
}