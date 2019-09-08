#ifndef ECEALPTEKIN_ALPTEKIN_ECE_HW3_HEADER
#define ECEALPTEKIN_ALPTEKIN_ECE_HW3_HEADER
#include <string>
using namespace std;

struct neighborNode
{
   string neighborName;
   neighborNode * next;

   neighborNode::neighborNode()
   {
	neighborName = "";
	next = NULL;
   }

   neighborNode::neighborNode(string s,neighborNode * n)
                :neighborName(s),
	             next(n)
   {}

};
struct houseNode
{
string houseName;
neighborNode * neighborListHead;
houseNode * next;

houseNode::houseNode()
{
	houseName = "";
	neighborListHead = NULL;
	next = NULL;
}

houseNode::houseNode(string s,neighborNode * n,houseNode * h)
	:houseName(s),
	neighborListHead(n),
	next(h)
{}

};

class linkedlist
{
public:

   linkedlist();
   void addHouseNode(string hname);
   void addNeighborNode(string hname, string nname);
   void printAll();
   bool hnExists(string hname);
   bool nnExists(string hname, string nname);
   void deleteAll(); //to deallocate all dynamic data
   //other member functions…
   void option1(string annexer,string annexed);
   neighborNode * getNeighbor(string hname);
   houseNode * getHouse(string hname);
   void DeleteHouse(houseNode * todeleted);
   void DeleteNeighbor(houseNode * list,string deleted);
   void MergeNeighbor(neighborNode * first,neighborNode * second,string annexer);
   void option2();
   void addtoPathList(string t);
   void DeletePath();
   bool TwiceNeighbor(neighborNode * head,string annexer);
   neighborNode * DeleteNeighbor1(neighborNode * list,neighborNode * deleted);

private:

  houseNode * head;
  houseNode * p_head;
};

#endif

