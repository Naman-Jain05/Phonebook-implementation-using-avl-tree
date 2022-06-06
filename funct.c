#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include"head.h"


int max(int a, int b)
 {
  return (a > b) ? a : b;
}

int height(struct per_tree_node  *N) 			//get height of personal	
{
	int retval;
  	if (N == NULL)
  	{
  		retval=0;		
  	}
  	else
  	{
  		retval=N->hight;
  	}
    return retval;
}

int prof_height(struct prof_tree_node  *N)			//get height of professional 
{
	int retval;
  	if (N == NULL)
  	{
  		retval=0;		
  	}
  	else
  	{
  		retval=N->hight;
  	}
    return retval;
}

struct per_tree_node* per_create_node(int n, Entry e) 				//creating new node and setting values in personal
{	
	struct per_tree_node* newnode;
	newnode = (struct per_tree_node*)(malloc(sizeof(struct per_tree_node)));
	newnode->data = e;
	newnode->phoneNo=n;
	newnode->hight=1;
	newnode->data.type=0;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

struct prof_tree_node* prof_create_node(int n, profEntry pe)		//creating new node and setting values in professional
{	
	struct prof_tree_node* newnode;
	newnode = (struct prof_tree_node*)(malloc(sizeof(struct prof_tree_node)));
	newnode->data = pe;
	newnode->phoneNo=n;
	newnode->hight=1;
	newnode->data.type=1;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

int getBalance(struct per_tree_node *N) 			//gives balance factor in personal node
{
  int retval;
  if (N == NULL)
  {
  	retval=0;
  }
  else
  {
  	retval=height(N->left) - height(N->right);
  }
  return retval;
}

int prof_getBalance(struct prof_tree_node *N)		//gives balance factor in professional node
{
  int retval;
  if (N == NULL)
  {
  	retval=0;
  }
  else
  {
  	retval=prof_height(N->left) - prof_height(N->right);
  }
  return retval;
}

void per_inorder(struct per_tree_node* root)		//personal inorder
{
    if (root != NULL) 
	{
		sc=success;
        per_inorder(root->left);
        printf("%d :%d :%s :%s :%s\n",root->phoneNo,getBalance(root),root->data.name,root->data.last_name,root->data.mail);
		per_inorder(root->right);
    }
}

void per_inorder_rev(struct per_tree_node* root)		//in reverse order right->print->left
{
    if (root != NULL) 
	{
		sc=success;
        per_inorder_rev(root->right);
        printf("%d :%d :%s :%s :%s\n",root->phoneNo,getBalance(root),root->data.name,root->data.last_name,root->data.mail);
		per_inorder_rev(root->left);
    }
}

void prof_inorder(struct prof_tree_node* root)			//professional inorder
{
    if (root != NULL) 
	{
		sc=success;
        prof_inorder(root->left);
        printf("%d :%d :%s :%s :%s :%s :%s %d\n",root->phoneNo,prof_getBalance(root),root->data.name,root->data.last_name,root->data.mail,root->data.address,root->data.institute,root->data.officeNo);
		prof_inorder(root->right);
    }
}

void prof_inorder_rev(struct prof_tree_node* root)		//in reverse order right->print->left
{
    if (root != NULL) 
	{
		sc=success;
        prof_inorder_rev(root->right);
        printf("%d :%d :%s :%s :%s :%s :%s %d\n",root->phoneNo,prof_getBalance(root),root->data.name,root->data.last_name,root->data.mail,root->data.address,root->data.institute,root->data.officeNo);
		prof_inorder_rev(root->left);
    }
}

void per_range(struct per_tree_node* root,int k1,int k2)
{
   	if (root!=NULL )
    {
      
 	if ( k1 < root->phoneNo)
 	{
 		per_range(root->left, k1, k2);
	}
    
 	if ( k1 <= root->phoneNo && k2 >= root->phoneNo )			//if in range print
 	{
 		sc=success;
 		printf("%d :%d :%s :%s :%s\n",root->phoneNo,getBalance(root),root->data.name,root->data.last_name,root->data.mail);
	}
     
 	per_range(root->right, k1, k2);
 	}
 	
}

void prof_range(struct prof_tree_node* root,int k1,int k2)
{
   	if (root!=NULL )
    {
      
 	if ( k1 < root->phoneNo)
 	{
 		prof_range(root->left, k1, k2);
	}
    
 	if ( k1 <= root->phoneNo && k2 >= root->phoneNo )		//if in range print
 	{
 		sc=success;
 		printf("%d :%d :%s :%s :%s :%s :%s %d\n",root->phoneNo,prof_getBalance(root),root->data.name,root->data.last_name,root->data.mail,root->data.address,root->data.institute,root->data.officeNo);
	}
     
 	prof_range(root->right, k1, k2);
 	}
}

struct per_tree_node *minValueNode(struct per_tree_node *node) 		//get leftmost node
{
  struct per_tree_node *current = node;

  while (current->left != NULL)
  {
  	current = current->left;
  }

  return current;
}


struct prof_tree_node *profminValueNode(struct prof_tree_node *node)  //get leftmost node
{
  struct prof_tree_node *current = node;

  while (current->left != NULL)
  {
  	current = current->left;
  }

  return current;
}

// Right rotate personal
struct per_tree_node *rightRotate(struct per_tree_node *y) 
{
  struct per_tree_node *x = y->left;
  struct per_tree_node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->hight = max(height(y->left), height(y->right)) + 1;
  x->hight = max(height(x->left), height(x->right)) + 1;

  return x;
}

// Left rotate personal
struct per_tree_node *leftRotate(struct per_tree_node *x) 
{
  struct per_tree_node *y = x->right;
  struct per_tree_node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->hight = max(height(x->left), height(x->right)) + 1;
  y->hight = max(height(y->left), height(y->right)) + 1;

  return y;
}


// Right rotate professional
struct prof_tree_node *profrightRotate(struct prof_tree_node *y) 
{
  struct prof_tree_node *x = y->left;
  struct prof_tree_node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->hight = max(prof_height(y->left), prof_height(y->right)) + 1;
  x->hight = max(prof_height(x->left), prof_height(x->right)) + 1;

  return x;
}

// Left rotate professional
struct prof_tree_node *profleftRotate(struct prof_tree_node *x) 
{
  struct prof_tree_node *y = x->right;
  struct prof_tree_node *T2 = y->left;

  y->left = x;
  x->right = T2;

  x->hight = max(prof_height(x->left), prof_height(x->right)) + 1;
  y->hight = max(prof_height(y->left), prof_height(y->right)) + 1;

  return y;
}


struct per_tree_node *insertNode(struct per_tree_node *nod, int key,Entry e)		//insert in personal //phone number is key
{
  if (nod == NULL)
  {
  	return (per_create_node(key, e));
  } 
  if (key < nod->phoneNo)
  {
  	nod->left = insertNode(nod->left, key,e);
  }
  else if (key > nod->phoneNo)
  {
  	nod->right = insertNode(nod->right, key,e);
  }
  else
  {
  	sc=fail;
  	 return nod;
  }
   
  nod->hight = 1 + max(height(nod->left),height(nod->right));

  int balance = getBalance(nod);
  if (balance > 1 && key < nod->left->phoneNo)
  {
  	return rightRotate(nod);
  }
    
  if (balance < -1 && key > nod->right->phoneNo)
  {
  	return leftRotate(nod);
  }
    
  if (balance > 1 && key > nod->left->phoneNo) 
  {
    nod->left = leftRotate(nod->left);
    return rightRotate(nod);
  }

  if (balance < -1 && key < nod->right->phoneNo) 
  {
    nod->right = rightRotate(nod->right);
    return leftRotate(nod);
  }

  return nod;
}


struct prof_tree_node *profinsertNode(struct prof_tree_node *nod, int key,profEntry pe)		//insert in professional 
{
  if (nod == NULL)
  {
  	return (prof_create_node(key, pe));
  } 
  if (key < nod->phoneNo)
  {
  	nod->left = profinsertNode(nod->left, key,pe);
  }
  else if (key > nod->phoneNo)
  {
  	nod->right = profinsertNode(nod->right, key,pe);
  }
  else
  {
  	sc=fail;
  	 return nod;
  }
   
  nod->hight = 1 + max(prof_height(nod->left),prof_height(nod->right));

  int balance = prof_getBalance(nod);
  if (balance > 1 && key < nod->left->phoneNo)
  {
  	return profrightRotate(nod);
  }
    
  if (balance < -1 && key > nod->right->phoneNo)
  {
  	return profleftRotate(nod);
  }
    
  if (balance > 1 && key > nod->left->phoneNo) 
  {
    nod->left = profleftRotate(nod->left);
    return profrightRotate(nod);
  }

  if (balance < -1 && key < nod->right->phoneNo) 
  {
    nod->right = profrightRotate(nod->right);
    return profleftRotate(nod);
  }

  return nod;
}

struct per_tree_node *deleteNode(struct per_tree_node *root, int key)   //delete node from personal
{
  if (root == NULL)
  {
  	return root;
  }
  if (key < root->phoneNo)
  {
  	root->left = deleteNode(root->left, key);
  }
  else if (key > root->phoneNo)
  {
  	root->right = deleteNode(root->right, key);
  }
  
  else 
  {
    if ((root->left == NULL) || (root->right == NULL)) 
	{
      struct per_tree_node *t = root->left ? root->left : root->right;

      if (t == NULL) 
	  {
        t = root;
        root = NULL;
      } 
	  else
	  {
	  	*root = *t;
	  }
      free(t);
    } 
	else 
	{
      struct per_tree_node *temp = minValueNode(root->right);
      root->phoneNo = temp->phoneNo;
      root->right = deleteNode(root->right, temp->phoneNo);
    }
  }

  if (root == NULL)
  {
  	return root;
  }
    
  // Update the balance factor of each node and balance the tree
  root->hight = 1 + max(height(root->left),height(root->right));

  int balance = getBalance(root);
  if (balance > 1 && getBalance(root->left) >= 0)
  {
  	return rightRotate(root);
  }
  if (balance > 1 && getBalance(root->left) < 0) 
  {
    root->left = leftRotate(root->left);
    return rightRotate(root);
  }
  if (balance < -1 && getBalance(root->right) <= 0)
  {
  	return leftRotate(root);
  }
  if (balance < -1 && getBalance(root->right) > 0) 
  {
    root->right = rightRotate(root->right);
    return leftRotate(root);
  }

  return root;
}


struct prof_tree_node *profdeleteNode(struct prof_tree_node *root, int key)  //delete node from professional
{
  if (root == NULL)
  {
  	return root;
  }
  if (key < root->phoneNo)
  {
  	root->left = profdeleteNode(root->left, key);
  }
  else if (key > root->phoneNo)
  {
  	root->right = profdeleteNode(root->right, key);
  }
  
  else 
  {
    if ((root->left == NULL) || (root->right == NULL)) 
	{
      struct prof_tree_node *t = root->left ? root->left : root->right;

      if (t == NULL) 
	  {
        t = root;
        root = NULL;
      } 
	  else
	  {
	  	*root = *t;
	  }
      free(t);
    } 
	else 
	{
      struct prof_tree_node *temp = profminValueNode(root->right);
      root->phoneNo = temp->phoneNo;
      root->right = profdeleteNode(root->right, temp->phoneNo);
    }
  }

  if (root == NULL)
  {
  	return root;
  }
    
  // Update the balance factor of each node and balance the tree
  root->hight = 1 + max(prof_height(root->left),prof_height(root->right));

  int balance = prof_getBalance(root);
  if (balance > 1 && prof_getBalance(root->left) >= 0)
  {
  	return profrightRotate(root);
  }
  if (balance > 1 && prof_getBalance(root->left) < 0) 
  {
    root->left = profleftRotate(root->left);
    return profrightRotate(root);
  }
  if (balance < -1 && prof_getBalance(root->right) <= 0)
  {
  	return profleftRotate(root);
  }
  if (balance < -1 && prof_getBalance(root->right) > 0) 
  {
    root->right = profrightRotate(root->right);
    return profleftRotate(root);
  }

  return root;
}


void search_per(struct per_tree_node* root,int key)		//bst search in O(logN) (binary)
{
    if(root==NULL)
    {
        printf("No such number exist in tree\n");
    }
	else
	{
	
    if(root->phoneNo==key)
    {
    	sc=success;
    	printf("phone-no,height,first-name,last-name,email:\n");
    	printf("%d :%d :%s :%s :%s\n",root->phoneNo,root->hight,root->data.name,root->data.last_name,root->data.mail);
    	
    }
    if(root->phoneNo>key)
    {
        search_per(root->left,key);
    }
    if(root->phoneNo<key)
    {
        search_per(root->right,key);
    } 
	}
    
}

void search_prof(struct prof_tree_node* root,int key)		//bst search in O(logN) (binary)
{
    if(root==NULL)
    {
        printf("No such number exist in tree\n"); 
    }
	else
	{
	
    if(root->phoneNo==key)
    {
    	sc=success;
    	printf("phone-no,height,first-name,last-name,email,address,institute,office-no:\n");
    	printf("%d :%d :%s :%s :%s :%s :%s %d\n",root->phoneNo,root->hight,root->data.name,root->data.last_name,root->data.mail,root->data.address,root->data.institute,root->data.officeNo);
    
    }
    if(root->phoneNo>key)
    {
        search_prof(root->left,key);
    }
    if(root->phoneNo<key)
    {
        search_prof(root->right,key);
    } 
	}
    
}

void edit_per(struct per_tree_node* root,int key,Entry e)		//binary search then edit
{
    if(root==NULL)
    {
        printf("No such number exist in tree\n"); 
    }
	else
	{
	
    if(root->phoneNo==key)
    {
    	sc=success;
    	root->data = e;
    	
    }
    if(root->phoneNo>key)
    {
        edit_per(root->left,key,e);
    }
    if(root->phoneNo<key)
    {
        edit_per(root->right,key,e);
    } 
    
	}
}

void edit_prof(struct prof_tree_node* root,int key,profEntry pe)		//binary search then edit
{
    if(root==NULL)
    {
        printf("No such number exist in tree\n"); 
    }
	else
	{
	
    if(root->phoneNo==key)
    {
    	sc=success;
    	root->data = pe;
    	
    }
    if(root->phoneNo>key)
    {
        edit_prof(root->left,key,pe);
    }
    if(root->phoneNo<key)
    {
        edit_prof(root->right,key,pe);
    } 
	}
}

struct per_tree_node *insert_name(struct per_tree_node *nod, int number,Entry e)//based on name see net1.c
{
	if (nod == NULL)
  	{
  	return (per_create_node(number, e));
  	} 
  	if (strcmp(nod->data.name,e.name)>0)
  	{
  	nod->left = insert_name(nod->left, number,e);
  	}
  	else if (strcmp(nod->data.name,e.name)<0)
  	{
  	nod->right = insert_name(nod->right, number,e);
  	}
  	else
  	{
  	 	nod=insertNode(nod, number,e);//if name are same insert based on number
  	}
  	
  	nod->hight = 1 + max(height(nod->left),height(nod->right));

  int balance = getBalance(nod);
  if (balance > 1 && strcmp(e.name,nod->left->data.name)<0)//key < nod->left->phoneNo	
  {
  	return rightRotate(nod);
  }
    
  if (balance < -1 && strcmp(e.name,nod->right->data.name)>0)//key > nod->right->phoneNo	
  {
  	return leftRotate(nod);
  }
    
  if (balance > 1 && strcmp(e.name,nod->left->data.name)>0)
  {
    nod->left = leftRotate(nod->left);
    return rightRotate(nod);
  }

  if (balance < -1 && strcmp(e.name,nod->right->data.name)<0)	 
  {
    nod->right = rightRotate(nod->right);
    return leftRotate(nod);
  }

  return nod;
}

struct prof_tree_node *insert_prof_name(struct prof_tree_node *nod, int number,profEntry pe)
{
	if (nod == NULL)
  	{
  	return (prof_create_node(number, pe));
  	} 
  	if (strcmp(nod->data.name,pe.name)>0)
  	{
  	nod->left = insert_prof_name(nod->left, number,pe);
  	}
  	else if (strcmp(nod->data.name,pe.name)<0)
  	{
  	nod->right = insert_prof_name(nod->right, number,pe);
  	}
  	else
  	{
  	 	nod=profinsertNode(nod, number,pe);//if name are same insert based on number
  	}
  	
  	nod->hight = 1 + max(prof_height(nod->left),prof_height(nod->right));

  int balance = prof_getBalance(nod);
  if (balance > 1 && strcmp(pe.name,nod->left->data.name)<0)//key < nod->left->phoneNo
  {
  	return profrightRotate(nod);
  }
    
  if (balance < -1 && strcmp(pe.name,nod->right->data.name)>0)//key > nod->right->phoneNo
  {
  	return profleftRotate(nod);
  }
    
  if (balance > 1 && strcmp(pe.name,nod->left->data.name)>0) 
  {
    nod->left = profleftRotate(nod->left);
    return profrightRotate(nod);
  }

  if (balance < -1 && strcmp(pe.name,nod->right->data.name)<0) 
  {
    nod->right = profrightRotate(nod->right);
    return profleftRotate(nod);
  }

  return nod;
}

