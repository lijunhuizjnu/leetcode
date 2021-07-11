/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        set<Node*> s={};
        while(p!=NULL){
            s.insert(p);
            p=p->parent;
        }
        while(q!=NULL){
            if(s.find(q)!=s.end()){
                return q;
            }
            q=q->parent;     
        }
        return NULL; 
    }
};
