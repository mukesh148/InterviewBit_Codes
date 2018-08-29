// string Solution::minWindow(string A, string B) {
    
    
//     int start = 0, end = 0;
    
//     map<char, int> hash;
//     for(int i=0; i<B.length(); i++){
//         if(hash.find(B[i])==hash.end()){
//             hash[B[i]]=1;
//         }
//         else hash[B[i]]++;
//     }
    
//     int n = B.length();
//     for(int low = 0; i = 0; i<A.length(); i++){
        
//         if( hash.find(A[i])==hash.end() ) continue;
        
//         int count = 0;
//         if(count == n) return "";
        
//         low=i;
//         while( i<A.length() && total!= n){
            
//             if( hash[A[i]]>0 && hash.find(A[i])!= hash.end()){
//                 hash[A[i]]--;
//                 count++;
//             }
//             i++;
//         }
//         if(total!=n) return "";
//         else{
//             if( i-low < end-start ){
//                 start = low;
//                 end = i;
//             }
//         }
        
//         i++;
//     }
    
    
// }


string Solution::minWindow(string S, string T) {
    
    if (S.length() < T.length()) return "";
        unordered_map<char, int> counts;
        for (int i = 0; i < T.length(); i++) {
            if (counts.find(T[i]) == counts.end()) {
                counts[T[i]] = 1;
            } else {
                counts[T[i]]++;
            }
        }
        int start = 0;
        int length = 0;
        int total = 0;
        for (int head = 0, tail = 0; tail < S.length(); tail++) {
            auto itTail = counts.find(S[tail]);
            if (counts.find(S[tail]) == counts.end()) { 
                continue;
            }
            counts[S[tail]]--;
            if (counts[S[tail]] >= 0) {
                total++;
            }
            // check if we have all characters in T covered. 
            if (total == T.size()) {
                // Now move the head pointer till popping out those characters 
                // still makes sure that all characters in T are covered. 
                while (counts.find(S[head]) == counts.end() || counts[S[head]] < 0) {
                    if (counts.find(S[head]) != counts.end()) counts[S[head]]++;
                    head++;
                }
                // Now [head - 1, tail] is a valid substring. Update the answer. 
                if (length == 0 || tail - head + 1 < length) {
                    length = tail - head + 1;
                    start = head;
                }
            }
        }
        return S.substr(start, length);
}// string Solution::minWindow(string A, string B) {
    
    
//     int start = 0, end = 0;
    
//     map<char, int> hash;
//     for(int i=0; i<B.length(); i++){
//         if(hash.find(B[i])==hash.end()){
//             hash[B[i]]=1;
//         }
//         else hash[B[i]]++;
//     }
    
//     int n = B.length();
//     for(int low = 0; i = 0; i<A.length(); i++){
        
//         if( hash.find(A[i])==hash.end() ) continue;
        
//         int count = 0;
//         if(count == n) return "";
        
//         low=i;
//         while( i<A.length() && total!= n){
            
//             if( hash[A[i]]>0 && hash.find(A[i])!= hash.end()){
//                 hash[A[i]]--;
//                 count++;
//             }
//             i++;
//         }
//         if(total!=n) return "";
//         else{
//             if( i-low < end-start ){
//                 start = low;
//                 end = i;
//             }
//         }
        
//         i++;
//     }
    
    
// }


string Solution::minWindow(string S, string T) {
    
    if (S.length() < T.length()) return "";
        unordered_map<char, int> counts;
        for (int i = 0; i < T.length(); i++) {
            if (counts.find(T[i]) == counts.end()) {
                counts[T[i]] = 1;
            } else {
                counts[T[i]]++;
            }
        }
        int start = 0;
        int length = 0;
        int total = 0;
        for (int head = 0, tail = 0; tail < S.length(); tail++) {
            auto itTail = counts.find(S[tail]);
            if (counts.find(S[tail]) == counts.end()) { 
                continue;
            }
            counts[S[tail]]--;
            if (counts[S[tail]] >= 0) {
                total++;
            }
            // check if we have all characters in T covered. 
            if (total == T.size()) {
                // Now move the head pointer till popping out those characters 
                // still makes sure that all characters in T are covered. 
                while (counts.find(S[head]) == counts.end() || counts[S[head]] < 0) {
                    if (counts.find(S[head]) != counts.end()) counts[S[head]]++;
                    head++;
                }
                // Now [head - 1, tail] is a valid substring. Update the answer. 
                if (length == 0 || tail - head + 1 < length) {
                    length = tail - head + 1;
                    start = head;
                }
            }
        }
        return S.substr(start, length);
}
