#include<iostream>
#include<stdio.h>
#include<fstream>
#include<string>
#include"Graph.h"
#include<math.h>
Graph m_Graph;
using namespace std;
void Init()
{   
	char filename1[50]="Vex.txt";
    char filename2[50]="Edge.txt";
	ifstream infile;
    infile.open(filename1);
	int i=0;
	while(!infile.eof()) 
     {
          infile>>m_Graph.m_aVexs[i].num>>m_Graph.m_aVexs[i].name>>m_Graph.m_aVexs[i].desc;
          i++;
     }
	m_Graph.m_nVexNum=i-1;
    /*string s;
	getline(infile,s);
    int vm=int(s[0]);
    for(int i=0;i<vm;i++)
	  {
		 Vex vex;
		 getline(infile,s);
		 vex.num=int(s[0]);
		 getline(infile,s);
		 strcpy(vex.name,s.data());
		 getline(infile,s);
		 strcpy(vex.desc,s.data());
	     InsertVex(vex,i);
	  }*/
	infile.close();
	for(int m=0;m<m_Graph.m_nVexNum;m++)
		for(int n=0;n<m_Graph.m_nVexNum;n++)
		{
			m_Graph.m_aAdjMatrix[m][n]=0;
		}
	infile.open(filename2);
	int place1,place2,distance,pos1,pos2;
    Edge eg;
	while(!infile.eof()) 
	{	
              infile>>place1>>place2>>distance;
              pos1=GetVex(place1).num;
              pos2=GetVex(place2).num;
			  eg.vex1=pos1;
			  eg.vex2=pos2;
			  eg.weight=distance;
			  InsertEdge(eg);
	}
	for (int i=0;i<m_Graph.m_nVexNum;i++)
        for (int j=0;j<m_Graph.m_nVexNum;j++)
            {
				if((i!=j)&& (m_Graph.m_aAdjMatrix[i][j]==0))
				{
				     m_Graph.m_aAdjMatrix[i][j]=INT_MAX;
				}
	     	}
	/*infile.open(filename2);
	streambuf* old_buffer = cin.rdbuf(infile.rdbuf());
	string s2;
	while(cin >> s2)
	{
        
	}*/
}
int InsertVex(Vex sVex,int nvm)
{   
  return 0;
}
int InsertEdge(Edge sEdge)
{
	m_Graph.m_aAdjMatrix[sEdge.vex1][sEdge.vex2]=sEdge.weight;
	m_Graph.m_aAdjMatrix[sEdge.vex2][sEdge.vex1]=sEdge.weight;
	return 0;
}
int GetVexnum()
{
	return m_Graph.m_nVexNum;
}
Vex GetVex(int nVex)
{
	return m_Graph.m_aVexs[nVex];

}
Graph Getgraph()
{
	return m_Graph;
}
void DFS(int nVex,int index,int vNum[20])
{
	if(index==m_Graph.m_nVexNum)
	{
		cout<<m_Graph.m_aVexs[vNum[0]].name;
		for(int i=1;i<m_Graph.m_nVexNum;i++)
		{
			cout<<"->"<<m_Graph.m_aVexs[vNum[i]].name;
		}
		cout<<endl;
	}
	int j = 0;
	for(int i=0;i<m_Graph.m_nVexNum;i++) 
	{
		if((m_Graph.m_aAdjMatrix[nVex][i]!= 0)&&(m_Graph.m_aAdjMatrix[nVex][i]!=INT_MAX))
		{
			j=0;
			for(;j<index;j++){
				if(m_Graph.m_aVexs[i].num==vNum[j])
				break;
			}
			if(j==index){
				vNum[index]=m_Graph.m_aVexs[i].num;
				DFS(i, index + 1, vNum);
			}
		}
	}
	/*int j;
	int i=nVex;
	int n=0;
	if(m_Graph.Visited[i]=false)
	{
		pList->vexs[n]=i;
		n++;
	}
	for(int m=0;m<m_Graph.m_nVexNum;m++)
	{
		if((m_Graph.m_aAdjMatrix[i][m]!=0)&& (m_Graph.Visited[m]=false))
		{
			pList->vexs[n]=m;
			n++;
			DFS(m,n,pList);
		}
	}
	*/
}
/*void DFSTraverse(int vmm,PathList &pList)
{
	int NVEX=vmm;
	int count=0;
	int nIndex=0;
	for(int n=0;n<m_Graph.m_nVexNum;n++)
	{
		m_Graph.Visited[n]=false;
	}
	for(int j=0;j<Getgraph().m_nVexNum;j++)
				{
					if(Getgraph().m_aAdjMatrix[NVEX][j]!=0)
					{
						count++;
					}
				}
	DFS(NVEX,pList);

	for(int j=0;j<Getgraph().m_nVexNum;j++)
				{
					if(Getgraph().m_aAdjMatrix[NVEX][j]!=0)
					{
						nIndex++;
					}
				}

}*/
void Dijkstra(int source,int destination)
{
	bool visited[20];
	int dist[100];
	int path[100];
	memset(visited, 0, sizeof(visited));
	visited[source]=true;
	for(int i=0;i<m_Graph.m_nVexNum;i++)
	{
		dist[i]=m_Graph.m_aAdjMatrix[source][i];
		path[i]=source;
	}
	int min_cost;
	int min_cost_index;
	for(int i=0;i<m_Graph.m_nVexNum;i++)
	{
		min_cost=INT_MAX;
		for(int j=0;j<m_Graph.m_nVexNum;j++)
		{
			if(visited[j]==false && dist[j]<min_cost)
			{
				min_cost=dist[j];
				min_cost_index=j;
			}
		}
		visited[min_cost_index]=true;
		for (int j=0;j<m_Graph.m_nVexNum;j++)
        {
            if(visited[j]==false && m_Graph.m_aAdjMatrix[min_cost_index][j]!=INT_MAX && m_Graph.m_aAdjMatrix[min_cost_index][j]+min_cost<dist[j])
            {
                dist[j]=m_Graph.m_aAdjMatrix[min_cost_index][j]+min_cost;
                path[j]=min_cost_index;
            }
        }
	}
	/*for(int i=0;i<m_Graph.m_nVexNum;i++)
    {
        if (i!=source)
        {*/
    cout<<m_Graph.m_aVexs[source].name<<"到"<<m_Graph.m_aVexs[destination].name<<"的最短距离是"<<dist[destination]<<"，路径是：" <<m_Graph.m_aVexs[destination].name;
    int t= path[destination];
    while(t!=source)
      {
          cout<<"-"<<m_Graph.m_aVexs[t].name;
          t=path[t];
      }
    cout<<"-"<<m_Graph.m_aVexs[source].name<<endl;
}
void Prim(int v)
{
	int lowcost[100],closest[100],i,min,j,k;
	int length=0;
	for (i=0;i<m_Graph.m_nVexNum;i++)
	{
		closest[i] = v;
		lowcost[i] = m_Graph.m_aAdjMatrix[v][i];
	}
	for (i=1;i<m_Graph.m_nVexNum;i++)
	{
 
		min=INT_MAX;
		for (j=0;j<m_Graph.m_nVexNum;j++)//遍历所有节点
		{
			if (lowcost[j]!=0 && lowcost[j]<min)//若该节点还未被选且权值小于之前遍历所得到的最小值
			{
				min = lowcost[j];//更新min的值
				k = j;//记录当前最小权重的节点的编号
			}
		}
		cout<<m_Graph.m_aVexs[closest[k]].name<<"-"<<m_Graph.m_aVexs[k].name<<"   "<<min<<"m"<<endl;
		lowcost[k]=0;//表明k节点已被选了(作标记)
		for (j=0;j<m_Graph.m_nVexNum;j++)//遍历所有节点
		{
			if (m_Graph.m_aAdjMatrix[k][j]!=0 && m_Graph.m_aAdjMatrix[k][j]!=INT_MAX && m_Graph.m_aAdjMatrix[k][j]<lowcost[j])
			{
				
				lowcost[j]=m_Graph.m_aAdjMatrix[k][j];
				closest[j]=k;
				length+=lowcost[j];
			}
		}
	}
	cout<<"铺设电路的总长度为："<<length<<"m"<<endl;
}