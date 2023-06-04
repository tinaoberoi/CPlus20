#include <iostream>
#include <map>
#include <string>

using namespace std;

class TreeNode {
    public:
        string key;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;
        bool isLeaf;

    TreeNode(){
        key = "";
        left = NULL;
        right = NULL;
        parent = NULL;
        isLeaf = false;
    };
    TreeNode(string s, TreeNode* leftNode, TreeNode* rightNode, bool isAnimal){
        key = s;
        left = leftNode;
        right = rightNode;
        isLeaf = isAnimal;
    };

};

class Tree{
    public:
        TreeNode* root;
        Tree (){
            root = NULL;
        }
        void initializeTree(){
            TreeNode* left = new TreeNode("Is it a hawk?", NULL, NULL, true);
            TreeNode* right = new TreeNode("Is it a dog?", NULL, NULL, true);
            root = new TreeNode("Does it fly?", left, right, false);
            left->parent = root;
            right->parent = root;
        }
};

int main(){
    Tree t;
    t.initializeTree();
    bool flag = true;
    while(flag){
        cout<<"Welcome to animal game. Think of an animal"<<endl;
        TreeNode* temp = t.root;
        while(true){
            auto x = temp->key;
            cout<<temp->key<<endl;
            string ans;
            getline(cin, ans);
            if (ans == "yes" || ans == "y"){
                if(temp->isLeaf){
                    cout<<"I win!"<<endl;
                    break;
                } else {
                    temp = temp->left;
                }
            } else if (ans == "no" || ans == "n") {
                if (temp->isLeaf){
                    cout<<"You win! What was it? ";
                    string newanimal, newques;
                    getline(cin,newanimal);
                    cout<<"What question distinguishes a " + newanimal + " ? ";
                    getline(cin, newques);
                    TreeNode* tparent = temp->parent;
                    if(tparent->left == temp){
                        TreeNode* ttleft = new TreeNode("Is it a " + newanimal, NULL, NULL, true);
                        TreeNode* tleft = new TreeNode(newques, ttleft, temp, false);
                        tparent->left = tleft;
                        temp->parent = tleft;
                        temp = t.root;
                    } else {
                        TreeNode* ttleft = new TreeNode("Is it a " + newanimal, NULL, NULL, true);
                        TreeNode* tright = new TreeNode(newques, ttleft, temp, false);
                        tparent->right= tright;
                        temp->parent = tright;
                        temp = t.root;
                    }
                    cout<<"You want to play again? Enter q to quit the game or enter to continue. If you want to start over type 'forget' to start fresh ";
                    string playagain;
                    getline(cin, playagain);
                    if(playagain == "q"){
                        flag = false;
                    } else if (playagain == "forget"){
                        t.initializeTree();
                        temp = t.root;
                    }
                    break;
                } else {
                    temp = temp->right;
                }
            } else {
                cout<<"You did not provide a right answer. Lets start again."<<endl;
                break;
            }
        }
    }
    return 0;
}