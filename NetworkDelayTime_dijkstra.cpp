class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // shortest path tree set
        vector<bool> spt(N+1,false);
        // current shortest distance of each vertexs
        vector<int> dist(N+1,INT_MAX);
        // maximum network delaytime
        int maxdelay=0;
        // initialize node K
        dist[K] = 0;
        
        // find the shortest time path to every node in th enetwork
        for(int count=1; count < N; count++){
            // current closest node in the unvisited set
            int u = mindistance(spt,dist,N);
            spt[u] = true;
            
            // update the time cost of u's children node
            for(auto node : times){
                int v = node[1], w = node[2];
                if(node[0] == u && dist[u]+w<dist[v]){
                    dist[v] = dist[u]+w;
                }
            }
        }
        
        // find the maximum time delay
        for(int i=1; i<=N; i++){         
            maxdelay = max(maxdelay,dist[i]);
        }
        
        // If there exists node unvisited, return -1
        if(maxdelay == INT_MAX){return -1;}
        
        return maxdelay;
    }
    
    // Utility function to find the closest node in the unvisited set, return its index
    int mindistance(vector<bool> spt, vector<int> dist,int N){
        int min = INT_MAX,min_index;
        
        for(int v=1; v<=N; v++){
            if(!spt[v] && dist[v]<=min){
                min = dist[v];
                min_index = v;
            }
        }
        
        return min_index;
    }
};