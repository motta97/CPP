class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int length = s.length();
        int j = length-1;
        bool flag = true;
        for(int i=0;i<length/2;i++){
            if(s[i]!=s[j--]){
                flag = false;
                break;
            }
        }
       return flag;
    }
};
