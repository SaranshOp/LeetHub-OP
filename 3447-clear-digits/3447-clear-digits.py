class Solution:
    def clearDigits(self, s: str) -> str:
        # Use a list to store characters for efficient modification
        answer = []

        # Iterate over each character in the input string
        for char in s:
            # If the current character is a digit
            if char.isdigit() and answer:
                # If the answer list is not empty, remove the last character
                answer.pop()
            else:
                # If the character is not a digit, add it to the answer list
                answer.append(char)

        # Join the list back into a string before returning
        return "".join(answer)







# class Solution:
#     def clearDigits(self, s: str) -> str:
#         n = len(s) // 2
#         while n:
#             ind = next((i for i, c in enumerate(s) if c.isdigit()), None)
#             if ind is not None:
#                 s = s[:ind-1] + s[ind+1:]
#             else:
#                 break
#             n -= 1
#         return s

# # // class Solution {
# # // public:
# # //     string clearDigits(string s) {
# # //         int n = s.size() / 2;
# # //         while (n--) {
# # //             auto it = find_if(s.begin(), s.end(), [](char c) { return isdigit(c); });
# # //             if (it!= s.end()) {
# # //                 s.erase(it);
# # //                 s.erase(it-1);
# # //             } else {
# # //                 break;
# # //             }
# # //         }
# # //         return s;
# # //     }
# # // };


# # ind = next((i for i, c in enumerate(s) if c.isdigit()), None) # in python .isdigit() method and also next() we could have also used del keyword like it alt from c++ .erase
# # auto it = find_if(s.begin(), s.end(), [](char c) { return isdigit(c); }) # in C++ isdigit( ) is a function
# #             if (it!= s.end()) {
# #                  s.erase(it);