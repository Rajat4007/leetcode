class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string res = "";
        unordered_map<string, string> mpp;
        for (int k = 0; k < knowledge.size(); k++) {
            mpp[knowledge[k][0]] = knowledge[k][1];
        }
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                string key = "";
                int j = i + 1;
                while (s[j] != ')') {
                    key += s[j];
                    j++;
                }
                if (mpp.count(key)){
                    res += mpp[key];
                }
                else{
                    res += "?";
                }
                i = j;
            }else{
                res += s[i];
            }
            

        }
        return res;
    }
};