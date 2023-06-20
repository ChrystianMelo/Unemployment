/**
 * @file BipartiteGraph.hpp
 * @author Chrystian Melo(meloo.chrys@gmail.com)
 * @brief Classe representando um grafo bipartido.
 *
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <algorithm>
#include <iostream>
#include <utility>
#include <functional>
#include <vector>
#include <limits>
#include <queue>
#include <cassert>
#include <unordered_set>

template <typename T>
class BipartiteGraph {
private:
	/**
	 * @brief Vertices do grafo.
	 */
	std::vector<T> m_vertices;

	/**
	 * @brief Vertices do grafo.
	 */
	std::vector<T> m_vertices2;

	/**
	 * @brief .
	 */
	int m_verticesSize;

	/**
	 * @brief
	 **/
	std::vector<std::vector<T>> m_adjacency;

	/**
	 * @brief
	 **/
	std::vector<T> matching;

public:
	/**
	 * @brief
	 **/
	BipartiteGraph(int n) : m_verticesSize(n) {
		m_adjacency.resize(m_verticesSize);
	}

	/**
	 * @brief
	 **/
	void addEdge(T v1, T v2) {
		// Adiciona o vertice, se necessário.
		addVertex(v1);
		addVertex2(v2);

		// Recupera o indice dos verices
		int i1 = getIndex(v1);

		// Adiciona a aresta
		m_adjacency[i1].push_back(v2);
	}

	/**
	 * @brief
	 **/
	std::vector<std::pair<int, T>> greedyMatching() {
		matching.assign(m_verticesSize, T());
		std::unordered_set<T> visited;

		for (int i = 0; i < m_verticesSize; i++) {
			if (matching[i].empty()) {
				for (T v : m_adjacency[i]) {
					if (visited.find(v) == visited.end()) {
						visited.insert(v);
						matching[i] = v;
						break;
					}
				}
			}
		}

		std::vector<std::pair<int, T>> pairs;
		for (int i = 0; i < m_verticesSize; i++) {
			if (!matching[i].empty()) {
				pairs.push_back({ i, matching[i] });
			}
		}

		return pairs;
	}

	/**
	 * @brief Algoritmo de matching usando programação dinâmica para encontrar a melhor solução possível no grafo bipartido.
	 **/
	int dpMatching() {
		int m = m_vertices.size();
		int n = m_vertices2.size();

		std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (m_adjacency[i - 1].size() > 0) {
					// Verificar todas as opções de casamento para o vértice i da parte a
					for (T v : m_adjacency[i - 1]) {
						// Escolher a opção com o maior número de arestas
						dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
					}
				}
				// Caso não haja casamento para o vértice i da parte a
				dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
			}
		}

		return dp[m][n];
	}
private:
	/**
	* @brief Retorna o �ndice do v�rtice no grafo.
	*
	* @param vertex O v�rtice a ser adicionado.
	* @return O �ndice do v�rtice no grafo. Se n�o for encontrado, retorna T().
	**/
	int getIndex(T vertex)
	{
		for (std::size_t i = 0; i < m_vertices.size(); i++)
		{
			if (m_vertices[i] == vertex)
			{
				return i;
			}
		}
		for (std::size_t i = 0; i < m_vertices2.size(); i++)
		{
			if (m_vertices2[i] == vertex)
			{
				return i;
			}
		}
		return -1;
	}

	/**
	 * @brief
	 **/
	void addVertex(T v) {
		// Adiciona o vertice
		if (std::find(m_vertices.begin(), m_vertices.end(), v) == m_vertices.end())
			m_vertices.push_back(v);
	}

	/**
	 * @brief
	 **/
	void addVertex2(T v) {
		// Adiciona o vertice
		if (std::find(m_vertices2.begin(), m_vertices2.end(), v) == m_vertices2.end())
			m_vertices2.push_back(v);
	}
};
#endif
