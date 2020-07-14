#include "Graph.h"
#include<queue>


Graph::Graph(const std::vector<std::vector<size_t>>& v)
{
	for (size_t i{}; i < v.size(); i++)
	{
		mat.push_back(std::vector<size_t>{});
		for (size_t j{}; j < v.size(); j++)
			mat[i].push_back(v[i][j]);
	}
	size = v.size();
	color = std::vector<size_t>(size);
	d = std::vector<size_t>(size);
	p = std::vector<size_t>(size);
	dis = std::vector<size_t>(size);
	f = std::vector<size_t>(size);
}

void BFS(Graph& G, size_t s)
{
	for (size_t i{}; i < G.size; i++)
	{
		if (i != s)
		{
			G.color[i] = 0;
			G.d[i] = 1e5;
			G.p[i] = G.size;
		}
	}
	G.color[s] = 1;
	G.d[s] = 0;
	G.p[s] = G.size;

	std::queue<size_t> Q;
	Q.push(s);
	while (!Q.empty())
	{
		size_t u = Q.front();
		Q.pop();
		for (size_t v{}; v < G.size; v++)
		{
			if (G.mat[u][v] == 1)
			{
				if (G.color[v] == 0)
				{
					G.color[v] = 1;
					G.d[v] = G.d[u] + 1;
					G.p[v] = u;
					Q.push(v);
				}
			}
		}
		G.color[u] = 2;
	}
	std::cout << "BFS result is: { ";
	for (size_t i{}; i < G.size - 1; i++)
	{
		std::cout << G.d[i] << ", ";
	}
	std::cout << G.d[G.size - 1] << " }\n";
}

void print_path(const Graph& G, size_t s, size_t v)
{
	if (v == s)
		std::cout << s << ", ";
	else if (G.p[v] == G.size)
		std::cout << "NO path from " << s
		<< " to " << v << "exists\n";
	else
	{
		print_path(G, s, G.p[v]);
		std::cout << v << ", ";
	}
}


void DFS(Graph& G)
{
	for (size_t u{}; u < G.size; u++)
	{
		G.color[u] = 0;
		G.p[u] = G.size;
	}
	G.time = 0;
	for (size_t u{}; u < G.size; u++)
	{
		if (G.color[u] == 0)
			DSF_visit(G, u);
	}
}

void DSF_visit(Graph & G, size_t u)
{
	G.time++;
	G.dis[u] = G.time;
	G.color[u] = 1;
	for (size_t i{}; i < G.size; i++)
	{
		if (G.mat[u][i] == 1)
			if (G.color[i] == 0)
			{
				G.p[i] = u;
				DSF_visit(G, i);
			}
	}
	G.color[u] = 2;
	G.time++;
	G.f[u] = G.time;
}


Graph::~Graph()
{
}
