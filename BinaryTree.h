#pragma once
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

template<class T>
struct BinaryTreeNode
{
T _data;
BinaryTreeNode<T> *_left;
BinaryTreeNode<T> *_right;
BinaryTreeNode(const T& d)
:_data(d)
,_left(NULL)
,_right(NULL)
{}
};
template<class  T>
class BinaryTree
{
public:
BinaryTree()
:_root(NULL)
{}
BinaryTree(const T* a, size_t size, const T& invalid)
{
size_t index = 0;
_root = _Create(a, size, index, invalid);
}
void PrevInorder()
{
_PrevInorder(_root);
cout << endl;
}

void PrevIorder_R()  //先压右，在压左
{
	stack<BinaryTreeNode<T> *> s;
	if (_root)
	{
		s.push(_root);
	}
	while (!s.empty())
	{
		BinaryTreeNode<T> *top = s.top();//取栈顶
		s.pop();
		cout << top->_data << " ";  //访问栈顶元素
		if (top->_right != NULL)
		{
			s.push(top->_right);
		}
		if (top->_left != NULL)
		{
			s.push(top->_left);
		}
	}
	cout << endl;
		
}
//void PrevIorde_R()
//{
//BinaryTreeNode<T> *cur = _root;
//stack<BinaryTreeNode<T>*>  s;
//while (cur || !(s.empty()))
//{
//	while (cur)
//	{
//		cout << cur->_data << " ";
//		s.push(cur);
//		cur = cur->_left;
//	}
//	BinaryTreeNode<T> *top = s.top();
//	s.pop();
//	cur = top->_right;
//}
//cout << endl;
//}
void InInorder()
{
_InInorder(_root);
cout << endl;
}
void InInorder_R()
{
BinaryTreeNode<T> *cur = _root;
stack<BinaryTreeNode<T> *> s;
while (cur || !s.empty())
{
	while (cur)
	{
		s.push(cur);
		cur = cur->_left;
	}
	BinaryTreeNode<T> *top = s.top();
	cout << top->_data << " ";
	s.pop();
	cur = top->_right;
}
cout << endl;
}
void PostInorder()
{
_PostInorder(_root);
cout << endl;

}
	
void PostInorder_R()
{
BinaryTreeNode<T> *cur = _root;
BinaryTreeNode<T> *prev = NULL;  //保存前一个节点
stack<BinaryTreeNode<T> *> s;
s.push(_root);
while ( !s.empty())
{
	cur = s.top();
	if ((cur->_left == NULL&&cur->_right == NULL)
		|| ((prev != NULL)
		&& (prev == cur->_left || prev == cur->_right)))
	{
		cout << cur->_data << " ";
		s.pop();
		prev = cur;
	}
	else
	{
		if (cur->_right != NULL)
			s.push(cur->_right);
		if (cur->_left != NULL)
			s.push(cur->_left);
	}
}
cout << endl;
}

void LevelOrder() //层次遍历（队列实现）
{
	queue<BinaryTreeNode<T>*> q;
	if (_root != NULL)
	{
		q.push(_root);
	}
	while (!q.empty())
	{
		BinaryTreeNode<T> *front = q.front();
		cout << front->_data << " ";
		if (front->_left != NULL)
		{
			q.push(front->_left);
		}
		if (front->_right != NULL)
		{
			q.push(front->_right);
		}
		q.pop();
	}
	cout << endl;
}
void Size()
{
size_t size = 0;
	_Size(_root,size);
	cout << "size:" << size;
	cout << endl;
}
void Depth()
{
size_t depth = 0;
depth= _Depth(_root);
cout <<"depth"<< depth << endl;
}
void  LeafSize()
{
size_t ls = 0;
ls = _LeafSize(_root);
cout << "LeafSize:" << ls << endl;
}
protected:
BinaryTreeNode<T>* _Create(const T* a, size_t size, size_t& index, const T& invalid)
{
BinaryTreeNode<T> *root = NULL;
while ((index < size) && (a[index] != invalid))
{
	root = new BinaryTreeNode<T>(a[index]);
	root->_left = _Create(a, size, ++index, invalid);
	root->_right = _Create(a, size, ++index, invalid);
}
return root;
}
void _PrevInorder(BinaryTreeNode<T> *root)
{
if (root == NULL)
{
	return;
}
	cout << root->_data << " ";
	_PrevInorder(root->_left);
	_PrevInorder(root->_right);
}
void _InInorder(BinaryTreeNode<T> *root)
{
if (root == NULL)
{
	return;
}
_InInorder(root->_left);
cout << root->_data << " ";
_InInorder(root->_right);
}
void _PostInorder(BinaryTreeNode<T> *root)
{
if (root == NULL)
{
	return;
}
_PostInorder(root->_left);
_PostInorder(root->_right);
cout << root->_data << " ";
}
size_t  _Size(BinaryTreeNode<T> *root, size_t &sz)
{
if (root == NULL)
{
	return 0;
}
	sz++;
	_Size(root->_left, sz);
	_Size(root->_right, sz);
		 
}
size_t _Depth(BinaryTreeNode<T> *root)
{
if (root == NULL)
{
	return 0;
}
size_t left = _Depth(root->_left);
size_t right = _Depth(root->_right);
return left > right ? left + 1 : right + 1;
}
size_t _LeafSize(BinaryTreeNode<T> *root)
{
if (root == NULL)
{
	return 0;
}
if (root->_left == NULL&&root->_right == NULL)
{
	return 1;
}
return  _LeafSize(root->_left) + _LeafSize(root->_right);
}

protected:
BinaryTreeNode<T> *_root;
};
void test()
{
int a1[10] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6, };
int a2[9] = { 1, 2, 3, '#', '#', 4, '#', '#', 5 };
BinaryTree<int> b1(a1, 10, '#');
BinaryTree<int> b2(a2, 9, '#');
b1.PrevInorder();
b1.PrevIorder_R();
b1.InInorder();
b1.InInorder_R();
b1.PostInorder();
b1.PostInorder_R();
b1.LevelOrder();
b1.Size();
b2.Size();
b1.Depth();
b2.Depth();
b1.LeafSize();
b2.LeafSize();
}