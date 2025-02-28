class Solution {
public:
    bool isSameFeq(int f1[], int f2[]) { // O(1)
        for (int i = 0; i < 26; i++) {
            if (f1[i] != f2[i]) {
                return false;
            }
        }
        return true;
    }

    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) {
            return false;
        }

        int feq1[26] = {0}; // Frequency array for s1
        int feq2[26] = {0}; // Frequency array for current window in s2

        // Build the frequency array for s1
        for (int i = 0; i < s1.length(); i++) {
            feq1[s1[i] - 'a']++;
            feq2[s2[i] -
                 'a']++; // Also build the initial window's frequency array
        }

        // Sliding window starts from s2[0] to s2[s1.length()-1]
        for (int i = s1.length(); i < s2.length(); i++) {
            // If the frequency arrays match, return true
            if (isSameFeq(feq1, feq2)) {
                return true;
            }

            // Slide the window: add the new character at s2[i] and remove the
            // old character at s2[i - s1.length()]
            feq2[s2[i] - 'a']++; // Add the new character to the window
            feq2[s2[i - s1.length()] -
                 'a']--; // Remove the old character from the window
        }

        // Check the last window
        return isSameFeq(feq1, feq2);
    }
};