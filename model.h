#include<./vector.h>
#include<edge.h>
#include<vector>

class Model {
    public:
        std::vector<Vector> vertex;
        int vertex_amount;
        std::vector<Edge> edges;
        int edge_amount;
        int size;
        Model(std::vector<Vector> vertex, int vertex_amount, std::vector<Edge> edges, int edge_amount, int size){
            vertex = vertex;
            vertex_amount = vertex_amount;
            edges = edges;
            edge_amount = edge_amount;
            size = size;
        }

    int render(Model target, int resolution);
};