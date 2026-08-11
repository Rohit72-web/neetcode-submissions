class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        mp[target-nums[0]] = 0;
        for(int i =1;i<nums.size(); i++){
            if(mp.find(nums[i])!=mp.end()) return {mp[nums[i]],i};
            mp[target-nums[i]] = i;
        }
        return {};
    }
    
};
