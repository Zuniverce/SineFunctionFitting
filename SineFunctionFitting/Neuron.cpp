#include "Neuron.h"
#include "Definition.h"
Neuron::Neuron(unsigned PresentLayer, unsigned PresentNeuron)
{
	presentLayer = PresentLayer;
	presentNeuron = PresentNeuron;
	delta = 0;
	bias = 0;
	gradBias = 0;
	weightedSummation = 0;
}

void Neuron::build()
{
	if (presentLayer) // 输入层的神经元不需要计算工作，不给予权重 (避免访问越界)
	{
		for (unsigned i = 0; i < network.layer[presentLayer - 1].neuron.size(); i++)
		{
			weight.push_back(randomDouble(-maxWeight, maxWeight));
			gradWeight.push_back(0);
		}
		bias = randomDouble(-maxBias, maxBias);
		gradBias = 0;
	}
}

void Neuron::forward()
{
	weightedSummation = 0;
	for (unsigned i = 0; i < network.layer[presentLayer - 1].neuron.size(); i++)
	{
		weightedSummation += weight[i] * network.layer[presentLayer - 1].out[i];
	}
	weightedSummation += bias;
	network.layer[presentLayer].out[presentNeuron] = a(weightedSummation, presentLayer); // 将计算结果存入out中的对应位置
}

void Neuron::backward()
{
	// 求出delta
	if (presentLayer == network.layer.size() - 1) // 处理输出层
	{
		delta = (network.layer[presentLayer].out[presentNeuron] -
			network.truth[presentNeuron]) *
			a_(weightedSummation, presentLayer);
		// 实际上，这只是以方差作为代价函数的delta
	}
	else // 处理隐藏层
	{
		delta = 0;
		for (unsigned i = 0; i < network.layer[presentLayer + 1].neuron.size(); i++)
		{
			delta += network.layer[presentLayer + 1].neuron[i].delta *
				network.layer[presentLayer + 1].neuron[i].weight[presentNeuron];
		}
		delta *= a_(weightedSummation, presentLayer);
	}

	// 叠加权值和偏置的偏导数
	for (unsigned i = 0; i < network.layer[presentLayer - 1].neuron.size(); i++)
	{
		gradWeight[i] += delta * network.layer[presentLayer - 1].out[i];
	}
	gradBias += delta;
}

void Neuron::update()
{
	for (unsigned i = 0; i < network.layer[presentLayer - 1].neuron.size(); i++)
	{
		double deltaWeight = -eta * gradWeight[i];
		weight[i] += deltaWeight;
	}
	double deltaBias = -eta * gradBias;
	bias += deltaBias;
}

void Neuron::clearGrade()
{
	for (unsigned i = 0; i < gradWeight.size(); i++)
	{
		gradWeight[i] = 0;
	}
	gradBias = 0;
}
