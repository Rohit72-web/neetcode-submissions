class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // using bucket sort
        unordered_map<int,int>mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        vector<vector<int>>freq(nums.size()+1);
        for(auto it: mp){
            freq[it.second].push_back(it.first);
        }
        vector<int> result;
        for(int i = freq.size()-1; i>=1; i--){
            for (int x : freq[i]) {
                result.push_back(x);

                if (result.size() == k) {
                    return result;
                }
            }
        }
        return result;

    }
};
