struct Node{
    bool eow;
    vector<Node*> children;
    Node(){
        eow=false;
        children.resize(26);
    }
};
class Trie{
    Node* root;
    public:

    Trie(){
        root=new Node();

    }
    void insert(string word) {
        Node* p=root;
        for(auto&c:word){
            if(p->children[c-'a']==nullptr){
                p->children[c-'a']=new Node();
            }
            p=p->children[c-'a'];
        }
        p->eow=true;
    }

    bool search(string word) {
        Node* p=root;
        for(auto&c:word){
            if(p->children[c-'a']==nullptr){
                return false;
            }
            p=p->children[c-'a'];
        }
        if(p->eow) return true;
        return false;
    }

    bool startsWith(string prefix) {
        Node* p=root;
        for(auto&c:prefix){
            if(p->children[c-'a']==nullptr){
                return false;
            }
            p=p->children[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */