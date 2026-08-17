class Solution {
public:
    int minThrows(int n, vector<int>& lad, vector<int>& sn) {
        int N = n * n;

        // jump[x] = destination if x has a snake/ladder
        // -1 means no snake/ladder
        vector<int> jump(N + 1, -1);

        // Store ladders
        for (int i = 0; i < lad.size(); i += 2) {
            jump[lad[i]] = lad[i + 1];
        }

        // Store snakes
        for (int i = 0; i < sn.size(); i += 2) {
            jump[sn[i]] = sn[i + 1];
        }

        // BFS
        vector<int> dist(N + 1, -1);
        queue<int> q;

        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            if (curr == N)
                return dist[curr];

            // Try dice values 1 to 6
            for (int dice = 1; dice <= 6; dice++) {
                int next = curr + dice;

                if (next > N)
                    break;

                // Take snake/ladder immediately
                if (jump[next] != -1) {
                    next = jump[next];
                }

                // Visit only once
                if (dist[next] == -1) {
                    dist[next] = dist[curr] + 1;
                    q.push(next);
                }
            }
        }

        return -1;
    }
};
