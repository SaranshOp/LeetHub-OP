class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
       stack<int> stack;

    for (int asteroid : asteroids) {
        bool destroyed = false;
        while (!stack.empty() && asteroid < 0 && stack.top() > 0) {
            if (abs(asteroid) > abs(stack.top())) {
                stack.pop();
            } else if (abs(asteroid) == abs(stack.top())) {
                stack.pop();
                destroyed = true;
                break;
            } else {
                destroyed = true;
                break;
            }
        }

        if (!destroyed) {
            stack.push(asteroid);
        }
    }

    vector<int> result(stack.size());
    for (int i = stack.size() - 1; i >= 0; --i) {
        result[i] = stack.top();
        stack.pop();
    }

    return result;
 
    }
};