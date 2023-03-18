#include "Layer.h"
#include "Definition.h"

Layer::Layer(unsigned PresentLayer)
{
	presentLayer = PresentLayer;
}
void Layer::build()
{
	unsigned neuronNum;
	cout << "��" << presentLayer << "�����Ԫ����:" << endl;
	cin >> neuronNum;

	for (unsigned i = 0; i < neuronNum; i++) // ������Ԫ
	{
		neuron.push_back(Neuron(presentLayer, i));
		neuron[i].build();
	}

	for (unsigned i = 0; i < neuronNum; i++) // ��ʼ��out[] (�п������?)
	{
		out.push_back(0);
	}
}

void Layer::inReset()
{
	for (unsigned i = 0; i < neuron.size(); i++)
	{
		/*cout << "�������Ԫ " << i << " :" << endl;
		cin >> out[i];*/
		fin >> out[i];
	}
}

void Layer::inReset(vector<double> x)
{
	for (unsigned i = 0; i < neuron.size(); i++)
	{
		out[i] = x[i];
	}
}

void Layer::forward()
{
	for (unsigned i = 0; i < neuron.size(); i++)
	{
		neuron[i].forward();
	}
}

void Layer::backward()
{
	for (unsigned i = 0; i < neuron.size(); i++)
	{
		neuron[i].backward();
	}
}

void Layer::update()
{
	for (unsigned i = 0; i < neuron.size(); i++)
	{
		neuron[i].update();
	}
}

void Layer::clearGrad()
{
	for (unsigned i = 0; i < neuron.size(); i++)
	{
		neuron[i].clearGrade();
	}
}
