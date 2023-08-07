#include "CPP_OOP_08_Calc.h"

// CPP: 정의부, 구현부
// inline 생략, 자동 inline 화
CPP_OOP_08_Calc::CPP_OOP_08_Calc(int value)
    : value(value)
{}

// :: 클래스 소속
CPP_OOP_08_Calc& CPP_OOP_08_Calc::Add(int value)
{
    this->value += value; return *this;
}

CPP_OOP_08_Calc& CPP_OOP_08_Calc::Sub(int value)
{
    this->value -= value; return *this;
}

CPP_OOP_08_Calc& CPP_OOP_08_Calc::Mul(int value)
{
    this->value *= value; return *this;
}

CPP_OOP_08_Calc& CPP_OOP_08_Calc::Div(int value)
{
    this->value /= value; return *this;
}

CPP_OOP_08_Calc& CPP_OOP_08_Calc::Mod(int value)
{
    this->value %= value; return *this;
}
