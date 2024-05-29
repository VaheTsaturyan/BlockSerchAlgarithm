#include "graph.h"
#include "output.h"
#include "input.h"


int main()
{
	gph::Json jsonObj =  gph::open_file_give_jsonObj();
	std::unordered_map<gph::ID, std::vector<gph::ID>> map =  gph::conv_to_map(jsonObj);
	gph::Graph graph(map.size());
	gph::create_adj_matrix(map, graph);
	graph.blockSerch();
	auto b = graph.getBlocks();
	gph::outputInCansol(b);
	return 0;
}
