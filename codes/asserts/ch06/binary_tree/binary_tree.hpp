//
// Created by HRF on 2023/1/6.
//

#ifndef ESSENTIAL_CPP_BINARY_TREE_HPP
#define ESSENTIAL_CPP_BINARY_TREE_HPP

#include <iostream>
#include <string>

using namespace std;

template<typename Type>
class BinaryTree;

template<typename valType>
class BTnode {
    friend class BinaryTree<valType>;

public:
    explicit BTnode(const valType &);

    void insert_value(const valType &);

    static void lchild_leaf(BTnode *leaf, BTnode *subtree);

    void remove_value(const valType &val, BTnode *&prev);

    void preorder(BTnode *pt, ostream &os) const;

    void inorder(BTnode *pt, ostream &os) const;

    void postorder(BTnode *pt, ostream &os) const;

    void display_val(BTnode *pt, ostream &os) const;

private:
    valType _val;
    int _cnt;
    BTnode *_lchild;
    BTnode *_rchild;
};

template<typename elemType>
class BinaryTree {
public:
    BinaryTree();

    BinaryTree(const BinaryTree &);

    ~BinaryTree();

    BinaryTree &operator=(const BinaryTree &);

    bool empty() { return _root == 0; }

    void clear() {
        if (_root) {
            clear(_root);
            _root = 0;
        }
    }

    void insert(const elemType &);

    void remove(const elemType &);

    void preorder() const { _root->preorder(_root, cout); }

    void inorder() const { _root->inorder(_root, cout); }

    void postorder() const { _root->postorder(_root, cout); }

private:
    BTnode<elemType> *_root;

    void clear(BTnode<elemType> *pt);

    // 将src所指的子树复制到tar所指的子树
    void copy(BTnode<elemType> *tar, BTnode<elemType> *src);
    void remove_root();
};
template<typename valType>
inline BTnode<valType>::BTnode(const valType &val): _val(val) {
    _cnt = 1;
    _lchild = _rchild = 0;
}

template<typename valType>
void BTnode<valType>::insert_value(const valType &val) {
    if (_val == val) {
        _cnt++;
        return;
    }
    if (val < _val) {
        if (!_lchild)
            _lchild = new BTnode(val);
        else
            _lchild->insert_value(val);
    } else {
        if (!_rchild)
            _rchild = new BTnode(val);
        else
            _rchild->insert_value(val);
    }
}

template<typename valType>
void BTnode<valType>::lchild_leaf(BTnode *leaf, BTnode *subtree) {
    while (subtree->_lchild)
        subtree = subtree->_lchild;
    subtree->_lchild = leaf;
}

template<typename valType>
void BTnode<valType>::remove_value(const valType &val, BTnode *&prev) {
    if (val < _val) {
        if (!_lchild)
            // 不在此二叉树中
            return;
        else
            _lchild->remove_value(val, _lchild);
    } else if (val > _val) {
        if (!_rchild)
            return;
        else
            _rchild->remove_value(val, _rchild);
    } else {
        // 找到了，重置此树，然后删除这个节点
        if (_rchild) {
            prev = _rchild;
            if (_lchild) {
                if (!prev->_lchild)
                    prev->_lchild = _lchild;
                else
                    BTnode<valType>::lchild_leaf(_lchild, prev->_lchild);
            }
        } else {
            prev = _lchild;
        }
        delete this;
    }
}

template<typename valType>
void BTnode<valType>::preorder(BTnode *pt, ostream &os) const {
    if(pt) {
        display_val(pt, os);
        if (pt->_lchild) {
            preorder(pt->_lchild, os);
        }
        if (pt->_rchild) {
            preorder(pt->_rchild, os);
        }
    }
}

template<typename valType>
void BTnode<valType>::inorder(BTnode *pt, ostream &os) const {
    if(pt) {
        if (pt->_lchild) {
            inorder(pt->_lchild, os);
        }
        display_val(pt, os);
        if (pt->_rchild) {
            inorder(pt->_rchild, os);
        }
    }
}

template<typename valType>
void BTnode<valType>::postorder(BTnode *pt, ostream &os) const {
    if(pt) {
        if (pt->_lchild) {
            postorder(pt->_lchild, os);
        }
        if (pt->_rchild) {
            postorder(pt->_rchild, os);
        }
        display_val(pt, os);
    }
}

template<typename valType>
void BTnode<valType>::display_val(BTnode *pt, ostream &os) const {
    os << pt->_val;
    if (pt->_cnt > 1)
        os << "( " << pt->_cnt <<" )";
    else
        os << " ";
}

template<typename elemType>
inline BinaryTree<elemType>::BinaryTree() : _root(0) {}

template<typename elemType>
inline BinaryTree<elemType>::BinaryTree(const BinaryTree &rhs) {
    copy(_root, rhs._root);
}

template<typename elemType>
inline BinaryTree<elemType>::~BinaryTree() {
    clear();
}

template<typename elemType>
BinaryTree<elemType> &BinaryTree<elemType>::operator=(const BinaryTree &rhs) {
    if (this != &rhs) {
        clear();
        copy(_root, rhs._root);
    }
    return *this;
}

template<typename elemType>
void BinaryTree<elemType>::insert(const elemType &elem) {
    if (!_root)
        _root = new BTnode<elemType>(elem);
    else
        _root->insert_value(elem);
}

template<typename elemType>
inline void BinaryTree<elemType>::remove(const elemType &elem) {
    if (_root) {
        if (_root->_val == elem)
            // 根节点的移除操作做特殊处理
            remove_root();
        else
            _root->remove_value(elem, _root);
    }
}

template<typename elemType>
void BinaryTree<elemType>::remove_root() {
    if (!_root) return;

    BTnode<elemType> *tmp = _root;
    if (_root->_rchild) {
        _root = _root->_rchild;

        // 将左子节点搬移到右子节点的左子树的底部
        if (tmp->_rchild) {
            BTnode<elemType> *lc = tmp->_lchild;
            BTnode<elemType> *newlc = _root->_lchild;
            if (!newlc)
                _root->_lchild = lc;
            // 遍历整个左子树
            else BTnode<elemType>::lchild_leaf(lc, newlc);
        }
    } else {
        _root = _root->_lchild;
    }

    delete tmp;
}

template<typename elemType>
void BinaryTree<elemType>::clear(BTnode<elemType> *pt) {
    if (pt) {
        clear(pt->_lchild);
        clear(pt->_rchild);
        delete pt;
    }
}

template<typename elemType>
void BinaryTree<elemType>::copy(BTnode<elemType> *tar, BTnode<elemType> *src) {
    if (src) {
        tar = new BTnode<elemType>(src->_val);
    }
    if (src->_lchild)
        copy(tar->_lchild, src->_lchild);
    if (src->_rchild)
        copy(tar->_rchild, src->_rchild);
}

#endif //ESSENTIAL_CPP_BINARY_TREE_HPP
