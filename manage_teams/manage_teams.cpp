#include "manage_teams.h"

void manage_teams::initialize() {

    std::array<std::pair<int, int>, 56> edges = {{
        std::make_pair(Atlanta_Hawks, Charlotte_Hornets), std::make_pair(Atlanta_Hawks, Memphis_Grizzlies), std::make_pair(Atlanta_Hawks, New_Orleans_Pelicans), std::make_pair(Atlanta_Hawks, Orlando_Magic),
        std::make_pair(Boston_Celtics, New_York_Knicks), std::make_pair(Boston_Celtics, Toronto_Raptors),
        std::make_pair(Brooklyn_Nets, New_York_Knicks), std::make_pair(Brooklyn_Nets, Philadelphia_76ers),
        std::make_pair(Charlotte_Hornets, Indiana_Pacers), std::make_pair(Charlotte_Hornets, Miami_Heat), std::make_pair(Charlotte_Hornets, Washington_Wizards),
        std::make_pair(Chicago_Bulls, Detroit_Pistons), std::make_pair(Chicago_Bulls, Indiana_Pacers), std::make_pair(Chicago_Bulls, Milwaukee_Bucks),
        std::make_pair(Cleveland_Cavaliers, Detroit_Pistons), std::make_pair(Cleveland_Cavaliers, Indiana_Pacers), std::make_pair(Cleveland_Cavaliers, Philadelphia_76ers), std::make_pair(Cleveland_Cavaliers, Washington_Wizards),
        std::make_pair(Dallas_Mavericks, Houston_Rockets), std::make_pair(Dallas_Mavericks, Oklahoma_City_Thunder), std::make_pair(Dallas_Mavericks, San_Antonio_Spurs),
        std::make_pair(Denver_Nuggets, Los_Angeles_Lakers), std::make_pair(Denver_Nuggets, Minnesota_Timberwolves), std::make_pair(Denver_Nuggets, Oklahoma_City_Thunder), std::make_pair(Denver_Nuggets, Phoenix_Suns), std::make_pair(Denver_Nuggets, Utah_Jazz),
        std::make_pair(Detroit_Pistons, Minnesota_Timberwolves), std::make_pair(Detroit_Pistons, New_York_Knicks), std::make_pair(Detroit_Pistons, Toronto_Raptors),
        std::make_pair(Golden_State_Warriors, Los_Angeles_Lakers), std::make_pair(Golden_State_Warriors, Sacramento_Kings),
        std::make_pair(Houston_Rockets, New_Orleans_Pelicans), std::make_pair(Houston_Rockets, San_Antonio_Spurs),
        std::make_pair(Los_Angeles_Clippers, Los_Angeles_Lakers), std::make_pair(Los_Angeles_Clippers, Denver_Nuggets), std::make_pair(Los_Angeles_Clippers, Golden_State_Warriors), std::make_pair(Los_Angeles_Clippers, Phoenix_Suns), std::make_pair(Los_Angeles_Clippers, Sacramento_Kings), std::make_pair(Los_Angeles_Clippers, Utah_Jazz),
        std::make_pair(Los_Angeles_Lakers, Phoenix_Suns), std::make_pair(Los_Angeles_Clippers, Sacramento_Kings), std::make_pair(Los_Angeles_Lakers, Utah_Jazz),
        std::make_pair(Memphis_Grizzlies, New_Orleans_Pelicans), std::make_pair(Memphis_Grizzlies, Oklahoma_City_Thunder),
        std::make_pair(Miami_Heat, Charlotte_Hornets), std::make_pair(Miami_Heat, New_Orleans_Pelicans), std::make_pair(Miami_Heat, Orlando_Magic),
        std::make_pair(Milwaukee_Bucks, Minnesota_Timberwolves),
        std::make_pair(Minnesota_Timberwolves, Portland_Trail_Blazers),
        std::make_pair(New_York_Knicks, Toronto_Raptors),
        std::make_pair(Oklahoma_City_Thunder, Denver_Nuggets),
        std::make_pair(Philadelphia_76ers, Washington_Wizards),
        std::make_pair(Portland_Trail_Blazers, Sacramento_Kings), std::make_pair(Portland_Trail_Blazers, Utah_Jazz),
        std::make_pair(Toronto_Raptors, New_York_Knicks),
        std::make_pair(Washington_Wizards, Cleveland_Cavaliers)
    }};

    std::array<float, 56> weights = {{
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
        373, 388.4, 688.4,
        395, 466,
        730.9, 866.1, 235.6,
        337.1,
        1729.3,
        491.1,
        679.6,
        140,
        579.7, 765.5,
        491.1,
        371
    }};

    g = {edges.begin(), edges.end(), weights.begin(), 30};
}

void manage_teams::shortest_path(int initial, int target) {
    int p = initial;
    int distanceSum = 0;

    boost::array<int, 30> directions{};
    boost::dijkstra_shortest_paths(g, target,
        boost::predecessor_map(directions.begin()));
    while (p != target) {
        printCity(static_cast<Teams>(p));
        distanceSum += get(boost::edge_weight_t(),
                           g, boost::edge(p, directions[p], g).first);
        std::cout << ", ";
        p = directions[p];
    }
    printCity(static_cast<Teams>(p));
    std::cout << " (distance: " << distanceSum << ")" << std::endl;
}

void manage_teams::minimum_spanning_tree() {
    typedef boost::graph_traits < Graph >::edge_descriptor Edge;
    std::vector < Edge > spanning_tree;

    kruskal_minimum_spanning_tree(g, std::back_inserter(spanning_tree));

    std::cout << "Printing the edges in the MST:" << std::endl;
    int distanceSum = 0;
    int distance;
    for (auto & ei : spanning_tree) {
        printCity(static_cast<Teams>(source(ei, g)));
        std::cout << " <--> ";
        printCity(static_cast<Teams>(target(ei, g)));
        distance = get(boost::edge_weight_t(), g,
                       boost::edge(source(ei, g), target(ei, g), g).first);
        distanceSum += distance;
        std::cout << " (distance: " << distance << ")" << std::endl;
    }

    std::cout << "\nTotal distance of MST: " << distanceSum << std::endl;
}


void manage_teams::depth_first_search(Teams team) {

}

void manage_teams::breadth_first_search(Teams team) {

}




void manage_teams::printCity(Teams team)
{
    switch(team)
    {
        case Atlanta_Hawks : std::cout << "Atlanta Hawks";
        break;
        case Boston_Celtics : std::cout << "Boston Celtics";
        break;
        case Brooklyn_Nets : std::cout << "Brooklyn Nets";
        break;
        case Charlotte_Hornets : std::cout << "Charlotte Hornets";
        break;
        case Chicago_Bulls : std::cout << "Chicago Bulls";
        break;
        case Cleveland_Cavaliers : std::cout << "Cleveland Cavaliers";
        break;
        case Dallas_Mavericks : std::cout << "Dallas Mavericks";
        break;
        case Denver_Nuggets : std::cout << "Denver Nuggets";
        break;
        case Detroit_Pistons : std::cout << "Detroit Pistons";
        break;
        case Golden_State_Warriors : std::cout << "Golden State Warriors";
        break;
        case Houston_Rockets : std::cout << "Houston Rockets";
        break;
        case Indiana_Pacers : std::cout << "Indiana Pacers";
        break;
        case Los_Angeles_Clippers : std::cout << "Los Angeles Clippers";
        break;
        case Los_Angeles_Lakers : std::cout << "Los Angeles Lakers";
        break;
        case Memphis_Grizzlies : std::cout << "Memphis Grizzlies";
        break;
        case Miami_Heat : std::cout << "Miami Heat";
        break;
        case Milwaukee_Bucks : std::cout << "Milwaukee Bucks";
        break;
        case Minnesota_Timberwolves : std::cout << "Minnesota Timberwolves";
        break;
        case New_Orleans_Pelicans : std::cout << "New_Orleans Pelicans";
        break;
        case New_York_Knicks : std::cout << "New York Knicks";
        break;
        case Oklahoma_City_Thunder : std::cout << "Oklahoma City Thunder";
        break;
        case Orlando_Magic : std::cout << "Orlando Magic";
        break;
        case Philadelphia_76ers : std::cout << "Philadelphia 76ers";
        break;
        case Phoenix_Suns : std::cout << "Phoenix Suns";
        break;
        case Portland_Trail_Blazers : std::cout << "Portland Trail Blazers";
        break;
        case Sacramento_Kings : std::cout << "Sacramento Kings";
        break;
        case San_Antonio_Spurs : std::cout << "San Antonio Spurs";
        break;
        case Toronto_Raptors : std::cout << "Toronto Raptors";
        break;
        case Utah_Jazz : std::cout << "Utah Jazz";
        break;
        case Washington_Wizards : std::cout << "Washington Wizards";
        break;
    }
}
