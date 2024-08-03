#pragma once

struct  Point 
{
	/// 地图三维坐标的一个点描述
	int		xPos;
	int		yPos;
	int		zPos;

	bool    tostring( char * str)
	{
		sprintf(str,"%d %d %d",xPos,yPos,zPos);
		return true;
	}

	bool operator == ( const Point & node2 ) const
	{
		return ( ( this->xPos == node2.xPos ) && ( node2.yPos == this->yPos) && (this->zPos == node2.zPos) );
	}
};

class Node3D
{
public:
	friend class Star;
public:
	Node3D(void);

	~Node3D(void);
	
	void  setStart( bool _start = true ) {  start = _start ;}//bool 数据类型
	void  setDestination( bool _Des =true ) {  destinantion = _Des;}
	void  setPath( bool _Path =true ) { path = _Path;}
	void  setWalkable( bool _able) { walkable = _able;}
	bool  getWalkable()  { return walkable; }
	void  setPoint(Point point)			      
	{
		memcpy(&this->point,&point,sizeof(Point));
	}
	//下面都是运算符
	bool  operator < ( const Node3D & node ) const //运算符重载为类的成员函数的一般格式为：<函数类型> operator <运算符>(<参数表>){ <函数体> }
	{
		return this->f < node.f;
	}
	
	bool  operator < ( const Node3D * node ) const
	{
		return this->f < node->f ; 
	}

	bool  operator() ( const Node3D & node1 , const Node3D & node2 ) const
	{
		return node1 < node2 ; 
	}

	bool  operator == ( const Node3D & node )const
	{
		return ( (this->point.xPos == node.point.xPos ) && ( this->point.yPos == node.point.yPos)  && ( this->point.zPos == node.point.zPos) );
	}

	bool  operator != ( const Node3D & node )const
	{
		return ( (this->point.xPos != node.point.xPos ) || ( this->point.yPos != node.point.yPos)  || ( this->point.zPos != node.point.zPos) );
	}

	bool  operator || ( const Node3D & node)const
	{
		return true ;
	}

public:
	static const int SIZE = 1200000;
	Point			 point;
	Node3D			 *parent;	
	int				 f;
	int				 g;
	int				 h;
	int				 ambient;
	int			     color;
	int				 alpha;
	bool			 walkable;
	bool			 start;
	bool			 destinantion;
	bool			 path;
};