#include <iostream>
#include <vector>
using namespace std;
vector <double> calculateI(vector <double> x, vector <double> y, double searchedX)
{
	vector <double> IVector;
	
	for (int i = 0; i < x.size(); i++)
	{
		double product = 1;
		for (int j = 0; j < x.size(); j++)
		{
			if (j == i) continue;
			product *= (searchedX - x[j]) / (x[i] - x[j]);
		}
		IVector.push_back(product);
		cout << "\n" << product << endl;
	}
	return IVector;
}
double calculateLagrange(vector <double> IVector, vector <double> y)
{
	double sum=0;
	for (int i = 0; i < y.size(); i++)
	{
		sum += y[i] * IVector[i];
	}
	return sum;
}
#define hardcoded 0
int main()
{
	vector <double> x;
	vector <double> y;
	if (!hardcoded)
	{
		cout << "Podaj liczbe punktow\n";
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cout << "Podajesz punkt" << i + 1 << endl;
			double temp;
			cin >> temp;
			x.push_back(temp);
			cin >> temp;
			y.push_back(temp);
		}
		cout << "Dla jakiego x obliczyć wartosc?\n";
		double searchedX;
		cin >> searchedX;
		cout << "Wartosc w punkcie " << searchedX << " wynosi " << calculateLagrange(calculateI(x, y, searchedX), y);
		cin.ignore();
		cin.ignore();
		cin.ignore();
		cin.ignore();
	}
	else
	{
		x.push_back(1);
		x.push_back(3);
		x.push_back(5);
		y.push_back(12);
		y.push_back(4);
		y.push_back(4);
		double searchedX;
		searchedX = 4;
		cout << "Wartosc w punkcie " << searchedX << "wynosi " << calculateLagrange(calculateI(x, y, searchedX), y) << " powinna 3\n";
		cin.ignore();
		cin.ignore();
		cin.ignore();
		cin.ignore();
	}
	
	
}