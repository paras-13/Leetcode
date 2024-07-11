
// 1190. Reverse Substrings Between Each Pair of Parentheses
/*
* Ques
*   You are given a string s that consists of lower case English letters and brackets.
*   Reverse the strings in each pair of matching parentheses, starting from the innermost one.
*   Your result should not contain any brackets.
*/
// Code ->
#include <bits/stdc++.h>
using namespace std;

// Function starts
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char>st;
        st.push(s[0]);
        int ptr = 1;
        while(!st.empty()) {
            if(s[ptr] == ')') {
                string str;
                while(st.top()!='(') {
                    char ch = st.top();
                    str.push_back(ch);
                    st.pop();
                }
                st.pop();
                if(st.empty() && ptr==s.length()-1) return str;
                for(int i=0; i<str.length(); i++)
                    st.push(str[i]);
            }
            else if(ptr==s.length()){
                string str;
                while(!st.empty()){
                    str.push_back(st.top());
                    st.pop();
                }
                reverse(str.begin(), str.end());
                return str;
            }
            else
                st.push(s[ptr]);
            ptr++;
        }
        return " ";
    }
};
// Function ends


int main() {
    string str;
    cout << "Enter string:";
    cin>>str;
    Solution s1;
    cout << s1.reverseParentheses(str);
}