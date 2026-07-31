class TrieNode {
public:
    TrieNode* child[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for(int i = 0; i < 26; i++) {
            child[i] = nullptr;
        }
    }
};
class Solution {
public:
    TrieNode* root = new TrieNode();
    void insert(string& word) {
        TrieNode* node = root;

        for(char c:word) {
            int idx = c - 'a';
            if(node->child[idx] == nullptr) {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }
        node->isEnd = true;
    }

    void dfs(TrieNode* node, string curr, vector<string>& ans) {
        if(ans.size() == 3) return;

        if(node->isEnd) ans.push_back(curr);

        for(int i = 0; i < 26; i++) {
            if(node->child[i] != nullptr){
                dfs(node->child[i], curr + char(i + 'a'), ans);
            }
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());

        for(string &word:products)
            insert(word);
        
        vector<vector<string>> res;
        TrieNode* node = root;
        string prefix = "";

        for(char c:searchWord) {
            prefix += c;

            if(node != nullptr) {
                node = node->child[c - 'a'];
            }

            vector<string>suggestions;

            if(node != nullptr)
                dfs(node, prefix,suggestions);

            res.push_back(suggestions);
        }

        return res;
    }
};