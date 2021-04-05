//0404 

#include <iostream>
using namespace std;

int P[250000];
long long answer = 0;

typedef struct vertex{
    int value;
    vertex* left=nullptr;
    vertex* right=nullptr;
    int depth;
}Vertex;

void insert(Vertex& V, int X) {
    if (X < V.value) {
        if (V.left != nullptr) {
            insert(*V.left, X);
        } else {
            V.left = new Vertex;
            V.left->value = X;
            V.left->depth = V.depth+1;
            answer+=V.depth+1;
        }
    } else {
        if (V.right!=nullptr) {
            insert(*V.right, X);
        } else {
            V.right = new Vertex;
            V.right->value = X;
            V.right->depth = V.depth+1;
            answer+=V.depth+1;
        }
    }
}

int main(){
    
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> P[i];
    }
    Vertex root;
    root.value = P[0];
    root.depth=1;

    for (int i=1; i<=n-1; i++) {
        insert(root, P[i]);
    }   

    cout<<answer+1;
}

