class Solution {
public:
    int maxProfit(vector<int>& prices) {
        stack<int> st;
        for(int i=0; i<prices.size(); i++){
            st.push(prices[i]);
        }
        // if(st.size() == 1) return 0;
        int max_profit = 0;
        while(!st.empty()){
            if(st.size() == 1) return max_profit;
            int t = st.top();
            st.pop();
            int s_top = st.top();
            st.pop();
            int profit = t - s_top;
            max_profit = max(profit,max_profit);
            st.push(max(t,s_top));
        }
        return max_profit;
    }
};
