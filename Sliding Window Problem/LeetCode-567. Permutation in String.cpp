class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> freq;
        if(s2.size() < s1.size()){
            return false;
        }

        for(char c: s1){
            freq[c]++;
        }

        int required = freq.size();
        int n = s1.size();


        int left = 0, right = 0;

        while(right < s2.size()){
            char c = s2[right];

            if(freq.count(c)){
                freq[c]--;

                if(freq[c] == 0){
                    required--;
                }
            }

            right++;

            if(right - left == n){
                if(required == 0){
                    return true;
                }

                char leftChar = s2[left];
                if(freq.count(leftChar)){
                    if(freq[leftChar] == 0){
                        required++;
                    }
                    freq[leftChar]++;

                }
                left++;
            }
        }
        return false;
    }
};
