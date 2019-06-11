#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "Graph.h"

#define GRAPHSIZE 200



int main()
{
	std::ifstream inputFile;
	std::string fileName = "DijkstraData.txt";
	inputFile.open(fileName);
	std::string nextFromFile = "", nextPiece = "";
	int currentNode = 0;
	std::vector<DirectedGraphNode> myGraph(GRAPHSIZE);
	std::vector<int> result;
	int start, target;
	GraphSearch searchTools;

	if (inputFile.is_open())
	{
		while(true)
			if (inputFile.fail())
			{
				break;
			}
			else
			{
				inputFile >> nextFromFile;
				
				if (nextFromFile.find(',') != std::string::npos)
				{
					std::stringstream separateString(nextFromFile);
					std::vector<int> mypair;
					while (getline(separateString, nextPiece, ','))
					{
						if (currentNode == 200)
						{
							currentNode = 200;
						}
						mypair.push_back(std::stoi(nextPiece));
					}
					std::pair<int, int> nextPair(mypair[0], mypair[1]);
					myGraph[currentNode - 1].outgoingEdges.push_back(nextPair);
				}
				else
				{
					currentNode++;
					
				}
			}
	}
	else
	{
		std::cout << "Unable to open " << fileName << std::endl;
	}
	inputFile.close();

	//myGraph[currentNode - 1].outgoingEdges.pop_back(); // remove the duplicate edge that was added to the last node. This is a bug, I am not sure about it's origin.
	int findThis = 196;
	int pathLength = searchTools.dijkstras(myGraph, 0, findThis);

	std::cout << "The shortest length from 1 to " << findThis + 1 << " is :  " << pathLength << std::endl;
}


