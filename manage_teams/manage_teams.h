#pragma once
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/array.hpp>
#include <array>
#include <utility>
#include <iostream>

typedef boost::adjacency_list<boost::listS, boost::vecS,
        boost::undirectedS, boost::no_property,
        boost::property<boost::edge_weight_t, int>> Graph;

class manage_teams {
public:
    enum Teams {Atlanta_Hawks, Boston_Celtics, Brooklyn_Nets, Charlotte_Hornets,
        Chicago_Bulls, Cleveland_Cavaliers, Dallas_Mavericks, Denver_Nuggets,
        Detroit_Pistons, Golden_State_Warriors, Houston_Rockets, Indiana_Pacers,
        Los_Angeles_Clippers, Los_Angeles_Lakers, Memphis_Grizzlies, Miami_Heat,
        Milwaukee_Bucks, Minnesota_Timberwolves, New_Orleans_Pelicans, New_York_Knicks,
        Oklahoma_City_Thunder, Orlando_Magic, Philadelphia_76ers, Phoenix_Suns,
        Portland_Trail_Blazers, Sacramento_Kings, San_Antonio_Spurs, Toronto_Raptors,
        Utah_Jazz, Washington_Wizards};

    void initialize();
    void shortest_path(int initial, int target);
    void minimum_spanning_tree();
    void depth_first_search(Teams team);
    void breadth_first_search(Teams team);

private:


    void printCity(Teams team);
    Graph g;

};