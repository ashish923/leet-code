class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int j= 0,i=0, n = nums.size(),c = 0,maxx = 0;
        unordered_map<int,int> mp;
        vector<int> vc(n,0);
        vc[0] = nums[i];
       
        while(j < n){
            
            if(mp.find(nums[j]) == mp.end()){
                mp[nums[j]]++;
                
                if(j>0){
                    vc[j] = vc[j-1] + nums[j];
                }
                
                if(i==0)
                    maxx = max(maxx,vc[j]);
                else
                maxx = max(maxx,vc[j] - vc[i-1]);
                j++;
                
              
            }
            else{
               
                mp.erase(nums[i]);
                i++;
                
            }
        }
       return maxx;
        
    }
};