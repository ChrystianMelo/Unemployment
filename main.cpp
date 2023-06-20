/**
 * @file Main.cc
 * @author Chrystian Melo (meloo.chrys@gmail.com)
 * @brief Classe principal do projeto.
 *
 * @copyright Copyright (c) 2023
 */
#include <iostream>
#include <cassert>
#include <fstream>

#include "BipartiteGraph.hpp"


/**
 * @brief Classe principal do projeto.
 **/
int main(int argc, char const* argv[])
{
	std::string inputFilename("C:\\Users\\Chrystian Melo\\Documents\\Alg1\\Unemployment\\test_cases\\inputs\\test_case0.txt");

	std::ifstream myfileInput(inputFilename);
	assert(myfileInput);

	int usersSize, jobsSize, connectionsSize;
	myfileInput >> usersSize >> jobsSize >> connectionsSize;

	BipartiteGraph<std::string> graph(usersSize);

	// Adiciona os vertices e arestas.
	for (int i = 0; i < connectionsSize; i++)
	{
		std::string from, to;
		myfileInput >> from >> to;

		graph.addEdge(from, to);
	}

	std::cout << "Guloso: " << graph.greedyMatching().size() << std::endl;
	std::cout << "Exato: " << graph.dpMatching().size() << std::endl;

	return 0;
}