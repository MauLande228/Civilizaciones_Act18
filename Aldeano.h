#pragma once

#include<iostream>
#include<iomanip>
#include<string>

class Aldeano {
private:
	std::string name;
	std::string gender;
	size_t age;
	size_t health;

public:
	Aldeano();
	Aldeano(const std::string&, const size_t&, const std::string&, const size_t&);

	void setName(const std::string&);
	void setGender(const std::string&);
	void setAge(const size_t&);
	void setHealth(const size_t&);

	std::string getName();
	std::string getGender();
	size_t getAge() const;
	size_t getHealth() const;

	friend std::ostream& operator << (std::ostream& out, Aldeano& a) {
		out << std::left;
		out << std::setw(20) << a.name;
		out << std::setw(20) << a.age;
		out << std::setw(20) << a.gender;
		out << std::setw(20) << a.health;
		out << std::endl;

		return out;
	}

	friend std::istream& operator >> (std::istream& in, Aldeano& a) {
		std::cin.ignore();
		std::cout << "Nombre de aldeano: ";
		std::getline(std::cin, a.name);

		std::cout << "Edad del aldeano: ";
		std::cin >> a.age;

		std::cin.ignore();
		std::cout << "Genero del aldeano: ";
		std::getline(std::cin, a.gender);

		std::cout << "Salud del aldeano: ";
		std::cin >> a.health;

		return in;
	}

	bool operator == (const Aldeano& a)const {
		return name == a.name;
	}

	bool operator < (const Aldeano& a)const {
		return name < a.name;
	}
};