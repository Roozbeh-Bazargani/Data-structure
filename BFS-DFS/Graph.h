#pragma once
#include<vector>
#include<iostream>

class Graph
{
public:
	Graph(const std::vector<std::vector<size_t>>&);
	~Graph();
	std::vector<std::vector<size_t>> mat;
	std::vector<size_t> color;
	std::vector<size_t> d;
	std::vector<size_t> p;
	std::vector<size_t> dis;
	std::vector<size_t> f;
	size_t size;
	size_t time;
};

void BFS(Graph&, size_t);
void print_path(const Graph&, size_t, size_t);
void DFS(Graph&);
void DSF_visit(Graph& G, size_t u);
