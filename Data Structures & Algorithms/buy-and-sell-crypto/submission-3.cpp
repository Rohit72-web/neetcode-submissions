class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_profit = 0;
        int mini = prices[0];
        for(int i=0; i<prices.size(); i++){
            max_profit = max(max_profit, prices[i]-mini);
            mini = min(mini,prices[i]);
        }
        return max_profit;
    }
};
