#include <iostream>
#include <list>
#include <queue>
#include <string.h>
#include<vector>
using namespace std;
class Graph 
{
    private:
    int V;
    list<int> *adjacency;
    public:
    Graph(int _V)
    {
        this->V = _V;
        adjacency = new list<int>[V+ 1];
    }
    void AddEdge(int v, int n)
    {
        adjacency[v].push_back(n);
    }  
    void BFS(int v)
    {
        bool check[V+1];
        memset(check, false, sizeof(check));

        check[v] = true;
        list<int> queue;
        queue.push_back(v);
        list<int>::iterator i;
        while(!queue.empty())
        {
            v = queue.front();
            cout << v << " ";
            queue.pop_front();
            for(i = adjacency[v].begin(); i != adjacency[v].end(); i++)
            {
                if (!check[*i])
                {
                    check[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
        cout << endl;
    }
};
int main()
{
    Graph *graph = new Graph(6);
    graph->AddEdge(1, 2);
    graph->AddEdge(1, 3);
    graph->AddEdge(2, 1);
    graph->AddEdge(2, 4);
    graph->AddEdge(2, 5);
    graph->AddEdge(3, 1);
    graph->AddEdge(3, 5);
    graph->AddEdge(4, 2);
    graph->AddEdge(4, 5);
    graph->AddEdge(4, 6);
    graph->AddEdge(5, 2);
    graph->AddEdge(5, 3);
    graph->AddEdge(5, 4);
    graph->AddEdge(5, 6);
    graph->AddEdge(6, 4);
    graph->AddEdge(6, 5);
    graph->BFS(2);
    delete(graph);

}