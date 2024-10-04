// Longest Substring Without Repeating Characters
// Time :- O(N)
// Space :- O(N)
// my approach
#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string str) {
        unordered_map<char, int>mp;
        int n = str.length();
        int maxWindow = 0;
        int ptr=0, i=0;
        while(ptr+maxWindow < n) {
            if(i == n) {
                maxWindow = max(maxWindow, i-ptr);
                break;
            }
            if(mp.find(str[i]) == mp.end()) {
                mp[str[i]] = ptr+1;
                i++;
            }
            
            else {
                if(mp[str[i]] > ptr) {
                    mp[str[i]] = ptr;
                    maxWindow = max(maxWindow, i-ptr);
                    ptr++;
                    i = ptr;
                }
                else {
                    mp[str[i]] = ptr+1;
                    i++;
                }
            }
        }
        return maxWindow;
    }
};

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;
    Solution s1;
    cout << s1.lengthOfLongestSubstring(str);
    return 0;
}