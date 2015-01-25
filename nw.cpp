#include <iostream>
#include <cmath>

using namespace std;

double fact(double i)
{
	if (i == 0)
		return 1;
	else
		return (i * fact(i-1));
}

int main()
{
	int n;

	cout<<"enter the number of points : ";
	cin>>n;

	double a[n][2],x;
	int i, j;

	for (i = 0; i < n; i++) {
		cin>>a[i][0];
		cin>>a[i][1];
	}

	cout<<"enter x : ";
	cin>>x;

	for (i = 0; i < n; i++) {
		for (j = n - 1; j > i; j--) {
			a[j][1] = a[j][1] - a[j - 1][1];
		}
	}

	for (i = 0; i < n; i++) {
		cout<<a[i][1]<<' ';
	}
	cout<<endl<<endl;

	double p = 0, ans = 0, r = 0;
	p = (x - a[n-1][0]) / (abs(a[n-1][0] - a[n-2][0]));

	for (i = 0; i < n; i++) {
		x = p;
		r = 1;
		for (j = 0; j > i; j++) {
			r = r * x;
			x = x + 1;
		}
		ans = ans + (a[i][1] * r) / fact(i);
	}

	cout<<ans<<endl;

	return 0;
}
