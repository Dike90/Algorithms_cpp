#ifndef __BST_H__
#define __BST_H__
template <class K,class V>
class BST{
struct Node{   
    K key;
    V val;
    Node *left,*right;
    int N;
    Node():left(NULL),right(NULL){};
    Node(K key,V val,int N):left(NULL),right(NULL),key(key),val(val),N(N){};
};   
    Node *root;
public:
    BST():root(NULL){};
    void insert(K key, V val){
        root = insert(root,key,val);
    }
    V get(K key){   return get(root,key);};
    int size(){ return size(root);};
    K min() { return min(root)->key;};
    K floor(K key){
        Node * x = floor(root,key);
        if (x == NULL) return NULL;
        return x->key;
    }
    K select(int k){
        return select(root,k)->key;
    }
    void delMin(){
        root = delMin(root);
    }
    void printTree(){
        printTree(root,0);
    }
    void delKey(K key){
        root = delKey(root,key);
    }
private:
    Node *insert(Node *x,K key,V val){
        if(x==NULL) return new Node(key,val,1);
        if( key < x->key) 
            x->left = insert(x->left,key,val);
        else if (key > x->key) 
            x->right = insert(x->right,key,val);
        else
            x->val = val;
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }
    V get(Node *x, K key){
        if (x == NULL) return NULL;
        if (key < x->key) return get(x->left,key);
        else if (key > x->key) return get(x->right,key);
        else return x->val;
    }
    int size(Node *x){
        if (x == NULL) return 0;
        else return x->N;
    }
    Node * min(Node * x){
        if (x->left == NULL) return x;
        return min(x->left);
    }
    //向下取整
    //如果给定的key小于二叉查找树的根节点的键，那么小于等于key的最大键一定存在于根节点的左子树中;
    //如果给定的key大于二叉查找树的根节点的键，那么只有当根节点右子树中存在小于等于key的节点，floor才
    //存在于根节点的右子树中，否则根节点的键就是小于key的最大键。
    Node * floor(Node *x ,K key ){
        if (x==NULL) return NULL;   //找不到就返回NULL
        if ( key == x->key) return x;
        //如果key小于节点x的key，就在x节点的左子树中寻找
        else if ( key < x->key) return floor(x->left, key);
        //执行到这里，说明当前节点x的key是小于key的，那么就在x的右子树中寻找
        Node *t = floor(x->right,key);
        if (t != NULL) return t;
        else return x;
    }
    //寻找排名为k的键？？？有k个键小于它？？？
    Node * select(Node *x, int k){
        if (x==NULL) return NULL;
        int t = size(x->left);
        if (t > k) return select(x->left,k);
        else if (t < k) return select(x->right,k-t-1);
        else return x;
    }
    //删除键值最小的节点。
    //从根节点开始一直递归的访问节点的左子节点，若节点的左子节点为NULL，说明该节点就是键值最小的节点
    //删除该节点，返回该节点的右子节点。
    Node *delMin(Node * x){
        if (x->left == NULL){
            Node *temp = x->right;
            delete x;
            return temp;
        }
        x->left = delMin(x->left);
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }
    void printTree(Node *x, int indent){
        if (x==NULL) return ;
        printTree(x->left,indent+1);
        for (int i=0; i<indent; i++)
            std::cout<<" ";
        std::cout<<"["<<x->key<<","<<x->val<<","<<x->N<<"]"<<std::endl;
        printTree(x->right,indent+1);
    }
    Node * delKey(Node *x, K key){
        if (x==NULL) return NULL;
        if (key < x->key) x->left = delKey(x->left,key);
        else if (key > x->key) x->right = delKey(x->right,key);
        else{
            Node *right = x->right;
            Node *left = x->left;
            if (left == NULL) {
                delete x;
                return right;
            }
            if (right == NULL) {
                delete x;
                return left;
            }
            x = min(right);
            x->right = delMin(right);
            x->left = left;
        }
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }
};




#endif