/* Structure of Binary Tree Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL) return ans;
        map<int,int>leftView;
        queue<pair<Node*, int>>q;
        q.push(make_pair(root, 0));
        while(!q.empty()){
            pair<Node*, int>temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int lvl = temp.second;
            if(leftView.find(lvl) == leftView.end()){
                leftView[lvl] = frontNode->data;
            }
            if(frontNode->left) q.push(make_pair(frontNode->left, lvl+1));
            if(frontNode->right) q.push(make_pair(frontNode->right, lvl+1));
            
        }
        for(auto i:leftView){
            ans.push_back(i.second);
        }
        return ans;
    }
};