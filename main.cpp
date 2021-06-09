#include "matrix.h"
#include <vector>
using namespace std;


void floydWarshall(Matrix &D, Matrix &P) {
    for (int k = 0; k < D.size; k++) {
        for (int i = 0; i < D.size; i++) {
            for (int j = 0; j < D.size; j++) {
                int sum;
                if (D.data[i][k] == INF || D.data[k][j] == INF) {
                    sum = INF;
                } else {
                    sum = D.data[i][k] + D.data[k][j];
                }

                if (D.data[i][j] > sum)
                    P.data[i][j] = P.data[i][k];
                D.data[i][j] = min(D.data[i][j], sum);
            }
        }
        //D.print_D();
        P.print_P();
    }
}

void printShortestPath(Matrix Graph, int start, int end) {
    if (start == end){
        cout<<"\nPath between "<<start<<" and "<<end<<" -> "<<start;
        return;
    }

    if(Graph.data[start][end] == NIL){
        cout<<"\nNo path"<<endl;
        return;
    }
    cout<<"\nPath between "<<start<<" and "<<end<<" -> "<<start;
    while(start!=end) {
        start = Graph.data[start][end];
        cout<<" -> "<<start;
    }
}
int main() {

    Matrix W(5);
    Matrix P(5);

    vector<int> values{0, 6, INF, INF, INF, INF, 0, -5, INF, 2, INF, INF, 0, 4, INF, 7, 1, INF, 0, INF, -4, INF, 8, 3, 0};
    //vector<int> successors{NIL, 5, NIL, NIL, NIL, NIL, NIL, 4, NIL, 4, NIL, NIL, NIL, 3, NIL, 2, 2, NIL, NIL, NIL, 1, NIL, 1, 1, NIL};
    for (int i = 0; i < W.size; i++) {
        for (int j = 0; j < W.size; j++) {
            W.data[i][j] = values.back();
            //W.data[i][j].succ = successors.back();
            values.pop_back();
            //successors.pop_back();
        }
    }

    for (int i = 0; i < W.size; i++)
        for (int j = 0; j < W.size; j++)
            P.data[i][j] = j;


    //P.print_P();

    floydWarshall(W, P);

    cout<<endl<<"Po algorytmie:\n";
//    W.print_D();
    P.print_P();

    for (int i = 0; i < W.size; i++) {
        for (int j = 0; j < W.size; j++) {
            printShortestPath(P, i, j);
            cout<<"\tCost: "<<W.data[i][j]<<endl;
        }
    }
    return 0;
}
