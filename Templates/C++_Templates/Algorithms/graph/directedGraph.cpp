#include <bits/stdc++.h>
using namespace std;


class DirectedGraphMatrix{
private:
    int** adjMatrix;
    int nVertex;
public:
    DirectedGraphMatrix(int vertex){
        this->nVertex = vertex;
        adjMatrix = new int*[nVertex];
        for(int i = 0; i < nVertex; i++){
            adjMatrix[i] = new int[nVertex];
            for(int j = 0; j < nVertex; j++)
                adjMatrix[i][j] = 0;
        }
    }

    void addEdge(int i, int j){
        adjMatrix[i][j]++, adjMatrix[j][i]++;
    }

    void removeEdge(int i, int j){
        adjMatrix[i][j]--, adjMatrix[j][i]--;
    }

    void printGraph(){
        for(int i = 0; i < nVertex; i++){
            cout << i << "-> ";
            for(int j = 0; j < nVertex; j++)
                cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
    }

};

class DirectedGraphList{
private:
    int vertex;
    vector<int>* list;
public:
    DirectedGraphList(int v, vector<int> adj[]){
        vertex = v;
        list = adj;
    }

    void addEdge(int i, int j){
        list[i].push_back(i);
        list[j].push_back(j);
    }

    void BFS(int s, bool visited[]){
        queue<int> q;
        visited[s] = true;
        q.push(s);
        while (!q.empty()){
            int u = q.front();
            q.pop();
            for(int v: list[u]) if (!visited[v]) visited[v] = true, q.push(v);
        }
    }

    int disconnectedBFS(){
        int connected = 0;
        bool visited[vertex];
        for(int i = 0; i < vertex; i++) visited[i] = false;
        for(int i = 0; i < vertex; i++) if (!visited[i]) BFS(i, visited), connected++;
        return connected;
    }

    void DFSProcess(int s, bool visited[]){
        visited[s] = true;
        cout << s << " ";
        for(auto u: list[s])
            if (!visited[u]) DFSProcess(u, visited);
    }

    int DFS(){
        bool visited[vertex];
        int connected = 0;
        for(int i = 0; i < vertex; i++) visited[i] = false;
        for(int i = 0; i < vertex; i++)if (!visited[i]) DFSProcess(i, visited), connected++;
        return connected;
    }

};
