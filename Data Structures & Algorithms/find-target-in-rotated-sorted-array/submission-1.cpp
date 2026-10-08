class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right, int target){
        while(left<= right){
            int mid = (left+right)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid]> target) right = mid-1;
            else left = mid+1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        while(left<=right){
            int mid = (left+right)/2;
            if(nums[left]<=nums[mid]){
                if(target >= nums[left] && target <= nums[mid]){
                   return binarySearch(nums,left,mid,target);
                }
                else{
                    left = mid + 1;
                }
            }
            else{
                if(target >= nums[mid] && target <= nums[right]){
                    return binarySearch(nums,mid,right,target);
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};
