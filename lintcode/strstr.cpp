class Solution {
public:
    int BASE = 1000000;
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr(string &source, string &target) {
        // Write your code here
        int tLength = target.size();
        if (tLength == 0) {
            return 0;
        }
        
        // 31 ^ m;
        int power = 1;
        for (int i = 0; i < tLength; i++) {
            power = (power * 31) % BASE; 
        }
        
        // compute target hashcode
        int targetCode = 0;
        for (int i = 0; i < tLength; i++) {
            targetCode = (targetCode * 31 + target[i]) % BASE;
        }
        
        int hashcode = 0;
        for (int i = 0; i < source.size(); i++) {
            
            // abc + d
            hashcode = (hashcode * 31 + source[i]) % BASE;
            if (i < tLength - 1) {
                continue;
            }
            
            
            if (i >= tLength) {
                // abcd - a
                hashcode = (hashcode - source[i - tLength] * power) % BASE;
                if (hashcode < 0) {
                    hashcode += BASE;
                }
            }
            
            if (hashcode == targetCode) {
                if (source.substr(i-tLength+1, tLength) == target) {
                    return i-tLength+1;
                }
            }
        }
        return -1;
    }
};