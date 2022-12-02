class Solution {
public:
    bool closeStrings(string word1, string word2) {
     unordered_map<char,int> mp1; //A map to get the frequency of string 1
        unordered_map<char,int> mp2; //A map to get the frequency of string 2
        vector<int> v1;
        vector<int> v2;
        if(word1.size()==word2.size()) //It is possible only if both string have same length
        {
            for(auto it:word1)
            {
                mp1[it]++; 
            }
             for(auto it:word2)
            {
                mp2[it]++;
            }
            for(int i=0;i<word2.size();i++)
            {
             if (word2.find(word1[i]) != std::string::npos)  //To check whether the element exist in the string 2 or not
             {
                 v1.push_back(mp1[word1[i]]);//if it exist just addedits frequency to a new vector
             }
            else
                {
                    return false;//If it doesnot exist then return false.
                }
                 if (word1.find(word2[i]) != std::string::npos) //same for string 2 elements in string 1
             {
                 v2.push_back(mp2[word2[i]]);
             }
                else
                {
                    return false;
                }
            }
            sort(v1.begin(),v1.end()); //sorted the vectors 
            sort(v2.begin(),v2.end());
            if(v1==v2)  //compared them so that if the occurences are matching then return true else false
                return true;
            else
                return false;
        }
        else
            return false;   
    }
};