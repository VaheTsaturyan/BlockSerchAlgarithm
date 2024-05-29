#pragma once
#include <fstream>
#include <string>
#include <unordered_map>


#include "json/single_include/nlohmann/json.hpp"
#include "graph.h"

namespace gph{

using ID = int;

using Json = nlohmann::json;

Json open_file_give_jsonObj();

std::unordered_map<ID , std::vector<ID>> conv_to_map(Json jsonData);

void create_adj_matrix(std::unordered_map<ID,std::vector<ID>>& map,gph::Graph& graph);

}//namespace gr