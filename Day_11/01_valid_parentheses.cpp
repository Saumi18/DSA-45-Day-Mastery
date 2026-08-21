// Day 11 — Stack
// Problem: Valid Parentheses
//
// My notes:
// Pattern: Stack + Matching Pairs
//
// Intuition:
// Opening bracket → push into stack
// Closing bracket → check top, if matching → pop
// Mismatch OR empty stack → false
// At the end, stack must be empty
//
// Important:
// Never call st.top() without checking !st.empty()
// Otherwise → runtime error
//
// Time: O(n)
// Space: O(n)


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(!st.empty() && ((s[i]=='}' && st.top()=='{')||(s[i]==')' && st.top()=='(')||(s[i]==']' && st.top()=='['))){
                st.pop();
            }
            else {
                return false;
            }
        }
        if(st.empty()) return true;
        else return false;
    }
};

