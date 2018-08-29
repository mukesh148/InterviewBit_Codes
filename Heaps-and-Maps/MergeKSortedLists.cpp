/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
ListNode* merge_pointer( ListNode* a, ListNode* b){
    
    
    ListNode* ret = NULL;
    ListNode* itr;
    while (a!=NULL && b!=NULL){
        
        if(a->val < b->val){
            if( ret==NULL ){
                ret = a;
                itr = ret;
            }
            else{
                itr->next = a;
                itr = itr->next;
            }
            a = a->next;
        }
        else {
            if( ret==NULL ){
                ret = b;
                itr = ret;
            }
            else{
                itr->next = b;
                itr = itr->next;
            }
            b = b->next;
        }
    }
    if( a!=NULL ){
        if(ret==NULL) return a;
        itr->next = a;
    }
    if( b!=NULL ){
        if(ret==NULL) return b;
        itr->next = b;
    }
    return ret;
} 



ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    
    ListNode* head = NULL;
    for(int i=0; i<A.size(); i++){
        
        head = merge_pointer( head, A[i]);
        
    }
    
    return head;
}

