#pragma once
#include<vector>

using namespace std;

//������� �������� �� ������� ��������� � ������ �������������
vector<vector<int>> adjvec(vector<vector<int>> adj_matr, int& max_len);
vector<vector<int>> adjlist(vector<vector<int>> adj_matr);
vector<vector<int>> edgelist(vector<vector<int>> adj_matr);
vector<vector<int>> incmatr(vector<vector<int>> adj_matr);

//������� ������ ������� �������������
void print_adjvec(vector<vector<int>> adj_vec, int len);
void print_adjlist(vector<vector<int>> adj_list);
void print_edgelist(vector<vector<int>> edge_list);
void print_adjmatr(vector<vector<int>> adj_matr);
void print_incmatr(vector<vector<int>> inc_matr);

//������� �������� � ������� ��������� ������� �������������
vector<vector<int>> from_adjvec(vector<vector<int>> adj_vec);
vector<vector<int>> from_adjlist(vector<vector<int>> adj_list);
vector<vector<int>> from_edgelist(vector<vector<int>> edge_list);
vector<vector<int>> from_incmatr(vector<vector<int>> inc_matr);

//��������������� �������
int find_max(vector<vector<int>> vec);  // ����� ������������� ������ ������� � edge_list