class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int right = n-1;
        int left = n-2;
        if(n == 1) return max_profit;
        while(left>=0){
            int t = prices[right];
            int s_t = prices[left];
            int profit = t - s_t;
            max_profit = max(max_profit,profit);
            if(prices[right]>prices[left]) left--;
            else{
                right = left;
                left--;
            }
        }
        return max_profit;
    }
};
