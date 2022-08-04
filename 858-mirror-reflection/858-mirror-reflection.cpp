class Solution {
public:
    long long gcd(long long p , long long q){
      if(q == 0) return p;
      return gcd(q , p%q);
    }
    int mirrorReflection(int p, int q) {
      if( (p/gcd(p,q))%2 == 0) return 2;
      if( (q/gcd(p,q) )%2 != 0) return 1;
      return 0;
    }
};