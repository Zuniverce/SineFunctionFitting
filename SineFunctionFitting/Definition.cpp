#include "Definition.h"
double eta = 0.001;
long double flag = 0.0005;
double maxWeight = 3;
double maxBias = 5;
ifstream fin;
Network network;
double randomDouble(double min, double max)
{
	return 1.0 * rand() / RAND_MAX * (max - min) + min;
}

double sigmoid(double x)
{
	return 1.0 / (1 + exp(-x));
}

double a(double x, unsigned PresentLayer)
{
	if (PresentLayer == network.layer.size() - 1)
	{
		return x;
	}
	else
		return sigmoid(x);
}

double a_(double x, unsigned PresentLayer)
{
	if (PresentLayer == network.layer.size() - 1)
	{
		return 1;
	}
	else
		return sigmoid(x) * (1 - sigmoid(x));
}

double SQR(double x)
{
	return x * x * x * x;
}

double fittee(vector<double> x)
{
	// 可以根据实际情况更改
	return sin(x[0]);
}