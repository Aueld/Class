#include <iostream>

using namespace std;

class Data
{
	int hp;
	int attack;
	float exp;
public:
	void SetData(int hpData, int attackData, float expData)
	{
		hp = hpData;
		attack = attackData;
		exp = expData;
	}

	void SetData(Data data)
	{
		// 같은 클래스끼리는 private여도 접근 가능
		hp = data.hp;
		attack = data.attack;
		exp = data.exp;
	}

	int GetHp()
	{
		return hp;
	}

	int GetAttack()
	{
		return attack;
	}

	float GetExp()
	{
		return exp;
	}
};

class Seller
{
	int objPrice;
	int numOfObj;
	int money;

public:
	void InitMembers(int price, int num, int mo)
	{
		objPrice = price;
		numOfObj = num;
		money = mo;
	}

	int SaleObj(int mo)
	{
		int num = mo / objPrice;
		numOfObj -= num;
		money += mo;
		return num;
	}

	void ShowSaleResult()
	{
		cout << "Seller" << endl;
		cout << "남은 물건 : " << numOfObj << endl;
		cout << "판매 수익 : " << endl << endl;
	}
};

class Buyer
{
	int money;
	int numOfObj;

public:
	void InitMembers(int mo)
	{
		money = mo;
		numOfObj = 0;
	}

	void BuyObj(Seller& seller, int mo)
	{
		numOfObj += seller.SaleObj(mo);
		money -= mo;
	}

	void ShowBuyResult()
	{
		cout << "Buyer" << endl;
		cout << "현재 잔액 : " << money << endl;
		cout << "물건 개수 : " << numOfObj << endl << endl;
	}
};

int main()
{
	Data data;
	
	data.SetData(100, 10, 0);

	cout << data.GetHp() << endl;

	Seller seller;
	seller.InitMembers(1000, 20, 0);
	
	Buyer buyer;
	buyer.InitMembers(5000);

	seller.ShowSaleResult();
	buyer.ShowBuyResult();

	buyer.BuyObj(seller, 2000);

	seller.ShowSaleResult();
	buyer.ShowBuyResult();


	return 0;
}
