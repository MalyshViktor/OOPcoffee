#include<iostream>

using namespace std;

class Beverage
{
	int cost;
public:
	virtual double getCost() = 0;
	virtual ~Beverage()
	{
	
	}
};

class Espresso: public Beverage
{
public:
	double getCost()
	{
		return 5.5;
	}

};

class Capuccino : public Beverage
{
public:
	double getCost()
	{
		return 7.5;
	}
};

class Cocoa : public Beverage
{
public:
	double getCost()
	{
		return 8.5;
	}

};


class Ingredients : public Beverage
{
protected:
	Beverage *b;
public:

};

class Sugar: public Ingredients
{
public:
	Sugar(Beverage* b)
	{
		this->b = b;
	}
	double getCost() override
	{
		return b->getCost()+0.25;
	}
	~Sugar()
	{
		cout << "Destructor Sugar" << endl;
		delete b;
	}
};

class Cream: public Ingredients
{

public:
	Cream(Beverage* b)
	{
		this->b = b;
	}
	double getCost() override
	{
		return b->getCost() + 0.75;
	}
	~Cream()
	{
		cout << "Destructor Cream" << endl;
		delete b;
	}
};

class Chocolate: public Ingredients
{

public:
	Chocolate(Beverage* b)
	{
		this->b = b;
	}
	double getCost() override
	{
		return b->getCost() + 0.5;
	}
	~Chocolate()
	{
		cout << "Destructor Chocolate" << endl;
		delete b;
	}
};

int main()
{
	Beverage* B = new Cocoa;
	cout<<B->getCost()<<endl;
	B = new Sugar(B);
	B = new Chocolate(B);
	B = new Cream(B);
	cout<<B->getCost()<<endl;
	delete B;
}