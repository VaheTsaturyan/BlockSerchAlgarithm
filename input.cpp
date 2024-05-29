#include "input.h"

namespace gph {

Json open_file_give_jsonObj(){
    
	std::string path = "graph.json";
   
    std::ifstream file(path);
    if (!file.is_open()) {
        std::exit(0);
    }
    Json data;
    try{
        file >> data;
    }
    catch(const nlohmann::detail::parse_error e) {
        std::exit(0);
    }
	file.close();
    return data;
}


std::unordered_map<int , std::vector<int>> conv_to_map(Json jsonData){
    std::unordered_map<int, std::vector<int>> map_data;
    for (auto& [key, value] : jsonData.items()) {
        int mapKey = stoi(key);
        std::vector<int> mapValue = value.get<std::vector<int>>();
        map_data[mapKey] = mapValue;
    }
    return map_data; 
}

void create_adj_matrix(std::unordered_map<ID,std::vector<ID>>& map, gph::Graph& graph){
    for (auto it: map) {
        for (auto val : it.second) {
			graph.addEdge(it.first, val);
        }
    }
}




}//namespace gph 