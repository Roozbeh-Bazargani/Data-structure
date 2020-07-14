#include"Graph.h"

void display_time(const Graph& g);

int main()
{
	std::vector<std::vector<size_t>> v;
	v.push_back(std::vector<size_t> {0, 1, 1, 0});
	v.push_back(std::vector<size_t> {1, 0, 0, 1});
	v.push_back(std::vector<size_t> {1, 0, 0, 1});
	v.push_back(std::vector<size_t> {0, 1, 1, 0});
	Graph g{ v };
	BFS(g, 1);
	print_path(g, 1, 3);
	std::cout << std::endl;
	DFS(g);
	display_time(g);
	return 0;
}

void display_time(const Graph& g)
{
	for (size_t i{}; i < g.size; i++)
		std::cout << "Vertex(" << i << "): " << g.dis[i]
			<< ":" << g.f[i] << "\n";
}