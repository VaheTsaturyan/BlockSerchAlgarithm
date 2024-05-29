#include "graph.h"

namespace gph{

Caunt count = 0;

//Edge::Edge(ID u, ID v)

Edge::Edge(ID id1, ID id2)
{
	this->id1_ = id1;
	this->id2_= id2;
}

Graph::Graph(Caunt veritesCaunt)
{
	this->veritasCaunt_ = veritesCaunt;
	this->edgeCaunt_ = 0;
	adj = std::vector<std::list<ID>>(veritesCaunt);
}

void Graph::addEdge(ID id1, ID id2)
{
	adj[id1].push_back(id2);
	++edgeCaunt_;
}

const std::vector<std::unordered_set<ID>>& Graph::getBlocks(){
	return blocks_;
}

void Graph::BCCUtil(ID id1, std::vector<Caunt>& disc, std::vector<Caunt>& low, std::vector<std::list<Edge>>& st,std::vector<ID>& parent)
{
	static int time = 0;
	disc[id1] = low[id1] = ++time;
	int children = 0;

	std::list<ID>::iterator i;

	for (i = adj[id1].begin(); i != adj[id1].end(); ++i) {
		int v = *i;
		if (disc[v] == -1) {
			children++;
			parent[v] = id1;
			st[0].push_back(Edge(id1, v));
			BCCUtil(v, disc, low, st, parent);
			low[id1] = std::min(low[id1], low[v]);
			if ((disc[id1] == 1 && children > 1) || (disc[id1] > 1 && low[v] >= disc[id1])) {
				std::unordered_set<ID> tempSet;
				while (st[0].back().id1_ != id1 || st[0].back().id2_ != v) {
					tempSet.insert(st[0].back().id1_);
					tempSet.insert(st[0].back().id2_);
					st[0].pop_back();
				}
				tempSet.insert(st[0].back().id1_);
				tempSet.insert(st[0].back().id2_);
				st[0].pop_back();
				blocks_.push_back(tempSet);
				count++;
			}
		}
		else if (v != parent[id1]) {
			low[id1] = std::min(low[id1], disc[v]);
			if (disc[v] < disc[id1]) {
				st[0].push_back(Edge(id1, v));
			}
		}
	}
}

void Graph::blockSerch()
{
	std::vector<int> disc(veritasCaunt_);
	std::vector<int> low (veritasCaunt_);
	std::vector<ID> parent(veritasCaunt_);
	std::vector<std::list<Edge>> st = std::vector<std::list<Edge>>(edgeCaunt_);
	for (int i = 0; i < veritasCaunt_; i++) {
		disc[i] = NIL;
		low[i] = NIL;
		parent[i] = NIL;
	}

	for (int i = 0; i < veritasCaunt_; i++) {
		if (disc[i] == NIL)
			BCCUtil(i, disc, low, st, parent);

		int j = 0;
		std::unordered_set<ID> tempSet;
		while (st[0].size() > 0) {
			j = 1;
			tempSet.insert(st[0].back().id1_);
			tempSet.insert(st[0].back().id2_);
			st[0].pop_back();
		}
		if (j == 1) {
			blocks_.push_back(tempSet);	
			count++;
		}
	}
}


} // namespace gph