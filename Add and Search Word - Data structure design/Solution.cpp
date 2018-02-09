class WordDictionary {
public:
	string prefix;
	bool isWord;
	map<char, WordDictionary*> next;
	/** Initialize your data structure here. */
	WordDictionary() {
		prefix = "";
		isWord = false;
	}
	WordDictionary(string pre) {
		prefix = pre;
		isWord = false;
	}
	/** Adds a word into the data structure. */
	void addWord(string word) {
		if (prefix == word && isWord){
			return;
		}
		else if (prefix == word){
			isWord = true;
			return;
		}
		int i = 0;
		auto key = next.find(word[prefix.length()]);
		if (key != next.end()){

		}
		else{
			WordDictionary* obj = new WordDictionary(word.substr(0, prefix.length() + 1));
			next.insert(pair<char, WordDictionary*>(word[prefix.length()], obj));
		}
		if (next[word[prefix.length()]]->prefix == word){
			next[word[prefix.length()]]->isWord = true;
			return;
		}
		next[word[prefix.length()]]->addWord(word);
	}

	/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
	bool search(string word) {
		if (prefix.length() == word.length() && isWord)
			return true;
		else if (prefix.length() == word.length())
			return false;
		auto key = next.find(word[prefix.length()]);
		vector<WordDictionary*> tosearch;

		if (key != next.end()){
			tosearch.push_back(next[word[prefix.length()]]);
		}
		else if (word[prefix.length()] == '.'){
			auto it = next.begin();
			for (; it != next.end(); it++){
				tosearch.push_back(it->second);
			}
		}
		else
			return false;

		for (int i = 0; i < tosearch.size();i++){
			if (tosearch[i]->search(word))
				return true;
		}
		return false;
	}
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary obj = new WordDictionary();
 * obj.addWord(word);
 * bool param_2 = obj.search(word);
 */
