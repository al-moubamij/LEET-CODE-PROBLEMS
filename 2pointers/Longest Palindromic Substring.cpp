class Longest_Palindromic_Substring {
public:
    int propagation(string s,int *l,int *r){
        int n=s.size() , ans=1;
        while((*l) >=0 && (*r)<n && s[*l]==s[*r])
        {
            ans = (*r)-(*l)+1;
            (*r)++;
            (*l)--;
        }
        return ans;
    }
    string longestPalindrome(string s) {
        int n=s.size(),l=0,r=0;
        string ans="";
        int maxLength = 0;
        if(s.size()==1){
            return s;
        }
        if(s==""){
            return s;
        }
        for(int i=0;i<n-1;i++)
        {
            //if odd
                int l1 =i;
                int r1 =i;
                int len1 = propagation(s,&l1,&r1);
            //if even
                int l2 =i;
                int r2 =i+1;
                int len2 = propagation(s,&l2,&r2);


            //select the right palindrom 
            if(maxLength< max(len1 , len2)){
                if(len1>len2){
                    maxLength=len1;
                    ans = s.substr(l1+1,len1);
                }else{
                    maxLength = len2;
                    ans = s.substr(l2+1,len2);
                }
            }
        }
        return ans;
    }
};