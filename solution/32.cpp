#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//???댁쭊?몃━?먯꽌 ?ъ슜???몃뱶 ?뺤쓽 
struct Node {
  int id, x, y;
  Node* left = nullptr;
  Node* right = nullptr;

  Node(int id, int x, int y) : id(id), x(x), y(y) {}

};

//???댁쭊?몃━ ?뺤쓽
class BinaryTree {
private:
  Node* root = nullptr;
  //???몃뱶 醫뚰몴瑜?湲곗??쇰줈 ?뺣젹????湲곗????섎뒗 ?⑥닔
  static bool compareNodes(Node* a, Node* b) {
        if (a->y != b->y) return a->y > b->y;
     
    return a->x < b->x;
  }

 //?????몃뱶瑜?異붽??섎뒗 ?⑥닔
  Node* addNode(Node* current, Node* newNode) {
    if (current == nullptr) return newNode;
    //??異붽??섎젮怨??섎뒗 ?몃뱶?? 醫뚰몴瑜?湲곗??쇰줈 ?꾩옱?몃뱶???쇱そ ?뱀? ?ㅻⅨ履??먯떇 ?щ?瑜??먮떒?섍퀬 異붽?
    if (newNode->x < current->x) current->left = addNode(current->left, newNode);
    else current->right = addNode(current->right, newNode);
      
    return current;
  }

 // ?꾩쐞 ?쒗쉶瑜?吏꾪뻾?섎ŉ 寃쎈줈瑜???ν븯???⑥닔
  void preOrder(Node* node, vector<int>& traversal) {
    if (node == nullptr) return;
    traversal.push_back(node->id);
    preOrder(node->left, traversal);
    preOrder(node->right, traversal);
  }

  // ?꾩쐞 ?쒗쉶瑜?吏꾪뻾?섎ŉ 寃쎈줈瑜???ν븯???⑥닔
  void postOrder(Node* node, vector<int>& traversal) {
    if (node == nullptr) return;
    postOrder(node->left, traversal);
    postOrder(node->right, traversal);
    traversal.push_back(node->id);
  }

public:
  BinaryTree() : root(nullptr) {}

  //??nodeinfo瑜?湲곗??쇰줈 ?댁쭊?몃━瑜?援ъ텞?섎뒗 ?⑥닔
  void buildTree(const vector<vector<int>>& nodeInfo) {
    vector<Node*> nodes;
    //??媛??몃뱶??(?몃뜳??x醫뚰몴,y醫뚰몴) ?뺣낫瑜?nodes?????
    for (int i = 0; i < nodeInfo.size(); ++i) {
      nodes.push_back(new Node(i + 1, nodeInfo[i][0], nodeInfo[i][1]));
    }
  
    //???댁쭊?몃━瑜?援ъ텞?섍린 ?꾪빐 ?몃뱶瑜??뺣젹
    sort(nodes.begin(), nodes.end(), compareNodes);
   //???댁쭊?몃━ 援ъ텞
    for (Node* node : nodes) {
      root = addNode(root, node);
    }
  }

// ?꾩쐞?쒗쉶 ??寃쎈줈瑜?諛섑솚?섎뒗 ?⑥닔  
vector<int> getPreOrderTraversal() {
    vector<int> traversal;
    preOrder(root, traversal);
    
    return traversal;
  }

  // ?꾩쐞?쒗쉶 ??寃쎈줈瑜?諛섑솚?섎뒗 ?⑥닔
  vector<int> getPostOrderTraversal() {
    vector<int> traversal;
    postOrder(root, traversal);
      
    return traversal;
  }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
  BinaryTree tree;

  //???댁쭊?몃━瑜?援ъ텞?섍퀬 ?쒗쉶寃곌낵瑜?諛섑솚
  tree.buildTree(nodeinfo);
  vector<int> preOrder = tree.getPreOrderTraversal();
  vector<int> postOrder = tree.getPostOrderTraversal();
    
  return {preOrder, postOrder};
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iterator>
#include <iostream>
void print(vector<vector<int>> vec)
{
    for(auto& vec_elem : vec)
    {
      copy(vec_elem.begin(), vec_elem.end(), std::ostream_iterator<int>(cout, " "));
      cout << endl;
    }
}

int main()
{
  print(solution({{5, 3}, {11, 5}, {13, 3}, {3, 5}, {6, 1}, {1, 3}, {8, 6}, {7, 2}, {2, 2}}));
 
  /**
   異쒕젰媛?
   7 4 6 9 1 8 5 2 3 
   9 6 5 8 1 4 3 2 7 
  **/
  
    return 0;
}
