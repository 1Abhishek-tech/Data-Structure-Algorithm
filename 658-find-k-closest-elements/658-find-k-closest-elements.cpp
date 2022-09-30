class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int l=0,r=arr.size()-1;
        int mid=l+(r-l)/2;
        int temp=-1;
        
        // binary search
        while(l<=r){
            mid=l+(r-l)/2;
            if(arr[mid]==x){
                temp=mid;
                break;
            }
            else if(arr[mid]<x)
                l=mid+1;
            else
                r=mid-1;
        }
        //making sure we have the right index 'temp'
        if(temp==-1){
            temp=l;
            if(temp>arr.size()-1)
                temp=arr.size()-1;
        }
        
        if(temp-1>=0){
            if(abs(arr[temp-1]-x)<=abs(arr[temp]-x))
                temp-=1;
        }
        
        
        
        vector<int> v={arr[temp]};
        // take two pointers l and r and keep moving them away from 'x' or arr[temp]
        l=temp-1;
        r=temp+1;
        while(v.size()<k){
            if(l>=0 && r<arr.size()){
                if( abs(arr[l]-x)<=abs(arr[r]-x) ){
                    v.push_back(arr[l]);
                    l--;
                    // cout<<"1";
                }
                else{
                    v.push_back(arr[r]);
                    r++;
                    // cout<<"2";
                }
            }
            else if(l>=0){
                v.push_back(arr[l]);
                l--;
                // cout<<"3";
            }
            else if(r<arr.size()){
                v.push_back(arr[r]);
                r++;
                // cout<<"4";
            }
        }
        sort(v.begin(),v.end());
        return v;  
    }
};