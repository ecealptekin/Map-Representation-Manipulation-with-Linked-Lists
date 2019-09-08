#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "ecealptekin_Alptekin_Ece_hw3_header.h"

//Ece Alptekin
//24156
//Homework 3 – Map Representation & Manipulation with Linked Lists 

using namespace std;

int main()
{
	linkedlist List;
	ifstream in;
	string filename;
	cout << "Please enter a file name." << endl;
	cin >> filename;
	in.open(filename);

	while(!in.is_open())
	{
		cout << "Please enter a file name." << endl;
		cin >> filename;
		in.open(filename);
	}

	cout << "Successfully opened file westeros.txt" << endl;
	cout << "\n";
	cout << "######## TOPOLOGY ########" << endl;
	cout << "\n";

	string line;
	string hname;
	string nname;

	while(getline(in,line))
	{
		stringstream ss(line);

		ss >> hname;
		ss >> nname;

		if(List.nnExists(hname,nname))
		{
			cout << "Processing " << hname << ", " << nname << endl << "Redundant information! An entry with " << hname << " and " << nname << " is already processed." << endl << "\n";
		}

		else
		{

			if(!List.hnExists(hname)) //house is not in the map
			{
				List.addHouseNode(hname);
				List.addNeighborNode(hname,nname);
			}

			else if(List.hnExists(hname)) //house is already in the map
			{
				List.addNeighborNode(hname,nname);
			}

			if(!List.hnExists(nname)) //neighbor is not in the map as a house
			{
				List.addHouseNode(nname);
				List.addNeighborNode(nname,hname);
			}

			else if(List.hnExists(nname)) //neighbor is already in the list as a house
			{ 
				List.addNeighborNode(nname,hname);
			}
			cout << "Processing " << hname << ", " << nname << endl << "Topology information successfully added." << endl << "\n";
		}
	}
		//for the first
		cout << "######## MAP ########" << endl << "\n";
		List.printAll();
		cout << "\n\n";
	    string option;
		cout << "Please select an option [1-2-3]." << endl;
		cout << "1. Annexation! War for the iron throne continues..." << endl;
		cout << "2. Tyrion must travel, do a path check for the famous imp." << endl;
		cout << "3. Exit" << endl;
		cin >> option;
	
		while(option != "3")
		{
			if(option == "1")
			{
				string annexer,annexed;
				cout << "Please enter two houses first the annexer and the annexed. (ex: Tyrell Stark)." << endl;
				cin >> annexer >> annexed;
				List.option1(annexer,annexed);
			    cout << "Please select an option [1-2-3]." << endl;
			    cout << "1. Annexation! War for the iron throne continues..." << endl;
			    cout << "2. Tyrion must travel, do a path check for the famous imp." << endl;
			    cout << "3. Exit" << endl;
			    cin >> option;
			}

			else if(option == "2")
			{
				string t= "";
				cout << "Please enter a path. (ex: Tyrell Martell Tully)" << endl;
				cin.ignore();
				getline(cin,t);
				stringstream ss(t);
				string s;
				while(ss >> s)
				{
					List.addtoPathList(s);
				}
				
				List.option2();
				cout << "Please select an option [1-2-3]." << endl;
			    cout << "1. Annexation! War for the iron throne continues..." << endl;
			    cout << "2. Tyrion must travel, do a path check for the famous imp." << endl;
			    cout << "3. Exit" << endl;
			    cin >> option;
			}

			else
			{
				cout << "Invalid option please select from the menu." << endl << "\n";
			    cout << "Please select an option [1-2-3]." << endl;
			    cout << "1. Annexation! War for the iron throne continues..." << endl;
			    cout << "2. Tyrion must travel, do a path check for the famous imp." << endl;
			    cout << "3. Exit" << endl;
			    cin >> option;
			}

		}

		if(option == "3")
		{
			cout << "List deleted and program ended." << endl;
		}

		List.deleteAll();

		cin.get();
		cin.ignore();
		return 0;
	}
