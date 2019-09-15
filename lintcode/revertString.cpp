class Solution {
public:
    /**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
    void rotateString(string &str, int offset) {
        if (str.size() <= 1) {
            return;
        }
        
        offset = offset % str.size();
        revert(str, 0, str.size() - offset - 1);
        revert(str, str.size() - offset, str.size()-1);
        revert(str, 0, str.size() - 1);
    }
private:
    void revert(string &str, int start, int end) {
        for (int i = start, j = end; i < j; i++, j--) {
            char temp = str[i];
            str[i] = str[j];
            str[j] = temp;
        }
    }
};