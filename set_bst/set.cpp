#include "set.h"

treenode *copynodes(treenode *original) {
  if (original != nullptr){
    treenode* neuetr = new treenode(original->value);
  neuetr->left=copynodes(original->left);
  neuetr->right=copynodes(original->right);
  return neuetr;
 }
  return nullptr;
}

void deallocatenodes(treenode* node) {
  if (node == nullptr)
    return;
  deallocatenodes (node->right);
  deallocatenodes (node->left);
  delete node;
}

bool contains2(treenode* n, int i){
  while (n != nullptr) {
    if (n->value < i) {
      n = n->right;
    } else if (n->value > i) {
      n = n->left;
    } else if (n->value == i) {
      return true;
    }
  }
  return false;
}


bool set::contains(int i) const { return contains2(root, i); }

bool insert2(treenode *&rt, int val) {
  if (rt!=nullptr)
  {
    if (rt->value==val)
      return false;
    else if (rt->value<val)
      return insert2(rt->right, val);
    else if (rt->value>val)
      return insert2(rt->left, val);
  }
  else {
    rt=new treenode(val);
    return true;
  }
}

bool set::insert(int i) {
  if (!(insert2(root,i))){
    return false;
  }
  set_size++;
  return true;
}

void set::clear() { 
  deallocatenodes(this->root);
  this->root = nullptr;
  set_size=0;
}

size_t set::size() const { return set_size; }

bool set::empty() const { 
  if (set_size!=0) {
    return false;
  } else {
    return true;
  }
  return true;  
}
