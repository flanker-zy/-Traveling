    #pragma once
    #include<iostream>
    #include<cmath>
    #include<fstream>   //�ļ����뺯��
    #include <iomanip>  //��ʽ�淶��
    using namespace std;
    typedef int status;
    typedef char VElemType;

    #define MAXSIZE 30      
    #define MAX_LENGTH 999999
    #define	OK 1
    #define ERROR -1

    //Ĭ��Ϊ����ͼ�����ݽṹ���ڽӾ���
    typedef struct node
    {
        VElemType vexs[MAXSIZE];    //�����һά����
        int arcs[MAXSIZE][MAXSIZE] = { 0 };   //�ߵĶ�ά����
        int vexnum;  //�������
        int arcnum;  //�ߵĸ���
    }Graph;

    //��������
    void CreateGragh(Graph& G);
    void DFS(Graph G, VElemType start);
    int getvex(Graph G, VElemType v);

    bool is_visited[MAXSIZE];			// �洢��ǰ�����Ƿ��ѱ�����
    char path[MAXSIZE][MAXSIZE];	// �洢����·��
    int lenth[MAX_LENGTH] = { 0 };		// �洢����·����Ӧ�ĳ���
    long int num = 0, step= 0;          //�����±�Ͳ���
    long int best = INT_MAX ;       //������̳���
