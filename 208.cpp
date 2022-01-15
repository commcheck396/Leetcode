class Trie {
public:
    typedef struct trienode{
        struct trienode *next[26];
        bool isend;
    }trienode;
    trienode* root;
    Trie() {
        root=new trienode();
    }
    
    void insert(string word) {
        auto position=root;
        for(auto c:word){
            if(position->next[c-'a']==nullptr){
                position->next[c-'a']=new trienode();
                position=position->next[c-'a'];
                //position->isend=false;
            }
            else {
                position=position->next[c-'a'];
            }
        }
        position->isend=true;
    }
    bool dfs(trienode *position,string word,int p){
        //if(p==word.size())
        if(word[p]!='.'){
            if(position->next[word[p]-'a']!=nullptr){
                if(p==word.size()-1){
                    if(position->next[word[p]-'a']->isend==true)return true;
                    else return false;
                }
                else {
                    if(dfs(position->next[word[p]-'a'],word,p+1)==false)return false;
                }
                // if(p==word.size()-1){
                //     return true;
                // }
                // if(dfs(position->next[word[p]-'a'],word,p+1)==false)return false;
            }
            else return false;
        }
        else {
            int flag=0;
            for(int k=0;k<26;k++){
                word[p]='a'+k;
                if(dfs(position,word,p)==true){
                    flag=1;
                    break;
                }
            }
            if(flag==0)return false;
        }
        return true;
    }
    
    bool search(string word) {
        auto position=root;
        return dfs(position,word,0);
    }
    
    bool startsWith(string pre) {
        auto position=root;
        for(auto c:pre){
            if(position->next[c-'a']!=nullptr)continue;
            else return false;
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