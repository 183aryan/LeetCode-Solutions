class Solution {
public:
    int strStr(string haystack, string needle) {
        int j=0;
        for(int i=0;i<haystack.size();i++){
            if(j < needle.size() and haystack[i] == needle[j]){
                j++;
                if(j == needle.size()) return (i - j + 1);
            }
            else{
                i = i - j;
                j = 0;
            }
            
        }
        return -1;
    }
};