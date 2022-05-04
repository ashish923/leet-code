class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int c_max = INT_MIN;
        int start = -1,end;
    for(int i=0; i<n; i++){
        if(c_max < nums[i]) 
            c_max = nums[i];
        if(nums[i] < c_max) 
            end = i;
        
        // cout<<c_max<<" "<<nums[i]<<" "<<end<<"\n";
    }
       int c_min = INT_MAX; 
    for(int i=n-1; i>=0; i--){
        
        if(c_min > nums[i]) c_min = nums[i];
        
        if(nums[i] > c_min) start = i;
    }    
        // cout<<end;
     if(start == -1) return 0;
        
        return end - start + 1;
    
    }
};