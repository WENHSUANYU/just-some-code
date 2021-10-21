#include<iostream>
using namespace std;

#define MAX 100000
#define Weight_MAX 10000
typedef long long ll;

class Truck
{
    private:
        int n, k;
        ll *T;
    public:
        void set_n(int n)
        {
            this->n = n;
        }

        void set_k(int k)
        {
            this->k = k;
        }

        void set_T(ll *T)
        {
            this->T = new ll[this->n];
            this->T = T;
        }
        int check(ll P)
        {
            int i = 0;
            for (int j = 0; j < this->k; j++) {
                ll s = 0;
                while (s + this->T[i] < P) {
                    s += this->T[i];
                    i++;
                    if (i == n)
                        return n;
                }
            }
            return i;
        }

        int solve()
        {
            ll left = 0;
            ll right = MAX * Weight_MAX;
            ll mid;
            while (right - left > 1) {
                mid = (left + right) / 2;
                int num_merchan = check(mid);
                if (num_merchan >= this->n)
                    right = mid;
                else
                    left = mid;
            }        
            return right;
        }

};


int main()
{
    int n, k;
    
    Truck truck;
    cin >> n >> k;
    truck.set_n(n);
    truck.set_k(k);
    ll *tmp = new ll[n];
    for (int i = 0; i < n; i++)
        cin >> tmp[i];
    truck.set_T(tmp);
    int ans = truck.solve();
    cout << ans << endl;
    delete [] tmp;


    return 0;
}