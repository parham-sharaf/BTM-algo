#include "manage_teams.h"

void manage_teams::initialize() {
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

double manage_teams::shortest_path(int initial, int target) {
    int p = initial;
    double distanceSum = 0;

    boost::array<int, 31> directions{};
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

    return distanceSum;
}

double manage_teams::minimum_spanning_tree() {
    typedef boost::graph_traits < Graph >::edge_descriptor Edge;
    std::vector < Edge > spanning_tree;

    boost::array<int, 31> directions{};
    kruskal_minimum_spanning_tree(g, std::back_inserter(spanning_tree),
                                  boost::predecessor_map(directions.begin()).
                                          weight_map(boost::get(&Distance::distance, g)));

    std::cout << "Printing the edges in the MST:" << std::endl;
    double distanceSum = 0;
    for (auto & ei : spanning_tree) {
        std::cout << g[source(ei, g)].team << " <--> " << g[target(ei, g)].team;
        std::cout << " (distance: " << g[ei].distance << ")" << std::endl;
        distanceSum += g[ei].distance;
    }

    std::cout << "\nTotal distance of MST: " << distanceSum << std::endl;

    return distanceSum;
}


double manage_teams::depth_first_search(Teams team) {
    travelPlan.clear();

    Graph dg = g;

    Iter ei, ei_end;
    Iter next;
    int shortestPath;
    bool found_unvisited;
    bool multiple = false;
    double distanceSum = 0;
    dg[team].isVisited = true;
    std::stack<Vertex> stack;
    Vertex curr;
    curr = team;
    stack.push(curr);
    int visitedCities = 0;

    while (visitedCities != num_vertices(dg)) {
        shortestPath = INFINITY;
        found_unvisited = false;
        multiple = false;
        std::cout << "Visiting: " << dg[curr].team << std::endl;
        for (const auto& item: travelPlan) {
            if (item.team == dg[curr].team) {
                multiple = true;
            }
        }
        if (!multiple)
            travelPlan.push_back(dg[curr]);
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
            }
        }
    }
    return distanceSum;
}

double manage_teams::breadth_first_search(Teams team) {
    travelPlan.clear();
    Graph bg = g;

    Iter ei, ei_end;
    Vertex curr;
    double distanceSum = 0;
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
        travelPlan.push_back(g[*list.begin()]);
        list.erase(list.begin());
        curr = list.front();
        std::cout << std::endl;
    }

    return distanceSum;
}

std::deque<City> manage_teams::getTravelPlan() {
    return travelPlan;
}

double manage_teams::createCustomPlan(const std::vector<std::string>& list, bool order) {
    travelPlan.clear();
    double distanceSum = 0;
    int initial = 0;
    int target = 0;
    if (order) {
        for (int i = 0; i < list.size() - 1; i++) {
            for (auto city : boost::make_iterator_range(vertices(g))) {
                if (g[city].team == list[i])
                    initial = city;
                if (g[city].team == list[i + 1])
                    target = city;
            }
            distanceSum += shortest_path(initial, target);
            travelPlan.push_back(g[initial]);
        }
        travelPlan.push_back(g[target]);
    }
    else {
        std::vector<int> selectionVert;
        for (const auto& selection: list) {
            for (auto city: boost::make_iterator_range(vertices(g))) {
                if (g[city].team == selection) {
                    selectionVert.push_back(city);
                }
            }
        }

        double tempDistance = 0;
        int shortestCityIndex;
        travelPlan.push_back(g[selectionVert[0]]);
        initial = selectionVert[0];
        selectionVert.erase(selectionVert.begin());
        while (!selectionVert.empty()) {
            double endPointsDistance = INFINITY;
            for (int j = 0; j < selectionVert.size(); j++) {
                if (g[initial].team != g[selectionVert[j]].team)
                    tempDistance = shortest_path(initial, selectionVert[j]);
                if (tempDistance < endPointsDistance) {
                    endPointsDistance = tempDistance;
                    shortestCityIndex = j;
                }
            }
            travelPlan.push_back(g[selectionVert[shortestCityIndex]]);
            initial = selectionVert[shortestCityIndex];
            selectionVert.erase(selectionVert.begin() + shortestCityIndex);
            distanceSum += endPointsDistance;
        }
    }
    return distanceSum;
}

void manage_teams::addNewVertex() {
    Vertex v1 = boost::add_vertex(g);
    g[v1].team = "Seattle Supersonics";

    auto e1 = boost::add_edge(Sacramento_Kings, v1, g).first;
    g[e1].distance = 752.4;

    auto e2 = boost::add_edge(Portland_Trail_Blazers, v1, g).first;
    g[e2].distance = 173.8;
    teamNames.emplace_back("Seattle Supersonics");

}

std::vector<std::string> manage_teams::getTeamNames() {
    return teamNames;
}
