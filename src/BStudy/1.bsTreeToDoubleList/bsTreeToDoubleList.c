
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

BSTreeNode* ConvertNode(BSTreeNode* pNode,int asRight)
{
	BSTreeNode *pLeft = NULL;
	BSTreeNode *pRight= NULL;
	 BSTreeNode *pTemp = pNode;

	if(pNode==NULL)
		return NULL;
	if(pNode->m_pLeft)
		pLeft = ConvertNode(pNode->m_pLeft,0);

	if(pLeft!=NULL)
	{
		pLeft->m_pRight = pNode;
		pNode->m_pLeft =pLeft;
	}
	if(pNode->m_pRight)
	{
		pRight =ConvertNode(pNode->m_pRight,1);
	}


	
		if(pRight!=NULL)
       {
             pNode->m_pRight = pRight;
             pRight->m_pLeft = pNode;
       }

      
      // If the current node is the right child of its parent,
      // return the least node in the tree whose root is the current node
      if(1==asRight)
       {
            while(pTemp->m_pLeft!=NULL)
                   pTemp = pTemp->m_pLeft;
       }
      // If the current node is the left child of its parent,
      // return the greatest node in the tree whose root is the current node
      else
       {
            while(pTemp->m_pRight!=NULL)
                   pTemp = pTemp->m_pRight;
       }
	   

    return pTemp;
	//	
}


BSTreeNode* BSTreeToDoubleList(BSTreeNode* root)
{

	return ConvertNode(root,1);
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
	BSTreeNode *p=head;
	printf("\n print DoubleList\n");
	if(NULL!=p)
	{
		while(NULL!=p)
		{
			printf("%d ",p->m_nValue);
			p=p->m_pRight;	
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
		
	printf("Binary Sort Tree:10 6 14 4 8 12 16\n");
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
