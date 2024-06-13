#include<model.h>
#include<math.h>

int * plot(int coord0, int coord1, int resolution, int target_size){
    int coordinate0 = (int)(coord0)*std::floor(resolution/target_size);
    int coordinate1 = (int)(coord1)*std::floor(resolution/target_size);
    int result[2] = {coordinate0, coordinate1};
    return result;
}

int render(Model target, int resolution){
    int image[resolution][resolution];
    int target_size = target.size; // From 10 to 100. To be converted to resolution.
    //convert vertex to resolution and render
    for(int i = 0; i < target.vertex_amount; i++){
        // int coordinate0 = (int)(target.vertex[i].coords[0])*std::floor(resolution/target_size);
        // int coordinate1 = (int)(target.vertex[i].coords[1])*std::floor(resolution/target_size);
        int * result = plot(target.vertex[i].coords[0], target.vertex[i].coords[1], resolution, target_size);
        image[result[0]][result[1]] = 1;
    }
    //convert edges to vertex and render
    for(int i = 0; i < target.edge_amount; i++){
        Edge current_edge = target.edges[i];
        Vector path(current_edge.corners[0].coords[0] - current_edge.corners[0].coords[1], current_edge.corners[1].coords[0] - current_edge.corners[1].coords[1]);
        Vector drawn = path.scale_by((int)(resolution/target_size), path);
        int * result = plot(current_edge.corners[0].coords[0], current_edge.corners[0].coords[1], resolution, target_size);
        image[result[0]][result[1]] = 1;
        for(int i = 0;i < (int)(resolution/target_size); i++){
            image[current_edge.corners[0].coords[0] + drawn.scale_by(i, drawn).coords[0]][current_edge.corners[0].coords[1] + drawn.scale_by(i, drawn).coords[1]] = 1;
            
        }        
    }
}