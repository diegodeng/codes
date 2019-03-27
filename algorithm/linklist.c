#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libalgorithm.h"

/*
 * LinkList struct  约定的结构： 头指针是链表必要元素。
 * 
 *    头指针       头节点         第一节点      第二节点            第n节点
 *  -------->  (head|next) -> (A1|next) -> (A2| next) -> ...->(An|NULL)
 */

LinkList newNode()
{
	LinkList node = NULL;
	
	node = (LinkList)malloc(sizeof(Node)); 
	if(node == NULL){
		loge("newNode malloc error\r\n");
		goto done;
	}
	memset(node,0,sizeof(Node));
done: 
	return node;
}
void freeNode(LinkList L)
{
	if( L == NULL){
		return;
	}
	free(L);
	return;
}
/*
 * function: search the pos in the linklins
 * parameter:
 *		L:     linklist 
 * 		pos:   need search pos
 * 		type:  0: search add pos  1: search delete position 
 * return the node address if not return null
 */
static LinkList searchPostion(LinkList L,int pos,int type)
{
	int j = 1;
	LinkList p,s= NULL;
	if(L == NULL){
		loge("searchPostion parameter error\r\n");
		return NULL;
	}
	p = L;
	
	switch(type)
	{
		case 0:{
			while( p && j < pos){
				p = p->next;
				j++;
			}
			if( !p || j > pos){
				loge("searchAddPostion not found \r\n");
				break;
			}
			else{
				s = p;			
				break;
			}
		}
		case 1:{
			while( (p->next) && j < pos){
				 p = p->next;
				 j++;
			}
			if( !(p->next) && j > pos){
				loge("searchDeletePostion not found\r\n");
				break;
			}
			else{
				s = p->next;
				break;
			}
		}
		default:
			break;
	}
	return s;
}

LinkList searchAddPostion(LinkList L,int pos)
{
	return searchPostion(L,pos,0);
}
LinkList searchDeletePostion(LinkList L,int pos)
{
	return searchPostion(L,pos,1);
}

LinkList InitLinkList()
{
	LinkList list = NULL;
	
	list = (LinkList)malloc(sizeof(Node)); //head node;
	if(list == NULL){
		loge("InitLinkList malloc error\r\n");
	}
	memset(list,0,sizeof(Node)); 
	logi("InitLinkList success\r\n");
	return list;
}
void ClearLinkList(LinkList *L){
	LinkList p, q;
	
	if(L == NULL){
		loge("DestoryLinkList  parameter error\r\n");
		return;
	}
	
	p = (*L)->next; //the first node
	
	while(p){
		q = p-> next;
		free(p);
		p = q;	
	}
	(*L)->next  = NULL;
	return;
}
void DestoryLinkList(LinkList *L)
{
	LinkList p;
		
	p = *L;
	
	free(p);

	return;
}

int  getElem(LinkList L,int pos, ElemType *e)
{
	return 0;
}
int	 locateElem(LinkList L,ElemType e)
{
	return 0;
}

/*
 *  
 */
int  LinkListInsert(LinkList *L,int pos,ElemType e)
{
	int i = 1;
	LinkList p,s;  //一级指针；
	
	p = *L;
	while( p && i < pos){  //用于寻找第pos个节点
		p = p->next;
		i++;
	}

	if( !p && i > pos){
		return -1;
	}
	
	s = (LinkList)malloc(sizeof(Node));
	if(s == NULL){
		loge("InitLinkList malloc error\r\n");
		return -1;
	}
	memset(s,0,sizeof(Node)); 
	s->data = e;
	
	s->next = p->next;
	p->next = s;

	return 0;
}
int  LinkListDelete(LinkList *L,int pos,ElemType *e)
{
	int j = 1;
	LinkList p,q;
	
	//init pointer
	p = *L;
	
	while( p->next && j < pos){
		p = p->next;
		j++;
	}
	if( !(p->next) || j > pos){
		loge("LinkListDelete node does no exist\r\n");
		return -1; 
	}
	q = p->next;
	
	//delete node;
	//p->next = p->next->next;
	p->next = q->next;
	
	*e =q->data;
	free(q);
	return 0;
}
int  LinkListLength(LinkList L)
{
	return 0;
}
void showLinkList(LinkList L)
{
	return;
}
