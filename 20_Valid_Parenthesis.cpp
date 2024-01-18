// 20. Valid Parenthesis
/*
Ques:- Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
*/
// Code-->
class Solution {
public:
    bool isValid(string s)
    {
        stack <char> st;
        if(s.length() == 1) return false;
        for(int i=0; i<s.length(); i++)
        {
            char bracket = s[i];
            if(bracket=='(' || bracket == '[' || bracket == '{') st.push(bracket);
            else
            {
                if(!st.empty())
                {
                    char ch = st.top();
                    if(s[i]==')') 
                    {
                        if(ch == '(') st.pop();
                        else return false;
                    }
                    else if(s[i]==']') 
                    {
                        if(ch == '[') st.pop();
                        else return false;
                    }
                    if(s[i]=='}') 
                    {
                        if(ch == '{') st.pop();
                        else return false;
                    }
                }
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};