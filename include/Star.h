#pragma once
#include <map>
#include <vector>
#include "Node3D.h"
using namespace std;

class MyNodeSort
{
public:
	bool  operator() ( const Node3D * node1 , const Node3D * node2 ) const
	{
		if ( node1 != node2 )
		{
			if ( node1->f == node2->f )
			{	if ( node2->h == node2->h)
			if ( node1->g == node2->g)
			{
				return node1 < node2 ;
			}
			return node1->g < node2->g;
			return node1->h < node2->h;
			}	
			return ( node1->f < node2->f ) ;
		}
		else if ( node1->f > node2->f)
		{
			return true;
		}
		return false;
		
	}
};

class Star
{
public:
	Star(void);
	~Star(void);
	
	void  Init();
	void  Display();
	bool  Creatgraph();
	bool  findpath() 
	{
		return Creatgraph(); 
		//return Find_path(&startp) ;
	}
	bool  Find_path(Node3D * node );
	void  searchchNode(Node3D * adjNode , Node3D * current);
	void  animate();
	long  get_h_value(int p);
	long  get_g_value(int p);

	inline bool findItem( map<Node3D*,int,MyNodeSort> &table , Node3D * node)
	{
		typedef map<Node3D*,int,MyNodeSort>::iterator MAPNODE;
		for ( MAPNODE iter = table.begin() ; iter != table.end() ; iter ++ )
		{
			if ( node->point == iter->first->point )
			{
				return true ;
			}
		}
		return false;
	}
private:

	// open list and close list
	map<Node3D*,int,MyNodeSort> open;
	map<Node3D*,int,MyNodeSort> close;
	vector<Point>   path;

	// start point and end point
	Node3D       startp;
	Node3D		 endp; 

	Node3D		 GPoint;
};
