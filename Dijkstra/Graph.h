#pragma once
#include <vector>
#ifndef GRAPH_H
#define GRAPH_H

struct DirectedGraphNode
{
	std::vector<std::pair<int, int>> incomingEdges;
	std::vector<std::pair<int, int>> outgoingEdges;
	bool seen = false;


};

struct UndirectedGraphNode
{
	int* neighbours;
	int parent;
	int* children;
	int numberOfNeighbours;
	bool seen;
};


class GraphSearch {
public:
	bool dfs(std::vector<DirectedGraphNode>& g, int start, int target);
	bool bfs(std::vector<DirectedGraphNode>& g, int start, int target);
	int dijkstras(std::vector<DirectedGraphNode>& g, int start, int target);
};


#endif // !GRAPH.h
											