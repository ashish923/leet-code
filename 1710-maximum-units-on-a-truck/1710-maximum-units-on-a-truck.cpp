class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        
        return b[1] < a[1];
    }
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int s = 0;
        sort(boxTypes.begin(),boxTypes.end(),comp);
        for(int i=0; i<boxTypes.size(); i++){
            if(truckSize == 0) break;
            if(boxTypes[i][0] <= truckSize){
                s += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else{
                s += truckSize*boxTypes[i][1];
                truckSize = 0;
                
            }
            
               
        }
      return s; 
    }
         
};