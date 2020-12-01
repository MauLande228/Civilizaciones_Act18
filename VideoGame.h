#pragma once

#include<vector>
#include<algorithm>
#include"Civilizacion.h"

class VideoGame {
private:
	std::string userName;
	std::vector<Civilizacion> game;

public:
	VideoGame();
	VideoGame(const std::string&, const std::vector<Civilizacion>&);

	void setUname(const std::string&);
	void agregarCivilizacion(const Civilizacion&);
	void insertar(const Civilizacion&, const size_t&);
	void inicializar(const Civilizacion&, const size_t&);
	void eliminar(const std::string&);
	void ordenarNombre();
	void ordenarXpos();
	void ordenarYpos();
	void ordenarPuntaje();
	void mostrar();

	std::string getUname()const;
	size_t total();
	Civilizacion& primera();
	Civilizacion& ultima();
	Civilizacion* buscar(const Civilizacion&);

	friend VideoGame& operator << (VideoGame& vg, const Civilizacion c) {
		vg.agregarCivilizacion(c);

		return vg;
	}
};