/* Structure of binary tree node
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
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        map<int,map<int,vector<int>>>nodes;
        queue<pair<Node*,pair<int,int>>>q;
        vector<vector<int>> ans;
        if(root == NULL) return ans;
        q.push(make_pair(root,make_pair(0,0)));
        while(!q.empty()){
            pair<Node*, pair<int,int>>temp = q.front();
            q.pop();
            Node* front_elem=temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            nodes[hd][lvl].push_back(front_elem->data);
            if(front_elem->left){
                q.push(make_pair(front_elem->left, make_pair(hd-1, lvl+1)));
            }
            if(front_elem->right){
                q.push(make_pair(front_elem->right, make_pair(hd+1, lvl+1)));

            }
        }
        for(auto i:nodes){
            vector<int> col;
            for(auto j:i.second){
                for(auto k: j.second) col.push_back(k);
            }
             ans.push_back(col);
        }
        return ans;
    }
};