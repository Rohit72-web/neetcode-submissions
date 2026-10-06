class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int n = heights.size();
        vector<int> left_min(n,0);
        vector<int> right_min(n,0);
        
        for(int i=0; i<n; i++){
            if(i == 0){
                left_min[i] = -1;
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                left_min[i] = -1;
                st.push(i);
                continue;
            }
            left_min[i] = st.top();
            st.push(i);
        }

        while(!st.empty()){
            st.pop();
        }

        // evaluating right_min
        for(int i=n-1; i>=0; i--){
            if(i == n-1){
                right_min[i] = -1;
                st.push(i);
                continue;
            }
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(st.empty()){
                right_min[i] = -1;
                st.push(i);
                continue;
            }
            right_min[i] = st.top();
            st.push(i);
        }

        // calculating max rectangle
        int maxi = INT_MIN;
        for(int i=0; i<n; i++){
            if(left_min[i] == -1 && right_min[i] == -1){
                maxi = max(maxi,heights[i]*n);
                continue;
            }
            if(left_min[i] == -1 || right_min[i] == -1){
                if(left_min[i] == -1) maxi = max(maxi, (right_min[i])* heights[i]);
                else maxi = max(maxi, (n- left_min[i]-1)* heights[i]);
                continue;
            }
            maxi = max(maxi, (right_min[i]-left_min[i]-1)*heights[i]);
        }

        return maxi;
    }
};
