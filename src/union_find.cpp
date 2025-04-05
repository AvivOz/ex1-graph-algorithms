// Author: avivoz4@gmail.com

#include "../include/union_find.hpp"
#include <stdexcept>

namespace graph {

    UnionFind::UnionFind(int n) : size(n) {
        parent = new int[n];
        rank = new int[n];

        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    UnionFind::~UnionFind() {
        delete[] parent;
        delete[] rank;
    }

    int UnionFind::find(int x) {

        if (x < 0 || x >= size) {
            throw std::out_of_range("Element index out of range");
        }

        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void UnionFind::unionSets(int x, int y) {

        if (x < 0 || x >= size || y < 0 || y >= size) {
            throw std::out_of_range("Element index out of range");
        }

        int rootX = find(x);
        int rootY = find(y);

        if (rootX == rootY) return;

        // Union by rank
        if (rank[rootX] < rank[rootY]) {
            parent[rootX] = rootY;
        } else if (rank[rootX] > rank[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rank[rootX]++;
        }
    }

}
