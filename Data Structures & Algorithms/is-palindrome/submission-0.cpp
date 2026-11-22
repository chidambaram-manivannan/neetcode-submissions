class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char c) {
            return !isalnum(c);
        }), s.end());

        for(char &ch: s) {
            ch = tolower(ch);
        }

        int n = (int)s.size();
        for(int i = 0, j = n-1; i < j; ++i, --j) {
            if(s[i] != s[j]) return false;
        }

        return true;
    }
};