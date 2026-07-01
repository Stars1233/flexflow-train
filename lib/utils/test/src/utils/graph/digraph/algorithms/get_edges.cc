#include "utils/graph/digraph/algorithms/get_edges.h"
#include "utils/containers/set_of.h"
#include "utils/graph/algorithms.h"
#include "utils/graph/digraph/digraph.h"
#include "utils/graph/instances/adjacency_digraph.h"
#include <doctest/doctest.h>

using namespace ::FlexFlow;

TEST_SUITE(FF_TEST_SUITE) {
  TEST_CASE("get_edges(DiGraphView)") {
    DiGraph g = DiGraph::create<AdjacencyDiGraph>();

    std::vector<Node> n = add_nodes(g, 4);
    std::vector<DirectedEdge> e = {
        DirectedEdge{n.at(0), n.at(1)},
        DirectedEdge{n.at(0), n.at(2)},
        DirectedEdge{n.at(0), n.at(3)},
        DirectedEdge{n.at(1), n.at(2)},
    };
    add_edges(g, e);

    SUBCASE("Base") {
      std::set<DirectedEdge> correct = set_of(e);
      std::set<DirectedEdge> result = get_edges(g);
      CHECK(result == correct);
    }

    SUBCASE("Adding an edge") {
      g.add_edge(DirectedEdge{n.at(3), n.at(1)});
      std::set<DirectedEdge> correct = {
          DirectedEdge{n.at(0), n.at(1)},
          DirectedEdge{n.at(0), n.at(2)},
          DirectedEdge{n.at(0), n.at(3)},
          DirectedEdge{n.at(1), n.at(2)},
          DirectedEdge{n.at(3), n.at(1)},
      };
      std::set<DirectedEdge> result = get_edges(g);
      CHECK(result == correct);
    }

    SUBCASE("Removing an edge") {
      g.remove_edge(DirectedEdge{n.at(0), n.at(3)});
      std::set<DirectedEdge> correct = {
          DirectedEdge{n.at(0), n.at(1)},
          DirectedEdge{n.at(0), n.at(2)},
          DirectedEdge{n.at(1), n.at(2)},
      };
      std::set<DirectedEdge> result = get_edges(g);
      CHECK(result == correct);
    }
  }
}
