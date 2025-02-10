#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
bool vis[N];
vector<int> adj[N];
stack<int> st;
vector<int> adjT[N];
void dfs(int node)
{
    vis[node] = true;
    for (int v : adj[node])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }

    st.push(node);
}
void dfs3(int node)
{
    vis[node] = true;
    cout<<node<<" ";
    for (int v : adjT[node])
    {
        if (!vis[v])
        {
            dfs3(v);
        }
    }
}
int kosaraju(int node)
{
    for (int i = 0; i < node+1; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }

    for (int i = 1; i < node+1; i++)
    {
        vis[i] = 0;
        for (int v : adj[i])
        {
            adjT[v].push_back(i);
        }
    }

    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {
            scc++;
            cout<<scc<<" SCC is: ";
            dfs3(node);
            cout<<endl;
        }
    }
    return scc;
}
int main()
{

//    int n = 5;
//    int edges[5][2] =
//    {
//        {1, 0}, {0, 2},
//        {2, 1}, {0, 3},
//        {3, 4}
//    };
//    vector<int> adj[n];
//    for (int i = 0; i < n; i++)
//    {
//        adj[edges[i][0]].push_back(edges[i][1]);
//    }
    int node,edge;
    cin>>node>>edge;
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int ans = kosaraju(node);
    cout << "The number of strongly connected components is: " << ans << endl;
    return 0;
}
