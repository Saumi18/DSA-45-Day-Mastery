// Day 11 — Stack
// Problem: Evaluate Reverse Polish Notation
//
// My notes:
// Pattern: Stack + Postfix Evaluation
// Number → push | Operator → pop 2, calculate, push result
// For - and /: temp2 op temp1
// stoi() converts string → int
// Time: O(n)
// Space: O(n)


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]!="*" && tokens[i]!="/" && tokens[i]!="+" && tokens[i]!="-"){
                st.push(stoi(tokens[i]));
            }
            if(tokens[i]=="*" && st.size()>=2){
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                st.push(temp1*temp2);
            }
            if(tokens[i]=="+" && st.size()>=2){
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                st.push(temp1+temp2);
            }
            if(tokens[i]=="-" && st.size()>=2){
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                st.push(temp2-temp1);
            }
            if(tokens[i]=="/" && st.size()>=2){
                int temp1 = st.top();
                st.pop();
                int temp2 = st.top();
                st.pop();
                if(temp1 != 0) st.push(temp2/temp1);
            }
        }
        return st.top();
    }
};

