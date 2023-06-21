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
	int usersSize, jobsSize, connectionsSize;
	std::cin >> usersSize >> jobsSize >> connectionsSize;

	BipartiteGraph<std::string> graph(usersSize);

	for (int i = 0; i < connectionsSize; i++)
	{
		std::string from, to;
		std::cin >> from >> to;

		graph.addEdge(from, to);
	}

	std::cout << "Guloso: " << graph.greedyAlgorithm() << std::endl;
	std::cout << "Exato: " << graph.exactAlgorithm() << std::endl;

	return 0;
}
