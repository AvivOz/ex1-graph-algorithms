#pragma once

namespace graph {

    /**
     * @brief A simple Union-Find (Disjoint Set Union) data structure.
     * 
     * Supports union and find operations with path compression.
     * Used for cycle detection in Kruskal's algorithm.
     */
    class UnionFind {
    private:
        int* parent; ///< parent[i] holds the parent of node i.
        int* rank;   ///< rank[i] approximates the depth of tree rooted at i.
        int size;    ///< Total number of elements (vertices).

    public:
        /**
         * @brief Constructs a Union-Find structure with n elements.
         * 
         * Initially, each element is in its own set.
         * 
         * @param n The number of elements.
         */
        UnionFind(int n);

        /**
         * @brief Destructor – frees all allocated memory.
         */
        ~UnionFind();

        /**
         * @brief Finds the root of the set containing the given element.
         * 
         * Uses path compression for optimization.
         * 
         * @param x The element whose set to find.
         * @return The representative (root) of the set.
         */
        int find(int x);

        /**
         * @brief Unites the sets containing x and y.
         * 
         * Uses union by rank optimization.
         * 
         * @param x An element in the first set.
         * @param y An element in the second set.
         */
        void unionSets(int x, int y);
    };

}
