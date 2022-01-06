/*
BFS & DFS Algo for Disconnected graph
*/
#include "iostream"
#include "queue"
using namespace std;

class Graph{
private:
    void DFSHelper(int startingIndex, bool* visited){
        cout << startingIndex << " ";
        visited[startingIndex] = true;
        for(int i = 0;i<vertices;i++){
            if(i == startingIndex) continue;
            if(source[startingIndex][i] && !visited[i]){
                DFSHelper(i,visited);
            }
        }
    }
    void BFSHelper(int stattingIndex, bool* visited){
        queue<int> q;
        q.push(stattingIndex);
        visited[stattingIndex] = true;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            cout << front << " ";
            for(int i = 0;i<vertices;i++){
                if(i == front) continue;
                if(source[front][i] && !visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

public:
    bool **source;
    int vertices;
    Graph(int _vertices){
        vertices = _vertices;
        source = new bool*[vertices];
        for(int i = 0;i<vertices;i++){
            source[i] = new bool[vertices];
            for(int j = 0;j<vertices;j++){
                source[i][j] = false;
            }
        }
    }

    void add(int v1, int v2){
        source[v1][v2] = true;
        source[v2][v1] = true;
    }

    void DFS(){
        bool *visited = new bool[vertices];
        for(int i=0;i<vertices;i++) visited[i] = false;
        for(int i =0;i<vertices;i++){
            if(!visited[i]) DFSHelper(i,visited);
        } 
    }
    void BFS(){
        bool *visited = new bool[vertices];
        for(int i=0;i<vertices;i++) visited[i] = false;
        for(int i =0;i<vertices;i++){
            if(!visited[i]) BFSHelper(i,visited);
        } 
    }
};
int main(){
    Graph g(10);
    g.add(1,2);
    g.add(1,3);
    g.add(2,4);
    g.add(5,6);
    g.add(5,7);
    g.add(5,8);
    g.add(0,5);
    g.DFS();
    cout << endl;
    g.BFS();
}