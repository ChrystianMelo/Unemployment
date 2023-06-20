/**
 * @file BipartiteGraph.hpp
 * @author Chrystian Melo(meloo.chrys@gmail.com)
 * @brief Classe representando um grafo bipartido.
 *
 */

#ifndef GRAPH_HPP
#define GRAPH_HPP

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
			for (T v : m_adjacency[i]) {
				if (visited.find(v) == visited.end()) {
					visited.insert(v);
					matching[i] = v;
					break;
				}
			}
		}

		std::vector<std::pair<int, T>> pairs;
		for (int i = 0; i < m_verticesSize; i++) {
			pairs.push_back({ i, matching[i] });
		}

		return pairs;
	}

	/**
	 * @brief Algoritmo de matching usando programação dinâmica para encontrar a melhor solução possível no grafo bipartido.
	 **/
	std::vector<std::pair<T, T>> dpMatching() {
		std::vector<bool> visited(m_verticesSize, false);
		std::vector<std::pair<T, T>> matches(m_verticesSize);
		std::vector<int> parent(m_verticesSize, -1);

		for (int i = 0; i < m_verticesSize; i++) {
			if (!visited[i]) {
				std::fill(parent.begin(), parent.end(), -1);
				bool found = false;

				// Executa uma DFS a partir do vértice atual
				found = dfs(i, parent, visited);

				if (found) {
					for (int j = 0; j < m_verticesSize; j++) {
						if (parent[j] != -1) {
							matches[j] = (std::make_pair(m_vertices[parent[j]], m_vertices[j]));
							matching[j] = m_vertices[parent[j]];
						}
					}
				}
			}
		}

		return matches;
	}

	/**
	 * @brief
	 **/
	bool dfs(int start, std::vector<int>& parent, std::vector<bool>& visited) {
		visited[start] = true;

		for (int i = 0; i < m_verticesSize; i++) {
			for (T v : m_adjacency[i]) {
				if (!visited[i]) {
					if (matching[i] == T() || dfs(i, parent, visited)) {
						parent[i] = start;
						return true;
					}
				}
			}

		}
		return false;
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
		for (std::size_t i = 0; i < m_verticesSize; i++)
		{
			if (m_vertices[i] == vertex)
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

};
#endif