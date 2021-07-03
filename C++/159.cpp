class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        //Two Pointers 双指针
        int M=1,ans=1,m=0,n=0;
        char a=s[0],b;
        int aa=0,bb=0;
        while(n<s.size()&&s[n]==a){
            aa+=1;
            n++;
        }      
        if(n==s.size())return s.size();//if only 1 or 2 characters,return the size()
        else n+=1;
        b=s[n-1],bb=1,M=n-m;
        //printf("m=%d n=%d M=%d aa=%d bb=%d\n",m,n,M,aa,bb);
        while(n<s.size()){
            //printf("a=%c b=%c m=%d n=%d M=%d aa=%d bb=%d\n",a,b,m,n,M,aa,bb);
            if(m==n){n+=1;continue;}
            if(s[n]==a){n+=1;aa++;M=max(n-m,M);}
            else if(s[n]==b){n+=1;bb++;M=max(n-m,M);}
            else{
                //If the third letter appears, move the first pointer until there are only two
                while(aa>0&&bb>0){
                    printf("%d %d\n",aa,bb);
                    if(m==n)break;
                    if(s[m]==a){aa--;}
                    else if(s[m]==b){bb--;}
                    m+=1;
                }
                if(aa==0){aa=1;a=s[n];}
                else if(bb==0){bb=1;b=s[n];}
                n+=1;
            }
        }
        //printf("m=%d n=%d M=%d aa=%d bb=%d\n",m,n,M,aa,bb);
        return M;
    }
};
