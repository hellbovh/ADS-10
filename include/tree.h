// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <iostream>
#include <vector>
#include <algorithm>

struct Node {
  bool isRoot = false;
  char ch;
  std::vector<Node*> nodes;
};

class Tree {
 private:
  Node* root;
  std::vector<std::vector<char>> perms;
  void insertNode(Node * root, const std::vector<char>&chars) {
    for (char ch : chars) {
      Node* tnode = new Node;
      tnode->ch = ch;
      root->nodes.push_back(tnode);
      std::vector<char> remainch(chars);
      remainch.erase(std::find(remainch.begin(), remainch.end(), ch));
      insertNode(tnode, remainch);
    }
  }

  void findPerm(Node * root, std::vector<char> chars) {
    if (!root->isRoot)
      chars.push_back(root->ch);
    if (root->nodes.empty()) {
      perms.push_back(chars);
    } else {
      for (Node* child : root->nodes) {
        findPerm(child, chars);
      }
    }
  }
  
 public:
  explicit Tree(const std::vector<char>&chars) {
    root = new Node;
    root->isRoot = true;
    insertNode(root, chars);
    std::vector<char> cur;
    findPerm(root, cur);
  }
  std::vector<std::vector<char>> getPermutations() const {
    return perms;
  }
};

#endif  // INCLUDE_TREE_H_
