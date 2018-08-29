struct node{
    node* chararr[26];
    bool exist;
    int freq;
    // node( bool bul=true ){
        
    //     freq = 1;
    //     exist = bul;
    //     for(int i=0; i<26; i++) chararr[i]=NULL;
    // }
};

struct node* getNode(void)
{
    node* pNode =  new node;
    pNode->exist = false;
    pNode->freq = 1;
    
    for(int i=0; i<26; i++) pNode->chararr[i]=NULL;
    return pNode;
};

void insert( node* root, string &A ){
    
    node* new_node = root;
    for(int i=0; i<A.length(); i++){
        
        int index = A[i]-'a' ;
        if( !new_node->chararr[index] ){
            new_node->chararr[index] = getNode();
        }
        else {
            new_node->chararr[index]->freq++;
            // cout << A << "  " << char( 'a' + index) << " " << new_node->freq << " \n";
        }
        
        new_node = new_node->chararr[index];
    }
    new_node->exist = true;
    return;
}

string search( node* root, string &A){
    
    string ret = "";
    node* temp = root;
    for(int i=0; i<A.length(); i++){
        
        int index = A[i]-'a';
        temp = temp->chararr[ index ];
        // cout << A << " " << temp->freq << " " << i << " " << char( index + 'a' ) << " \n";
        if( temp->freq == 1){
            ret = A.substr(0, i+1);
            return ret;
        }
    }
    return A;
}


vector<string> Solution::prefix(vector<string> &A) {
    
    vector<string> ret;
    
    node* trie = getNode();
    for(int i=0; i<A.size(); i++){
        insert( trie, A[i]);
    }
    
    for(int i=0; i<A.size(); i++){
        
        string str = search(trie, A[i]);
        // cout << A[i] << " " << str << " strings \n";
        ret.push_back( str );
    }
    
    return ret;
}

