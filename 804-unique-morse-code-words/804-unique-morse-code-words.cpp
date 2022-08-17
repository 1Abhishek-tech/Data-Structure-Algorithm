class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
       vector<string> code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        // code[ch - 'a']
      set<string> unique;
      for(int i = 0 ; i < words.size() ; i++){
        string word = words[i];
        string encoded = "";
        for(int j = 0 ; j < word.size() ; j++){
          char ch = word[j];
          string decoded = code[ch - 'a'];
          encoded+=decoded;
        }
        if(unique.find(encoded) != unique.end())
          continue;
        else
          unique.insert(encoded);
      }
      return unique.size();
    }
};