#include"Aldeano.h"

Aldeano::Aldeano() : name("NO_NAME"), age(0), gender("NO_GENDER"), health(0) {}

Aldeano::Aldeano(const std::string& name, const size_t& age, const std::string& gender, const size_t& health) {
	this->name = name;
	this->age = age;
	this->gender = gender;
	this->health = health;
}

void Aldeano::setName(const std::string& name) {
	this->name = name;
}

void Aldeano::setAge(const size_t& age) {
	this->age = age;
}

void Aldeano::setGender(const std::string& gender) {
	this->gender = gender;
}

void Aldeano::setHealth(const size_t& health) {
	this->health = health;
}

std::string Aldeano::getName() {
	return name;
}

size_t Aldeano::getAge()const {
	return age;
}

std::string Aldeano::getGender() {
	return gender;
}

size_t Aldeano::getHealth()const {
	return health;
}