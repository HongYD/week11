#include<iostream>
using namespace std;
const float Learning_Rate=0.01f;
class Artificial
{
public:
	float a, b,a1,b1;
	Artificial() :a(0.0f), b(0.0f), a1(0.0f), b1(0.0f) {};
	Artificial(const float& _a, const float& _b, const float& _a1, const float& _b1) :a(_a), b(_b), a1(_a1), b1(_b1) {};
	float First_Differential(const float& x)
	{
		return a*x + b;
	}
	float Second_Differential(const float& x)
	{
		return a1*(a*x + b) + b1;
	}
};
void main()
{
	Artificial fx((float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX, (float)rand() / RAND_MAX);
	const float What_We_Want_Y = 1.0f;
	float What_We_Input_TO_X;
	cout << "Before" << fx.Second_Differential(What_We_Input_TO_X) << endl;
	for (int i = 0; i < 1000; i++)
	{
		const float _error = What_We_Want_Y - fx.Second_Differential(What_We_Input_TO_X);
		const float E = 0.5*_error*_error;
		float w = fx.a*What_We_Input_TO_X + fx.b;
		float e_a =w-_error*What_We_Input_TO_X ;
		float e_a1 = w;
		float e_b = w - 1;
		float e_b1 = w;

		fx.a -= Learning_Rate*e_a;
		fx.a1 -= Learning_Rate*e_a1;
		fx.b -= Learning_Rate*e_b;
		fx.b1 -= Learning_Rate*e_b1;

		cout <<"After" <<fx.Second_Differential(What_We_Input_TO_X) << endl;
	}

	




}