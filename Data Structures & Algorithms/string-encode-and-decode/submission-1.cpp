class Solution {
public:

    string encode(vector<string>& strs) {
        string s;
        for(int i=0; i<strs.size(); i++){
            for(auto st: strs[i]){
                s+=st;
            }
            s+='\n';
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string>output;
        string temp;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '\n'){
                 output.push_back(temp);
                 temp.clear();
            }
            else{
                temp+=s[i];
            }
        }
        return output;
    }
};
