class Solution {
public:
    bool check(char ch){
        if(isalpha(ch) || isdigit(ch)) return true;
        return false;
    }
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.size()-1;
        while(left<right){
            if(s[left] == ' ' || check(s[left]) == false ){
                left++;
                continue;
            }
            if(s[right] == ' ' || check(s[right]) == false){
                right--;
                continue;
            }
            if(toupper(s[left]) != toupper(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};
