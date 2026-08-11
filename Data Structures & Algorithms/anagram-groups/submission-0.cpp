class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<int>>mp;
         vector<string> st = strs;

         for(int i=0; i<strs.size(); i++){
            sort(strs[i].begin(),strs[i].end());
            mp[strs[i]].push_back(i);
         }
         vector<vector<string>> result;
         for(auto it: mp){
            vector<string> temp;
            for(int i=0;i<it.second.size();i++){
                temp.push_back(st[it.second[i]]);
            }
            result.push_back(temp);
         }
         return result;
    }
};
