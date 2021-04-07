#include <stdio.h>

struct TreeNode
{
	int value;
	TreeNode* sibling; //pointer to the next sibling or NULL if it doesn't exist
	TreeNode* firstChild; //pointer to the first child(left in this implementation) or NULL if it doesn't exist
};

/*
* Two cases:
* 1) Adding new node as new root and currennt root is left child if odd
* 2) Adding new node as new root and current root is right siblinng if even - node is not last!!!
* 
* Possible modification: 
* In order to reduce long list of even numbers, when odd node is added it can divide list on some way(if this node is not last)
*/
void addNode(int newValue, TreeNode* weirdTree)
{
	bool isOdd = (newValue & 1) == 1 ? true : false;

	TreeNode* pom = new TreeNode(*weirdTree); // moving current root down or right
	weirdTree->value = newValue;
	if (isOdd)
	{
		weirdTree->firstChild = pom;
		weirdTree->sibling = 0;
	}
	else
	{
		weirdTree->firstChild = 0;
		weirdTree->sibling = pom;
	}
}

TreeNode generateTree(int m, int* a)
{
	// initialization:
	TreeNode weirdTree;
	weirdTree.firstChild = 0;
	weirdTree.sibling = 0;
	if (a == 0) { return weirdTree; }
	
	weirdTree.value = a[m - 1];

	for (int i = m - 2; i >= 0; i--)
	{
		addNode(a[i], &weirdTree);
	}

	return weirdTree;
}

void preorderWierdTree(TreeNode* weirdTree)
{
	if (weirdTree == 0) 
	{
		return; 
	}

	// process:
	const char* isLeaf = weirdTree->firstChild == 0 ? "LEAF" : "INNER";
	printf("%d(%s)   ", weirdTree->value, isLeaf);

	// continue:
	preorderWierdTree(weirdTree->sibling);
	preorderWierdTree(weirdTree->firstChild);
}

int main()
{
	int a[9] = { 3, 1, 4, 48, 2, 5, 3, 6, 18 };
	int m = 9;
	TreeNode weirdTree = generateTree(m, a);
	
	printf("Result:\r\n");
	preorderWierdTree(&weirdTree);
	printf("\r\n");

	getchar();
	return 0;
}