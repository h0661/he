
#include "stdio.h"
#include "stdlib.h"

typedef struct BSTreeNode BSTreeNode;
struct BSTreeNode
{
	int m_nValue;        //value of node
	struct BSTreeNode *m_pLeft; //left childe of node
	struct BSTreeNode *m_pRight;
};


BSTreeNode *pHead = NULL; 


/*create Binary Sort Tree*/
BSTreeNode* BSTreeCreate(int value)
{
	BSTreeNode *root = (BSTreeNode *)malloc(sizeof(BSTreeNode));
	if(NULL==root)
	{	
		printf("Binary Sort Tree malloc failed!\n");
	}	
	else
	{
		root->m_nValue = value;
		root->m_pLeft  = NULL;
		root->m_pRight = NULL;
	}
	return root;
}
/*destory Binary Sort Tree*/
void BSTreeDestory(BSTreeNode *root)
{
	if(root!=NULL)
	{
		if(root->m_pLeft!=NULL)
		{
			BSTreeDestory(root->m_pLeft);
		}
		if(root->m_pRight!=NULL)
		{
			BSTreeDestory(root->m_pRight);
		}
	}
	free(root);
	
}

/*insert Binary Sort Tree*/
BSTreeNode* BSTreeInsertNode(BSTreeNode *root,int value)
{
	if(root ==NULL)
	{
		root = BSTreeCreate(value);
	}
	else if(value<root->m_nValue)
	{
		root->m_pLeft = BSTreeInsertNode(root->m_pLeft,value);
	}
	else if(value>root->m_nValue)
	{
		root->m_pRight = BSTreeInsertNode(root->m_pRight,value);
	}
	return root;
}




BSTreeNode* BSTreeToDoubleList(BSTreeNode* root)
{
	BSTreeNode *head=NULL,*tail=NULL;


	return head;
}

void inOrderBSTree(BSTreeNode* pBSTree)
{
	if(NULL==pBSTree)
	{
		return;
	}
	if(NULL!=pBSTree->m_pLeft)
	{
		inOrderBSTree(pBSTree->m_pLeft);
	}
//	convertToDoubleList(pBSTree);

	if(NULL!=pBSTree->m_pRight)
	{
		inOrderBSTree(pBSTree->m_pRight);
	}
}
/*print Binary Sort Tree*/
void BSTreePrint(BSTreeNode* root)
{
	if(NULL!=root)
	{
		
		printf("%d  ",root->m_nValue);
	
		if(root->m_pLeft!=NULL)
		{
			BSTreePrint(root->m_pLeft);
		}

		if(root->m_pRight!=NULL)
		{
			BSTreePrint(root->m_pRight);
		}

		
	}
	else 
	{
		printf("Binary Sort Tree is empty!\n");
	}
}
void DoubleListPrint(BSTreeNode* head)
{
	if(NULL!=head)
	{
		while(NULL!=head)
		{
			printf("%d ",head->m_nValue);
		}
		printf("\n");
	}
	else
	{
		printf("DoubleList is empty!\n");
	}
}

int main(void)
{
	BSTreeNode *pRoot = NULL;
	BSTreeNode *pDoubleLinkHead = NULL;
		
	printf("Binary Sort Tree£º10 6 14 4 8 12 16\n");
	pRoot =BSTreeInsertNode(pRoot,10);
	BSTreeInsertNode(pRoot,6);
	BSTreeInsertNode(pRoot,14);
	BSTreeInsertNode(pRoot,4);
	BSTreeInsertNode(pRoot,8);
	BSTreeInsertNode(pRoot,12);
	BSTreeInsertNode(pRoot,16);

	BSTreePrint(pRoot);
	pDoubleLinkHead = BSTreeToDoubleList(pRoot);
	DoubleListPrint(pDoubleLinkHead);

	BSTreeDestory(pRoot);

	return 0;
}
