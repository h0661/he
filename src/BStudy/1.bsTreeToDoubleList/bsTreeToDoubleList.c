
#include "stdio.h"
#include "stdlib.h"

typedef struct BSTreeNode BSTreeNode;
struct BSTreeNode			//a node in the binary sort tree
{
	int m_nValue;        //value of node
	struct BSTreeNode *m_pLeft; //left childe of node
	struct BSTreeNode *m_pRight;//right child of node
};


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
	if(NULL==root)
	{
		return;
	}

	if(root->m_pLeft!=NULL)
	{
		BSTreeDestory(root->m_pLeft);
	}
	if(root->m_pRight!=NULL)
	{
		BSTreeDestory(root->m_pRight);
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

BSTreeNode* ConvertNodeByMid(BSTreeNode* pNode) 
{
	BSTreeNode *pTemp = pNode;
	static BSTreeNode *pHead = NULL;     
	static BSTreeNode *pTail = NULL;
	
	if(NULL == pTemp)
	{
		printf("the Binary Sort Tree is empty!\n");
		return NULL;
	}
	//Convert the left sub-tree
	if(NULL!=pTemp->m_pLeft)
	{
		ConvertNodeByMid(pTemp->m_pLeft);
	}

	// Put the current node into the double list
	if(NULL==pHead)
	{
		pHead=pTemp;
		pTail=pTemp;
	}
	else
	{
		pTail->m_pRight = pTemp;
		pTemp->m_pLeft = pTail;
		pTail =pTemp;
	}
	//Convert the right sub-tree
	if(NULL!=pTemp->m_pRight)
	{
		ConvertNodeByMid(pTemp->m_pRight);
	}

	return pHead;
}


BSTreeNode* ConvertNode(BSTreeNode* pNode,int isRight)
{
	BSTreeNode *pTemp = pNode;
	BSTreeNode *pLeft = NULL;
	BSTreeNode *pRight =NULL;

	if(NULL==pNode)
	{
		printf("the Binary Sort Tree is empty!\n");
		return NULL;
	}
	
	//Convert the left sub-tree
	if(NULL!=pNode->m_pLeft)
	{
		pLeft = ConvertNode(pNode->m_pLeft,0);
	}
	
	//Convert the left sub-tree
	if(NULL!=pNode->m_pRight)
	{
		pRight=ConvertNode(pNode->m_pRight,1);
	}

	//Connect the pleft to the current node
	if(NULL!=pLeft)
	{
		pLeft->m_pRight = pNode;
		pNode->m_pLeft = pLeft;
	}
	
	//Connect the pRight to the current node 
	if(NULL!=pRight)

	{
		pNode->m_pRight = pRight;
		pRight->m_pLeft =pNode;
	}
	
	//if right return to the head if left return to the tail;
	if(1==isRight)
	{
		while(pNode->m_pLeft!=NULL)
		{	
			pNode =pNode->m_pLeft;
		}
	}
	else
	{
		while(pNode->m_pRight!=NULL)
		{	
			pNode =pNode->m_pRight;
		}
	}
	

	return pNode;
}



BSTreeNode* BSTreeToDoubleList(BSTreeNode* root)
{

	return ConvertNode(root,1);
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
void BSTreeMirro(BSTreeNode *pNode)
{
	BSTreeNode *pTemp=pNode;
	BSTreeNode *pTmp=NULL;
	if(NULL==pTemp)
	{
		printf("the Binary Sort Tree node is empty!\n");
		return;
	}
	pTmp= pTemp->m_pRight;
	pTemp->m_pRight=pTemp->m_pLeft;
	pTemp->m_pLeft =pTmp;


	if(NULL!=pTemp->m_pLeft)
	{
		BSTreeMirro(pTemp->m_pLeft);
	}
	if(NULL!=pTemp->m_pRight)
	{
		BSTreeMirro(pTemp->m_pRight);
	}
}
int main(void)
{
	BSTreeNode *pRoot = NULL;
	BSTreeNode *pDoubleLinkHead = NULL;
		
	printf("Binary Sort Tree:10 6 14 4 8 12 16 \n");
	pRoot =BSTreeInsertNode(pRoot,10);
	BSTreeInsertNode(pRoot,6);
	BSTreeInsertNode(pRoot,14);
	BSTreeInsertNode(pRoot,4);
	BSTreeInsertNode(pRoot,8);
	BSTreeInsertNode(pRoot,12);
	BSTreeInsertNode(pRoot,16);

	BSTreePrint(pRoot);
	printf("Start Execute:BSTreeMirro!\n");
	BSTreeMirro(pRoot);
	BSTreePrint(pRoot);

	pDoubleLinkHead = ConvertNodeByMid(pRoot);
//	pDoubleLinkHead = BSTreeToDoubleList(pRoot);
	DoubleListPrint(pDoubleLinkHead);




	BSTreeDestory(pRoot);

	return 0;
}
