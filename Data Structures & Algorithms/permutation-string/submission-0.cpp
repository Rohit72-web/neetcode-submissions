class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.size()<s1.size()) return false;
        int left = 0;
        int right = s1.size()-1;
        
        
        while(right<s2.size()){
            bool pos = true;
            vector<int> mp(26,0);
            for(int i=0; i<s1.size(); i++){
                mp[s1[i]-'a']++;
            }
            for(int i=left; i<=right; i++){
                mp[s2[i]-'a']--;
            }
            for(int i=0; i<26; i++){
                if(mp[i]!=0){
                    left++;
                    pos = false;
                    break;
                }
            }
            if(pos) return true;
            right = left + s1.size()-1;
        }
        return false;
    }
};
