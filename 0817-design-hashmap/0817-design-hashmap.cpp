class AVLTree{
    class Node{
        public:
        int data;
        int val;
        Node* left;
        Node* right;
        int ht;

        Node(int item,int value){
            this->data=item;
            this->val = value;
            this->left=NULL;
            this->right=NULL;
            this->ht=0;
        }

    };

    Node* root;

    public:

    AVLTree(){
        this->root=NULL;
    }

    void add(int item,int value){
        root = add(root,item,value);
    }

    void remove(int item){
        root = remove(root,item);
    }


    Node* add(Node* node,int item,int value){
        if(node==NULL){
            Node* nn = new Node(item,value);
            return nn;
        }

        if(item < node->data){
            node->left = add(node->left,item,value);
        }
        else if(item > node->data){
            node->right = add(node->right,item,value);
        }
        else{
            node->data = item;
            node->val = value;
        }

        node->ht = max(height(node->left),height(node->right))+1;

        int bf = balancingFactor(node);

        //LL case
        if(bf>1 && item < node->left->data){
            return rightrotation(node);
        }

        //LR case
        if(bf>1 && item > node->left->data){
            node->left = leftrotation(node->left);
            return rightrotation(node);
        }

        //RR case
        if(bf<-1 && item > node->right->data){
            return leftrotation(node);
        }

        //RL case
        if(bf<-1 && item < node->right->data){
            node->right = rightrotation(node->right);
            return leftrotation(node);
        }

        return node;
    }

    Node* rightrotation(Node* x){
        Node* y = x->left;
        Node* yr = y->right;

        x->left = yr;
        y->right = x;

        x->ht = max(height(x->left),height(x->right))+1;
        y->ht = max(height(y->left),height(y->right))+1;

        return y;
    }

    Node* leftrotation(Node* x){
        Node* y = x->right;
        Node* yl = y->left;

        x->right = yl;
        y->left = x;

        x->ht = max(height(x->left),height(x->right))+1;
        y->ht = max(height(y->left),height(y->right))+1;

        return y;
    }

    int height(Node* node){
        if(node==NULL) return -1;

        return node->ht;
    }

    int balancingFactor(Node* node){
        return (height(node->left) - height(node->right));
    }

    int maximum(Node* node){
        if(node==NULL) return INT_MIN;
        if(node->right==NULL) return node->data;
        return maximum(node->right);
    }

    Node* remove(Node* node,int item){
        if(item < node->data){
            node->left = remove(node->left,item);
        }
        else if(item > node->data){
            node->right = remove(node->right,item);
        }
        else{
            if(!node->left && !node->right){
                delete node;
                return NULL;
            }
            else if(node->left && !node->right){
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else if(!node->left && node->right){
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else{
                int m = maximum(node->left);
                node->left = remove(node->left,m);
                node->data = m;
                return node;
            }
        }

        node->ht = max(height(node->left),height(node->right))+1;
        int bf = balancingFactor(node);

        //LL case
        if(bf>1 && balancingFactor(node->left)>=0){
            return rightrotation(node->left);
        }

        //LR case
        if(bf>1 && balancingFactor(node->left)<0){
            node->left = leftrotation(node->left);
            return rightrotation(node);
        }

        //RR case
        if(bf<-1 && balancingFactor(node->right)<=0){
            return leftrotation(node);
        }

        //RL case
        if(bf<-1 && balancingFactor(node->right)>0){
            node->right = rightrotation(node->right);
            return leftrotation(node);
        }

        return node;
    }

    int find(Node* node,int item){
        if(node==NULL) return -1;
        if(item < node->data){
            return find(node->left,item);
        }
        else if(item > node->data){
            return find(node->right,item);
        }
        else
            return node->val;
    }

    int find(int item){
        return find(root,item);
    }

};
class MyHashMap {
public:
    vector<AVLTree*> arr;
    MyHashMap() {
        arr.resize(10007,NULL);
    }
    
    void put(int key, int value) {
        if(arr[key%10007]==NULL){
            arr[key%10007] = new AVLTree();
        }
        arr[key%10007]->add(key,value);
    }
    
    int get(int key) {
        if(!arr[key%10007]) return -1;
        return arr[key%10007]->find(key);
    }
    
    void remove(int key) {
        if(!arr[key%10007] || arr[key%10007]->find(key)==-1) return;
        arr[key%10007]->remove(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */