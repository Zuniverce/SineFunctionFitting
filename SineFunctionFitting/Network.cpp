#include "Network.h"
#include "Definition.h"

void Network::build()
{
	unsigned layerNum;
	cout << "神经网络隐藏层数:" << endl;
	cin >> layerNum;
	layerNum += 2; // 加上输入层和输出层

	for (unsigned i = 0; i < layerNum; i++) // 构建神经网络结构
	{
		/*layer.push_back(Layer(i));
		layer[i].build();*/

		Layer obj{ i };
		obj.build();
		layer.push_back(obj);
	}
	for (unsigned i = 0; i < layer[layer.size() - 1].neuron.size(); i++) // 构建正解 (可能溢出?)
	{
		truth.push_back(0);
	}
	// 学习次数
	//cout << "学习次数:" << endl;
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
	for (unsigned i = 1; i < layer.size(); i++) // 第 i 层
	{
		cout << "第 " << i << " 层:" << endl;
		for (unsigned j = 0; j < layer[i].neuron.size(); j++) // 第 j 个神经元
		{
			cout << "神经元 " << j << endl;
			for (unsigned k = 0; k < layer[i - 1].neuron.size(); k++) // 第 k 个权重
			{
				cout << "对上层神经元 " << k << " 的权重: ";
				cout << layer[i].neuron[j].weight[k] << endl;
			}
			cout << "偏置: " << layer[i].neuron[j].bias << endl;
		}
		cout << endl;
	}
}
