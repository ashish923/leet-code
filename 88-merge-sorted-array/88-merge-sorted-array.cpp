class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
          vector <int> vc;
        int l = 0,h=0;


        while(l<m && h<n){
            // cout<<"dfghj";
            if(nums1[l] > nums2[h]){
                cout<<nums2[h]<<" ";
                vc.push_back(nums2[h]);h++;
            }
            else if(nums1[l] < nums2[h]){
                cout<<nums1[l]<<" ";
                vc.push_back(nums1[l]);l++;
            }
            else{
                cout<<nums1[l]<<" "<<nums2[h]<<" ";

                vc.push_back(nums1[l]);
                vc.push_back(nums2[h]);
                l++;h++;
            }
            
        }
        if(l<=m-1){
            while(l<m){
            // cout<<"dfghj";
                cout<<nums1[l]<<" ";
                vc.push_back(nums1[l]);
                l++;
                
            }
        }
        if(h<n){
            while(h<n){
                 // cout<<"dcfvgb";
                cout<<nums2[h]<<" ";
                vc.push_back(nums2[h]);
                h++;
                
            }
        }
        int gh = vc.size();
        for(int i=0 ; i<gh ;i++){
            nums1[i] = vc[i];

        }
        
        
    }
};