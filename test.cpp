// Program to print BFS traversal from a given
// source vertex. BFS(int s) traverses vertices
// reachable from s.
#include <iostream>
#include <vector>
#include <list>
#include "ADT_Graph.h"

using namespace std;


// Driver program to test methods of graph class
int main()
{
	// Create a graph given in the above diagram
	Grafo g(4);
	g.loadGraph(6);

	bool ans;

	ans = g.is_tree();
	(ans == 1) ? cout << "\nIs tree\n": cout << "\nIs not tree\n";

	cout << "Topological sort: ";
	g.topological_sort();
	cout << endl;

	ans = g.bipartite_graph();
	(ans == 1) ? cout << "Is bipartite\n": cout << "Is not bipartite\n";

	return 0;
}
