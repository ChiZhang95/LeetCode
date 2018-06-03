class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // mark whether a ndoe receives the signal
        vector<bool> received(N+1,false);
        // Breadth First Search
        queue<vector<int>> network;
        // record max time cost
        int maxcost=0;
        vector<int> cost(N+1,INT_MAX);
        // initialize node K
        received[K] = true;
        cost[K] = 0;
        for(auto node : times){
            if(node[0] == K){
                network.push(node);
            }
        }
        
        // BFS method
        while(!network.empty()){
            // for(int i=0; i<network.size(); i++){
                vector<int> curr = network.front();
                network.pop();
                int u = curr[0], v = curr[1], w = curr[2];
                
                // If this node didn't receive signal before
                if(!received[v]){
                    received[v] = true;
                    for(auto node : times){
                        if(node[0] == v){
                            network.push(node);
                        }
                    }
                }
                
                // If cost need to be updated
                if(cost[v] > cost[u]+w){
                    cost[v] = cost[u]+w;
                    for(auto node : times){
                        if(node[0] == v){
                            network.push(node);
                        }
                    }
                }
                
            
        }
        
        for(int i=1; i<N+1; i++){
            // If there exists node unreceived, return -1
            if(!received[i]){return -1;}
            maxcost = max(maxcost,cost[i]);
        }
        
        return maxcost;
    }
};