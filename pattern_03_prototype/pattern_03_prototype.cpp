/*
Завдання 3. Самостійно розібрати патерн Прототип.
Продемонструвати створення  різних видів зброї для деякої  гри(можна доповнити задачу про юніти). 
У програмі визначити масив з об’єктів зброї(прототипів). Застосувати патерн Прототип.

*/

#include "stdafx.h"
#include <iostream> 
#include <string>



using namespace std;

class Unit {
private:

	string name;
	int hp;
	int damage;

public:
	// конструктори
	Unit() : Unit("Unit", 10, 5) {}

	Unit(string name, int hp, int damage) 
	{
		setName(name);
		setHp(hp);
		setDamage(damage);
		
	}
	// ---

	string getName() const 
	{
		return name;
	}

	void setName(string newName) 
	{
		name = newName;
	}

	int getHp()const
	{
		return hp;
	}

	void setHp(int newHp)
	{
		hp = newHp;
	}

	int getDamage()const
	{
		return damage;
	}

	void setDamage(int newDamage)
	{
		damage = newDamage;
	}

	// віртуальна функція, для створення копій
	virtual Unit* Clone() const = 0;

	// вивід даних по юніту
	virtual void Show() const = 0;
	
	//	cout << "\nUnit:\t" << getName() << "\nHP:\t" << getHp() << "\nDamage:\t" << getDamage() << endl;
	
};


class Marines : public Unit {
private:

	string name;
	int hp;
	int damage;

public:

	// конструктори
	Marines() :Marines("Marines", 25, 20)
	{
		setName("Marines");
		setHp(25);
		setDamage(20);
	}

	Marines(string name, int hp, int damage)
	{
		setName("Marines");
		setHp(hp);
		setDamage(damage);
	}

public:
	string getName() const
	{
		return name;
	}

	void setName(string newName)
	{
		name = newName;
	}

	int getHp()const
	{
		return hp;
	}

	void setHp(int newHp)
	{
		hp = newHp;
	}

	int getDamage()const
	{
		return damage;
	}

	void setDamage(int newDamage)
	{
		damage = newDamage;
	}

	//реалізація віртуальної функції в нащадку
	Unit* Clone()const
	{
		Marines* tempUnit = new Marines (*this);
		return tempUnit;
	}

	void Show() const
	{
		cout << "\nUnit:\t" << getName() << "\nHP:\t" << getHp() << "\nDamage:\t" << getDamage() << endl;
	}
};


class MilitaryDoctor : public Unit {
private:

	string name;
	int hp;
	int damage;

public:

	// конструктори
	MilitaryDoctor() :MilitaryDoctor("MilitaryDoctor", 20, 15)
	{
		setName("MilitaryDoctor");
		setHp(20);
		setDamage(15);
	}

	MilitaryDoctor(string name, int hp, int damage)
	{
		setName("MilitaryDoctor");
		setHp(hp);
		setDamage(damage);
	}

public:
	string getName() const
	{
		return name;
	}

	void setName(string newName)
	{
		name = newName;
	}

	int getHp()const
	{
		return hp;
	}

	void setHp(int newHp)
	{
		hp = newHp;
	}

	int getDamage()const
	{
		return damage;
	}

	void setDamage(int newDamage)
	{
		damage = newDamage;
	}

	//реалізація віртуальної функції в нащадку
	Unit* Clone()const
	{
		MilitaryDoctor* tempUnit = new MilitaryDoctor(*this);
		return tempUnit;
	}

	void Show() const
	{
		cout << "\nUnit:\t" << getName() << "\nHP:\t" << getHp() << "\nDamage:\t" << getDamage() << endl;
	}
};

class CrazyScientist : public Unit {
private:

	string name;
	int hp;
	int damage;

public:

	// конструктори
	CrazyScientist() :CrazyScientist("CrazyScientist", 15, 10)
	{
		setName("CrazyScientist");
		setHp(15);
		setDamage(10);
	}

	CrazyScientist(string name, int hp, int damage)
	{
		setName("CrazyScientist");
		setHp(hp);
		setDamage(damage);
	}

public:
	string getName() const
	{
		return name;
	}

	void setName(string newName)
	{
		name = newName;
	}

	int getHp()const
	{
		return hp;
	}

	void setHp(int newHp)
	{
		hp = newHp;
	}

	int getDamage()const
	{
		return damage;
	}

	void setDamage(int newDamage)
	{
		damage = newDamage;
	}

	//реалізація віртуальної функції в нащадку
	Unit* Clone()const
	{
		CrazyScientist* tempUnit = new CrazyScientist(*this);
		return tempUnit;
	}

	void Show() const
	{
		cout << "\nUnit:\t" << getName() << "\nHP:\t" << getHp() << "\nDamage:\t" << getDamage() << endl;
	}
};

class Prototype
{
public:

	Unit* prototype(Unit* unit)
	{
		
		Unit* copy = unit->Clone();
		cout << "\n\tPrototype:";
		unit->Show();
		cout << "\n\tClone:";
		copy->Show();
		cout << "__  __  __  __  __\n";
		return copy;
	}
};



int main()
{


	Unit* arr[3] = { new Marines, new MilitaryDoctor, new CrazyScientist };

	Prototype p;
	Unit* u;

	for (int i = 0; i < 3; i++)
		u = p.prototype(arr[i]);
	
	delete u;
	for (int i = 0; i < 3; i++)
		delete arr[i];


	cout << endl;
	system("pause");
	return 0;

}