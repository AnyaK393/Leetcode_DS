class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Adjacency list: bi -> ai
        // We must complete bi before taking ai
        vector<vector<int>> adj(numCourses);

        // Indegree = number of prerequisites for each course
        vector<int> indegree(numCourses, 0);

        for(int i = 0; i < prerequisites.size(); i++) {
            int a = prerequisites[i][0];
            int b = prerequisites[i][1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int> q;

        // Courses with no prerequisites can be taken first
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        int completed = 0;

        while(!q.empty()) {
            int u = q.front();
            q.pop();

            completed++;

            // Taking course u satisfies a prerequisite
            // for each course v connected to u
            for(int v : adj[u]) {
                indegree[v]--;

                // All prerequisites for v are completed
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        // If every course is completed, there is no cycle
        return completed == numCourses;
    }
};