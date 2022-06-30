class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int s=INT_MAX,l = INT_MIN,n = nums.size(); 
        int mid = nums[n/2];
        int sum = 0;
        for(int i = 0; i < n; i++){
            sum += abs(nums[i] - mid);
            
        }
        
        return sum;
    }
};