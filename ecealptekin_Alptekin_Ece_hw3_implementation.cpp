#include "ecealptekin_Alptekin_Ece_hw3_header.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

linkedlist::linkedlist() 
{ //constructor

	head = NULL;
}

void linkedlist::addHouseNode(string hname)
{ //this function adds houses, which are read from the file
	houseNode * h = new houseNode(hname,NULL,NULL);

	if(head == NULL)
	{
		head = h;
	}
	else
	{
		houseNode * p = head;
		while(p->next != NULL)
		{
			p = p->next;
		}
		p->next = h;
	}
}

void linkedlist::addNeighborNode(string hname, string nname)
{ //this function adds neighbors, which are read from the file
	houseNode * p = head;
	houseNode * n = NULL;

	while(p != NULL)
	{
		if(p->houseName == hname)
		{
			n = p;
		}
		p = p->next;
	}

	neighborNode * s = n->neighborListHead;

	if(s == NULL)
	{
		n->neighborListHead = new neighborNode(nname,NULL);
	}

	else
	{
		while(s->next != NULL)
		{
			s = s->next;
		}
		s->next = new neighborNode(nname,NULL);
	}
}

void linkedlist::printAll()
{ //prints all the map
	houseNode * h = head;

	while(h != NULL)
	{
		neighborNode * n = h->neighborListHead;
		cout << h->houseName << ": ";

		while(n != NULL)
		{
			cout << n->neighborName << ", ";
			n = n->next;
		}
		cout << "\n";

		h = h->next;
	}
}

bool linkedlist::hnExists(string hname)
{ //it returns true if the house exists in the map 
	houseNode * p = head;

	while(p != NULL)
	{
		if(p->houseName == hname)
		{
			return true;
		}
		p = p->next;
	}
	return false;
}

bool linkedlist::nnExists(string hname, string nname)
{ //it returns true if the house has the neighbor
	houseNode * p = head;
	neighborNode * n = NULL;

	while(p != NULL)
	{
		if(p->houseName == hname)
		{
			n = p->neighborListHead;
		}
		p = p->next;
	}

	while(n != NULL)
	{
		if(n->neighborName == nname)
		{
			return true;
		}
		n = n->next;
	}
	return false;
}

void linkedlist::deleteAll()
{ //deletes all the map
	houseNode * n = head;
	while(n != NULL)
	{
		neighborNode * p = n->neighborListHead;
		neighborNode * next;
		while(p != NULL)
		{
			next = p->next; 
			delete p; 
			p = next; 
		}
		n = n->next;
	}

	houseNode * h = head;
	houseNode * next;
	while( h != NULL)
	{
		next = h->next; 
		delete h; 
		h = next; 
	}

	head = NULL;
	DeletePath();
}

neighborNode * linkedlist::getNeighbor(string hname)
{ //returns the neighborListHead of the house
	houseNode * h = head;
	neighborNode * n;
	while (h != NULL)
	{
		if(h->houseName == hname)
		{
			n = h->neighborListHead;
			return n;
		}
		h = h->next;
	}
}

houseNode * linkedlist::getHouse(string hname)
{ //returns the house from the map
	houseNode * p = head;
	while(p != NULL)
	{
		if(p->houseName == hname)
		{
			return p;
		}
		p = p->next;
	}
}

void linkedlist::DeleteHouse(houseNode * todeleted) 
{ //this function deletes the house from the map
	neighborNode * n = todeleted->neighborListHead;
	neighborNode * next;
	while(n != NULL)  
	{ 
		next = n->next; 
		delete n; 
		n = next; 
	} 

	/* Begin: code taken from ptrfunc.cpp and updated*/
	houseNode * k = head;
	if(k == todeleted)
	{
		head = head->next;
		delete k;
	}
	else
	{
		while (k->next != todeleted)
		{
			k = k->next;
		}

		k->next = todeleted->next;
		delete todeleted;
	}
	/* End: code taken from ptrfunc.cpp and updated*/
}

void linkedlist::DeleteNeighbor(houseNode * list,string deleted)
{ //this function deletes the neighbor from a neighborList of the house
	/* Begin: code taken from ptrfunc.cpp and updated*/
	neighborNode * p = list->neighborListHead;

	if(p->neighborName == deleted)
	{
		list->neighborListHead = p->next;
		delete p;
	}

	else
	{
		while(p->next->neighborName != deleted)
		{
			p = p->next;
		}
		neighborNode * temp = p->next;
		p->next = p->next->next;
		delete temp;
	}
	/* End: code taken from ptrfunc.cpp and updated*/
}

neighborNode * linkedlist::DeleteNeighbor1(neighborNode * list,neighborNode * deleted)
{ //it deletes the neighbor from the neighborlist and returns the updated list
	/* Begin: code taken from ptrfunc.cpp and updated*/
	neighborNode * p = list;

	if(p == deleted)
	{
		list = p->next;
		delete p;
	}

	else
	{
		while(p->next != deleted)
		{
			p = p->next;
		}
		neighborNode * temp = p->next;
		p->next = p->next->next;
		delete temp;
	}
	/* End: code taken from ptrfunc.cpp and updated*/
	return list;
}

void linkedlist::MergeNeighbor(neighborNode * first,neighborNode * second,string annexer)
{ //it merges the neighborlist of the annexer and annexed
	if(first != NULL)
	{

	while(first->next != NULL)
	{
		first = first->next;
	}

	while(second != NULL)
	{
		if(nnExists(annexer,second->neighborName))
		{
			second = second->next;
		}

		else if(second->neighborName == annexer)
		{
			second = second->next;
		}

		else
		{
			first->next = new neighborNode(second->neighborName, NULL);
			first = first->next;
			second = second->next;
		}
	  }
	}
}

bool linkedlist::TwiceNeighbor(neighborNode * head,string annexer)
{ //returns true if the annexer is already in the neighborlist 
	neighborNode * n = head;

	while(n != NULL)
	{
		if(n->neighborName == annexer)
		{
			return true;
		}
		n = n->next;
	}
	return false;
}

void linkedlist::option1(string annexer,string annexed)
{ 
	if(!hnExists(annexer))
	{
		cout << annexer << " does not exist!" << endl << "Update failed." << endl << "\n";
	}

	else if(!hnExists(annexed))
	{
		cout << annexed << " does not exist!" << endl << "Update failed." << endl << "\n";
	}

	else if(annexer == annexed)
	{
		cout << "A House cannot conquer itself!" << endl << "Update failed." << endl << "\n";
	}

	else if(!nnExists(annexer,annexed))
	{
		cout << "A house can only conquer a neighboring house! " << annexed  << " is not a neighbor of " << annexer << "." << endl << "Update failed." << endl << "\n";
	}

	else
	{
		DeleteNeighbor(getHouse(annexer),annexed); //deletes annexed from the neighborlist of the annexer

		houseNode * tm = head;
		while(tm != NULL)
		{
			neighborNode * n = getNeighbor(tm->houseName);
			neighborNode * p = n;
			while(n != NULL)
			{
				if(n->neighborName == annexed)
				{
					if(TwiceNeighbor(p,annexer)) //true if the annexer is in the list in order to avoid duplicate 
					{
						 neighborNode * temp = n->next;
						 houseNode * T = getHouse(tm->houseName);
						 T->neighborListHead = DeleteNeighbor1(p,n); //deletes the node for not having same two neighbors in the list and returns the modified neighborlist
                         n = temp; 
					}

					else
					{
						n->neighborName = annexer; //there is no annexer in the neighborlist, so there will be no duplication
						n = n->next;
					}
				}

				if(n != NULL)
				{
					n = n->next;
				}
			}
			tm = tm->next;
		}


		houseNode * t = head; 
		while(t != NULL)
		{
			if(nnExists(t->houseName,annexed))
			{
				DeleteNeighbor(t,annexed);	//deletes the annexed from the neighborlist of the houses
			}
			t = t->next;
		}

		neighborNode * first = getNeighbor(annexer); 
		neighborNode * second = getNeighbor(annexed);
		MergeNeighbor(first,second,annexer); //merge the neighborlist of the annexer and annexed

		DeleteHouse(getHouse(annexed)); //delete the annexed from the map

		cout << annexer << " conquered " << annexed << "!" << endl;
		cout << "######## MAP ########" << endl;
		printAll();
		cout << "\n\n";
	}
}

void linkedlist::addtoPathList(string t)
{ //it adds the houses,which will be travelled by Tyrion,to the list
	houseNode * h = p_head;
	if(h == NULL)
	{
		p_head = new houseNode(t,NULL,NULL);
	}

	else
	{
		while(h->next != NULL)
		{
			h = h->next;
		}

		h->next = new houseNode(t,NULL,NULL);
	}
}

void linkedlist::DeletePath()
{ //to deallocate all dynamic data
	houseNode * n = p_head;
	houseNode * next;
	while(n != NULL)  
	{ 
		next = n->next; 
		delete n; 
		n = next; 
	} 

	p_head = NULL;
}

void linkedlist::option2()
{
	bool flag = true;
	houseNode * p = p_head;
	houseNode * second = p->next;
	houseNode * first = p;

	while(second != NULL && flag == true) //until there is no path to follow or it is not a valid path
	{ 
		if(!hnExists(first->houseName)) 
		{
			cout << first->houseName << " does not exist in the map." << endl;
			flag = false;
		}

		else if(first->houseName == second->houseName)
		{
			cout << "You are already in " << second->houseName << endl;
		}

		else if(nnExists(first->houseName,second->houseName))
		{
			cout << "Path found between " << first->houseName << " and " << second->houseName << endl;
		}

		else if(!nnExists(first->houseName,second->houseName))
		{
			cout << second->houseName << " is not a neighbor of " << first->houseName << endl;			flag = false;
		}

		first = second;
		second = second->next;
	}

	if(flag == true)
	{
		cout << "Path search succeeded." << endl << "\n";
	}

	else if(flag == false)
	{
		cout << "Path search failed!" << endl << "\n";
	}

	DeletePath(); //to deallocate all dynamic data
}