#include "manage_teams.h"

void manage_teams::initialize() {
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
        cpair(Los_Angeles_Lakers, Phoenix_Suns), cpair(Los_Angeles_Clippers, Sacramento_Kings), cpair(Los_Angeles_Lakers, Utah_Jazz),
        cpair(Memphis_Grizzlies, New_Orleans_Pelicans), cpair(Memphis_Grizzlies, Oklahoma_City_Thunder),
        cpair(Miami_Heat, Charlotte_Hornets), cpair(Miami_Heat, New_Orleans_Pelicans), cpair(Miami_Heat, Orlando_Magic),
        cpair(Milwaukee_Bucks, Minnesota_Timberwolves),
        cpair(Minnesota_Timberwolves, Portland_Trail_Blazers),
        cpair(New_York_Knicks, Toronto_Raptors),
        cpair(Oklahoma_City_Thunder, Denver_Nuggets),
        cpair(Philadelphia_76ers, Washington_Wizards),
        cpair(Portland_Trail_Blazers, Sacramento_Kings), cpair(Portland_Trail_Blazers, Utah_Jazz),
        cpair(Toronto_Raptors, New_York_Knicks),
        cpair(Washington_Wizards, Cleveland_Cavaliers)
    }};


    g = {30};

    for (Teams i = Atlanta_Hawks; i != endofTeams; i = Teams(i+1))
    {
        g[(Vertex)i].team = teamNames[i];
    }

    for (int i = 0; weights[i] >= 0; ++i) {
        auto a = add_edge((Vertex) edges[i].first,
                          (Vertex) edges[i].second,
                          g).first;

        g[a].distance = weights[i];
    }
}

void manage_teams::shortest_path(int initial, int target) {
    int p = initial;
    int distanceSum = 0;

    boost::array<int, 30> directions{};
    boost::dijkstra_shortest_paths(g, target,
        boost::predecessor_map(directions.begin()).
            weight_map(boost::get(&Distance::distance, g)));
    while (p != target) {
        std::cout << g[p].team << ", ";
        distanceSum += g[edge(p, directions[p], g).first].distance;
        p = directions[p];
    }
    std::cout << g[target].team << std::endl;
    std::cout << " (distance: " << distanceSum << ")" << std::endl;
}

void manage_teams::minimum_spanning_tree() {
    typedef boost::graph_traits < Graph >::edge_descriptor Edge;
    std::vector < Edge > spanning_tree;

    boost::array<int, 30> directions{};
    kruskal_minimum_spanning_tree(g, std::back_inserter(spanning_tree),
                                  boost::predecessor_map(directions.begin()).
                                          weight_map(boost::get(&Distance::distance, g)));

    std::cout << "Printing the edges in the MST:" << std::endl;
    int distanceSum = 0;
    for (auto & ei : spanning_tree) {
        std::cout << g[source(ei, g)].team << " <--> " << g[target(ei, g)].team;
        std::cout << " (distance: " << g[ei].distance << ")" << std::endl;
        distanceSum += g[ei].distance;
    }

    std::cout << "\nTotal distance of MST: " << distanceSum << std::endl;
}


int manage_teams::depth_first_search(Teams team) {
    Graph dg = g;

    Iter ei, ei_end;
    Iter next;
    int shortestPath;
    bool found_unvisited;
    int distanceSum = 0;
    dg[team].isVisited = true;
    std::stack<Vertex> stack;
    Vertex curr;
    curr = team;
    stack.push(curr);
    int visitedCities = 0;

    while (visitedCities != num_vertices(dg)) {
        shortestPath = INFINITY;
        found_unvisited = false;
        std::cout << "Visiting: " << dg[curr].team << std::endl;
        for (boost::tie(ei, ei_end) = out_edges(curr, dg); ei != ei_end; ++ei) {
            if (!dg[target(*ei, dg)].isVisited) {
                found_unvisited = true;
                if (dg[*ei].distance < shortestPath) {
                    shortestPath = dg[*ei].distance;
                    next = ei;
                }
            }
            else if (!dg[*ei].discovery){
                std::cout << "[BACK EDGE]: ";
                std::cout << "(" << dg[source(*ei, dg)].team
                          << ", " << dg[target(*ei, dg)].team << ")";
                std::cout << std::endl;
            }
        }

        if (found_unvisited) {
            std::cout << "[DISCOVERY EDGE]: ";
            std::cout << "(" << dg[source(*next, dg)].team
                      << ", " << dg[target(*next, dg)].team << ")";
            std::cout << std::endl;
            visitedCities++;
            distanceSum += dg[*next].distance;
            std::cout << std::endl;
            dg[target(*next, dg)].isVisited = true;
            dg[*next].discovery = true;
            stack.push(target(*next, dg));
            curr = target(*next, dg);
        }
        else {
            if (visitedCities == num_vertices(dg) - 1) visitedCities++;
            else if (!stack.empty()) {
                stack.pop();
                curr = stack.top();
//                std::cout << "-- Backtracking to " << dg[curr].team << "...\n" << std::endl;
            }
        }
    }
    return distanceSum;
}

int manage_teams::breadth_first_search(Teams team) {
    Graph bg = g;

    Iter ei, ei_end;
    Vertex curr;
    Vertex src;
    int distanceSum = 0;
    bg[team].isVisited = true;
    curr = team;
    std::vector<Vertex> list;
    std::vector<Vertex> lvl;
    list.push_back(team);

    while (!list.empty()) {
        lvl.clear();
        std::cout << "Visiting: " << bg[curr].team << std::endl;
        for (boost::tie(ei, ei_end) = out_edges(curr, bg); ei != ei_end; ++ei) {
            if (!bg[target(*ei, bg)].isVisited) {
                bg[*ei].discovery = true;
                distanceSum += bg[*ei].distance;
                bg[target(*ei, bg)].isVisited = true;
                lvl.push_back(target(*ei, bg));
            }
            else if (!bg[*ei].discovery){
                std::cout << "[BACK EDGE]: ";
                std::cout << "(" << bg[source(*ei, bg)].team
                          << ", " << bg[target(*ei, bg)].team << ")";
                std::cout << std::endl;
            }
        }

        sort(lvl.begin(), lvl.end(),[bg, curr](const Vertex &a, const Vertex &b) -> bool {
            return bg[edge(curr, a, bg).first].distance <
                   bg[edge(curr, b, bg).first].distance;
        });
        for (auto i: lvl) {
            std::cout << "[DISCOVERY EDGE]: ";
            std::cout << "(" << bg[curr].team
                      << ", " << bg[i].team << ")";
            std::cout << std::endl;
        }

        list.insert(list.end(), lvl.begin(), lvl.end());
        src = *list.begin();
        list.erase(list.begin());
        curr = list.front();
        std::cout << std::endl;
    }

    return distanceSum;
}
