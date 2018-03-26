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
        std::unordered_map<int,Employee*> m;
        for(auto x:employees){
            m[x->id] = x;
        }
        return DFS(m,id);
    }
    int DFS(std::unordered_map<int,Employee*> m, int id){
        int sum=m[id]->importance;
        for(auto i:m[id]->subordinates){
            sum += DFS(m,i);
        }
        return sum;
    }
};