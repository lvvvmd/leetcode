class Trie {
public:
    /** Initialize your data structure here. */
    string prefix;
    bool isWord;
    map<char, Trie*> next;
    Trie() {
        prefix = "";
        isWord = false;
    }
    
    Trie(string pre) {
        prefix = pre;
        isWord = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if (prefix == word && isWord){
			return;
		}
		else if (prefix == word){
			isWord = true;
			return;
		}
        int i = 0;
        auto key = next.find(word[prefix.length()]);
        if(key != next.end()){
            
        }
        else{
            Trie* obj = new Trie(word.substr(0, prefix.length()+1));
            next.insert(pair<char, Trie*>(word[prefix.length()], obj));
        }
        if(next[word[prefix.length()]]->prefix == word){
            next[word[prefix.length()]]->isWord = true;
            return ;
        }
        next[word[prefix.length()]]->insert(word);
        
        
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(prefix == word && isWord)
            return true;
        else if(prefix == word)
            return false;
        auto key = next.find(word[prefix.length()]);
        if(key != next.end()){
            return next[word[prefix.length()]]->search(word);
        }
        else
            return false;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix2) {
         if(prefix == prefix2)
            return true;
       
        auto key = next.find(prefix2[prefix.length()]);
        if(key != next.end()){
            return next[prefix2[prefix.length()]]->startsWith(prefix2);
        }
        else
            return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */
