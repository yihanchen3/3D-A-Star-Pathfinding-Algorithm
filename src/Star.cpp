#include "StdAfx.h"
#include "Star.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <math.h>
#include <Windows.h>
#define  xDepth  200
#define  yDepth  200
#define  zDepth	 30

Node3D  nodes[200][200][30] ;
short	aray[200][200][30] = { 0 };

Star::Star(void)
{
}

Star::~Star(void)
{
}

bool Star::Creatgraph()
{
	Node3D node;

	int i, j, k;
	ifstream infile; 
	infile.open("../input/input.txt", ios::in); //input map file
	if (!infile.is_open())
	{
		cerr << "open error!" << endl;
		exit(1);
	}
	for (i = 0; i < 200; i++)
	{
		for (j = 0; j < 200; j++)
		{
			for (k = 0; k < 30; k++)
			{
				infile >> aray[i][j][k];
			}

		}
	}
	infile.close();

	// define start and end point
	int startpointx;
	int startpointy;
	int startpointz;
	int endpointx;
	int endpointy;
	int endpointz;
	cout << "Please input the strat point:" << endl;
	cin >> startpointx >>startpointy >>startpointz;
	cout << "Please input the end point:" << endl;
	cin >> endpointx >> endpointy >> endpointz;
	
	for ( int i = 0 ; i < zDepth ; i++ )
	{
		for ( int j  = 0; j < yDepth ; j++ )
		{
			for ( int k = 0 ; k < xDepth ; k++ )
			{
				Point pi;
				pi.xPos = k ;
				pi.yPos = j ;
				pi.zPos = i ;
				bool isWalkable = aray[k][j][i] >= 1 ? true : false; // 1 is walkable, 0 is not walkable
				node.setWalkable( isWalkable );
				node.setPoint( pi );
				nodes[k][j][i] = node; 
			}
		}
	}
	
	startp = nodes[startpointx][startpointy][startpointz];			// set start point
	endp   = nodes[endpointx][endpointy][endpointz];			// set end point
	Find_path( &nodes[startpointx][startpointy][startpointz] );
	return true ;
}

bool Star::Find_path(Node3D * node)
{
	if ( *node != endp  && endp.getWalkable() )
	{
		do 
		{
			close[node] =  node->f;
			int	sz = max(node->point.zPos -1 , 0 );
			int	ez = min(node->point.zPos +1 ,zDepth-1);

			int	sy = max(node->point.yPos -1 , 0 );
			int	ey = min(node->point.yPos +1 ,yDepth-1);

			int	sx = max(node->point.xPos -1 , 0 );
			int	ex = min(node->point.xPos +1 ,xDepth-1); // point shall not exceed the boundary
			// search the 26 adjacent nodes
			for ( int i = node->point.zPos-1; i <= ez ; i++ )
			{
				for ( int j  = node->point.yPos-1; j <= ey ; j++ )
				{
					for ( int k = node->point.xPos; k <= ex ; k++ )
					{
						if ( !( i == node->point.zPos && j== node->point.yPos && k == node->point.xPos ) && !(j == node->point.yPos && k == node->point.xPos))// shall not be the same node
						{
							searchchNode( &nodes[k][j][i], node );
						}
					}
				}
			}

			Node3D * best = NULL;
			if ( open.size() >= 1 )// if there is a node in open list, then find the first node from original open list, and place new node
			{
				best = open.begin()->first;
				open.erase( open.begin() );// delete the node pointed by position, return the iterator pointing to the next node
			}
			node = best;
		} while ( node != NULL  && (*node != endp)) ;
	}

	if ( node != NULL  && endp.getWalkable() && (*node == endp))// path connected to the end point
	{
		std::cout << "PATH FOUND: " << std::endl;
		Node3D *adjNode = node;

		path.clear();
		while ( *adjNode != startp )
		{
			if ( *adjNode != startp )
			{
				adjNode->setPath( true );
				path.push_back( adjNode->point );
			}
			if ( adjNode->parent == NULL )
			{
				break ;
			}
			adjNode = (Node3D*)(adjNode->parent);
		}
		
		path.push_back( adjNode->point );
		for ( int i = path.size()-1 ; i >=0  ; --i )
		{
			char str[1000];
			path[i].tostring(str);
			
			std::cout << str << std::endl;// print the path
		}
	}
	else
	{
		std::cout << "PATH NOT FOUND"  << std::endl;
	}
	return true ;
}

void Star::searchchNode(Node3D * adjNode  , Node3D * current)
{
	
	bool xZDiagonal = ( adjNode->point.xPos != current->point.xPos && adjNode->point.zPos != current->point.zPos && adjNode->point.yPos == current->point.yPos);//bool����true �� false
	bool xYDiagonal = ( adjNode->point.xPos != current->point.xPos && adjNode->point.yPos != current->point.yPos && adjNode->point.zPos == current->point.zPos);
	bool yZDiagonal = ( adjNode->point.yPos != current->point.yPos && adjNode->point.zPos != current->point.zPos && adjNode->point.xPos == current->point.xPos);
	bool xyzDigonal = ( adjNode->point.yPos != current->point.yPos && adjNode->point.zPos != current->point.zPos && adjNode->point.xPos != current->point.xPos);
	bool corner = false;
	Node3D * tmp = current;
	// adjNode is in close list
	if(  adjNode->getWalkable() &&  !findItem(open,adjNode) && !findItem(close,adjNode) && !corner)
	{

		adjNode->parent = tmp;
		if (xyzDigonal = true)
		{
			adjNode->g = current->g + 17;
		}
		else
		{
			adjNode->g = current->g + (xZDiagonal || xYDiagonal || yZDiagonal) ? 14 : 10;
		}

		int difX = endp.point.xPos - adjNode->point.xPos;
		int difY = endp.point.yPos - adjNode->point.yPos;
		int difZ = endp.point.zPos - adjNode->point.zPos;

		if( difX < 0 )		difX = difX * -1 ;
		if( difY < 0 )		difY = difY * -1 ;
		if( difZ < 0 )      difZ = difZ * -1 ;

		adjNode->h = (difX + difY + difZ ) * 10;
		adjNode->f = adjNode->g + adjNode->h ;

		open.insert(  pair<Node3D*,int>( adjNode , adjNode->f ) );
	}
	// adjNode is in open list
	else if  ( adjNode->getWalkable() && !findItem(close,adjNode) && !corner ) 
	{
		int g;
			if (xyzDigonal = true)
			{
				g = current->g + 17;
			}
			else
			{
				g = current->g + (xZDiagonal || xYDiagonal || yZDiagonal) ? 14 : 10;
			}
		if ( g < adjNode->g )
		{
			adjNode->g = g;
			adjNode->parent = current;
		}
	}
}