#include <iostream>
using namespace std;

class Leaf{
    public:
    string msg;
        Leaf(string msg){
            this->msg=msg;
    }
};
class Node{
    public:
    int value;
    Node *left;
    Node *right;
    Leaf *leftL;
    Leaf *rightL;
    Node(int val){
    value=val;
        left=NULL;
        right=NULL;
        leftL=NULL;
        rightL=NULL;
}
};

Leaf* traverseTree(Node* temp, int n) {
    while (temp != nullptr){
        if (n <= temp->value) {
            if (temp -> leftL == NULL){
                temp = temp->left;
            } else {
                return temp -> leftL;
            }
        } else if (n > temp->value) {
            if (temp -> rightL == NULL){
                temp = temp -> right;
            } else {
                return temp -> rightL;
            };
        }
    }
    return nullptr;
}

int main() {
    Node *root = new Node(80);
    Node *l = new Node(54);
    Node *r = new Node(140);
    Node *rl = new Node(104);
    Node *ll = new Node(49);
    Node *lr = new Node(60);
    
    
    Leaf *leaf1 = new Leaf("Victory");
    Leaf *leaf2 = new Leaf("Happy");
    Leaf *leaf3 = new Leaf("55");
    Leaf *leaf4 = new Leaf("Flower");
    Leaf *leaf5 = new Leaf("Power");
    Leaf *leaf6 = new Leaf("Vision");
    Leaf *leaf7 = new Leaf("Net");
    
    root -> left = l;
    root -> right = r;
    r -> rightL = leaf7;
    r -> left = rl;
    rl -> rightL = leaf6;
    rl -> leftL = leaf5;
    l -> left = ll;
    l -> right = lr;
    ll -> leftL = leaf1;
    ll -> rightL = leaf2;
    lr -> leftL = leaf3;
    lr -> rightL = leaf4;
    
    int n; cin>>n;
    Leaf* found = traverseTree(root, n);
    if (found == nullptr) {
        cout << "Error" << endl;
    } else {
        cout << found->msg << endl;
    };
    
    return 0;
}
