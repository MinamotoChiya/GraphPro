#include<iostream>
#include<stdlib.h>
#include"Graph.h"
using namespace std;
int main(){
    while(1){
	cout<<"===== ������Ϣ����ϵͳ ====="<<endl;
	cout<<"      1.������������ͼ      "<<endl;
	cout<<"      2.��ѯ������Ϣ        "<<endl;
	cout<<"      3.���ξ��㵼��        "<<endl;
	cout<<"      4.�������·��        "<<endl;
	cout<<"      5.�����·�滮        "<<endl;
	cout<<"      0.�˳�ϵͳ            "<<endl;
	cout<<"������������<0~5>:"<<endl;
	int cho;
	cin>>cho;
	switch(cho)
	   {
	     case 1:
		     {
				 Init();
				 cout<<"==== ������������ͼ ===="<<endl;
				 cout<<"������Ŀ:"<<Getgraph().m_nVexNum<<endl;
				 cout<<"---- ���� ----"<<endl;
				 for(int i=0;i<Getgraph().m_nVexNum;i++)
				 {
					 cout<<Getgraph().m_aVexs[i].num<<"-"<<Getgraph().m_aVexs[i].name<<endl;
				 }
				 cout<<"---- �� ----"<<endl;
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
				cout<<"==== ��ѯ������Ϣ ===="<<endl;
				for(int i=0;i<Getgraph().m_nVexNum;i++)
				 {
					 cout<<Getgraph().m_aVexs[i].num<<"-"<<Getgraph().m_aVexs[i].name<<endl;
				 }
				cout<<"��������Ҫ��ѯ�ľ����ţ�";
				int en;
				cin>>en;
				cout<<GetVex(en).name<<endl;
				cout<<GetVex(en).desc<<endl;
				cout<<"---- �ܱ߾��� ----"<<endl;
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
				cout<<"==== ���ξ��㵼�� ===="<<endl;
				for(int i=0;i<Getgraph().m_nVexNum;i++)
				 {
					 cout<<Getgraph().m_aVexs[i].num<<"-"<<Getgraph().m_aVexs[i].name<<endl;
				 }
				cout<<"��������ʼ����:";
				int snumber;
				cin>>snumber;
				cout<<"����·��Ϊ:"<<endl;
				int vnume[20];
				vnume[0]=snumber;
				DFS(snumber,1,vnume);
			}
			break;
		case 4:
			{
				cout<<"==== �������·�� ===="<<endl;
				for(int i=0;i<Getgraph().m_nVexNum;i++)
				 {
					 cout<<Getgraph().m_aVexs[i].num<<"-"<<Getgraph().m_aVexs[i].name<<endl;
				 }
				cout<<"��������ʼ�ص��Ŀ�ĵر��:";
				int sou,des;
				cin>>sou>>des;
				Dijkstra(sou,des);
			}
			break;
		case 5:
			{
				cout<<"==== �����·�滮 ===="<<endl;
			    cout<<"��������������������·��"<<endl;
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