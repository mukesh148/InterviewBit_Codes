int Solution::solve(vector<string> &A) {
    
    vector<double> B(A.size());
    double min=2147483647, max=0;
    int count=0;
    for(int i=0; i<A.size(); i++){
        // B[i] = strtof(A[i]);
        B[i] = atof(A[i].c_str());
        if(B[i]>max) max=B[i];
        if(min>B[i]) min=B[i];
    }
    // int any_count=0;
    // A = (0,2/3), B=(2/3,1), C=(1,2)
    
    if(max<2.0/3.0){
        // cout << "first \n";
        double a=B[0], b=B[1], c=B[2];
        for(int i=3; i<B.size(); i++){
            if(B[i]>c) c = B[i];
            if(c>b) swap(b,c);
            if(b>a) swap(a,b);
        }
        if(a+b+c>1) return 1;
        // else count++;
    }
    if(1){
        // cout << "second \n";
        double a=B[0], b=B[1];
        for(int i=2; i<B.size(); i++){
            if(B[i]<2.0/3.0){
                if(B[i]>b) b = B[i];
                if(b>a) swap(a,b);
            }
        }
        for(int i=0; i<B.size(); i++){
            int any_t;
            if(B[i]>2.0/3.0 and (B[i]+a+b)>1 and (B[i]+a+b)<2) return 1;
        }
        // count++;
    }
    if(1){
        // cout << "third \n";
        double a=B[0], b=B[1];
        for(int i=2; i<B.size(); i++){
            if(B[i]<b) b = B[i];
            if(b<a) swap(a,b);
        }
        for(int i=0; i<B.size(); i++){
            if(B[i]>=1 and (B[i]+a+b)>1 and (B[i]+a+b)<2) return 1;
        }
    }
    if(1){
        // cout << "fourth \n";
        vector<double> temp;
        for(int i=0; i<B.size(); i++){
            if(B[i]>2.0/3.0) temp.push_back(B[i]);
        }
        // cout << temp.size() <<" a \n";
        // cout << b <<" b \n";
        if(temp.size()>1){
        double a=temp[0], b=temp[1];
        for(int i=0; i<B.size(); i++){
            if(B[i]>2.0/3.0){
                if(B[i]<b) b = B[i];
                if(b<a) swap(a,b);
            }
        }
        // cout << a <<" a \n";
        // cout << b <<" b \n";
        for(int i=0; i<B.size(); i++){
            if(B[i]<2.0/3.0 and (B[i]+a+b)>1 and (B[i]+a+b)<2) return 1;
        }
        }
    }
    if(1){
        // cout << "fifth \n";
        
        vector<double> temp1;
        for(int i=0; i<B.size(); i++){
            if(B[i]>2.0/3.0 and B[i]<1) temp1.push_back(B[i]);
        }
        vector<double> temp2;
        for(int i=0; i<B.size(); i++){
            if(B[i]>1) temp2.push_back(B[i]);
        }
        if(temp1.size()!=0 and temp2.size()!=0){
        double a1=B[0], b1=B[1];
        for(int i=2; i<B.size(); i++){
            if(B[i]>2.0/3.0 and B[i]<1){
                if(B[i]<b1) b1 = B[i];
                if(b1<a1) swap(a1,b1);
            }
        }
        double a2=B[0], b2=B[1];
        for(int i=2; i<B.size(); i++){
            if(B[i]>1){
                if(B[i]<b2) b2 = B[i];
                if(b2<a2) swap(a2,b2);
            }
        }
        if((min+a1+a2)>1 and (min+a1+a2)<2) return 1;
        }
    }
    // cout << min << "min \n";
    // cout << max << "max \n";
    // for(int i=0; i<B.size(); i++){
    //     cout << B[i] << " value \n";
    //     cout << typeid(B[i]).name() << " type \n";
    // }
    // cout << B[0]+B[1] << "\n";
    
    // double a=B[0], b=B[1], c=B[2];
    // for(int i=3; i<B.size(); i++){
    //     if(B[i]<c) c = B[i];
    //     if(c<b) swap(b,c);
    //     if(b<a) swap(a,b);
    // }
    // cout << a << "\n";
    // cout << b << "\n";
    // cout << c << "\n";
    // cout << a + b + c << "\n";
    
    // if(a+b+c < 2 and a+b+c >1) return 1;
    
    return 0;
}


// // A = (0,2/3), B=(2/3,1), C=(1,2)
//     if(max<2.0/3.0){
//         cout << "first \n";
//         double a=B[0], b=B[1], c=B[2];
//         for(int i=3; i<B.size(); i++){
//             if(B[i]>c) c = B[i];
//             if(c>b) swap(b,c);
//             if(b>a) swap(a,b);
//         }
//         if(a+b+c>1) return 1;
//     }
//     else if(min<2.0/3.0 and max>2.0/3.0 and max<1){
//         cout << "second \n";
//         double a=B[0], b=B[1];
//         for(int i=2; i<B.size(); i++){
//             if(B[i]<2.0/3.0){
//                 if(B[i]>b) b = B[i];
//                 if(b>a) swap(a,b);
//             }
//         }
//         for(int i=0; i<B.size(); i++){
//             if(B[i]>2.0/3.0 and (B[i]+a+b)>1 and (B[i]+a+b)<2) return 1;
//         }
//         count++;
//     }
//     else if(min<2.0/3.0 and max>=1){
//         cout << "third \n";
//         double a=B[0], b=B[1];
//         for(int i=2; i<B.size(); i++){
//             if(B[i]<b) b = B[i];
//             if(b<a) swap(a,b);
//         }
//         for(int i=0; i<B.size(); i++){
//             if(B[i]>=1 and (B[i]+a+b)>1 and (B[i]+a+b)<2) return 1;
//         }
//     }
//     else if(count==1){
//         cout << "fourth \n";
//         double a=B[0], b=B[1];
//         for(int i=2; i<B.size(); i++){
//             if(B[i]>2.0/3.0){
//                 if(B[i]<b) b = B[i];
//                 if(b<a) swap(a,b);
//             }
//         }
//         for(int i=0; i<B.size(); i++){
//             if(B[i]<2.0/3.0 and (B[i]+a+b)>1 and (B[i]+a+b)<2) return 1;
//         }
//     }
//     else{
//         cout << "fifth \n";
//         double a1=B[0], b1=B[1];
//         for(int i=2; i<B.size(); i++){
//             if(B[i]>2.0/3.0 and B[i]<1){
//                 if(B[i]<b1) b1 = B[i];
//                 if(b1<a1) swap(a1,b1);
//             }
//         }
//         double a2=B[0], b2=B[1];
//         for(int i=2; i<B.size(); i++){
//             if(B[i]>1){
//                 if(B[i]<b2) b2 = B[i];
//                 if(b2<a2) swap(a2,b2);
//             }
//         }
//         if((min+a1+a2)>1 and (min+a1+a2)<2) return 1;
//     }
//     cout << min << "min \n";
//     cout << max << "max \n";

