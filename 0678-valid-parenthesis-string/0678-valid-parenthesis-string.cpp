class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;  // The minimum count of open parentheses
        int high = 0; // The maximum count of open parentheses

        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low--;
                high--;
            } else { // c == '*'
                low--;   // Treat '*' as ')'
                high++;  // Treat '*' as '('
            }
            
            // A negative low indicates there are more ')' than '('
            if (low < 0) {
                low = 0; // We can treat some '*' as '(' to balance
            }
            
            // If high goes negative, we have a problem
            if (high < 0) {
                return false; // Too many ')'
            }
        }

        // At the end, we need to ensure we have balance
        return low == 0; // If low reaches 0, we can balance out the parentheses
    }
};
