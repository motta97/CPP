//assuming we have a total of 5 vertices with the given matrix
int n =5;
int m[5][5]={{0,1,1,0,1},{1,0,0,0,1},{1,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
queue q(n);
int visited[5]={};
void BFS(int i){
    int u;
    cout<<i<<endl;
    q.enqueue(i);
    while(!q.isEmpty()){
        u = q.dequeue();
        for(int v = 1;v<=n;v++){
            if(m[u][v]==1&&visited[v]==0){//adjacent and not visited
                q.enqueue(v);
                visited[v]=1;
                cout<<v<<endl;
            }
        }
    }
}
//O(n^2)
