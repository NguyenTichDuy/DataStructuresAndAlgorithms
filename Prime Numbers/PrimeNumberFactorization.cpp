#include<stdio.h>
#include<string.h>
#include<vector>

using namespace std;

vector<int> primes;
vector<int> factorization;
void sieve(int n)
{
    bool check[n];
    memset(check, true, sizeof(check));
    for (int i = 2; i <= n; i++)
    {
        if (check[i])
        {
            primes.push_back(i);
            check[i] = false;
            for (int j = i * i; j <= n; j += i)
            {
                check[j] = false;
            }
        }
    }
}
void PrimeFactorzation(int n)
{
    for (int i = 0; i < primes.size();)
    {
        if (n % primes[i] == 0)
        {
            factorization.push_back(primes[i]);
            n /= primes[i];
        }
        else
        {
            i++;
        } 
    }
}
void Factorization(int n)
{
    int idx = 0, f = primes[idx];

    while (n != 1 && n >= f*f)
    {
        while (n % primes[idx] == 0)
        {
            n /= primes[idx];
            factorization.push_back(primes[idx]);
        }
        f = primes[++idx];
    }
    if (n != 1)
    {
        factorization.push_back(primes[idx]);
    }
}
void print()
{
    for (int i = 0; i < primes.size(); i++)
    {
        printf("%d ", primes[i]);
    }
    printf("\n");
    for (int i = 0; i < factorization.size(); i++)
    {
        printf("%d ", factorization[i]);
    }
    
}
int main()
{
    sieve(50);
    Factorization(18);
    print();
}
