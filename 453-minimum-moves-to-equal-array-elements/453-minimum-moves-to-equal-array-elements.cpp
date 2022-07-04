class Solution {
    static bool cmp(int a, int b){
        return a > b;
    }
public:
    int minMoves(vector<int>& nums) {
      sort(nums.begin(),nums.end(),cmp);
        int result = 0;
        for(int i = 1; i < nums.size(); i++){
            result += i * (nums[i] - nums[i-1]);
        }
        return abs(result);
    }
};