class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if(prerequisites.size() == 0){return true;}
        
        graph = vector<vector<int>> (numCourses);
        for(auto i:prerequisites){
            graph[i.first].push_back(i.second);
        }
        
        // states: 0 = unknown, 1 = visiting, 2 = visisted
        vector<int> v(numCourses,0);
        
        for(int i=0; i<numCourses; i++){
            if(dfsCycle(i,v)) {return false;}
        }
        return true;
    }
    
private:
    vector<vector<int>> graph;
    bool dfsCycle(int cur, vector<int>& v){
        if(v[cur] == 1) return true;
        if(v[cur] == 2) return false;
        
        v[cur] = 1;
        
        for(int t:graph[cur]){
            if(dfsCycle(t,v)){return true;}
        }
        
        v[cur] = 2;
        
        return false;
    }
};