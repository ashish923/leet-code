class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        unordered_set<int> st;
        unordered_map<int,int> mp;
        for(int i=0; i<n; i++){
            st.insert(nums[i]);
            mp[nums[i]]++;
        }
        int maxx = 0;
        for(int i=0; i<n; i++){
            int z = nums[i];
            int c = 1;
            if(mp.find(z) != mp.end())
            {
                int zm = z - 1;
                while(mp.count(zm) > 0){
                    mp.erase(zm);
                    zm--;
                    c++;
                }
                zm = z+1;
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