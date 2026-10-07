class Solution {
public:
    bool fun(int mid, vector<int>& piles, int h){
        int sum = 0;
        for(int i=0; i<piles.size(); i++){
            sum += (piles[i]+mid-1)/mid;
            if(sum > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int i=0; i<piles.size(); i++){
            maxi = max(maxi,piles[i]);
            mini = min(mini,piles[i]);
        }
        int left = 1;
        int right = maxi;
        int ans = INT_MAX;
        while(left<=right){
            int mid = (right+left)/2;
            if(fun(mid,piles,h)){
                right = mid-1;
                ans = min(ans,mid);
            }
            else{
                left = mid+1;
            }
        }
        return ans;
    }
};
