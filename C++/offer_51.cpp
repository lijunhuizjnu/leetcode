class Solution {
public:
    int count; 
    void mergesort(vector<int>& nums,int left,int right){
        if(left<right){
            int mid=(left+right)/2;
            mergesort(nums,left,mid);
            mergesort(nums,mid+1,right);
            merge(nums,left,mid,mid+1,right);
        }
    }
    void merge(vector<int> &n,int left1,int right1,int left2,int right2){
        vector<int>n2(right2-left1+1, 0);
        int m=0;
        int k1=left1,k2=left2;
        while((k1<=right1)&&(k2<=right2)){   
            if(n[k1]<=n[k2]){
                n2[m]=n[k1];
                k1++;
                m++;
            }
            else  {       
                n2[m]=n[k2];
                k2++;
                m++;
                count+=right1-k1+1;//the only be difference with mergeSort  
            }
        }
            while(k1<=right1){n2[m++]=n[k1++];}
            while(k2<=right2){n2[m++]=n[k2++];}
            for(int i=left1;i<=right2;i++){
                n[i]=n2[i-left1];
            }
    }
    int reversePairs(vector<int>& nums) {
        count=0;
        mergesort(nums,0,nums.size()-1);
        return count;
    }
};
