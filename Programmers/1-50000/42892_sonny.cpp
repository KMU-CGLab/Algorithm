// 42892 : 길 찾기 게임 Lv3

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class Node
{
    public:
    int id, x, y;
    
    Node* parent;
    Node* left;
    Node* right;
    
    Node() {}
    
    Node(int inId, int inX, int inY) : id(inId), x(inX), y(inY) 
    {
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};

void MakeTree(Node* parent, Node* child)
{
    if(parent->x > child->x)
    {
        if(parent->left == NULL)
        {
            parent->left = child;
            return;
        }
        MakeTree(parent->left, child);
    }
    else
    {
        if(parent->right == NULL)
        {
            parent->right = child;
            return;
        }
        MakeTree(parent->right, child);
    }
}

bool SortCompare(const Node& a, const Node& b)
{
    if(a.y == b.y)
        return a.x < b.x;
    
    return a.y > b.y;
}

void MakePreorder(Node* parent, vector<int>& out)
{
    if(parent == NULL) return;
    out.push_back(parent->id);
    MakePreorder(parent->left, out);
    MakePreorder(parent->right, out);
}

void MakePostorder(Node* parent, vector<int>& out)
{
    if(parent == NULL) return;
    MakePostorder(parent->left, out);
    MakePostorder(parent->right, out);
    out.push_back(parent->id);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) 
{
    vector<vector<int>> answer;
    vector<Node> nodes;
    
    for(int idx = 0; idx < nodeinfo.size(); idx++)
    {
        int id = idx + 1;
        int x = nodeinfo[idx][0];
        int y = nodeinfo[idx][1];
        
        Node node = Node(id, x, y);
        nodeinfo[idx].push_back(id);
        nodes.push_back(node);
    }
    
    sort(nodes.begin(), nodes.end(), SortCompare);
    
    Node* root = &nodes[0];
    
    for(int i = 1; i < nodes.size(); i++)
    {
        MakeTree(root, &nodes[i]);
    }
    
    vector<int> preorder;
    MakePreorder(root, preorder);
    
    vector<int> postorder;
    MakePostorder(root, postorder);
    
    answer.push_back(preorder);
    answer.push_back(postorder);
    
    return answer;
}