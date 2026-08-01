class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        else
            return false;
    }
    int countVowelSubstrings(string word) {
        int n = word.length();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> feq(26, 0);

            for (int j = i; j < n; j++) {
                if (!isVowel(word[j]))
                    break;

                feq[word[j] - 'a']++;

                if (feq['a' - 'a'] && feq['e' - 'a'] && feq['i' - 'a'] &&
                    feq['o' - 'a'] && feq['u' - 'a'])
                    ans++;
            }
        }

        return ans;
    }
};