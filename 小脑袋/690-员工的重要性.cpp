/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int ans = 0;
        int index = 0;
        for(int i = 0 ; i < employees.size(); ++i){
            if(employees[i]->id == id){
                ans += employees[i]->importance;
                index = i;
                break;
            }
        }
        for(int i = 0; i < employees[index]->subordinates.size(); i++){
            ans += getImportance(employees, employees[index]->subordinates[i]);
        }
        return ans;
    }
};
