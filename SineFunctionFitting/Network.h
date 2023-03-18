#pragma once
#include "Global.h"
#include "Layer.h"
class Network // Éñ¾­ÍøÂçÀà
{
public:
	unsigned times;
	vector<Layer> layer;
	vector<double> truth;
	void build();
	void inReset();
	void inReset(vector<double> x);
	void setTruth();
	void forward();
	void backward();
	void update();
	long double cost();
	void clearGrad();
	void show();
};
