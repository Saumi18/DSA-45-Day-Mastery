// Day 11 — Stack
// Problem: Min Stack
//
// My notes:
// Pattern: Stack + Auxiliary Stack
// Idea: Use minSt to keep track of minimum elements
// getMin(): minSt.top() gives minimum in O(1)
// Push: push into minSt if val <= current minimum
// Pop: if st.top() == minSt.top(), pop from both
// Time: O(1) for push, pop, top, getMin
// Space: O(n)


class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {
    }
    
    void push(int val) {
        st.push(val);
        if(minSt.empty()) minSt.push(val);
        else if(minSt.top()>=val){
            minSt.push(val);
        }
        else return;
    }
    
    void pop() {
        if(minSt.top()==st.top()){
            st.pop();
            minSt.pop();
        }
        else st.pop();
        return;
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

