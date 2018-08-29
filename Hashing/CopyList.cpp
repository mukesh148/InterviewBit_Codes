/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    
    RandomListNode* node = A;
    while( node!=NULL ){
        RandomListNode* copynode = new RandomListNode(node->label);
        RandomListNode* anocopy = node->next;
        node->next = copynode;
        copynode->next = anocopy;
        node = anocopy;
    }
    
    node = A;
    while( node!= NULL ){
        RandomListNode* copynode = node->next;
        if( node->random!=NULL ){
            
            copynode->random = node->random->next;
            
        }
        else{
            copynode->random = NULL;
        }
        node= copynode->next;
    }
    
    node = A;
    RandomListNode* ret = node->next;
    RandomListNode* copy = node->next;
    
    while(node!=NULL && copy->next!=NULL ){
        
        node->next = node->next->next;
        copy->next = copy->next->next;
        node = node->next;
        copy = copy->next;
    }
    return ret;
    
}

