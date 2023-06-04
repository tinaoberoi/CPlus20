#include <iostream>
#include <memory>

using namespace std;

struct node
{
  node(int val): key_value(val), left(nullptr), right(nullptr) {}
//   node(const node& cnode): left(nullptr), right(nullptr), key_value(-1) 
//   {
//      auto temp = make_shared<node>(cnode.key_value);
//      temp->left = nullptr;
//      temp->right = nullptr;
//   }
  int key_value;
  shared_ptr<node> left;
  shared_ptr<node> right;
};

class btree
{
    shared_ptr<node> root;
    public:
        btree(): root(nullptr){};
        btree(const btree& tree_original)
        {
            //auto new_tree{make_shared<btree>()};
            auto temp = tree_original.root;
            auto new_root = make_shared<node>(0);
            new_root->key_value = temp->key_value;
            root = move(new_root);
            while (temp)
            {
                (*this).insert(temp->key_value); 
                if(temp->left){
                    (*this).insert(temp->left->key_value);
                }
                temp = temp->left;
            }
            temp = tree_original.root;
            while (temp)
            {
                (*this).insert(temp->key_value); 
                if(temp->right){
                    (*this).insert(temp->right->key_value);
                }
                temp = temp->right;
            }
        }

        void recu_func(){

        }

        void insert(int key){
            return insert(key, root);
        }
        shared_ptr<node>& search(int key){
            return search(key, root);
        }
        void destroy_tree(){
            return destroy_tree(root);
        }
 
    private:
        void destroy_tree(shared_ptr<node>& leaf){
            if(leaf){
                destroy_tree(leaf->left);
                destroy_tree(leaf->right);
                //leaf.release();
            }
            
        };
        void insert(int key, shared_ptr<node>& leaf){
            if(leaf){
                key < leaf->key_value ? insert(key, leaf->left) : insert(key, leaf->right);
            } else {
                leaf = make_shared<node>(key);
            }
        };
        shared_ptr<node>& search(int key, shared_ptr<node>& leaf){
            if (not root){
                return root;
            }
            if(key == leaf->key_value){
                return leaf;
            } else if (key < leaf->key_value){
                return search(key, leaf->left);
            } else {
                return search(key, leaf->right);
            }
        }
};

int main(){
    btree tree;
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    cout<< (tree.search(1))->key_value<<endl;

    btree tree2 = tree;
    cout<< (tree2.search(3))->key_value<<endl;

    return 0;
}