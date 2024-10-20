class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        string ans = "";
        string s1= strs[0];
        string s2 = strs[strs.size()-1];
        int i=0,j=0;
        while(i<s1.size()&&j<s2.size()){
            if(s1[i]==s2[j]) {
                ans += s1[i];
                i++;
                j++;

            }
            else{
                break;
            }
        }
        return ans;
    }
};