#include<iostream>
#include<vector>
#include"functions.h"

using namespace std;

int main() {
	system("chcp 1251>nul");

	vector<vector<int>> adj_matr;
	adj_matr = { {0, 0, 0, 0, 0},{1, 0, 0, 1, 0},{1, 0, 0, 0, 0},{0, 0, 1, 0, 1},{0, 0, 1, 0, 1} };
	print_adjmatr(adj_matr);

	int adj_vec_len = 0;
	vector<vector<int>> adj_vec = adjvec(adj_matr, adj_vec_len);
	print_adjvec(adj_vec, adj_vec_len);
	
	vector<vector<int>> edge_list = edgelist(adj_matr);
	print_edgelist(edge_list);

	vector<vector<int>> adj_list = adjlist(adj_matr);
	print_adjlist(adj_list);

	vector<vector<int>> inc_matr = incmatr(adj_matr);
	print_incmatr(inc_matr);

	vector<vector<int>> adj_matr2 = from_adjvec(adj_vec);
	print_adjmatr(adj_matr2);

	vector<vector<int>> adj_matr3 = from_adjlist(adj_list);
	print_adjmatr(adj_matr3);

	vector<vector<int>> adj_matr4 = from_edgelist(edge_list);
	print_adjmatr(adj_matr4);

	vector<vector<int>> adj_matr5 = from_incmatr(inc_matr); // получение adj_list из inc_matr;
	print_adjmatr(adj_matr5);

	vector<vector<int>> adj_list2 = adjlist(adj_matr5);
	print_adjlist(adj_list2);

	return 0;
}