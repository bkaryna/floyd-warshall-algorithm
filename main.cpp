#include "matrix.h"
#include <vector>
using namespace std;

void floydWarshall(Matrix &D, Matrix &P) {
    for (int k = 0; k < D.size; k++) {
        for (int i = 0; i < D.size; i++) {
            for (int j = 0; j < D.size; j++) {
                //prevent addition and subtraction operations on pseudo INF values  (inf +/- inf = inf)
                int sum;
                if (D.data[i][k] == INF || D.data[k][j] == INF) {
                    sum = INF;
                } else {
                    sum = D.data[i][k] + D.data[k][j];
                }
                //
                if (D.data[i][j] > sum)
                    P.data[i][j] = P.data[i][k];
                D.data[i][j] = min(D.data[i][j], sum);
            }
        }
    }
}

void printShortestPath(Matrix successorsMatrix, int from, int to) {
    if (from == to) {
        cout << "\nPath between " << from << " and " << to << ": {" << from << "}";
        return;
    }

    if (successorsMatrix.data[from][to] == NIL) {
        cout << "\nNo path between " << from << " and " << to;
        return;
    }

    cout << "\nPath between " << from << " and " << to << ": " << from;
    while (from != to) {
        from = successorsMatrix.data[from][to];
        cout << " -> {" << from << "}";
    }
}

int main() {
    Matrix W(5);//node pair matrix
    Matrix P(5);//successors matrix

    //initialize node pair matrix
    vector<int> values{0, 6, INF, INF, INF, INF, 0, -5, INF, 2, INF, INF, 0, 4, INF, 7, 1, INF, 0, INF, -4, INF, 8, 3, 0};
    for (int i = 0; i < W.size; i++) {
        for (int j = 0; j < W.size; j++) {
            W.data[i][j] = values.back();
            values.pop_back();
        }
    }

    //initialize successors pair matrix
    for (int i = 0; i < W.size; i++) {
        for (int j = 0; j < W.size; j++) {
            if (W.data[i][j] == INF)
                P.data[i][j] = NIL;
            else
                P.data[i][j] = j;
        }
    }

    floydWarshall(W, P);

    cout << endl
         << "Results\nNode pair matrix:\n";
    W.print();
    cout << "Successors matrix:\n";
    P.print();

    //print shortest path between two nodes + cost
    for (int i = 0; i < W.size; i++) {
        for (int j = 0; j < W.size; j++) {
            printShortestPath(P, i, j);
            cout << ";\t\tCost: " << W.data[i][j] << endl;
        }
    }

    return 0;
}
