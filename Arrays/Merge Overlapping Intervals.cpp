/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
// int comp(const int *p. const int *q){
//     Interval *a1 = (Interval*) p;
//     Interval *b1 = (Interval*) q;
//     return a1->start > b->start;
// }
int comp(Interval p, Interval q){
    return p.start < q.start;
}
 
vector<Interval> Solution::merge(vector<Interval> &A) {
    
    if(A.size()<=1) return A;
    vector<Interval> ret;
    
    // for(int i=0; i<A.size(); i++){
    //     Interval node = A[i];
    //     cout << node.start << " " << node.end << endl;
    // }
    // cout << " first iteration over \n";
    sort(A.begin(), A.end(), comp);
    
    Interval node = A[0];
    int head = A[0].start;
    int tail = A[0].end;
    for(int i=1; i<A.size(); i++){
        
        Interval nod = A[i];
        if( nod.start > tail ){
            Interval temp = Interval(head, tail);
            ret.push_back(temp);
            head = nod.start;
            tail = nod.end;
        }
        else{
            tail = max(tail, nod.end);
        }
        
    }
    ret.push_back(Interval(head, tail));
    // cout << " 2nd iteration over \n";
    
    return ret;
}

