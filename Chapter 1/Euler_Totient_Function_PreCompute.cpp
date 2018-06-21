/*
	This code shows an efficient implementation to pre-compute Euler's totient 
	of first 1000 numbers.
	
	References: 
	(a) Linear sieve alogirhtm from http://e-maxx.ru/algo/prime_sieve_linear
	(b) Precalculating phi function 1..N by @savinov - http://codeforces.com/blog/entry/10119
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
int phi[N+1];
int lowest_prime[N+1];
vector<int> primes;

void preCalculate_all_phi_N_sieve() {
	phi[1] = 1;
	for(int i = 2; i<=N; i++) {
		if(lowest_prime[i] == 0) {
			// i is prime. So using phi[prime] = prime - 1 property of Euler totient
			lowest_prime[i] = i;
			phi[i] = i-1;
			primes.push_back(i);
		} 
		else {
			if(lowest_prime[i] == lowest_prime[i/lowest_prime[i]]) {
				/*
					If lowest prime factor of i == lowest prime factor of i/(lowest prime of i),then
					both i and i/lowest prime of i have same prime factors as n.
					
					So using phi[n] = n*(1-1/p1) * (1-1/p2)*...* (1-1/pk) property, we have
					phi[i] = i * (1-1/p1) * (1-1/p2)*...* (1-1/pk) ...........................................(1)
					and
					phi[i/lowest_prime[i]] = (i/lowest_prime[i]) * * (1-1/p1) * (1-1/p2)*...* (1-1/pk)....... (2)
					
					From (1)&(2) above, we have,
					phi[i] = phi[i/lowest_prime[i]] * lowest_prime[i];
				*/
				phi[i] = phi[i/lowest_prime[i]] * lowest_prime[i];
			}
			else {
				/*
					lowest prime factor of i != lowest prime factor of i/(lowest_prime of i).
					So (2) won't have (1-1/lowest_prime[i]) but (1) will have (1-1/lowest_prime[i]).
					
					Therefore, by dividing both sides (1) by (2), and evaluating for phi[i], we have
					phi[i] = phi[i/lowest_prime[i]] * (lowest_prime[i] - 1);
				*/
				phi[i] = phi[i/lowest_prime[i]] * (lowest_prime[i] - 1);
			}
		}
		
		// Morking all the i multiples of primes by calculating their lowest_primes.
		for(int j = 0; j < primes.size() && primes[j] <= lowest_prime[i] && i*primes[j] <= N; j++){
			lowest_prime[i*primes[j]] = primes[j];
		}
	}
}

int main() {
	preCalculate_all_phi_N_sieve();
	int n = 500;
	int ans = phi[n];
	cout<<ans<<endl;
	return 0;
}
