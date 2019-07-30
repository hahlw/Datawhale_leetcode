class Solution {
public:
    //拓扑排序（忘得有点干净啊）
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<int> courses(numCourses,0);  
        unordered_map<int,vector<int>> M;   
        queue<int> Q;
            
        for(auto i : prerequisites){
            courses[i[0]]++;
            M[i[1]].push_back(i[0]);
        }   
        //先搜寻入度为0的点
        for(int j = 0; j < courses.size() ; ++j){
            if( courses[j] == 0 )
                Q.push(j);
        } 
        //开始进行广度优先搜索
        while(!Q.empty()){
            int cur = Q.front();
            Q.pop();
            res.push_back(cur);   
            for(auto i : M[cur]){ 
                courses[i]--;
                if(courses[i] == 0)
                    Q.push(i);
            } 
        }  
        return res.size() == numCourses ? res : vector<int>{};
    }
};
