class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
      
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            
            mp[nums[i]]++;
        }
        int maxx = 0;
        for(int i=0; i<n; i++){
            int z = nums[i];
            int c = 1;
//             first we check ele is present or not 
            if(mp.find(z) != mp.end())
            {
                int zm = z - 1;
//          in this loop we r checking to left the side how many element are there consecutively
                while(mp.count(zm) > 0){
                    mp.erase(zm);
                    zm--;
                    c++;
                }
                zm = z+1;
//                 same procedure in right side
               while(mp.count(zm) > 0){
                    mp.erase(zm);
                    zm++;
                    c++;
                }
            }
            mp.erase(z);
            maxx = max(maxx,c);
        }
        
      return maxx;  
    }
};