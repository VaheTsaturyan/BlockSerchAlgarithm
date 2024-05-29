#include "output.h"

namespace gph {


void outputInCansol(const std::vector<std::unordered_set<ID>>& blocks){
	for(auto block : blocks){
		for(auto verites : block){
			std::cout<<verites<<"\t";
		}
		std::cout<<std::endl;
	}
	std::cout << "Above are " << blocks.size() << " biconnected components in graph\n";
}


}// namemspace gph