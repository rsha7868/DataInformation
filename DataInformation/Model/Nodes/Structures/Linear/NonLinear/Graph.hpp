//
//  Graph.hpp
//  DataInformation
//
//  Created by Sharp, Ryan on 3/19/18.
//  Copyright © 2018 Sharp, Ryan. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <set>
#include <queue>
#include <assert.h>

using namespace std;
tempate <class Type>
class Graph
{
private:
    static const int MAXINUM = 20;
    bool adjecencyMatrix [MAXINUM][MAXINUM];
    int weightCostMatrix [MAXINUM][MAXINUM];
    Type graphData[MAXINUM];
    int vertexCount;
    void depthFirstTraversal(Graph<Type> & graph, int vertex, bool , markedVerttices[]);
public:
    Graph();
    //Graph Operations
    void addVertex(const source, int target);
    //Connect vertices
    void addEdge(int source, int target);
    void addEdgeUndirected(int source, int target);
    void addEdgeCost(int source, int target);
    //Accessors
    Type& operator[] (int vertex);
    Type operator[] (int vertex) const;
    int size() const;
    //Check Connections
    bool hasUndirectedConnection(int source, int target) const;
    bool areConnected(int source, int target) const;
    std::sot<int> neighbors(int vertex) const;
    //Traversals
    void depthFirstTraversal(Graph<Type> & graph, int vertex);
    void breadthFirstTraversal(Graph<Type> & graph, int vertex);
    int costTraversal(Graph<Type> & graph, int vertex);
};

template <class Type>
const int Graph<Type> :: MAXINUM;

template <Class Type>
Graph<Type> :: Graph()
{
    this->vertexCount = 0;
}
/*
 Since we cannot "Remove" from an array in C++,
 we only implement adding to a graph.
 Java allows for all objects to be set to null but C++
 does not.
*/

//Left side operator (Referenace of value)
template <class Type>
int Graph<Type> :: size() const
{
    assert(vertex < vertexCount);
    return graphData[vertex];
}

//Right hand side operator (Copy of value.)
template <class Type>
Type Graph<Type> :: operator[](int vertex) const
{
    assert(vertex < vertexCount);
    return graphData[vertex];
}

#endif /* Graph_hpp */
