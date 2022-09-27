class Solution {
public:
  void fillL(int f , int s , string& dominoes){
    for(int i = f ; i <= s ; i++) dominoes[i] = 'L';
  }
  void fillR(int f , int s , string& dominoes){
    for(int i = f ; i <= s ; i++) dominoes[i] = 'R';
  }  
  void fill(int f , int s , string& dominoes){
    while(f < s){
      dominoes[f] = 'R';
      dominoes[s] = 'L';
      f++ ; s-- ;
    } 
  }  
    string pushDominoes(string dominoes) {
      
      dominoes = 'L' + dominoes + 'R';
      int n = dominoes.size();
      int j = 0 , k = 0;
      while(k < n){
        while(dominoes[k] == '.')k++;
        int diff = k - j; 
        if(diff){
          if(dominoes[j] == 'L' && dominoes[k] == 'L') fillL(j+1 , k-1 , dominoes);
          else if(dominoes[j] == 'R' && dominoes[k] == 'R') fillR(j+1 , k-1 , dominoes);
          else if(dominoes[j] == 'R' && dominoes[k] == 'L') fill(j+1 , k-1 , dominoes);
        }
        
        j = k;
        k++;
      }
      return dominoes.substr(1,n-2);
    }
};