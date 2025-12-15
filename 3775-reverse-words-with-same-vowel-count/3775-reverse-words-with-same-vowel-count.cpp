class Solution {
public:
    string reverseWords(string s) {
       int n= s.length();
       int count=0;
       int j=n ;
       string word="";
       for(int i=0;i<n;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            word+=s[i];
            count++;
        }
        else if(s[i]==' '){
            j= i + 1;
            break;
        }
        else{
            word+=s[i];
        }
       } 
       string ans=word;
       
       string w="";
       int current_count=0;
       if(j<n)
       {for(int i=j;i<=n;i++){
        
        if(i==n || s[i]==' '){
            ans+=" ";
            if(current_count==count){
                reverse(w.begin(),w.end());
            }
            ans+=w;
            w="";
            current_count=0;
            continue;
        }
       else if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
            current_count++;
            w+=s[i];
        }
        else{
            w+=s[i];
        }
       }}
       return ans;
    }
};