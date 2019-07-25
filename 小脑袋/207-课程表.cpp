class Solution {
    /*
    构建邻接表和入度数组->入度为 0入队->广度遍历

原理：

step.1 找所有 indegree （入度）为 0 的顶点，然后删掉它们。如果找不到跳转到 step.2，否则继续 step.1
step.2 结束
    */
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, set<int>> adjcent;
        vector<int> indegree(numCourses);
        for (auto& edge : prerequisites) {
            int a = edge[0];
            int b = edge[1];
            adjcent[a].insert(b);
            ++indegree[b];
        }
        int count = 0;
        queue<int> todo;
        for (int i = 0; i < numCourses; ++i) {
            if (!indegree[i]) todo.push(i);
        }
        while (!todo.empty()) {
            auto v = todo.front();
            todo.pop();   
            ++count;
            auto& adjs = adjcent[v];
            for (auto adj : adjs) {
                --indegree[adj];
                if (!indegree[adj]) todo.push(adj);
            }
        }
        return count == numCourses;
    }
};
