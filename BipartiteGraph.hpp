/**
 * @file BipartiteGraph.hpp
 * @brief Classe representando um grafo bipartido.
 * @author Chrystian Melo (meloo.chrys@gmail.com)
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
	 * @brief Vertices da primeira parte do grafo.
	 */
	std::vector<T> m_vertices;

	/**
	 * @brief Vertices da segunda parte do grafo.
	 */
	std::vector<T> m_vertices2;

	/**
	 * @brief Tamanho dos vértices.
	 */
	int m_verticesSize;

	/**
	 * @brief Matriz de adjacência.
	 **/
	std::vector<std::vector<T>> m_adjacency;

	/**
	 * @brief Vetor de emparelhamento.
	 **/
	std::vector<T> m_matching;

public:
	/**
	 * @brief Construtor da classe BipartiteGraph.
	 * 
	 * @param n O tamanho do grafo.
	 **/
	BipartiteGraph(int n) : m_verticesSize(n) {
		m_adjacency.resize(m_verticesSize);
	}

	/**
	 * @brief Adiciona uma aresta ao grafo bipartido.
	 * 
	 * @param v1 O primeiro vértice da aresta.
	 * @param v2 O segundo vértice da aresta.
	 **/
	void addEdge(T v1, T v2) {
		addVertex(v1);
		addVertex2(v2);

		m_adjacency[getIndex(v1)].push_back(v2);
	}

	/**
	 * @brief Realiza o emparelhamento guloso no grafo bipartido.
	 * 
	 * @return Quantidade de pares emparelhados.
	 **/
	int greedyAlgorithm() {
		m_matching.assign(m_verticesSize, T());
		std::unordered_set<T> visited;

		for (int i = 0; i < m_verticesSize; i++) {
			if (m_matching[i].empty()) {
				for (T v : m_adjacency[i]) {
					if (visited.find(v) == visited.end()) {
						visited.insert(v);
						m_matching[i] = v;
						break;
					}
				}
			}
		}

		std::vector<std::pair<int, T>> pairs;
		for (int i = 0; i < m_verticesSize; i++) {
			if (!m_matching[i].empty()) {
				pairs.push_back({ i, m_matching[i] });
			}
		}

		return pairs.size();
	}

	/**
	 * @brief Algoritmo usando programação dinâmica para encontrar a melhor solução possível no grafo bipartido.
	 * 
	 * @return O número máximo de emparelhamentos.
	 **/
	int exactAlgorithm() {
		int m = m_vertices.size();
		int n = m_vertices2.size();

		std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				if (m_adjacency[i - 1].size() > 0) {
					for (T v : m_adjacency[i - 1]) {
						dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
					}
				}
				dp[i][j] = std::max(dp[i][j], dp[i - 1][j]);
			}
		}

		return dp[m][n];
	}

private:
	/**
	 * @brief Retorna o índice do vértice no grafo.
	 * 
	 * @param vertex O vértice a ser adicionado.
	 * 
	 * @return O índice do vértice no grafo. Se não for encontrado, retorna -1.
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
	 * @brief Adiciona um vértice ao grafo.
	 * 
	 * @param v O vértice a ser adicionado.
	 **/
	void addVertex(T v) {
		if (std::find(m_vertices.begin(), m_vertices.end(), v) == m_vertices.end())
			m_vertices.push_back(v);
	}

	/**
	 * @brief Adiciona um vértice à segunda parte do grafo.
	 * 
	 * @param v O vértice a ser adicionado.
	 **/
	void addVertex2(T v) {
		if (std::find(m_vertices2.begin(), m_vertices2.end(), v) == m_vertices2.end())
			m_vertices2.push_back(v);
	}
};

#endif