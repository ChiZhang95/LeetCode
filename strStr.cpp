class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0){return 0;}
        if(needle.size() > haystack.size()){return -1;}
        int flag=0;
        for(int i=0; i<haystack.size(); i++){
            // if the size of needle is larger than the last string, stop the loop.
            if(i+needle.size() > haystack.size()){break;}
            // If the first item is the same
            if(haystack[i] == needle[0] && needle[needle.size()-1] == haystack[i+needle.size()-1]){
                // Create two pointers
                int j = needle.size()-1;
                int k = 0;
                
                // traverse two strings
                while(k<=j){
                    if(needle[k] != haystack[k+i] || needle[j] != haystack[j+i]){
                        // If there exists unequal item, set flag = 1 and break this loop
                        flag = 1;
                        break;
                    }
                    k++;
                    j--;
                }
                
                // If every char is the same, return the position
                if(flag == 0) return i;
                // reset flag
                flag = 0;
            }
        }
        return -1;
    }
};