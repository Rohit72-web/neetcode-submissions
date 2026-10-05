class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int,int> mp;
        for(int i=0; i<speed.size(); i++){
            mp[position[i]] = speed[i];
        }
        sort(position.begin(), position.end());
        stack<float> st;
        for(int i=0; i<speed.size(); i++){
            st.push((float)(target-position[i])/mp[position[i]]);
        }
        int fleet = 0;
        while(!st.empty()){
            float top = st.top();
            st.pop();
            fleet++;
            while(!st.empty() && top >= st.top()){
                st.pop();
            }
        }
        
        
        return fleet;

    }
};
