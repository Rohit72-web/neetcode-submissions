class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        int left = 0;
        int right = 0;
        unordered_map<int,int> mp;
        int maxi = 0;
        int count = 0;
        while(right<n){
            while(mp.find(s[right])==mp.end() && right<n){
                mp[s[right]] = right;
                count++;
                right++;
            }
            maxi = max(maxi,count);
            while(s[left]!=s[right]){
                mp.erase(s[left]);
                left++;
                count--;
            }
            mp.erase(s[left]);
            left++;
            count--;
        }
        return maxi;
    }
};
