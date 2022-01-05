
#include "iostream"
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
        void printHelper(int current,bool* visited){
        cout << current << endl;
        visited[current] = true;
        for(int i = 0;i<vertices;i++){
            if(i == current) continue;
            if(source[current][i]) {
                if(visited[i]) continue;
                printHelper(i,visited);
            }
        }
    }

    void print(){
        bool *visited = new bool[vertices];
        for(int i = 0;i<vertices;i++) visited[i] = false;
        printHelper(0,visited);
    }


};
int main(){
    Graph *g = new Graph(5);
    g->add(0,2);
    g->add(2,1);
    g->add(3,1);
    g->add(0,3);
    g->print();
}
