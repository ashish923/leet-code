class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l = 0,h = nums.size()-1;
        int  c = 0;
        while(l<h){
            int z = nums[l] + nums[h];
            if(z == k){
                
                
                c++;
                int j = l;
                // while(nums[l] == nums[j]) l++;
                // j = h;
                // while(nums[h] == nums[j]) h--;
                l++;h--;
            }
            else if(z > k){
                h--;
                
            }else{
                l++;
            }
        }
        
        return c;
        
    }
};