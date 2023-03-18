#pragma once
#include "Global.h"
#include "Network.h"
extern double eta;
extern long double flag;
extern double maxWeight;
extern double maxBias;
extern ifstream fin;
extern Network network;
double randomDouble(double min = -RAND_MAX, double max = RAND_MAX);
double sigmoid(double x);
double a(double x, unsigned PresentLayer);
double a_(double x, unsigned PresentLayer);
double SQR(double x);
double fittee(vector<double> x);