class Solution {
public:
    int pivotIndex(vector<int>& nums, int target){
        int s = 0;
        int e = nums.size()-1;

        while(s<e){
            int mid = s + (e-s)/2;
            if(nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(nums[mid] >= nums[s]){
                s = mid + 1;
            }
            else{
                e = mid;
            }
        }
        return s;
    }
    int binarysearch(vector<int>& nums, int target, int s, int e){
        while(s<=e){
            int mid = s + (e-s)/2;
            if(nums[mid] == target){
                return mid;
            }
            else if(target > nums[mid]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int PivotIndex = pivotIndex(nums, target);
        if(target >= nums[0] && target <= nums[PivotIndex]){
            int ans = binarysearch(nums, target, 0, PivotIndex);
            return ans;
        }
        else{
            int ans = binarysearch(nums, target, PivotIndex+1, nums.size()-1);
            return ans;
        }
    }
};