class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(s.size() < p.size()){
            return ans;
        }

        unordered_map<char, int> freq;

        for(char  c: p){
            freq[c]++;
        }

        int left = 0, right = 0;
        int required = freq.size();

        int windowSize = p.size();

        while(right < s.size()){
            char c = s[right];

            if(freq.count(c)){
                freq[c]--;
                if(freq[c] == 0){
                    required--;
                }
            }

            right++;

            if(right - left == windowSize){
                if(required == 0){
                    ans.push_back(left);
                }

                char leftChar = s[left];
                if(freq.count(leftChar)){
                    if(freq[leftChar] == 0){
                        required++;
                    }
                    freq[leftChar]++;
                }
                left++;
            }
        }
        return ans;
    }
};
