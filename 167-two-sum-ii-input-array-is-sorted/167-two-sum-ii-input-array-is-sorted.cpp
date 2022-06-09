class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
         int a =0 ,b = numbers.size() -1;
        vector <int> vc;
        while(a<=b){
          if(numbers[a]+numbers[b] == target)
          {
              vc.push_back(a+1);
              vc.push_back(b+1);
            return vc;
          }
        if(numbers[a]+numbers[b] > target)    
            b--; 
        else
            a++;        
    }
        return vc;
    }
};