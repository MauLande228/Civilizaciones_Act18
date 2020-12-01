#include "Civilizacion.h"

Civilizacion::Civilizacion() : name("NO_NAME"), score(0), xPos(-1), yPos(-1) {}

Civilizacion::Civilizacion(const std::string& name, const int& xPos, const int& yPos, const int& score) {
	this->name = name;
	this->xPos = xPos;
	this->yPos = yPos;
	this->score = score;
}

void Civilizacion::setName(const std::string& name) {
	this->name = name;
}

void Civilizacion::setXpos(const int& xPos) {
	this->xPos = xPos;
}

void Civilizacion::setYpos(const int& yPos) {
	this->yPos = yPos;
}

void Civilizacion::setScore(const int& score) {
	this->score = score;
}

std::string Civilizacion::getName() {
	return name;
}

int Civilizacion::getXpos() {
	return xPos;
}
int Civilizacion::getYpos() {
	return yPos;
}

int Civilizacion::getScore() {
	return score;
}

void Civilizacion::agregarAldeanoInicio(const Aldeano& aldeano) {
	poblacion.push_front(aldeano);
}

void Civilizacion::agregarAldeanoFinal(const Aldeano& aldeano) {
	poblacion.push_back(aldeano);
}

void Civilizacion::eliminarPorNombre(const std::string& nombre) {
	for (auto it = poblacion.begin(); it != poblacion.end(); it++) {
		Aldeano& a = *it;

		if (nombre == a.getName()) {
			poblacion.erase(it);
			break;
		}
	}
}

void Civilizacion::mostrar() {
	std::cout << std::left;
	std::cout << std::setw(20) << "Nombre";
	std::cout << std::setw(20) << "Edad";
	std::cout << std::setw(20) << "Genero";
	std::cout << std::setw(20) << "Salud";

	for (auto it = poblacion.begin(); it != poblacion.end(); it++) {
		std::cout << *it << std::endl;
	}
}

void Civilizacion::elminarSaludMenorA(const size_t& salud) {
	poblacion.remove_if([salud](const Aldeano& a) {return a.getHealth() < salud; });
}

void Civilizacion::eliminarEdad() {
	poblacion.remove_if([](const Aldeano& a) {return a.getAge() >= 60; });
}

void Civilizacion::ordenarNombre() {
	poblacion.sort();
}

void Civilizacion::ordenarEdad() {
	poblacion.sort([](const Aldeano& a1, const Aldeano& a2) {return a1.getAge() > a2.getAge(); });
}

void Civilizacion::ordenaSalud() {
	poblacion.sort([](const Aldeano& a1, const Aldeano& a2) {return a1.getHealth() > a2.getHealth(); });
}

Aldeano* Civilizacion::buscar(const Aldeano& aldeano) {
	auto aldeanoAux = std::find(poblacion.begin(), poblacion.end(), aldeano);

	if (aldeanoAux == poblacion.end()) return nullptr;
	else return &(*aldeanoAux);
}