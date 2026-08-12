class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int maxi = 0;
        for(auto it: mp){
            if(mp.find(it.first-1)!=mp.end()) continue;
            int current = it.first;
            int longg = 1;
            while(mp.find(current+1)!=mp.end()){
                current++;
                longg++;
            }
            maxi = max(longg,maxi);

        }
        return maxi;


    }
};
