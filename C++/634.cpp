class Solution {
public:
    int findDerangement(int n) {
        long long int a[3]={0,1};\
        printf("0 1 ");
        if(n<3)return a[n-1];
        for(int i=2;i<n;i++){
            int k0=a[0],k1=a[1],k2=a[2];
            long long int temp=a[0]*i+a[1]*i;
            a[0]=a[1];
            a[1]=temp%(1000000000+7);
            //printf("%d ",a[1]);
        }
        return a[1];
    }
};
