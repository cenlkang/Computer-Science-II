#include <iostream>
using namespace std;

int Fibonacci(int n);

int main()
{
	for (int i=1; i<=20; i++)
		cout << Fibonacci(i) << endl;

	return 0;
}

int Fibonacci(int n)
{
	if (n<=2)
		return 1;
	else
		return Fibonacci(n-1) + Fibonacci(n-2);
}
