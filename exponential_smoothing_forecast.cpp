#include<iostream>
#include <stdlib.h>
#include<cmath>
using namespace std;

const int BUF_SIZE=100;

int main(int argc, char** argv)
{
	double alpha = atof(argv[1]);
	double forecast[BUF_SIZE];
	double forecast_2nd[BUF_SIZE];
	/*
	 * use stupid double buffer directly
	 * */
	double actualv[BUF_SIZE] = {
	1125,
	712,
	675,
	472,
	407,
	384,
	347,
	474,
	503,
	427,
	787,
	481,
	465,
	489,
	236,
	502,
	992,
	496,
	712,
	407,
	409,
	481,
	954,
	445,
	267,
	1048,
	127,
	176,
	652,
	460,
	366,
	647,
	453,
	684,
	994,
	460,
	549,
	662,
	426,
	470,
	566,
	349,
	961,
	853,
	507,
	878,
	410,
	563,
	436,
	938,
	478,
	504,
	617,
	117,
	1154,
	463,
	380,
	929,
	431,
	231,
	346,
	533,
	569,
	506,
	468,
	109,
	414,
	411,
	113,
	465,
	360,
	384,
	105,
	336,
	493,
	345,
	419,
	381,
	360,
	274,
	603,
	343,
	400,
	684,
	147,
	573,
	548,
	723};

	forecast[0]=actualv[0];
	forecast_2nd[0]=actualv[0];

	double sum_actual = actualv[0];
	double sum_forecast = forecast[0];
	double sum_forecast_2nd = forecast_2nd[0];
	double sum_y = actualv[0];
	double a = 0.0;
	double b = 0.0;
	double y = 0.0;

	int T = 0;
	for(int i=1;i<=BUF_SIZE;i++) {
		forecast[i]=(alpha*actualv[i-1]+(1-alpha)*forecast[i-1]);
		forecast_2nd[i]=alpha*forecast[i] + (1-alpha)*forecast_2nd[i-1];

		if(0 == actualv[i]) {
			T++;
			y = a + b*T;
		} else {
			a = 2*forecast[i] - forecast_2nd[i];
			b = alpha / (1-alpha) * (forecast[i] - forecast_2nd[i]);
			y = a + b;
		}

		sum_actual += actualv[i];
		sum_forecast += forecast[i];
		sum_forecast_2nd += forecast_2nd[i];
		sum_y += y;
		cout << "i:" << i 
			<< ", sum(actual):" <<  sum_actual
			<< ", sum(1st):" << sum_forecast
			<< ", sum(2nd):" << sum_forecast_2nd
			<< ", sum(Y):" << sum_y
			<< ", actual value:" <<  actualv[i] 
			<< ", 1st value:" << forecast[i]
			<< ", 2nd value:" << forecast_2nd[i]
			<< ", Y(T) value:" << y
			<<endl;

/*
		if(sum_forecast >=45000 || sum_forecast_2nd>=45000) {
			break;
		}
*/
	}

	return 0;
}
