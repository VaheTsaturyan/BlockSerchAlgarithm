#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <unordered_set>

namespace gph {
	
inline const int NIL = -1;
using ID = int;
using Caunt = int;


class Edge {
public:
	ID id1_;
	ID id2_;
	Edge(ID id1, ID id2);
};

class Graph {

public:
	
	Graph(ID veritesCaunt); 
	void addEdge(ID id1, ID id2); 
	void blockSerch();
	const std::vector<std::unordered_set<ID>>& getBlocks();

private:
	
	void BCCUtil(ID u, std::vector<Caunt>& disc, std::vector<Caunt>& low, std::vector<std::list<Edge>>& st,std::vector<ID>& parent);
	
private:
	
	std::vector<std::unordered_set<ID>> blocks_;
	std::vector<std::list<ID>> adj;
	Caunt veritasCaunt_;
	Caunt edgeCaunt_; 

};


} // namespace gph