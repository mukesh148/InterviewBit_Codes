// vector<int> find_factor(int min_val){
//     vector<int> temp;
//     int count = 0;
//     for(int i=1; i<= sqrt(min_val); i++){
//         if(min_val%i == 0){
//             temp.push_back(i);
//         }
//         if(i == sqrt(min_val)) count--;
//     }
//     count += temp.size()-1;
//     for(int i=count; i>=0; i--){
//         temp.push_back( min_val/temp[i] );
//     }
//     return temp;
// }

int gcd_(int x, int y){
    if(x < y) swap(x,y);
    if(y==0) return x;
    return gcd_(x%y, y);
}

// int find_gcd(int C, int D) {
//     if(D==0 or D==1) return 1;
//     vector<int> temp = find_factor(C);
    
//     for(int i=temp.size()-1; i>0; i--){
//         // cout << gcd_(temp[i], D) << " some \n";
//         if(gcd_(temp[i], D)==1) return temp[i];
//     }
    
//     return 1;
// }

int Solution::cpFact(int A, int B) {
    
    while(gcd_(A,B)!=1){
        A/=gcd_(A,B);
    }
    return A;
}


// int find_gcd(int C, int D) {
//     if(D==0) return 1;
//     vector<int> temp = find_factor(C);
//     vector<int> temp1 = find_factor(D);
//     int j=temp1.size()-1;
//     if(j==0) return 1;
//     for(int i= temp.size()-1; i>0; i--){
//         for(j=temp1.size()-1; j>0; j--){
//             if(temp[i] >= temp1[j] and temp[i]%temp1[j]==0){
//                 break;
//             }
//             if(temp[i] < temp1[j] and temp1[j]%temp[i]==0){
//                 break;
//             }
//         }
//         if(j==0){
//             return temp[i];
//         }
//     }
//     return 1;
// }

