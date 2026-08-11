class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> pre;
        vector<int> post(nums.size());
        for(int i = 0;i<nums.size(); i++){
            if(i  == 0) pre.push_back(1);
            else{
                pre.push_back(pre[i-1]*nums[i-1]);
            }
        }
        for(int i = nums.size()-1;i>=0; i--){
            if(i  ==nums.size()-1 ) post[nums.size()-1]=1;
            else{
                post[i] = post[i+1]*nums[i+1];
            }
        }

        for(int i=0; i<nums.size(); i++){
            post[i] = post[i]*pre[i];
        }
        return post;
    }
};
