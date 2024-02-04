#include <vector>
#include <unordered_map>

class CellRemoval {
public:
    std::unordered_map<int, std::vector<int>> tree;

    int count_cells(int node, int deletedCell) {
        
        if (node == deletedCell) {
            return 0;
        }
        
        // searched node is a leaf
        if (tree.find(node) == tree.end()) {
            return 1;
        }
        // count number of leaf nodes on left and right sides assuming binary tree formation
        int left = (tree[node].size() > 0) ? count_cells(tree[node][0], deletedCell) : 0;
        int right = (tree[node].size() > 1) ? count_cells(tree[node][1], deletedCell) : 0;
        return left + right;
    }

    int cellsLeft(std::vector<int> parent, int deletedCell) {
        tree.clear(); // clear 
        
        // build tree
        for (int i = 0; i < parent.size(); ++i) {
            tree[parent[i]].push_back(i);
        }

        // COUNT CELS FROM PARENT NODE
        return count_cells(-1, deletedCell);
    }
};
