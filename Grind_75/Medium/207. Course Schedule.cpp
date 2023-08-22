class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_set<int> visited;
        unordered_map<int, vector<int>> adj_list; 
        for (auto cur: prerequisites) {
            adj_list[cur[0]].push_back(cur[1]);
        }

        for (int i = 0; i < numCourses; i++) {
            if (!bfs(adj_list, i, visited)) return false;
        }

        return true;
        
    }

    bool bfs(unordered_map<int, vector<int>>& adj_list, int course, unordered_set<int>& visited) {
        if (adj_list[course].empty()) {
            return true; // no pre-reqs
        }
        if (visited.contains(course)) return false;
        int size = adj_list[course].size();
        vector<int> neigh = adj_list[course];

        visited.insert(course);

        for (int i = 0; i < size; i++) {
            if (!bfs(adj_list, neigh[i], visited)) return false;
        }

        visited.erase(course);

        adj_list[course].clear();

        return true;
    }
};