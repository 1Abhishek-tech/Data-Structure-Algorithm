class Trie {
public:
    class Node{
      public:
      bool end ;
      Node* next[26];
      Node(){
        end = false;
        for(int i = 0 ; i < 26 ; i++)
          next[i] = NULL;
      }
    };
    Node* trie;
    Trie() {
        trie = new Node();
    }
    
    void insert(string word) {
      Node* itr = trie;
      for(int i = 0 ; i < word.size() ; i++){
        if(! itr->next[ word[i] - 'a' ] )
        itr->next[ word[i] - 'a' ] = new Node();
        itr = itr->next[ word[i] - 'a' ] ;
      }
      itr->end = true ;
    }
    
    bool search(string word) {
        Node* itr = trie ;
      for(int i = 0 ; i < word.size() ; i++){
        if(! itr->next[ word[i] - 'a' ] )
         return false;
        itr = itr->next[ word[i] - 'a' ] ;
      }
      return itr->end;
    }
    
    bool startsWith(string prefix) {
        Node* itr = trie;
      for(int i = 0 ; i < prefix.size() ; i++){
        if( !itr->next[ prefix[i] - 'a' ] ) return false;
        itr = itr->next[ prefix[i] - 'a' ];
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