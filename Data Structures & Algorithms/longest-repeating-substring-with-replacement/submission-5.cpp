class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int max_count = 0;
        vector<int> mp(26,0);
        int max_len = 0;
        int left = 0;
        for(int right =0; right<n; right++){
            mp[s[right]-'A']++;
            max_count = max(max_count,mp[s[right]- 'A']);
            while((right-left+1)-max_count > k){
                mp[s[left] - 'A']--;
                left++;
            }
            max_len = max(max_len,(right-left+1));
        }
        return max_len;
    }
};
