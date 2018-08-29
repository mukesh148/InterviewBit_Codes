// string roman(int s){
    
//     switch(s){
//         case 1 :
//             return "I";
//             break;
//         case 2 :
//             return "II";
//             break;
//         case 3 :
//             return "III";
//             break;
//         case 4 :
//             return "IV";
//             break;
//         case 5 :
//             return "V";
//             break;
//         case 6 :
//             return "VI";
//             break;
//         case 7 :
//             return "VII";
//             break;
//         case 8 :
//             return "VIII";
//             break;
//         case 9 :
//             return "IX";
//             break;
//         case 10 :
//             return "X";
//             break;
//         case 50 :
//             return "L";
//             break;
//         case 100 :
//             return "C";
//             break;
//         case 500 :
//             return "D";
//             break;
//         case 1000 :
//             return "M";
//             break;
//         default  :
//             return "";
//     }
    
// }


string Solution::intToRoman(int num) {
    
    // 1000, 2000, 3000
        string M[] = {"", "M", "MM", "MMM"};
        // 100, 200, 300, .. 900
        string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
        // 10, 20, ... 90
        string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
        // 1, 2, ... 9
        string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
    // string ret = "";
    // int count = 0, itr = 0;
    // int first = A%10;
    // ret = roman(first) + ret;
    // A/= 10;
    // string add = "";
    // while(A > 0){
    //     itr+=1;
        
    //     count = A%10;
    //     // cout << itr << " " << count << "  itr \n";
        
    //     if(count < 5 and itr==1) {
    //         add = "X";
    //     }
    //     else if(count >= 5 and itr==1) {
    //         // ret = "L" + ret;
    //         add = "X";
    //         count = count % 5;
    //         for(int i=0; i<count; i++){
    //             ret = add + ret;
    //         }
    //         ret = "L" + ret;
    //         A/=10;
    //         continue;
    //     }
    //     else if(count < 5 and itr==2) {
    //         add = "C";
    //     }
    //     else if(count >= 5 and itr==2) {
    //         // ret = "D" + ret;
    //         add = "C";
    //         count = count % 5;
    //         for(int i=0; i<count; i++){
    //             ret = add + ret;
    //         }
    //         ret = "D" + ret;
    //         A/=10;
    //         continue;
    //     }
    //     else {
    //         add = "M";
    //     }
    //     // cout << itr << " " << count << " " << add << "  itr \n";
        
    //     for(int i=0; i<count; i++){
    //         ret = add + ret;
    //     }
    //     A/=10;
    // }
    // return ret;
}

