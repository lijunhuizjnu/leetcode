class Solution {
public:
    int num[105000];
    char flag[105000];
    int help(string s){
        int size=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='-'){flag[size++]='-';}
            else if(s[i]=='+'){flag[size++]='+';}
            else if(s[i]=='*'){flag[size++]='*';}
            else if(s[i]=='/'){flag[size++]='/';}
            else if(s[i]==' ')continue;
            else num[size-1]=num[size-1]*10+(s[i]-'0'); 
        }
        return size;
    }
    int calculate(string s) {
        printf("%d\n",s.size());
        int ans[105000],k=0,A=0;
        memset(num, 0, sizeof(ans));
        int size=help(string ('+'+s));
        for(int i=0;i<size;i++){
            if(flag[i]=='+'){ans[k++]=num[i];}
            else if(flag[i]=='-'){ans[k++]=-num[i];}
            else if(flag[i]=='*'){ans[k-1]*=num[i];}
            else if(flag[i]=='/'){ans[k-1]/=num[i];}
        }
        for(int i=0;i<k;i++)
            A+=ans[i];
        return A;
    }
};
