class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>vis;
        int j=0;
        if(s.size()==0){
            return 0;
        }
        int ans=1;
        for(int i=0;i<s.size();i++){
            if(vis.find(s[i])!=vis.end() && vis[s[i]]!=-1){
                int in=vis[s[i]];
                while(j<=in){
                    vis[s[j]]=-1;
                    j++;
                }
                vis[s[i]]=i;
            }
            else{
                vis[s[i]]=i;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};
