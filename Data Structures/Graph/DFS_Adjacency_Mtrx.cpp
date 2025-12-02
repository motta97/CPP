void DFS(int i){
    if(visited[i]==0){
        visited[i]=1;
        for(int v =1;v<=n;v++){
            if(m[i][v]==1&&visited[v]==0){
                DFS(v);
            }
        
        }
    }
}
