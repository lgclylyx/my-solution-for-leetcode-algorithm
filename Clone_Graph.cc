/*
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:

Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.

As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

    First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
    Second node is labeled as 1. Connect node 1 to node 2.
    Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.

Visually, the graph looks like the following:

       1
      / \
     /   \
    0 --- 2
         / \
         \_/

*/

/*

	DFS;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        unordered_set<UndirectedGraphNode *> us;
        unordered_map<int,UndirectedGraphNode *> um;
        UndirectedGraphNode* p = NULL;
        solver(node,p,us,um);
        return p;
    }
    void solver(UndirectedGraphNode *node, UndirectedGraphNode*& p, unordered_set<UndirectedGraphNode *>& us,unordered_map<int,UndirectedGraphNode *>& um){
        if(!node){
            return;
        }
        if(us.find(node) == us.end()){
            p = new UndirectedGraphNode(node->label);
            us.insert(node);
            um[p->label] = p;
        }else{
            auto t = um.find(node->label);
            p = t->second;
            return;
        }
        for(auto itr = node->neighbors.begin(); itr != node->neighbors.end();itr++){
            p->neighbors.push_back(NULL);
            solver(*itr,p->neighbors.back(),us,um);
        }
    }
*/

/*

	more effective; BFS;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> graph;
        
        if(node==nullptr)
            return nullptr;
        
        queue<UndirectedGraphNode *> q;
        q.push(node);
        graph[node] = new UndirectedGraphNode(node->label);
        
        while(!q.empty()){
            
            UndirectedGraphNode *vertex = q.front();
            q.pop();
            
            for(int i=0;i<vertex->neighbors.size();i++){
                
                UndirectedGraphNode *neighbor = vertex->neighbors[i];
                
                if(graph.find(neighbor)==graph.end()){
                    graph[neighbor] = new UndirectedGraphNode(neighbor->label);
                    q.push(neighbor);
                }
                
                graph[vertex]->neighbors.push_back(graph[neighbor]);
            }
        }
        
        return graph[node];
    }
*/