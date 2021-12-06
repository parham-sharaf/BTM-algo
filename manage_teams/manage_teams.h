#pragma once
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/named_function_params.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>
#include <boost/array.hpp>
#include <array>
#include <utility>
#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>



struct Distance {
    double distance;
    bool discovery = false;
};

struct City {
    std::string team;
    bool isVisited = false;
};

typedef boost::adjacency_list<boost::listS, boost::vecS,
        boost::undirectedS, City,
        Distance > Graph;

typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;
typedef boost::graph_traits<Graph>::edge_descriptor Edge;
typedef typename boost::graph_traits<Graph>::out_edge_iterator Iter;

class manage_teams {
public:
    enum Teams {Atlanta_Hawks, Boston_Celtics, Brooklyn_Nets, Charlotte_Hornets,
        Chicago_Bulls, Cleveland_Cavaliers, Dallas_Mavericks, Denver_Nuggets,
        Detroit_Pistons, Golden_State_Warriors, Houston_Rockets, Indiana_Pacers,
        Los_Angeles_Clippers, Los_Angeles_Lakers, Memphis_Grizzlies, Miami_Heat,
        Milwaukee_Bucks, Minnesota_Timberwolves, New_Orleans_Pelicans, New_York_Knicks,
        Oklahoma_City_Thunder, Orlando_Magic, Philadelphia_76ers, Phoenix_Suns,
        Portland_Trail_Blazers, Sacramento_Kings, San_Antonio_Spurs, Toronto_Raptors,
        Utah_Jazz, Washington_Wizards, endofTeams};


    void initialize();
    double shortest_path(int initial, int target);
    double minimum_spanning_tree();
    double depth_first_search(Teams team);
    double breadth_first_search(Teams team);
    std::deque<City> getTravelPlan();
    double createCustomPlan(const std::vector<std::string>&, bool order);

    const char* teamNames[30] {
            "Atlanta Hawks", "Boston Celtics", "Brooklyn Nets", "Charlotte Hornets",
            "Chicago Bulls", "Cleveland Cavaliers", "Dallas Mavericks", "Denver Nuggets",
            "Detroit Pistons", "Golden State Warriors", "Houston Rockets", "Indiana Pacers",
            "Los Angeles Clippers", "Los Angeles Lakers", "Memphis Grizzlies", "Miami Heat",
            "Milwaukee Bucks", "Minnesota Timberwolves", "New Orleans Pelicans", "New York Knicks",
            "Oklahoma City Thunder", "Orlando Magic", "Philadelphia 76ers", "Phoenix Suns",
            "Portland Trail Blazers", "Sacramento Kings", "San Antonio Spurs", "Toronto Raptors",
            "Utah Jazz", "Washington Wizards"
    };
private:
    typedef std::pair<Teams, Teams> cpair;

    std::array<std::pair<int, int>, 56> edges = {{
        cpair(Atlanta_Hawks, Charlotte_Hornets), cpair(Atlanta_Hawks, Memphis_Grizzlies), cpair(Atlanta_Hawks, New_Orleans_Pelicans), cpair(Atlanta_Hawks, Orlando_Magic),
        cpair(Boston_Celtics, New_York_Knicks), cpair(Boston_Celtics, Toronto_Raptors),
        cpair(Brooklyn_Nets, New_York_Knicks), cpair(Brooklyn_Nets, Philadelphia_76ers),
        cpair(Charlotte_Hornets, Indiana_Pacers), cpair(Charlotte_Hornets, Miami_Heat), cpair(Charlotte_Hornets, Washington_Wizards),
        cpair(Chicago_Bulls, Detroit_Pistons), cpair(Chicago_Bulls, Indiana_Pacers), cpair(Chicago_Bulls, Milwaukee_Bucks),
        cpair(Cleveland_Cavaliers, Detroit_Pistons), cpair(Cleveland_Cavaliers, Indiana_Pacers), cpair(Cleveland_Cavaliers, Philadelphia_76ers), cpair(Cleveland_Cavaliers, Washington_Wizards),
        cpair(Dallas_Mavericks, Houston_Rockets), cpair(Dallas_Mavericks, Oklahoma_City_Thunder), cpair(Dallas_Mavericks, San_Antonio_Spurs),
        cpair(Denver_Nuggets, Los_Angeles_Lakers), cpair(Denver_Nuggets, Minnesota_Timberwolves), cpair(Denver_Nuggets, Oklahoma_City_Thunder), cpair(Denver_Nuggets, Phoenix_Suns), cpair(Denver_Nuggets, Utah_Jazz),
        cpair(Detroit_Pistons, Minnesota_Timberwolves), cpair(Detroit_Pistons, New_York_Knicks), cpair(Detroit_Pistons, Toronto_Raptors),
        cpair(Golden_State_Warriors, Los_Angeles_Lakers), cpair(Golden_State_Warriors, Sacramento_Kings),
        cpair(Houston_Rockets, New_Orleans_Pelicans), cpair(Houston_Rockets, San_Antonio_Spurs),
        cpair(Los_Angeles_Clippers, Los_Angeles_Lakers), cpair(Los_Angeles_Clippers, Denver_Nuggets), cpair(Los_Angeles_Clippers, Golden_State_Warriors), cpair(Los_Angeles_Clippers, Phoenix_Suns), cpair(Los_Angeles_Clippers, Sacramento_Kings), cpair(Los_Angeles_Clippers, Utah_Jazz),
        cpair(Los_Angeles_Lakers, Phoenix_Suns), cpair(Los_Angeles_Lakers, Utah_Jazz), cpair(Los_Angeles_Lakers, Sacramento_Kings),
        cpair(Memphis_Grizzlies, New_Orleans_Pelicans), cpair(Memphis_Grizzlies, Oklahoma_City_Thunder),
        cpair(Miami_Heat, New_Orleans_Pelicans), cpair(Miami_Heat, Orlando_Magic),
        cpair(Milwaukee_Bucks, Minnesota_Timberwolves),
        cpair(Minnesota_Timberwolves, Portland_Trail_Blazers),
        cpair(New_York_Knicks, Toronto_Raptors),
        cpair(Oklahoma_City_Thunder, Denver_Nuggets),
        cpair(Philadelphia_76ers, Washington_Wizards),
        cpair(Portland_Trail_Blazers, Sacramento_Kings), cpair(Portland_Trail_Blazers, Utah_Jazz),
    }};

    Graph g;
    std::array<double, 57> weights = {{
        244.8, 383.8, 469.1, 438.8,
        215.3, 550,
        5.1, 97.4,
        585.1, 730.9, 402,
        282.6, 181.6, 92.1,
        164.9, 315.5, 431.2, 371,
        239.8, 206.7, 273.8,
        1016.1, 913.9, 679.6, 862.4, 519.1,
        694.7, 616.1, 231,
        385.1, 87.9,
        347.7, 197.4,
        0.0, 1016.1, 385.1, 373, 388.4, 688.4,
        373, 688.4, 388.4,
        395, 466,
        866.1, 235.6,
        337.1,
        1729.3,
        491.1,
        679.6,
        140,
        579.7, 765.5,
        -1
    }};

    std::deque<City> travelPlan;

};