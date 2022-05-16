class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int r = 0,j = bottom, t = top;
        int c_max = 0, c = 0;
        int p = bottom;
        int n = special.size();
        for(int i=0; i<n; i++){
            if(special[i] > p){
                c_max = max(c_max,special[i] - p);
            }
            
            p = special[i] + 1;
            
        }
        c_max = max(c_max,top - p + 1);
        return c_max;
        
        
//         while(j <= t){
            
//           if(j != special[r]){
//               c++;
              
//           }  
//             else {
//                 c_max = max(c_max,c);
//                 c = 0;
//                 r++;
//             }
            
//             if(r == special.size()){
//                 c_max = max(c_max,t-j);
//                 break;
//             }
//             j++;
//         }
//         c_max = max(c,c_max);
        
        // return c_max;
        
    }
};