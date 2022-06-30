class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=INT_MAX,l = INT_MIN,n = nums.size(); 
        int mid = nums[n/2];
        cout<<mid<<" ";
        int sum = 0;
        for(int i = 0; i < n; i++){
            
            if(nums[i] > mid) sum += nums[i] - mid;
            else if(nums[i] < mid) sum += mid - nums[i];
            
        }
        
        return sum;
    }
};