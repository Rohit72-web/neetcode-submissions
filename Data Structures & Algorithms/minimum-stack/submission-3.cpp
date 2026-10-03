class MinStack {
public:
    stack<int> st;
    stack<int> min;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(min.empty()){
             min.push(val);
             return;
        }
        if(st.top()<min.top()){
            min.push(st.top());
        }
        else{
            min.push(min.top());
        }
        
    }
    
    void pop() {
        st.pop();
        min.pop();
        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};
