#ifndef _GRAPH_H_
#define _GRAPH_H_
struct Vex
{
      int num;
      char name[20];
      char desc[1024];
};
struct Edge
{
      int vex1,vex2;
      int weight;
};
struct Graph
{
      int m_aAdjMatrix[20][20];
      Vex m_aVexs[20];
      int m_nVexNum;
};
typedef struct Path
{
	int vexs[20];
	Path *next;
}*PathList;
void Init();
int InsertVex(Vex sVex);
int InsertEdge(Edge sEdge);
Vex GetVex(int nVex);
int FindEdge(int nvex,Edge aEdge[]);
int GetVexnum();
Graph Getgraph();
void DFS(int nVex,int index,int vNum[20]);
void Dijkstra(int source,int destination);
/*void DFSTraverse(int nVex,PathList &pList);*/
void Prim(int v);
#endif 