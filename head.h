/*	BT20CSE087 Naman Jain

	>compiled on DEV-C++ 5.11
			or
	>https://www.onlinegdb.com/online_c_compiler
	
	>enter name without space everywhere 
	>name should be case sensititve
	>phone number is considered as integer 
	>address,institute name are taken as char
	>sort function displays list in ascending or descending order of phone number
	>sort based on first name->displays earlier entry in ascending order of name
	>balance factor is considered = left height- right height
	>for avl tree balance factor should be : -1,0,1
	>phone number is taken as key
	 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct perentry 
{	
	char name[50];
	char last_name[50];
	char mail[50];
	int type;
	
} Entry;

struct per_tree_node 
{
	int phoneNo;//key
	Entry data;
	int hight;
	struct per_tree_node *left;
	struct per_tree_node *right;
};

typedef struct prof_entry 
{
	char name[50];
	char last_name[50];
	char mail[50];
	int officeNo;
	char address[50];
	int type;
	char institute[50];
	
} profEntry;

struct prof_tree_node 
{
	int phoneNo;//key
	profEntry data;
	int hight;
	struct prof_tree_node *left;
	struct prof_tree_node *right;
};

enum status_code{success,fail};
enum status_code sc;

int max(int a, int b);

int height(struct per_tree_node  *N) ;

int prof_height(struct prof_tree_node  *N);

struct per_tree_node* per_create_node(int n, Entry e) ;

struct prof_tree_node* prof_create_node(int n, profEntry pe);

int getBalance(struct per_tree_node *N);

int prof_getBalance(struct prof_tree_node *N);

void per_inorder(struct per_tree_node* root);

void per_inorder_rev(struct per_tree_node* root);

void prof_inorder(struct prof_tree_node* root);

void prof_inorder_rev(struct prof_tree_node* root);

void per_range(struct per_tree_node* root,int k1,int k2);

void prof_range(struct prof_tree_node* root,int k1,int k2);

struct per_tree_node *minValueNode(struct per_tree_node *node) ;

struct prof_tree_node *profminValueNode(struct prof_tree_node *node);

struct per_tree_node *rightRotate(struct per_tree_node *y);

struct per_tree_node *leftRotate(struct per_tree_node *x) ;

struct prof_tree_node *profrightRotate(struct prof_tree_node *y);

struct prof_tree_node *profleftRotate(struct prof_tree_node *x) ;

struct per_tree_node *insertNode(struct per_tree_node *nod, int key,Entry e);

struct prof_tree_node *profinsertNode(struct prof_tree_node *nod, int key,profEntry pe);

struct per_tree_node *deleteNode(struct per_tree_node *root, int key) ;

struct prof_tree_node *profdeleteNode(struct prof_tree_node *root, int key) ;

void search_per(struct per_tree_node* root,int key);void search_prof(struct prof_tree_node* root,int key);

void edit_per(struct per_tree_node* root,int key,Entry e);

void edit_prof(struct prof_tree_node* root,int key,profEntry pe);

struct per_tree_node *insert_name(struct per_tree_node *nod, int number,Entry e);

struct prof_tree_node *insert_prof_name(struct prof_tree_node *nod, int number,profEntry pe);

