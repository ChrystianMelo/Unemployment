# Unemployment

# Introdução
Willie Gates é o CEO de uma grande rede social chamada LinkOut. No entanto, a rede está enfrentando uma crise significativa e está buscando maneiras de aumentar o engajamento dos usuários. O principal objetivo da LinkOut é conectar os usuários às vagas de emprego ideais. Infelizmente, Willie está recebendo muitas reclamações de usuários que não estão sendo recomendados para nenhuma vaga, enquanto seus colegas com qualificações semelhantes estão recebendo várias oportunidades de emprego. Desesperado, Willie contratou um especialista em algoritmos para desenvolver uma solução que pudesse garantir o maior número possível de vagas para os usuários, a fim de resolver os problemas relatados na rede. Felizmente, Willie possui um algoritmo altamente eficaz que determina se um usuário é adequado ou não para uma determinada vaga. Esses dados podem ser representados como um grafo bipartido, onde uma aresta candidato-vaga existe se o candidato atende aos requisitos da vaga. 
Preocupado com a rápida queda no número de usuários da LinkOut, o especialista sugeriu a utilização de um Proof of Concept para o problema, propondo uma abordagem gulosa de baixa complexidade que encontra uma solução de forma rápida. Willie aprovou a ideia, com a condição de que, assim que a solução gulosa estivesse pronta, o especialista também implementasse outro algoritmo que sempre encontrasse a melhor solução possível. 
O projeto proposto é implementar dois algoritmos que encontrem pares únicos de usuários e vagas para o maior número possível de usuários em uma rede. Em seguida, comparar ambas as soluções, destacando as vantagens e desvantagens de cada algoritmo.


# Modelagem
O projeto consiste na implementação da classe BipartiteGraph, que representa um grafo bipartido. Essa classe utiliza a estrutura de matriz de adjacência para armazenar as relações entre os vértices do grafo. Essa abordagem permite a implementação eficiente de algoritmos aproveitando a estrutura de dados para percorrer e encontrar pares correspondentes entre os conjuntos de vértices.
A classe BipartiteGraph possui os seguintes membros:
m_vertices: Um vetor que armazena os vértices do primeiro conjunto(Nome dos candidatos) do grafo. 
m_vertices2: Um vetor que armazena os vértices do segundo conjunto(Vagas disponiveis) do grafo. 
m_verticesSize: Um inteiro que representa o número total de vértices do primeiro conjunto(Nome dos candidatos) do grafo. 
m_adjacency: Uma matriz de adjacência que armazena as arestas do grafo. 
m_matching: Um vetor que armazena o emparelhamento encontrado pelo algoritmo.
Foram utilizados algoritmos para fazer o emparelhamento do grafo(Greedy e DynamicProgramming). Além de alguns métodos comuns (como addVertex e addEdge) juntamente com utilitários (como getIndex), para definir a classe.

# Implementação
Greedy Algorithm  (algoritmo guloso)
Esse algoritmo busca encontrar pares de usuários e vagas de forma rápida e simples, seguindo uma estratégia gananciosa. Ele percorre os candidatos e, para cada um deles, verifica se já foi recomendado para uma vaga. Caso não tenha sido, ele procura uma vaga que atenda aos requisitos do candidato e o emparelha com essa vaga. Esse processo é repetido até que todos os candidatos sejam avaliados. O algoritmo retorna uma lista de pares de usuários e vagas encontradas. 
Ele tem uma complexidade de O(V * E), onde V é o número de vértices e E é o número de arestas do grafo.
Lógica utilizada:
Inicialmente, todos os vértices do conjunto A do grafo são marcados como não emparelhados. 
Para cada vértice no conjunto A, o algoritmo percorre suas arestas adjacentes e tenta emparelhá-lo com um vértice do conjunto B que ainda não está emparelhado. 
O algoritmo seleciona o primeiro vértice disponível no conjunto B e realiza o emparelhamento. 
Esse processo é repetido para cada vértice no conjunto A. 
Ao final, o algoritmo retorna o conjunto de pares correspondentes encontrados.

exact Algorithm (algoritmo por programação dinâmica). 
Esse algoritmo busca encontrar a melhor solução possível para o problema, levando em consideração o maior número de pares de usuários e vagas que podem ser formados. Ele utiliza uma abordagem de programação dinâmica para calcular uma pontuação que representa a qualidade dos emparelhamentos. O algoritmo percorre os candidatos e vagas e, para cada um deles, calcula a pontuação máxima levando em conta as combinações anteriores. No final, ele retorna a pontuação máxima encontrada.
Ele tem uma complexidade de O(V^2 * E), onde V é o número de vértices e E é o número de arestas do grafo.
Lógica utilizada:
O algoritmo cria uma matriz de programação dinâmica, onde cada célula representa o número máximo de arestas emparelhadas considerando os vértices até aquele ponto. 
O algoritmo percorre a matriz de forma iterativa, preenchendo cada célula com o valor máximo possível de arestas emparelhadas. 
Para calcular o valor de cada célula, o algoritmo considera as opções de emparelhamento para o vértice atual e escolhe aquela que resulta no maior número de arestas emparelhadas. 
Ao final, o valor na célula de maior índice na matriz representa o número máximo de arestas emparelhadas possível no grafo bipartido. 
Além disso, o algoritmo pode rastrear os pares correspondentes encontrados durante o processo, se necessário.

Conclusão
Em resumo, o algoritmo guloso é mais rápido e adequado para grafos grandes, pois tem uma complexidade linear em relação ao número de vértices e arestas. Enquanto o algoritmo usando programação dinâmica é mais preciso, mas pode ser mais lento, pois sua complexidade é quadrática em relação ao número de vértices, especialmente em grafos com muitos vértices. 
A escolha do melhor algoritmo depende do contexto e das características específicas do grafo em questão. Se o desempenho e a eficiência forem fatores críticos, especialmente em grafos grandes, o algoritmo guloso pode ser preferível. Por outro lado, se a precisão do emparelhamento for mais importante e o tamanho do grafo for gerenciável, o algoritmo usando programação dinâmica pode fornecer resultados mais precisos.

