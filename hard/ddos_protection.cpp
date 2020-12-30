/*
    DDoS Protection
    Question 435 of 975

    https://binarysearch.com/problems/DDoS-Protection
*/

int solve(vector<vector<int>>& requests, int u, int g) {
    const int TIME_WINDOW = 60;

    unordered_map<int, int> inprocess;
    deque<vector<int>> window;

    int processed = 0;

    // Sort using brainfuck style lambda.
    // If there are requests at the same time by multiple users, requests with lower user_id are processed first.
    sort(requests.begin(), requests.end(), [](const vector<int> &l, const vector<int> &r) -> bool {
        return l[1] < r[1] ? true : (l[1] > r[1] ? false : l[0] < r[0]);
    });
    for (auto request : requests) {
        if (window.empty()) {
            if (g > 0) {
                processed++;
                inprocess[request[0]]++;
                window.push_back(request);
            } 
        } else {
            int window_start = request[1] - TIME_WINDOW;
            for (int timestamp = window.front()[1]; !window.empty() && timestamp <= window_start;) {
                inprocess[window.front()[0]]--;
                window.pop_front();
                if (!window.empty())
                    timestamp = window.front()[1];
            }
            if (window.size() >= 0 && window.size() < g) {
                int count = inprocess.find(request[0]) == inprocess.end() ? 0 : inprocess[request[0]];
                if (count >= 0 && count < u) {
                    processed++;
                    inprocess[request[0]]++;
                    window.push_back(request);
                } 
            }
        }
    }
    return processed;
}
