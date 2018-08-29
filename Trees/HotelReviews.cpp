// const int alphabet_size = 26;

// class solution{
  
//     struct TrieNode{
//         struct TrieNode* children[alphabet_size];
//         bool isEndOfWord;
//     };
    
// }

struct node{
    bool exist;
    node* arr[alphabet_size];
    node(bool bul=false){
        exist = bul;
        for(int i=0; i<26; i++)    arr[i] = NULL;
    }
};

void insert(node* root, string &A){
    
    node* temp = root;
    for(int i=0; i<A.length(); i++){
        
        int index = A[i]-'a';
        if( !temp->arr[index] ){
            temp->arr[index] = new node();
        }
        temp = temp->arr[index];
    }
    temp->exist = true;
    return;
}

bool search( node* root, string &A){
    
    node* temp = root;
    for(int i=0; i<A.size(); i++){
        if(temp->arr[A[i]-'a']==NULL)    return false;
        temp = temp->arr[A[i]-'a'];
    }
    return( temp->exist && temp!=NULL );
}

// vector<int> Solution::solve(string A, vector<string> &B) {
    
//     vector<int> ret;
    
    
    
    
    
//   return ret;
// }


void convert(string &str){
    //Convert _ to spaces
    for(int i=0; i<str.size(); i++)    if(str[i]=='_')    str[i]=' ';
    return;
}

vector<int> Solution::solve(string good, vector<string>& review){
    convert(good);
    node* trie = new node();
    string word;
    stringstream ss;
    ss<<good;
    while(ss>>word)    add(word,trie);
    int n = review.size();
    int k;
    vector<pair<int,int> > rating(n);
    for(int i=0; i<n; i++){
        convert(review[i]);
        ss.clear();
        ss<<review[i];
        k=0;
        while(ss>>word)    if(search(word,trie))    k++;
        rating[i].first = k;    rating[i].second = i;
    }
    sort(rating.begin(),rating.end(),cmp);
    vector<int> ans(n);
    for(int i=0; i<n; i++)    ans[i] = rating[i].second;
    return ans;
}

