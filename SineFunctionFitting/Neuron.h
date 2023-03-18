#pragma once
#include "Global.h"
class Neuron // ��Ԫ��
{
public:
	vector<double> weight;
	vector<double> gradWeight;
	double bias;
	double gradBias;
	double delta;
	double weightedSummation;
	unsigned presentLayer;
	unsigned presentNeuron;
	Neuron() = delete;
	Neuron(unsigned PresentLayer, unsigned PresentNeuron);
	void build();
	void forward();
	void backward();
	void update();
	void clearGrade();
};

