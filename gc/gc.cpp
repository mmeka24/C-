#include "node.h"
#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char input[150];
    char label_one[50];
    char label_two[50];
    int weight; // New variable for storing the weight
    graph* main_graph = new graph();

    while (true) {
        cout << "ADD EDGE, DELETE EDGE, ADD VERTEX, DELETE VERTEX, PATH, QUIT" << endl;
        cin.getline(input, 150);

        if (!strcmp("ADD EDGE", input)) {
            cout << "Enter the first node label: ";
            cin.getline(label_one, 50);
            cout << "Enter the second node label: ";
            cin.getline(label_two, 50);
            cout << "Enter the weight of the edge: ";
            cin >> weight;
            cin.ignore(); // consume newline
            main_graph->add_edge(label_one, label_two, weight);
        }
        else if (!strcmp("DELETE EDGE", input)) {
            cout << "Enter the first node label: ";
            cin.getline(label_one, 50);
            cout << "Enter the second node label: ";
            cin.getline(label_two, 50);
            main_graph->remove_edge(label_one, label_two);
        }
        else if (!strcmp("ADD VERTEX", input)) {
            cout << "Enter the vertex label: ";
            cin.getline(input, 150);
            main_graph->add_vertex(input);
        }
        else if (!strcmp("DELETE VERTEX", input)) {
            cout << "Enter the vertex label: ";
            cin.getline(input, 150);
            main_graph->remove_vertex(input);
        }
        else if (!strcmp("PATH", input)) {
            cout << "Enter the source node label: ";
            cin.getline(label_one, 50);
            cout << "Enter the destination node label: ";
            cin.getline(label_two, 50);
            main_graph->dijkstra(label_one, label_two);
        }
        else if (!strcmp("PRINT", input)) {
            main_graph->print();
        }
        else if (!strcmp("QUIT", input)) {
            delete main_graph;
            return 0;
        }
        else {
            cout << "Invalid command" << endl;
        }
    }
}
