#include<iostream>
#include<stdlib.h>
#include"Graph.h"
using namespace std;
int main(){
    while(1){
	cout<<"===== 景区信息管理系统 ====="<<endl;
	cout<<"      1.创建景区景点图      "<<endl;
	cout<<"      2.查询景点信息        "<<endl;
	cout<<"      3.旅游景点导航        "<<endl;
	cout<<"      4.搜索最短路径        "<<endl;
	cout<<"      5.铺设电路规划        "<<endl;
	cout<<"      0.退出系统            "<<endl;
	cout<<"请输入操作编号<0~5>:"<<endl;
	int cho;
	cin>>cho;
	switch(cho)
	   {
	     case 1:
		     {
				 Init();
				 cout<<"==== 创建景区景点图 ===="<<endl;
				 cout<<"顶点数目:"<<Getgraph().m_nVexNum<<endl;
				 cout<<"---- 顶点 ----"<<endl;
				 for(int i=0;i<Getgraph().m_nVexNum;i++)
				 {
					 cout<<Getgraph().m_aVexs[i].num<<"-"<<Getgraph().m_aVexs[i].name<<endl;
				 }
				 cout<<"---- 边 ----"<<endl;
				 for(int m=0;m<20;m++)
					 for(int n=0;n<=m;n++)
					 {
						 if((Getgraph().m_aAdjMatrix[m][n]!=0)&&(Getgraph().m_aAdjMatrix[m][n]!=INT_MAX))
						 {
							 cout<<"<"<<m<<","<<n<<">"<<"  "<<Getgraph().m_aAdjMatrix[m][n]<<endl;
						 }
					 }
			 }
			 break;
		case 2:
			{
				cout<<"==== 查询景点信息 ===="<<endl;
				for(int i=0;i<Getgraph().m_nVexNum;i++)
				 {
					 cout<<Getgraph().m_aVexs[i].num<<"-"<<Getgraph().m_aVexs[i].name<<endl;
				 }
				cout<<"请输入想要查询的景点编号：";
				int en;
				cin>>en;
				cout<<GetVex(en).name<<endl;
				cout<<GetVex(en).desc<<endl;
				cout<<"---- 周边景区 ----"<<endl;
				for(int j=0;j<Getgraph().m_nVexNum;j++)
				{
					if((Getgraph().m_aAdjMatrix[en][j]!=0)&&(Getgraph().m_aAdjMatrix[en][j]!=INT_MAX))
					{
						cout<<GetVex(en).name<<"->"<<GetVex(j).name<<"     "<<Getgraph().m_aAdjMatrix[en][j]<<"m"<<endl;
					}
				}
			}
			break;
		case 3:
			{
				cout<<"==== 旅游景点导航 ===="<<endl;
				for(int i=0;i<Getgraph().m_nVexNum;i++)
				 {
					 cout<<Getgraph().m_aVexs[i].num<<"-"<<Getgraph().m_aVexs[i].name<<endl;
				 }
				cout<<"请输入起始点编号:";
				int snumber;
				cin>>snumber;
				cout<<"导游路线为:"<<endl;
				int vnume[20];
				vnume[0]=snumber;
				DFS(snumber,1,vnume);
			}
			break;
		case 4:
			{
				cout<<"==== 搜索最短路径 ===="<<endl;
				for(int i=0;i<Getgraph().m_nVexNum;i++)
				 {
					 cout<<Getgraph().m_aVexs[i].num<<"-"<<Getgraph().m_aVexs[i].name<<endl;
				 }
				cout<<"请输入起始地点和目的地编号:";
				int sou,des;
				cin>>sou>>des;
				Dijkstra(sou,des);
			}
			break;
		case 5:
			{
				cout<<"==== 铺设电路规划 ===="<<endl;
			    cout<<"在以下两个景点间铺设电路："<<endl;
				int a=0;
				Prim(a);
			}
			break;
		case 0:
			{
					exit(0);
					break;
			}
	   }
	}
}