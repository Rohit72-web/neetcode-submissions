class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0;
        int right = k;
        int n = nums.size();
        int maxi = INT_MIN;
        int index = 0;
        vector<int> result;
        // edge case
        if(n<k){
            for(int i=0; i<n; i++){
                maxi = max(maxi, nums[i]);
            }
            result.push_back(maxi);
            return result;
        }
        // first k maximum
        for(int i=0; i<k; i++){
            if(nums[i]>maxi){
                maxi = nums[i];
                index = i;
            }
        }
        result.push_back(maxi);
        while(right<n){
            if(nums[right]>maxi){
                maxi = nums[right];
                result.push_back(nums[right]);
                index = right;
            }
            else{
                if(index == left){
                    maxi = INT_MIN;
                    for(int i = left+1; i<=right; i++){
                        if(nums[i]>maxi){
                            index = i;
                            maxi = nums[i];
                        }
                    }
                    result.push_back(maxi);
                }
                else{
                    result.push_back(maxi);
                }
            }
            left++;
            right++;
        }
        return result;
    }
};
