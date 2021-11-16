//https://leetcode.com/discuss/interview-question/351783/Microsoft-or-OA-2019-or-Min-Adj-Swaps-to-Make-Palindrome/590023
//https://leetcode.com/playground/oPheXrrW
bool couldBeP(string s) {
    map<char, int> res;
    for (auto v:s) {
        res[v]++;
    }
    auto it=res.begin();
    int signle=0;
    while(it!=res.end()) {
        if (it->second%2!=0) {
            signle++;
        }
        it++;
    }
    return signle<=1;
}

int minswap(string s) {
    if (!couldBeP(s)) return -1;
    int len = s.size();
    int l =0;
    int r =len-1;
    int sc = 0;
    int k=r;
    while (l<r) {
        k=r;
        while (k>=l && s[l]!=s[k]) {
            k--;
        }
        if (l!=k && s[l]==s[k]) {
            while (k<r) {
                swap(s[k], s[k+1]);
                k++;
                sc++;
            }
            r--;
            l++;
        } else {
            swap(s[l],s[l+1] );
            sc++;
        }
    }//ntiin -> n tii n -> ni t in
    //mamad -> m aad m -> ma d am
    //std::cout<<"ms----: "<<s<<endl;
    return sc;
}


int main() {
    string s1 = "abaabab"; //-> a baabb a -> ab aab ba -> aba b aba
    std::cout << minswap(s1)<<std::endl;
    string s2 = "mamad"; 
    std::cout<< minswap(s2)<<std::endl;
    string s3 = "ntiin";
    std::cout<<minswap(s3)<<std::endl;  
}