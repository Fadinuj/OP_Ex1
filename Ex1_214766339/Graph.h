#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

namespace graph{
class Graph
{
private:
    int numVertices;
    int** adjacencecy;
public:
    Graph(int vertics);
    ~Graph();
};

Graph::Graph(/* args */)
{
}

Graph::~Graph()
{
}