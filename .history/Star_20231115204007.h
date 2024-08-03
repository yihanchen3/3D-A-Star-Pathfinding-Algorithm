#pragma once
#include <map>
#include <vector>
#include "Node3D.h"
using namespace std;

/// ����
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
	
	void  Init(){
		startp.point.xPos = 0;
		startp.point.yPos = 0;
		startp.point.zPos = 0;
		startp.g = 0;
		startp.h = 0;
		startp.f = 0;
		startp.parent = NULL;
		startp.setWalkable(true);

		endp.point.xPos = 9;
		endp.point.yPos = 9;
		endp.point.zPos = 9;
		endp.g = 0;
		endp.h = 0;
		endp.f = 0;
		endp.parent = NULL;
		endp.setWalkable(true);
	}
	void  Display(){
		cout << "start point : " << startp.point.xPos << " " << startp.point.yPos << " " << startp.point.zPos << endl;
		cout << "end point : " << endp.point.xPos << " " << endp.point.yPos << " " << endp.point.zPos << endl;
	}
	bool  Creatgraph();

	bool  findpath() 
	{
		return Creatgraph(); 
		//return Find_path(&startp) ;
	}
	bool  Find_path(Node3D * node );
	void  searchchNode(Node3D * adjNode , Node3D * current);
	void  animate(){
		//for ( int i = 0 ; i < path.size() ; ++i )
		//{
		//	char str[1000];
		//	path[i].tostring(str);
		//	std::cout << str << std::endl;//���·��
		//}
	}
	long  get_h_value(int p){
		return 0;
	}
	long  get_g_value(int p){
		return 0;
	}

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

	/// open �� close��
	map<Node3D*,int,MyNodeSort> open;
	map<Node3D*,int,MyNodeSort> close;
	vector<Point>   path;

	/// ��ʼ �� ���� ����
	Node3D       startp;
	Node3D		 endp; 

	Node3D		 GPoint;
};
