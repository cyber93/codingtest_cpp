#include <vector>
using namespace std;

// ???몃뱶瑜??뺤쓽
class Node {
public:
  int val;
  Node *left, *right;

  Node(int key) : val(key), left(nullptr), right(nullptr) {}
};

//???댁쭊 ?먯깋 ?몃━ ?뺤쓽
class BST {
private:
  Node* root;

  
  Node* insertNode(Node* node, int key) {
    if (!node) {
      return new Node(key);
    }
    //????媛믨낵 ?꾩옱 ?몃뱶??媛믪쓣 鍮꾧탳?댁꽌 ?댁쭊?먯깋?몃━ 洹쒖튃??留욌뒗 ?꾩튂濡??대룞
    if (key < node->val) {
      node->left = insertNode(node->left, key);
    } else {
      node->right = insertNode(node->right, key);
    }
    return node;
  }

  bool searchNode(Node* node, int key) {
    //??李얜뒗 ??媛믪씠 ?녿뒗 寃쎌슦 
    if (!node) {
      return false;
    }
    //???댁쭊?먯깋?몃━?먯꽌 ??媛믪쓣 李얠? 寃쎌슦
    if (key == node->val) {
      return true;
    }
    //???꾩쭅 媛믪쓣 李얠? 紐삵븳 寃쎌슦, ?꾩옱 ?몃뱶媛믨낵 key 媛믪쓣 鍮꾧탳?댁꽌, ?대뒓 ?몃뱶?먯꽌 ?먯깋?좎? 寃곗젙
    return key < node->val ? 
           searchNode(node->left, key) : 
           searchNode(node->right, key);
  }

public:
  BST() : root(nullptr) {}

  void insert(int key) {
    root = insertNode(root, key);
  }

  bool search(int key) {
    return searchNode(root, key);
  }
};

vector<bool> solution(vector<int> lst, vector<int> search_lst) {
  BST bst;
  // ?댁쭊 ?먯깋 ?몃━???몃뱶 ?쎌엯
  for (int key : lst) {
    bst.insert(key);
  }

  vector<bool> result;
  // ?댁쭊 ?먯깋 ?몃━?먯꽌 李얜뒗 媛믪씠 ?덈뒗吏 ?뺤씤?섍퀬 ?먯깋寃곌낵瑜?result??異붽?
  for (int search_val : search_lst) {
    result.push_back(bst.search(search_val));
  }

  return result;
}

//?꾨옒 肄붾뱶???뚯뒪??肄붾뱶 ?낅땲??
#include <iterator>
#include <iostream>
void print(vector<bool> vec)
{
    copy(vec.begin(), vec.end(), std::ostream_iterator<bool>(cout, " "));
    cout << endl;
}

int main()
{
    // bool??異쒕젰????true??1 false??0 ?낅땲??
    print(solution({5, 3, 8, 4, 2, 1, 7, 10}, {1, 2, 5, 6})); //異쒕젰媛?: 1 1 1 0
    print(solution({1, 3, 5, 7, 9}, {2, 4, 6, 8, 10})); //異쒕젰媛?: 0 0 0 0 0    
    return 0;
}
