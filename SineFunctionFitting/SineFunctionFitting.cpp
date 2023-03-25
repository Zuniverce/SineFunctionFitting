#include "Global.h"
#include "Definition.h"
#include "Network.h"
const char* position = "Z:/project/program/learn/ArtificialIntelligence/NeuronNetwork/SineFunctionFitting/in.txt";
int main()
{
	fin.open(position);
	srand((unsigned)time(NULL));

	network.build();
	double cost = 10000000000;
	network.times = 1000;

	long long unsigned iter = 0;
	while (cost >= flag)
	{
		cost = 0;
		vector<double> x;
		x.push_back(0);
		for (unsigned i = 0; i < network.times; i++)
		{
			network.inReset(x);
			network.setTruth();
			network.forward();
			network.backward();
			cost += network.cost();
			x[0] += 0.005;
		}
		network.update();
		network.clearGrad();
		if(iter % 100 == 0)
		{
			//network.show();
			printf("%.10lf\n", cost);
		}
		iter++;
	}
	cout << network.truth[0] << ", " <<
		network.layer[network.layer.size() - 1].out[0] << ", " <<
		cost << endl;

	cout << "ok" << endl;
	fin.close();
	fin.open(position);
	for (int i = 0; i < 100; i++)
	{
		network.inReset();
		network.forward();
		cout << /*fittee(network.layer[0].out) << " " <<*/
			network.layer[network.layer.size() - 1].out[0] << endl;
	}
	network.show();
	return 0;
}
