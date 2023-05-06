class Solution {
public:


string predictPartyVictory(string senate) {
    int n = senate.size();
    queue<int> radiant, dire;

    // Initialize the queues with senators from each party
    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R')
            radiant.push(i);
        else
            dire.push(i);
    }

    while (!radiant.empty() && !dire.empty()) {
        int r = radiant.front();
        int d = dire.front();

        // Remove the senator with the lowest index from each queue
        radiant.pop();
        dire.pop();

        if (r < d) {
            // Radiant senator bans Dire senator
            radiant.push(r + n);
        } else {
            // Dire senator bans Radiant senator
            dire.push(d + n);
        }
    }

    return radiant.empty() ? "Dire" : "Radiant";
    }
};