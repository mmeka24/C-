/*
manasvi meka 
graph creator
*/
#include "node.h"
#include <iostream>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>
using namespace std;


int main(){
	char input[150];
	char label_one[50];
	char label_two[50];
    int adj_mat[20][20] = {0};
    int num; 
	graph * main_graph = new graph();
    
	//implementing the adj matrix
    //https://www.programiz.com/dsa/graph-adjacency-list


	while(true){
		cout << "ADD EDGE, DELETE EDGE, ADD VERTEX, DELETE VERTEX, PATH, PRINT, QUIT"<<endl;
		cin.getline(input,150);
		if(strcmp("ADD EDGE",input)==0){
            //cout << "label 1 " << endl; 
			cout << "Label 1,Label 2(in this format)"<<endl;
			cin.getline(input,150);
			strcpy(label_one,strtok(input,","));
			cout << label_one;
			strcpy(label_two,strtok(NULL,","));
			cout << label_one;
            cout << "what is your weight?" << endl; 
            cin >> num; 
            //main graph
			main_graph->add_edge(label_one,label_two, num);

		}
		else if(strcmp("DELETE EDGE",input) ==0 ){
			cout << "Label 1,Label 2(in this format)"<<endl;
			cin.getline(input,150);
			strcpy(label_one,strtok(input,","));
			strcpy(label_two,strtok(NULL,","));
			main_graph->remove_edge(label_one,label_two);	
		}
		else if(strcmp("ADD VERTEX",input)==0){
			cout << "LABEL OF VERTEX?"<<endl;
			cin.getline(input,150);
			main_graph->add_vertex(input);
		}
		else if(strcmp("DELETE VERTEX",input)==0){
			cout << "LABEL OF VERTEX?"<<endl;
			cin.getline(input,150);
			main_graph->remove_vertex(input);
		}
		else if(strcmp("PATH", input)==0){
			cout << "Label 1,Label 2(in this format)"<<endl;
			cin.getline(input,150);
			strcpy(label_one,strtok(input,","));
			strcpy(label_two,strtok(NULL,","));
			cout << label_one;
			cout << label_two;
			main_graph->dijkstra(label_one,label_two);
		}
		else if(strcmp("PRINT",input)==0){
			main_graph->print();
		}
		else if(strcmp("QUIT",input)==0){
			return 0;
		}
		else{
			cout << "?"<<endl;
		}
	}
}

//https://www.programiz.com/dsa/graph-adjacency-list


graph::graph() {
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            adj_mat[j][i] = 0;
        }
    }
}

void graph::add_vertex(char* label) {
    //adds the vertex 
    if (capacity < 20) {
        strcpy(label_ls[capacity], label);
        capacity++;
    }
}

void graph::add_edge(char* label_one, char* label_two, int weight) {
    //adds an edge given weight 
    int idx_one = -1;
    int idx_two = -1;
    for (int i = 0; i < capacity; i++) {
        if (strcmp(label_ls[i], label_one) == 0) {
            idx_one = i;
        } else if (strcmp(label_ls[i], label_two) == 0) {
            idx_two = i;
        }
    }
    if (idx_one == -1 || idx_two == -1) {
        cout << "One of the vertices does not exist" << endl;
        return;
    }
    adj_mat[idx_one][idx_two] = weight;
}


void graph::remove_vertex(char* label) {
    //removes vertex 
    int idx = -1;
    for (int i = 0; i < capacity; i++) {
        if (strcmp(label, label_ls[i]) == 0) {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        cout << "Vertex not there" << endl;
        return;
    }

    // Shift the rows up to remove the vertex row
    for (int i = idx; i < capacity - 1; i++) {
        for (int j = 0; j < capacity; j++) {
            adj_mat[i][j] = adj_mat[i + 1][j];
        }
    }

    // Shift the columns left to remove the vertex column
    for (int j = idx; j < capacity - 1; j++) {
        for (int i = 0; i < capacity; i++) {
            adj_mat[i][j] = adj_mat[i][j + 1];
        }
    }

    // Clear the last row and column
    for (int i = 0; i < capacity; i++) {
        adj_mat[capacity - 1][i] = 0;
        adj_mat[i][capacity - 1] = 0;
    }

    // Shift the labels
    for (int i = idx; i < capacity - 1; i++) {
        strcpy(label_ls[i], label_ls[i + 1]);
    }
    label_ls[capacity - 1][0] = NULL; // Clear the last label

    capacity--;
}

void graph::remove_edge(char* label_one, char* label_two) {
    //removes the edges between the vertices 
    int idx_one = -1;
    int idx_two = -1;
    for (int i = 0; i < capacity; i++) {
        if (strcmp(label_ls[i], label_one) == 0) {
            idx_one = i;
        } else if (strcmp(label_ls[i], label_two) == 0) {
            idx_two = i;
        }
    }
    if (idx_one == -1 || idx_two == -1) {
        cout << "One of the vertices does not exist" << endl;
        return;
    }
    //setting back to 0. ONE DIRECTIONAL
    adj_mat[idx_one][idx_two] = 0;
}

void graph::print() {
    //print for graph. prints matrix 
    //0 means none or else program is gonna pritn weiht 
    for (int i = 0; i < capacity; i++) {
        for (int j = 0; j < capacity; j++) {
            cout << adj_mat[i][j] << " ";
        }
        cout << endl;
    }
}

void graph::dijkstra(char* label_one, char* label_two) {
    //the dijkstras alg to find path 
    int idx_one = -1;
    int idx_two = -1;

    for (int i = 0; i < capacity; i++) {
        if (strcmp(label_one, label_ls[i]) == 0) {
            idx_one = i;
        } else if (strcmp(label_two, label_ls[i]) == 0) {
            idx_two = i;
        }
    }

    if (idx_one == -1 || idx_two == -1) {
        cout << "One of the vertices does not exist" << endl;
        return;
    }

    vector<int> dist(capacity, INT_MAX);
    vector<bool> sptSet(capacity, false);
    dist[idx_one] = 0;

    //https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

    for (int count = 0; count < capacity - 1; count++) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < capacity; v++) {
            if (!sptSet[v] && dist[v] <= min) {
                min = dist[v];
                min_index = v;
            }
        }

        int u = min_index;
        sptSet[u] = true;

        for (int v = 0; v < capacity; v++) {
            if (!sptSet[v] && adj_mat[u][v] && dist[u] != INT_MAX && dist[u] + adj_mat[u][v] < dist[v]) {
                dist[v] = dist[u] + adj_mat[u][v];
            }
        }
    }

    //printing out the shortest path from dijkstras algorithm 
    if (dist[idx_two] != INT_MAX) {
        cout << "The shortest path costs " << dist[idx_two] << endl;
    } else {
        cout << "There is no path" << endl;
    }
}


