#include<iostream>
#include<vector>
#include"functions.h"

using namespace std;

//функции перевода из матрицы смежности в другие представления
vector<vector<int>> adjvec(vector<vector<int>> adj_matr, int& max_len) {
	vector<vector<int>> adj_vec;
	int max_tmp;

	for (size_t i = 0; i < adj_matr.size(); i++) {
		max_tmp = 0;
		adj_vec.push_back({});
		for (size_t j = 0; j < adj_matr[i].size(); j++) {
			if (adj_matr[i][j] != 0) {
				adj_vec[i].push_back(j + 1);
				max_tmp++;
			}
		}
		if (max_tmp > max_len) {
			max_len = max_tmp;
		}
	}

	return adj_vec;
}
vector<vector<int>> adjlist(vector<vector<int>> adj_matr) {
	vector<vector<int>> adj_list;

	for (size_t i = 0; i < adj_matr.size(); i++) {
		adj_list.push_back({});
		for (size_t j = 0; j < adj_matr[i].size(); j++) {
			if (adj_matr[i][j] != 0) {
				adj_list[i].push_back(j + 1);
			}
		}
	}

	return adj_list;
}
vector<vector<int>> edgelist(vector<vector<int>> adj_matr) {
	vector<int> g, h;
	vector<vector<int>> res;

	for (size_t i = 0; i < adj_matr.size(); i++) {
		for (size_t j = 0; j < adj_matr[i].size(); j++) {
			if (adj_matr[i][j] != 0) {
				g.push_back(i + 1);
				h.push_back(j + 1);
			}
		}
	}

	res.push_back(g);
	res.push_back(h);

	return res;
}
vector<vector<int>> incmatr(vector<vector<int>> adj_matr) {
	vector<vector<int>> inc_matr;

	vector<vector<int>> edge_list = edgelist(adj_matr);

	for (size_t i = 0; i < adj_matr.size(); i++) {
		inc_matr.push_back({});
		for (size_t j = 0; j < edge_list[0].size(); j++) {
			inc_matr[i].push_back(0);
		}
	}

	for (size_t i = 0; i < edge_list[0].size(); i++) {
		if (edge_list[0][i] != edge_list[1][i]) {
			inc_matr[edge_list[0][i] - 1][i] = 1;
			inc_matr[edge_list[1][i] - 1][i] = -1;
		}
		else {
			inc_matr[edge_list[0][i] - 1][i] = 2;
		}
	}

	return inc_matr;
}

//функции печати каждого представления
void print_adjlist(vector<vector<int>> adj_list) {
	cout << "\n\nСписки смежности:\n";
	for (size_t i = 0; i < adj_list.size(); i++) {
		cout << i + 1 << " => ";
		if (adj_list[i].size() == 0) {
			cout << "NULL";
		}
		for (size_t j = 0; j < adj_list[i].size(); j++) {
			cout << adj_list[i][j];
			if (j + 1 < adj_list[i].size()) {
				cout << " -> ";
			}
		}
		cout << endl;
	}
}
void print_adjvec(vector<vector<int>> adj_vec, int len) {
	cout << "\n\nВекторы смежности:\n";
	for (size_t i = 0; i < adj_vec.size(); i++) {
		cout << i + 1 << ": ";
		for (size_t j = 0; j < len; j++) {
			if (j >= adj_vec[i].size()) {
				cout << 0 << " ";
			}
			else {
				cout << adj_vec[i][j] << " ";
			}
		}
		cout << endl;
	}
}
void print_adjmatr(vector<vector<int>> adj_matr) {
	cout << "\n\nМатрица смежности:\n";
	for (size_t i = 0; i < adj_matr.size(); i++) {
		for (size_t j = 0; j < adj_matr[i].size(); j++) {
			cout << adj_matr[i][j] << " ";
		}
		cout << endl;
	}
}
void print_edgelist(vector<vector<int>> edge_list) {
	cout << "\n\nСписок ребер:\n";
	cout << "g: ";
	for (size_t i = 0; i < edge_list[0].size(); i++) {
		cout << edge_list[0][i] << " ";
	}
	cout << "\nh: ";
	for (size_t i = 0; i < edge_list[1].size(); i++) {
		cout << edge_list[1][i] << " ";
	}
	cout << endl;
}
void print_incmatr(vector<vector<int>> inc_matr) {
	cout << "\n\nМатрица инцидентности:\n";
	for (size_t i = 0; i < inc_matr.size(); i++) {
		for (size_t j = 0; j < inc_matr[i].size(); j++) {
			if (inc_matr[i][j] != -1) {
				cout << " ";
			}
			if (inc_matr[i][j] == 2) {
				cout << 0 << " ";
			}
			else {
				cout << inc_matr[i][j] << " ";
			}
		}
		cout << endl;
	}
}

//функции перевода в матрицу смежности каждого представления
vector<vector<int>> from_adjvec(vector<vector<int>> adj_vec) {
	vector<vector<int>> adj_matr;
	for (size_t i = 0; i < adj_vec.size(); i++) {
		adj_matr.push_back({});
		for (size_t j = 0; j < adj_vec.size(); j++) {
			adj_matr[i].push_back(0);
		}
	}

	for (size_t i = 0; i < adj_vec.size(); i++) {
		for (size_t j = 0; j < adj_vec[i].size(); j++) {
			adj_matr[i][adj_vec[i][j] - 1] = 1;
		}
	}

	return adj_matr;
}
vector<vector<int>> from_adjlist(vector<vector<int>> adj_list) {
	vector<vector<int>> adj_matr;

	for (size_t i = 0; i < adj_list.size(); i++) {
		adj_matr.push_back({});
		for (size_t j = 0; j < adj_list.size(); j++) {
			adj_matr[i].push_back(0);
		}
	}

	for (size_t i = 0; i < adj_list.size(); i++) {
		for (size_t j = 0; j < adj_list[i].size(); j++) {
			adj_matr[i][adj_list[i][j] - 1] = 1;
		}
	}

	return adj_matr;
}
vector<vector<int>> from_edgelist(vector<vector<int>> edge_list) {
	vector<vector<int>> adj_matr;

	int size = find_max(edge_list);

	for (int i = 0; i < size; i++) {
		adj_matr.push_back({});
		for (int j = 0; j < size; j++) {
			adj_matr[i].push_back(0);
		}
	}

	for (size_t i = 0; i < edge_list[0].size(); i++) {
		adj_matr[edge_list[0][i] - 1][edge_list[1][i] - 1] = 1;
	}

	return adj_matr;
}
vector<vector<int>> from_incmatr(vector<vector<int>> inc_matr) {
	vector<vector<int>> adj_matr;

	vector<vector<int>> edge_list = { {}, {} };

	for (size_t j = 0; j < inc_matr[0].size(); j++) {
		for (size_t i = 0; i < inc_matr.size(); i++) {
			if (inc_matr[i][j] == 1) {
				edge_list[0].push_back(i + 1);
			}
			else if (inc_matr[i][j] == -1) {
				edge_list[1].push_back(i + 1);
			}
			else if (inc_matr[i][j] == 2) {
				edge_list[0].push_back(i + 1);
				edge_list[1].push_back(i + 1);
			}
		}
	}

	adj_matr = from_edgelist(edge_list);

	return adj_matr;
}

//вспомогательные функции
int find_max(vector<vector<int>> vec) {
	int max = 0;
	for (size_t i = 0; i < vec[0].size(); i++) {
		if (vec[0][i] > max) {
			max = vec[0][i];
		}
		if (vec[1][i] > max) {
			max = vec[0][i];
		}
	}
	return max;
}
