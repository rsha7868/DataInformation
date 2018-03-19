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
    std::set<int> neighbors(int vertex) const;
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

template <class Type>
void Graph<Type> :: addVertex(const Type& value)
{
    assert(vertexCount < MAXINUM);
    int newVertexNumber = vertexCount;
    vertexCount++;
    
    for(int otherVertexNumber = 0; otherVertexNumber < vertexCount; otherVertexNumber++)
    {
        adjacencyMatrix[otherVertexNumber][newVertexNumber] = false;
        adjacencyMatrix[newVertexNumber][otherVertexNumber] = false;
    }
    graphData[newVertexNumber] = value;
}

template <class Type>
void graph<Type> :: removeEdge(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyMatrix[source][target] = false;
}
template <class Type>
void Graph<Type> :: removeEdgeUndirected(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjecencyMatrix[source][target] = false;
    adjecencyMatrix[target][target] = false'
}
template <class Type>
void Graph<Type> :: removeEdgeCost(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    weighCostMatrix[source][target] = 0;
    weighCostMatrix[target][source] = 0;
}
template <class Type>
void Graph<Type> addEdge(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyCostMatrix[source][target] = true;
    
}
template <class Type>
void Graph<Type> :: addEdgeCost(int source, int target, int cost)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    weightCostMatrix[source][target] = cost;
    weightCostMatrix[target][source] = cost;
}
template <class Type>
void Graph<Type> :: addEdgeIndirected(int source, int target)
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    adjacencyCostMatrix[source][target] = true;
    adjacencyCostMatrix[target][source] = true;
}
template <class Type>
bool Graph<Type> :: hasUndirectedConnection(int source, int target) const
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    
    bool isAnEdge = false;
    isAnEdge = adjancecyMatrix[source][target] || adjacencyMatrix[target][source];
    
    return isAnEdge;
}
template <class Type>
bool Graph<Type> :: areConnected(int source, int target) const
{
    assert(source >= 0 && source < vertexCount && target >= 0 && target < vertexCount);
    
    bool isAnEdge = false;
    isAnEdge = adjancyMatrix[source][target];
    
    return isAnEdge;
}
template <class Type>
std::set<int> Graph<Type> :: neighbors(int vertex) const
{
    assert(vertex < vertexCount);
    std::set<int> vertexNeighbors;
    
    for(int index = 0; index < vertexCount; index++)
    {
        if(adjacencyMatrix[vertex][index])
        {
            vertexNeighbors.insert(index);
        }
    }
    return Neighbors;
}
template <class Type>
void Graph<Type> :: depthFirstTraversal(Graph<Type> & currentGraph, int vertex)
{
    bool vistedVerticies[MAXINUM];
    assert(vertex < currentGraph.size());
    std::fill_n(vistedVertices, currentGraph.size(), false);
    depthFirstTraversal(currentGraph, vertex, vistedVertices);
}
template <class Type>
void Graph<Type> :: depthFirstTranversal(Graph<Type> & currentGraph, int vertex, bool * visted)
{
    std::set<int> connections = currentGraph.neighbors(vertex);
    std::set<int>::iterator setIterator;
    
    visted[vertex] = true;
    cout << currentGraph[vertex] << ", " << endl;
    
    for(setIterator = connections.begin(); setIterator != connections.end(); setIterator++)
    {
        if(!visted[*setIterator])
        {
            depthFirstTTraversal(currentGraph, *setIterator, visted);
        }
    }
}
template <class Type>
int Graph<Type> :: costTranversal(Graph<Type> & currentGraph, int vertex)
{
    assert(vertex < currentGraph.size());
    int cost = 0;
    bool visted[MAXINUM];
    std::set<int> connections;
    std::set<int>::iterator set iterator;
    std::queue<int> vertexQueue;
    
    std::fill_n(visted,currentGraph.size(), false);
    visted[vertex] = true;
    
    vertexQueue.push(vertex);
    while(!vertexQueue.empty())
    {
        connections = currentGraph.neighbors(vertexQueue.front());
        vertexQueue.pop();
        
        for(!visited[*setIterator])
        {
            cost += weightCostMatrix[vertex][*setIterator];
            visited[*setIterator] = true;
            vertexQueue.push(*setIterator);
        }
    }
}

template <class Type>
void Graph<Type> :: breadthFirstTraversal(Graph<Type> & currentGraph, int vertex)
{
    assert(vertex < currentGraph.size());
    bool visited[MAXINUM];
    std::set<int> connections;
    std::set<int>::iterator set iterator;
    std::queue<int> vertexQueue;
    
    std::fill_n(visted,currentGraph.size(), false);
    visted[vertex] = true;
    cout << currentGraph[vertex] << endl;
    

}

#endif /* Graph_hpp */