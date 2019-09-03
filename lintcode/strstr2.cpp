class Solution {
public:
    int BASE = 1000000;
    /**
     * @param source: 
     * @param target: 
     * @return: return the index
     */
    int strStr2(const char *source, const char *target) {
        // Write your code here
        if (source == NULL || target == NULL) {
            return -1;
        }

        int tLength = strlen(target);;
        int sLength = strlen(source);
        
        if (tLength == 0) {
            return 0;
        }
        
        if (sLength == 0) {
            return -1;
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
        for (int i = 0; i < sLength; i++) {
            
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
                char buf[tLength+1];
                memcpy(buf, &source[i-tLength+1], tLength); 
                buf[tLength] = '\0';
                if (strcmp(buf,target) == 0) {
                    return i-tLength+1;
                }
            }
        }
        return -1;
    }
};