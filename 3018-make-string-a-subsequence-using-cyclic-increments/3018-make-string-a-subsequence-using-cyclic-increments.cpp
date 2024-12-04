class Solution {
public:
   bool canMakeSubsequence(string str1, string str2) {
    int n = str1.size();
    int m = str2.size();
    if (n < m) {
        return false;
    }

    int i = 0, j = 0;
    while (i < n && j < m) {
        char nextChar = (str1[i] - 'a' + 1) % 26 + 'a';
        if (str1[i] == str2[j] || nextChar == str2[j]) {
            i++;
            j++;
        } else {
            i++;
        }
    }
    
    if (j == str2.size()) {
        return true;
    }

    // i = 0;
    // while (i < n && j < m) {
    //     if (str1[i] == str2[j]) {
    //         i++;
    //         j++;
    //     } else {
    //         i++;
    //     }
    // }

    return false;
}


};