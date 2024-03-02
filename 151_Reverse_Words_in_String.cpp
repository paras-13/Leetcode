// 151. Reverse Words in a String
// Leetcode Solution: 
/*
Ques:- Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.

Approach: To create a vector of sub-string from the main string and reverse the vector
*/
class Solution {
public:
    string reverseWords(string s)
    {
        vector <string> str;
        stringstream st(s);
        string var;
        while(st >> var) str.push_back(var);

        reverse(str.begin(), str.end());
        string res="";
        for(int i=0; i<str.size()-1; i++)
            res+=str[i]+" ";
        return res+str[str.size()-1];
    }
};