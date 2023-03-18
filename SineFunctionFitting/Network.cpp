#include "Network.h"
#include "Definition.h"

void Network::build()
{
	unsigned layerNum;
	cout << "���������ز���:" << endl;
	cin >> layerNum;
	layerNum += 2; // ���������������

	for (unsigned i = 0; i < layerNum; i++) // ����������ṹ
	{
		/*layer.push_back(Layer(i));
		layer[i].build();*/

		Layer obj{ i };
		obj.build();
		layer.push_back(obj);
	}
	for (unsigned i = 0; i < layer[layer.size() - 1].neuron.size(); i++) // �������� (�������?)
	{
		truth.push_back(0);
	}
	// ѧϰ����
	//cout << "ѧϰ����:" << endl;
	//cin >> times;
}

void Network::inReset()
{
	layer[0].inReset();
}

void Network::inReset(vector<double> x)
{
	layer[0].inReset(x);
}

void Network::setTruth()
{
	for (unsigned i = 0; i < truth.size(); i++)
	{
		//TODO: set truth[i]
		truth[i] = fittee(layer[0].out);
	}
}

void Network::forward()
{
	for (unsigned i = 1; i < layer.size(); i++)
	{
		layer[i].forward();
	}
}

void Network::backward()
{
	for (unsigned i = unsigned(layer.size() - 1); i > 0; i--)
	{
		layer[i].backward();
	}
}

void Network::update()
{
	for (unsigned i = 1; i < layer.size(); i++)
	{
		layer[i].update();
	}
}

long double Network::cost()
{
	double C = 0;
	for (unsigned i = 0; i < layer[layer.size() - 1].neuron.size(); i++)
	{
		C += SQR(layer[layer.size() - 1].out[i] - truth[i]);
	}
	return 0.5 * C;
}

void Network::clearGrad()
{
	for (unsigned i = 1; i < layer.size(); i++)
	{
		layer[i].clearGrad();
	}
}

void Network::show()
{
	for (unsigned i = 1; i < layer.size(); i++) // �� i ��
	{
		cout << "�� " << i << " ��:" << endl;
		for (unsigned j = 0; j < layer[i].neuron.size(); j++) // �� j ����Ԫ
		{
			cout << "��Ԫ " << j << endl;
			for (unsigned k = 0; k < layer[i - 1].neuron.size(); k++) // �� k ��Ȩ��
			{
				cout << "���ϲ���Ԫ " << k << " ��Ȩ��: ";
				cout << layer[i].neuron[j].weight[k] << endl;
			}
			cout << "ƫ��: " << layer[i].neuron[j].bias << endl;
		}
		cout << endl;
	}
}
