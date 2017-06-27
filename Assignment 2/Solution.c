#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	char colour;
	struct node *leftChild;
	struct node *parent;
	struct node *rightChild;
};

typedef struct node rbt;

rbt* right_rotate(rbt* root, rbt* p);
rbt* left_rotate(rbt* root, rbt* p);
rbt* insert_fixup(rbt* root, rbt* p);
rbt* insert(rbt* root, int d );
int Visit(rbt* root, rbt* p);
int Pre_fix_tour(rbt* root);


rbt *temp;
int q;



rbt* right_rotate(rbt* root, rbt* s)
{
	rbt *y;
	y = s->leftChild;
	s->leftChild = y->rightChild;
	if (y->rightChild != NULL)
	{
		y->rightChild->parent = s;
	}
	y->parent = s->parent;
	rbt *temp=s;
	if(s->parent == NULL)
	{
		root = y;
	}
	else if (s == s->parent->leftChild)
	{
		s->parent->leftChild = y;
	}
	else
	{
		s->parent->rightChild = y;
	}
	y->rightChild = temp;
	temp->parent = y;
	return root;
}

rbt* left_rotate(rbt* root, rbt* r)
{
	rbt *y;
	y = r->rightChild;
	r->rightChild = y->leftChild;
	if (y->leftChild != NULL)
	{
		y->leftChild->parent = r;
	}
	y->parent = r->parent;
	rbt *temp=r;
	if(r->parent == NULL)
	{
		root = y;
	}
	else if (r == r->parent->leftChild)
	{
		r->parent->leftChild = y;
	}
	else
	{
		r->parent->rightChild = y;
	}
	y->leftChild = temp;
	temp->parent = y;
	return root;
}

rbt* insert_fixup(rbt* root, rbt* p)
{
	rbt *y, *w;
	int count =0;
	while((p != root) && (p->colour != 'B') && (p->parent->colour == 'R'))
	{
		
		if(p->parent == root){
			p->parent->colour = 'B';
			return root;
		}
		
		if (p->parent == p->parent->parent->leftChild)
		{
			y = p->parent->parent->rightChild;
			if((y != NULL) && (y->colour == 'R'))
			{
				w = p->parent->parent;
				p->parent->colour = 'B';
				y->colour = 'B';
				p->parent->parent->colour = 'R';
				p = w;
			}
			else 
			{
				if (p == p->parent->rightChild)
				{
					w = p->parent;
					root = left_rotate(root, p->parent);
					p = w;						
				}
				else
				{
					w = p->parent;
					char t = p->parent->colour;
					p->parent->colour = p->parent->parent->colour;
					p->parent->parent->colour = t;
					root = right_rotate(root,  p->parent->parent);
				}
			}											
		}
		else
		{
			y = p->parent->parent->leftChild;
			if((y != NULL) && (y->colour == 'R'))
			{
				w = p->parent->parent;
				p->parent->colour = 'B';
				y->colour = 'B';
				p->parent->parent->colour = 'R';
				p = w;
			}
			else 
			{
				if (p == p->parent->leftChild)
				{
					w = p->parent;
					root = right_rotate(root, p->parent);
					p = w;						
				}
				else
				{
					w = p->parent;
					char t = p->parent->colour;
					p->parent->colour = p->parent->parent->colour;
					p->parent->parent->colour = t;
					root = left_rotate(root, p->parent->parent);
				}
			}	
		 }
	}
	// q=Pre_fix_tour(root);
	root->colour = 'B';
	return root;
}

rbt* insert(rbt* root, int d )
{
	rbt *p = (rbt*)malloc(sizeof(rbt));
	p->data = d;
	p->leftChild = NULL;
	p->rightChild = NULL;
	p->colour = 'R';
	p->parent = NULL;
	rbt *x = root;
	rbt *y = NULL;
	if (root == NULL)
	{
		root = p;
		root->colour = 'B';
		return root;
	}
	while(x != NULL)
	{
		y = x;
		if (p->data < x->data)
		{
			if(x->leftChild==NULL){
				x->leftChild=p;
				break;
			}
			x = x->leftChild;
		}
		else
		{
			if(x->rightChild==NULL){
				x->rightChild=p;
				break;
			}
			x = x->rightChild;
		}
	}
	p->parent = y;
	if (y == NULL)
	{
		root = p;
	}
	
	root = insert_fixup( root, p);
	return root;
}

int Visit(rbt* root,rbt* p)
{
	if (p == root)
	{
		q = Visit(root,p->leftChild);
		printf("%d %c NIL\n", p->data, p->colour);
		q = Visit(root,p->rightChild);
	}
	else if (p != NULL)
	{
		q = Visit(root,p->leftChild);
		printf("%d %c %d\n", p->data, p->colour, p->parent->data);
		q = Visit(root,p->rightChild);
	}
	return 0;
}

int Pre_fix_tour(rbt* root)
{
	if (root == NULL)
	{
		printf("Empty Tree");
	}
	else
	{
		q = Visit(root,root);
	}
	return 0;
}

int main() 
{
	rbt *root = NULL;
	int n,i,p;
	scanf("%d", &n);
	for (i = 1; i <= n; ++i)
	{
		scanf("%d", &p);
		root = insert( root, p);
	}
	
	Pre_fix_tour(root);
	return 0;
}