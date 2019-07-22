class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        set <int> visited; 
        visited.insert(0); 
        stack <int> keys; 
        keys.push(0);
        while(!keys.empty())
        {
            int key = keys.top(); 
            cout << key;
            keys.pop();
            int rs = rooms[key].size();
            for(int i = 0; i < rs; ++i)
            {
                if(!visited.count(rooms[key][i])) 
                {
                    visited.insert(rooms[key][i]);
                    keys.push(rooms[key][i]); 
                }
            }
        }
        return visited.size() == rooms.size(); 
    }
};
