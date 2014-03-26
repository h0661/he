//1.构造二叉查找树
//2.中序遍历二叉查找树,因此结点按从小到大顺序访问,假设之前访问的结点己经调整为一个双向链表,那么只需要将当前结点连接至双赂链表的最后一个结点即可,访问完后那么只需要将当前结点连接至双赂链表的最后一个结点即可,假设之前访问完后访问完后双向链表也就调整完了.


#include "stdio.h"
typedef struct BSTreeNode BSTreeNode;
struct BSTreeNode
{
	int m_nValue;        //value of node
	BSTreeNode *m_pLeft; //left childe of node
	BSTreeNode *m_pRight;
};
void addBSTreeNode(BSTreeNode *&pCurrent,int value);
void inOrderBSTree(BSTreeNode *pBStree);
void BSTreeToDoubleList(BSTreeNode *pCurrent);

BSTreeNode *pHead = NULL; 
BSTreeNode *pIndex = NULL;

/*建立二叉排序树*/
void addBSTreeNode(BSTreeNode *&pCurrent,int value)
{
	if(NULL==pCurrent)
	{
		BSTreeNode *pBSTree = new BSTreeNode();
		pBSTree->m_nvalue = value;
		pBSTree->m_pLeft = NULL;
		pBSTree->m_pRight= NULL;
		pCurrent = pBSTree;	
	}
	else if(pCurrent->m_nValue<value)
	{
		addBSTreeNode(pCurrent->m_pRight,value);
	}	
	else if(pCurrent->m_nValue<value)
	{
		addBSTreeNode(pCurrent->m_pLeft,value);
	}	
	else
	{
		printf("node repeated!\n");
	}
}
void inOrderBSTree(BSTreeNode* pBSTree)
{
}
void convetToDoubleList(BSTreeNode* pCurrent)
{
}

int main()
{
	printf("BSTreeToDoubleList!\n");
	printf("BSTreeToDoubleList!\n");
}


