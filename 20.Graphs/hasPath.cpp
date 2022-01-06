/*
Given: Two points in a graph
TO Find: Return true if there exist a path between the two points in the graph;
*/

// Solution, we'll use DFS
#include "iostream"
#include "queue"
using namespace std;

class Graph{
private:
    bool hasPathHelper(int point1, int point2, bool *visited){
        if(source[point1][point2]) return true;
        visited[point1] = true;
        bool ans = false;
        for(int i = 0;i<vertices;i++){
            if(i == point1) continue;
            if(source[point1][i] && !visited[i]){
                ans = hasPathHelper(i,point2,visited);
            }
            if(ans) return ans;
        }
        return ans;
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
    bool hasPath(int point1, int point2){
        bool *visited = new bool[vertices];
        for(int i = 0;i<vertices;i++) visited[i] = false;
        return hasPathHelper(point1,point2,visited);
    }
};
int main(){
    Graph g(10);
    g.add(0,1);
    g.add(1,2);
    g.add(2,3);
    g.add(3,4);
    g.add(3,5);
    g.add(5,7);
    g.add(6,8);
    g.add(5,6);
    if(g.hasPath(0,9)){
        cout << "Exist";
    }else{
        cout << "Nop";
    }
}