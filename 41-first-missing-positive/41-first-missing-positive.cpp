class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n = nums.size();
       
        int i =0;
        int correct;
        while(i < n){
         
            
            if(nums[i] > 0 && nums[i] < n && nums[i] != nums[nums[i] - 1]){
                swap(nums[i],nums[nums[i] - 1]);
            }
            else
                i++;
            
        }
        
        for(int i=0; i<n; i++){
            
            if(i + 1 != nums[i])
                return i + 1;
        }
        return n+1;
    }
};