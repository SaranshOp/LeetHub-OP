class Solution {
public:
    string compressedString(string word) {
        string comp = "";

        // pos tracks our position in the input string
        int pos = 0;

        // Process until we reach end of string
        while (pos < word.length()) {
            int consecutiveCount = 0;

            char currentChar = word[pos];

            // Count consecutive occurrences (maximum 9)
            while (pos < word.length() && consecutiveCount < 9 &&
                   word[pos] == currentChar) {
                consecutiveCount++;
                pos++;
            }

            // Append count followed by character to result
            comp += to_string(consecutiveCount) + currentChar;
        }

        return comp;
    }
};


// class Solution:
//     def compressedString(self, word: str) -> str:
//         comp = []

//         # pos tracks our position in the input string
//         pos = 0

//         # Process until we reach end of string
//         while pos < len(word):
//             consecutive_count = 0

//             current_char = word[pos]

//             # Count consecutive occurrences (maximum 9)
//             while (
//                 pos < len(word)
//                 and consecutive_count < 9
//                 and word[pos] == current_char
//             ):
//                 consecutive_count += 1
//                 pos += 1

//             # Append count followed by character to the list
//             comp.append(str(consecutive_count))
//             comp.append(current_char)

//         # Join the list into a single string for the final result
//         return "".join(comp)