#pragma once // 중복시 한번만 선언
class CPP_OOP_08_Calc // 헤더: 선언부
{
	int value;
	
	public:
		CPP_OOP_08_Calc(int value);
	
		CPP_OOP_08_Calc& Add(int value);
		CPP_OOP_08_Calc& Sub(int value);
		CPP_OOP_08_Calc& Mul(int value);
		CPP_OOP_08_Calc& Div(int value);
		CPP_OOP_08_Calc& Mod(int value);
};
