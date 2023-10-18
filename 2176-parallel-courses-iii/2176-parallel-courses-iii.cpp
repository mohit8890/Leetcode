class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> graph(n + 1);
        for (const auto& relation : relations) {
            int prevCourse = relation[0];
            int nextCourse = relation[1];
            graph[prevCourse].push_back(nextCourse);
        }
        vector<int> memo(n + 1, -1);
        int minTime = 0;
        for (int i = 1; i <= n; i++) {
            minTime = max(minTime, divideAndConquerDfs(i, graph, time, memo));
        }
        return minTime;
    }

    int divideAndConquerDfs(int course, vector<vector<int>>& graph, vector<int>& time, vector<int>& memo) {
        if (memo[course] != -1) return memo[course];
        int maxTime = 0;
        for (int nextCourse : graph[course]) {
            maxTime = max(maxTime, divideAndConquerDfs(nextCourse, graph, time, memo));
        }
        memo[course] = maxTime + time[course - 1];
        return memo[course];
    }
};