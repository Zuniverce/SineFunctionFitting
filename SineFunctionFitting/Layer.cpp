#include "Layer.h"
#include "Definition.h"

Layer::Layer(unsigned PresentLayer)
{
	presentLayer = PresentLayer;
}
void Layer::build()
{
	unsigned neuronNum;
	cout << "第" << presentLayer << "层的神经元个数:" << endl;
	cin >> neuronNum;

	for (unsigned i = 0; i < neuronNum; i++) // 塞入神经元
	{
		neuron.push_back(Neuron(presentLayer, i));
		neuron[i].build();
	}

	for (unsigned i = 0; i < neuronNum; i++) // 初始化out[] (有可能溢出?)
	{
		out.push_back(0);
	}
}

void Layer::inReset()
{
	for (unsigned i = 0; i < neuron.size(); i++)
	{
		/*cout << "输入层神经元 " << i << " :" << endl;
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
