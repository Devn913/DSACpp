#include "iostream"
#include "queue"
using namespace std;

class Graph{
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

    void BFS(){
        queue<int> q;
        bool visited[vertices];
        for(int i =0;i<vertices;i++){
            visited[i] = false;
        }
        q.push(0);
        visited[0] = true;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            cout << front << endl;
            for(int i = 0;i<vertices;i++){
                if(i == front) continue;
                if(source[front][i] && !visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

};
int main(){
    Graph g(10);
    g.add(0,1);
    g.add(0,2);
    g.add(0,3);
    g.add(1,2);
    g.add(1,4);
    g.add(3,4);
    g.add(3,2);
    g.add(1,7);
    g.add(1,9);
    g.BFS();
}