//graph.h
#include <climits>
#include <vector>
#include <fstream>

using namespace std;

template<typename T>
class Graph
{
	private:
		//int max_size ;		//最大顶点数 
		vector<T> vertexList;	//顶点表
		vector< vector<int> > edge;//邻接矩阵
		//int currentEdges;		//当前边数	
		
		bool findVertex(const T& v);
		int getVertexPosition(const T& v);
		
	public:
		
//		Graph();		
		bool isEmpty();
		void printGraph();		
		int getNumberOfVertex();
		int getWeight(const T& v1, const T& v2);
		int getFirstNeighbor(int v);
		int getNextNeighbor(int v1,int v2);
		
		void insertVertex(const T& v);
		void deleteVertex(const T& v);
		void insertEdge(const T& v1, const T& v2, int w);
		void deleteEdge(const T& v1, const T& v2);
		
		void readGraph(string fileName);
};

//以矩阵的形式输出图 
template <typename T>
void Graph<T>:: printGraph()
{
	for(int i=0; i<vertexList.size(); i++)
	{
		cout<<vertexList[i]<<": [ ";
		for(int j=0; j<vertexList.size(); j++)
		{
			if(edge[i][j] < INT_MAX)
				cout<<edge[i][j]<<" ";
			else
				cout<<" ∞"<<" ";
		}
		cout<<"]"<<endl;
	}
	cout<<endl<<endl;
}

//检测图是否为空
template <typename T>
bool Graph<T>:: isEmpty()
{
	return vertexList.empty();
}

//返回图的顶点个数
template <typename T>
int Graph<T>:: getNumberOfVertex()
{
	return vertexList.size();
}

//返回顶点vertex在顶点表中的位置（序号）
template <typename T>
int Graph<T>:: getVertexPosition(const T& v)
{
	for(int i=0; i<vertexList.size(); i++)
	{
		if(vertexList[i] == v)//
		{
			return i;
		}
	}
	return -1;
}

//检查顶点vertex是否已在顶点表中
template <typename T>
bool Graph<T>:: findVertex(const T& v)
{
	if(getVertexPosition(v) != -1)
	{
		return true;
	}
	return false;	
}

//返回指定边的权值
template <typename T>
int Graph<T>:: getWeight(const T& v1, const T& v2)
{
	int pos1 = getVertexPosition(v1);
	int pos2 = getVertexPosition(v2);
	
	if(pos1 != -1 && pos2 != -1)
		return edge[pos1][pos2];
	else
		return INT_MAX;//实际应该进行异常处理 
}

//返回序号为v的顶点的第一个邻接顶点的序号
template <typename T>
int Graph<T>:: getFirstNeighbor(int v)
{
	for(int i=0; i<vertexList.size(); i++)
	{
		if(edge[v][i] > 0 && edge[v][i] < INT_MAX)
		{
			return i;
		}
	}
	return -1;
}

//返回序号为v1的顶点相对于序号为v2的顶点的下一个邻接顶点的序号
template <typename T>
int Graph<T>:: getNextNeighbor(int v1,int v2)
{
	if(v1 != -1 && v2 != -1)
	{
		for(int i = v2+1; i<vertexList.size(); i++)
		{
			if(edge[v1][i] > 0 && edge[v1][i] < INT_MAX)
			{
				return i;
			}
		}
	}
	return -1;
}

//插入一个顶点
template <typename T>
void Graph<T>:: insertVertex(const T& v)
{
	if(findVertex(v))//已存在该顶点 
		return;
	//增加列 
	for(int i=0; i<vertexList.size(); i++)
	{
		edge[i].push_back(INT_MAX);
	}
	//增加行
	vector<int> column(vertexList.size(), INT_MAX);
	column.push_back(0);
	edge.push_back(column);
	//加入顶点表 
	vertexList.push_back(v); 
}

/*在图中删去顶点v和所有与它相关联的边
*删除第pos行和第pos列 
*然后从顶点表中删除顶点 
*/
template <typename T>
void Graph<T>:: deleteVertex(const T& v)
{
	int pos = getVertexPosition(v);
	
	if(pos == -1)
		return;

	//删除第pos列 
	for(int i=0; i<vertexList.size(); i++)
	{
		edge[i].erase(edge[i].begin() + pos);
	}
	//删除第pos行
	edge.erase(edge.begin() + pos);
	//从顶点表中删除
	vertexList.erase(vertexList.begin() + pos);	  
}

/*插入一条边（v1,v2),边权值为w
 *插入之前顶点已存在 
*/
template <typename T>
void Graph<T>:: insertEdge(const T& v1, const T& v2, int w)
{
	int pos1 = getVertexPosition(v1);
	int pos2 = getVertexPosition(v2);
	
	if(pos1 != -1 && pos2 != -1)
	{
		edge[pos1][pos2] = w;
		edge[pos2][pos1] = w;
	}
}

/*在图中删去边
 *与删除的边关联的两个顶点已存在 
*/
template <typename T>
void Graph<T>:: deleteEdge(const T& v1, const T& v2)
{
	if(v1 == v2)
		return;
		
	int pos1 = getVertexPosition(v1);
	int pos2 = getVertexPosition(v2);
	
	if(pos1 != -1 && pos2 != -1)
	{
		edge[pos1][pos2] = INT_MAX;
		edge[pos2][pos1] = INT_MAX;
	}
}

//从文件中的数据构造图
template <typename T>
void Graph<T>:: readGraph(string fileName)
{
	int vertexNumber;
	T vertex;
	T v1,v2;
	int weight;
	
	ifstream in(fileName.c_str(),ios_base::in);
	if(!in)
	{
		cout<<"file open error!"<<endl;
		exit(1);
	}
	in>>vertexNumber;
	for(int i=0; i<vertexNumber; i++)
	{
		in>>vertex;
		insertVertex(vertex);//插入顶点
	}
	while(in>>v1>>v2>>weight)
	{
		insertEdge(v1, v2, weight);//插入边 
	}
} 