class Solution {
public:
    bool two = true;
    vector<int> color;
    void dfs(vector<vector<int> > graph, int s) {
        for(auto u:graph[s]) {
            if(color[u] == 0)
            {
                color[u] = 3 - color[s];
                dfs(graph, u);
            } else if(color[u] == color[s])
                two = false;
        }
    }    
    bool isBipartite(vector<vector<int>>& graph) {
        // graph bipartite if graph Acyclic and have odd verteces
        color.resize(graph.size(),0);
        for(int i = 0; i < graph.size(); ++ i)
            if(color[i] == 0)
            {
                color[i] = 1;
                dfs(graph, i);
            }
            return two;
    }
};

/*
To check, we color the graph in two colors {1,2}. 0 - color of unvisited vertex.
If we meet an edge with endpoints of the same color, then the graph is not bipartite.
*/
