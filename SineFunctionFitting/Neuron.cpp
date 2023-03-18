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
	if (presentLayer) // ��������Ԫ����Ҫ���㹤����������Ȩ�� (�������Խ��)
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
	network.layer[presentLayer].out[presentNeuron] = a(weightedSummation, presentLayer); // ������������out�еĶ�Ӧλ��
}

void Neuron::backward()
{
	// ���delta
	if (presentLayer == network.layer.size() - 1) // ���������
	{
		delta = (network.layer[presentLayer].out[presentNeuron] -
			network.truth[presentNeuron]) *
			a_(weightedSummation, presentLayer);
		// ʵ���ϣ���ֻ���Է�����Ϊ���ۺ�����delta
	}
	else // �������ز�
	{
		delta = 0;
		for (unsigned i = 0; i < network.layer[presentLayer + 1].neuron.size(); i++)
		{
			delta += network.layer[presentLayer + 1].neuron[i].delta *
				network.layer[presentLayer + 1].neuron[i].weight[presentNeuron];
		}
		delta *= a_(weightedSummation, presentLayer);
	}

	// ����Ȩֵ��ƫ�õ�ƫ����
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
