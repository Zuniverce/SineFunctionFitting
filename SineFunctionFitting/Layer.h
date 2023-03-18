#pragma once
#include "Global.h"
#include "Neuron.h"
class Layer // ≤„¿‡
{
public:
	unsigned presentLayer;
	vector<Neuron> neuron;
	vector<double> out;
	Layer() = delete;
	Layer(unsigned PresentLayer);
	void build();
	void inReset();
	void inReset(vector<double> x);
	void forward();
	void backward();
	void update();
	void clearGrad();
};
