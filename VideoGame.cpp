#include"VideoGame.h"

VideoGame::VideoGame() : userName("Guest") {}

VideoGame::VideoGame(const std::string& userName, const std::vector<Civilizacion>& game) {
	this->userName = userName;
	this->game = game;
}

void VideoGame::setUname(const std::string& userName) {
	this->userName = userName;

}

void VideoGame::agregarCivilizacion(const Civilizacion& civilizacion) {
	game.push_back(civilizacion);
}

void VideoGame::insertar(const Civilizacion& civilizacion, const size_t& pos) {
	game.insert(game.begin() + pos, civilizacion);
}

void VideoGame::inicializar(const Civilizacion& civilizacion, const size_t& cantidad) {
	game = std::vector<Civilizacion>(cantidad, civilizacion);
}

void VideoGame::eliminar(const std::string& name) {
	int count = 0;
	Civilizacion aux;
	Civilizacion* cDir;
	aux.setName(name);
	cDir = buscar(aux);

	while (game[count] != *cDir) {
		count++;
	}

	if (cDir == nullptr) std::cout << "No se encontro la civilizacion" << std::endl;
	else {
		game.erase(game.begin() + count);
	}

}

void VideoGame::ordenarNombre() {
	std::sort(game.begin(), game.end(),
		[](Civilizacion c1, Civilizacion c2) {return c1.getName() < c2.getName(); });
}

void VideoGame::ordenarXpos() {
	std::sort(game.begin(), game.end(),
		[](Civilizacion c1, Civilizacion c2) {return c1.getXpos() < c2.getXpos(); });
}

void VideoGame::ordenarYpos() {
	std::sort(game.begin(), game.end(),
		[](Civilizacion c1, Civilizacion c2) {return c1.getYpos() < c2.getYpos(); });
}

void VideoGame::ordenarPuntaje() {
	std::sort(game.begin(), game.end(),
		[](Civilizacion c1, Civilizacion c2) {return c1.getScore() > c2.getScore(); });
}

void VideoGame::mostrar() {
	std::cout << std::left;
	std::cout << userName << std::endl << std::endl;
	std::cout << std::setw(20) << "Civilizacion";
	std::cout << std::setw(20) << "Posicion en X";
	std::cout << std::setw(20) << "Posicion en Y";
	std::cout << std::setw(20) << "Puntaje";

	for (size_t i = 0; i < game.size(); i++) {
		Civilizacion& myCiv = game[i];

		std::cout << myCiv;
	}
}

std::string VideoGame::getUname()const {
	return userName;
}

Civilizacion& VideoGame::primera() {
	return game.front();
}

Civilizacion& VideoGame::ultima() {
	return game.back();
}

size_t VideoGame::total() {
	return game.size();
}

Civilizacion* VideoGame::buscar(const Civilizacion& civilizacion) {
	auto civ = std::find(game.begin(), game.end(), civilizacion);

	if (civ == game.end()) return nullptr;
	else return &(*civ);
}
