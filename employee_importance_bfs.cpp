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
        int sum = 0;
        queue<Employee*> q;
        q.push(m[id]);
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto i:curr->subordinates){
                q.push(m[i]);
            }
            sum += curr->importance;
        }
        return sum;
    }
};