class Solution {
public:
    bool fun(unordered_map<char,int>& mp) {
        for(auto it : mp) {
            if(it.second > 0) return true;
        }
        return false;
    }

    string minWindow(string s, string t) {
        if(s.size() < t.size()) return "";

        unordered_map<char,int> mp;

        for(char c : t)
            mp[c]++;

        int l = 0, r = 0;
        int start = 0, minLen = INT_MAX;

        while(r < s.size()) {

            if(mp.find(s[r]) != mp.end())
                mp[s[r]]--;

            while(!fun(mp)) {

                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                if(mp.find(s[l]) != mp.end())
                    mp[s[l]]++;

                l++;
            }

            r++;
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};