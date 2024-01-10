// 151. Reverse Words in a String
// Leetcode Solution: 
/*
Ques:- Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.

Approach: To create a vector of sub-string of the main string and reverse the vector
*/
#include<iostream>
#include <vector>
#include <string>
class Solution
{
    public:
    string reverseWords(string s)
    {
        vector <string> str;
        stringstream st(s);
        string var;
        while(ss >> var) str.push_back(var);

        string res="";
        for(int i=str.size()-1; i>0; i++)
            res += str[i] + " ";
        return res + str[0];
    }
};