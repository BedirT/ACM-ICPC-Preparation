// Modular Exponentiation (Power in Modular Aritmetic) (x^y)
#include <iostream>
using namespace std;

int main ()
{
	long long int x,y,mod, res=1;
	cin >> x >> y >> mod;
	x = x%mod;
	while (y > 0) {
		if (y%2) 
			res = (res*x)%mod;
		y = y/2;
		x= (x*x)%mod; 
	}
	cout << res << endl;

	return 0;
}
