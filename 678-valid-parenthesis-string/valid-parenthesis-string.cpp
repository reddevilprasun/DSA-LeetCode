class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;  // Minimum possible open parentheses
        int high = 0; // Maximum possible open parentheses

        for (char c : s) {
            if (c == '(') {
                low++;  // We need one more open parenthesis
                high++; // We could have one more open parenthesis
            } else if (c == ')') {
                low = max(0,
                          low - 1); // We close one open parenthesis if possible
                high--;             // We close one open parenthesis
            } else {
                low =
                    max(0, low - 1); // Treat '*' as ')' so we reduce open count
                high++; // Treat '*' as '(' so we increase open count
            }

            if (high < 0) {
                return false; // If high becomes negative, too many ')' so
                              // invalid
            }
        }

        return low == 0; // All open parentheses must be closed
    }
};