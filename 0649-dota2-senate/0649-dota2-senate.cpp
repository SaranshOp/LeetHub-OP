class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> rad, dir;
        int n = senate.length();
        // Add all senators to respect queue with index
        for (int i = 0; i < n; i++){
            if (senate[i] == 'R'){
                rad.push(i);
            }
            else {
                dir.push(i);
            }
        }
        // Use increasing n to keep track of position
        while (!rad.empty() && !dir.empty()){
            // Only "winner" stays in their queue
            if (rad.front() < dir.front()){
                rad.push(n++);
            }
            else {
                dir.push(n++);
            }
            rad.pop(), dir.pop();
        }
        return (rad.empty()) ? ("Dire") : ("Radiant");
    }
};

// #include <iostream>
// #include <queue>
// #include <string>

// std::string predictPartyVictory(std::string senate) {
//     std::queue<char> queue;
//     for (char c : senate) {
//         queue.push(c);
//     }

//     int bans = 0;

//     while (!queue.empty() && (std::count(queue.begin(), queue.end(), 'R') > 0) && (std::count(queue.begin(), queue.end(), 'D') > 0)) {
//         char current = queue.front();
//         queue.pop();

//         if (current == 'R') {
//             bans++;
//         } else {
//             bans--;
//         }

//         if ((current == 'D' && bans < 0) || (current == 'R' && bans > 0)) {
//             queue.push(current);
//         }
//     }

//     if (!queue.empty() && queue.front() == 'D') {
//         return "Dire";
//     }
//     return "Radiant";
// }

// int main() {
//     std::string input = "RDDRRD";
//     std::cout << "Predicted winning party: " << predictPartyVictory(input) << std::endl;
//     return 0;
// }
