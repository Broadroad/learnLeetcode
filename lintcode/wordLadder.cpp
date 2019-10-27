class Solution {
public:
    /*
     * @param start: a string
     * @param end: a string
     * @param dict: a set of string
     * @return: An integer
     */
    int ladderLength(string &start, string &end, unordered_set<string> &dict) {
        // write your code here
        int count = 1;
        unordered_set<string> m;
        
        dict.insert(start);
        dict.insert(end);
        
        std::queue<string> Q;
        Q.push(start);
        
        while (!Q.empty()) {

            count++;
            int len = Q.size();
            
            std::cout << count << std::endl;
            for (int i = 0; i < len; i++) {
                string s = Q.front();
                Q.pop();
                for (string word : getNextWords(s, dict)) {
                    if (m.count(word)) {
                        continue;
                    }
                    
                    if (word == end) {
                        return count;
                    }
                    
                    m.insert(word);
                    Q.push(word);
                }
            }
        }
        return 0;
    }
    
private: 
    vector<string> getNextWords(string word, unordered_set<string> &dict) {
        vector<string> words;
        
        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i < word.size(); i++) {
                char ch = word[i];
                if (word[i] != c) {
                    word[i] = c;
                    if (dict.count(word)) {
                        words.push_back(word);
                    }
                    word[i] = ch;
                }
            }
        }
        return words;
    }
};