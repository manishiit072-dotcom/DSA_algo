#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
vector<pair<int,int>> primepairs(int k) {
    int limit = 200000;
    vector<bool> isPrime(limit, true);
    vector<int> primes;
    vector<pair<int,int>> pairs;

    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i < limit && primes.size() < k; i++) {
        if (isPrime[i]) {
            primes.push_back(i);

            if (primes.size() >= 2) {
                pairs.push_back({primes[primes.size()-2], primes.back()});
            }

            for (long long j = 1LL * i * i; j < limit; j += i) {
                isPrime[j] = false;
            }
        }
    }

    return pairs;
}
int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
void solve(){
   int n;
   cin>>n;
   vector<pair<int,int>> result=primepairs(n);
   for(auto it:result){
       cout<<gcd(it.first,it.second)<<" ";
   }

}


int main()
{
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}