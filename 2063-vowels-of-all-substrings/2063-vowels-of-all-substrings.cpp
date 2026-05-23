class Solution {
public:
    bool isVowel(char c){
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }

    long long countVowels(string word) {
        long long cnt=0;
        int n=word.length();
        for(long long i=0;i<n;i++){
            if(isVowel(word[i])) cnt+=((i+1)*(n-i));
        }
        return cnt;
    }
};