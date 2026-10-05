class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int>output(n,0);
        for(int i=0; i<n; i++){
            if(i == 0 ) {
                st.push(i);
                continue;
            }
            while( !st.empty() && temperatures[st.top()]<temperatures[i]){
                output[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return output;
    }
};
