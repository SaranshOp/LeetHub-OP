class Solution {
public:
    bool canChange(string start, string target) {
        int startLength = start.size();
        // Pointer for start string and target string
        int startIndex = 0, targetIndex = 0;

        while (startIndex < startLength || targetIndex < startLength) {
            // Skip underscores in start
            while (startIndex < startLength && start[startIndex] == '_') {
                startIndex++;
            }
            // Skip underscores in target
            while (targetIndex < startLength && target[targetIndex] == '_') {
                targetIndex++;
            }
            // If one string is exhausted, both should be exhausted
            if (startIndex == startLength || targetIndex == startLength) {
                return startIndex == startLength && targetIndex == startLength;
            }

            // Check if the pieces match and follow movement rules
            if (start[startIndex] != target[targetIndex] ||
                (start[startIndex] == 'L' && startIndex < targetIndex) ||
                (start[startIndex] == 'R' && startIndex > targetIndex))
                return false;

            startIndex++;
            targetIndex++;
        }

        // If all conditions are satisfied, return true
        return true;
    }
};
// class Solution {
// public:
//     bool canChange(string start, string target) {
//         // Queue to store characters and indices from both strings
//         queue<pair<char, int>> startQueue, targetQueue;

//         // Record non-underscore characters and their indices
//         for (int i = 0; i < start.size(); i++) {
//             if (start[i] != '_') {
//                 startQueue.push({start[i], i});
//             }
//             if (target[i] != '_') {
//                 targetQueue.push({target[i], i});
//             }
//         }

//         // If number of pieces don't match, return false
//         if (startQueue.size() != targetQueue.size()) return false;

//         // Compare each piece's type and position
//         while (!startQueue.empty()) {
//             auto [startChar, startIndex] = startQueue.front();
//             startQueue.pop();
//             auto [targetChar, targetIndex] = targetQueue.front();
//             targetQueue.pop();

//             // Check character match and movement rules
//             if (startChar != targetChar ||
//                 (startChar == 'L' && startIndex < targetIndex) ||
//                 (startChar == 'R' && startIndex > targetIndex))
//                 return false;
//         }

//         return true;
//     }
// };