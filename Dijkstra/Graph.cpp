#include "Graph.h"
// inplementation of DFS to find specific nodes
bool GraphSearch::dfs(std::vector<DirectedGraphNode>& g, int start, int target)
{
	int count = 0;
	int nextNode;
	bool result = false;
	g[start].seen = true; // mark start node as seen
	if (start == target) 
	{
		result = true;
	}
	else
	{ 
		while (count < g[start].outgoingEdges.size() && result != true)
		{
			nextNode = g[start].outgoingEdges[count].first;//get the nextNode to be checked and then increment the count
			count++;
			if (g[nextNode - 1].seen == true)
			{
			//if seen, continue
			}// end if
			else
			{
			result = dfs(g, nextNode - 1, target); // recurse on the graph starting from the nextNode
			}//end else
		}//end while
	}
	if (result == true)
	{
		return true;
	}
	else
	{
		return false;
	}
	
}

bool GraphSearch::bfs(std::vector<DirectedGraphNode>& g, int start, int target)
{
	return false;
}

int GraphSearch::dijkstras(std::vector<DirectedGraphNode>& g, int start, int target)
{
	std::vector<int> pathLengths(g.size(), INT32_MAX);//set the a parts to all nodes to be be infinite(for all intents and purposes)
	int pathLength = 0; // keeps track of the current path length
	std::vector<int> visitedNodes(1, 0); //nodes that have been visited during the search
	int currentNode = start; 
	pathLengths[currentNode] = pathLength;


	while (currentNode != target)
	{
		g[currentNode].seen = true;
		int shortestOutEdge = INT32_MAX; // the shortest edge length is, at first, unknown
		for (int i = 0; i < visitedNodes.size(); i++) //cycle through the edges that have been visited and look for the small one that exits
		{
			int nextToCheck = visitedNodes[i];// the next node from the visited array to whose edges are to be checked.
			int edgeArraySize = g[nextToCheck].outgoingEdges.size(); // the size of the next node's outgoing array
			for (int edge = 0; edge < edgeArraySize; edge++) // take the smallest edge out
			{
				int nextOut = g[nextToCheck].outgoingEdges[edge].first - 1; // adjust node values to fit with array subscript notation
				int edgeLength = g[nextToCheck].outgoingEdges[edge].second;

				if (g[nextOut].seen == false)
				{
					if (edgeLength + pathLength < pathLengths[nextOut])
					{
						pathLengths[nextOut] = edgeLength + pathLength; // set the length of a node that has been encountered to the shortest part found so far
					}
					if (edgeLength < shortestOutEdge)
					{
						shortestOutEdge = edgeLength; //keep track of the small outedge length
						currentNode = nextOut; // and the node to which it travels
					}
				}
			}

		}
		pathLength += shortestOutEdge;
		for (int i = 0; i < g.size(); i++)
		{
			if (g[i].seen == false && pathLengths[i] < pathLength)//if there an alternative route is shorter, change route
			{
				pathLength = pathLengths[i];
				currentNode = i;
			}
		}
		visitedNodes.push_back(currentNode);
	}
	return pathLengths[target];
}
