#include <iostream>
#include <queue>
using namespace std;

typedef struct Node{
    char parent, left, right, me;
}node;

queue<char> preOrderAnswer;
queue<char> midOrderAnswer;
queue<char> postOrderAnswer;
node nodes[26];

void preOrder(node root){
    preOrderAnswer.push(root.me);
    if(root.left != '.'){
        preOrder(nodes[root.left-'A']);
    }
    if(root.right!='.'){
        preOrder(nodes[root.right-'A']);
    }
    return ;
}

void midOrder(node root){
    if(root.left != '.'){
        midOrder(nodes[root.left-'A']);
    }
    midOrderAnswer.push(root.me);
    if(root.right!='.'){
        midOrder(nodes[root.right-'A']);
    }
    return ;
}

void postOrder(node root){
    if(root.left != '.'){
        postOrder(nodes[root.left-'A']);
    }
    if(root.right!='.'){
        postOrder(nodes[root.right-'A']);
    }
    postOrderAnswer.push(root.me);
    return ;
}


int main(){
    int visited[26]={0,};
    int N;
    char tmp;
    cin >> N;
    for(int i=0; i<N; i++){
        char tmp;
        cin >> tmp;
        int index = tmp-'A';
        nodes[index].me = tmp;
        cin >> nodes[index].left >> nodes[index].right;
    }
    preOrder(nodes[0]);
    midOrder(nodes[0]);
    postOrder(nodes[0]);
    while(!preOrderAnswer.empty()){
        cout<<preOrderAnswer.front();
        preOrderAnswer.pop();
    }
    cout<<endl;
    while(!midOrderAnswer.empty()){
        cout<<midOrderAnswer.front();
        midOrderAnswer.pop();
    }
    cout<<endl;
    while(!postOrderAnswer.empty()){
        cout<<postOrderAnswer.front();
        postOrderAnswer.pop();
    }
}
