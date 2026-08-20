class Solution {
public:
    vector<int> funLeft(vector<int>& height,int n , vector<int> & left_max){
        left_max[0] = height[0];
        for(int i=1; i<n; i++){
            left_max[i] = max(height[i],left_max[i-1]);
        }
        return left_max;
    }
    vector<int> funRight(vector<int>& height,int n , vector<int> & right_max){
        right_max[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            right_max[i] = max(height[i],right_max[i+1]);
        }
        return right_max;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n);
        vector<int> right_max(n);
        funLeft(height,n, left_max);
        funRight(height,n,right_max);
        int answer = 0;
        for(int i =0; i<n; i++){
            int water = min(left_max[i],right_max[i]) - height[i];
            answer += water;
        }
        return answer;
    }
};
