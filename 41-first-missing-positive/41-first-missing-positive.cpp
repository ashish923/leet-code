class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
       long long n = nums.size();
        long long l = 0;
        unordered_set<long long>st;
        for(long long int i=0; i<n; i++){
            st.insert(nums[i]);
            if(nums[i]>l) l= nums[i];
        }
        for(long long int i=1; i<=l; i++){
            if(st.find(i) == st.end())
                return i;
        }
        return l+1;
    }
};