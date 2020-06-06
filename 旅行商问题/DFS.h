    #pragma once
    #include<iostream>
    #include<cmath>
    #include<fstream>   //文件输入函数
    #include <iomanip>  //格式规范库
    using namespace std;
    typedef int status;
    typedef char VElemType;

    #define MAXSIZE 30      
    #define MAX_LENGTH 999999
    #define	OK 1
    #define ERROR -1

    //默认为无向图的数据结构（邻接矩阵）
    typedef struct node
    {
        VElemType vexs[MAXSIZE];    //顶点的一维数组
        int arcs[MAXSIZE][MAXSIZE] = { 0 };   //边的二维数组
        int vexnum;  //顶点个数
        int arcnum;  //边的个数
    }Graph;

    //函数声明
    void CreateGragh(Graph& G);
    void DFS(Graph G, VElemType start);
    int getvex(Graph G, VElemType v);

    bool is_visited[MAXSIZE];			// 存储当前城市是否已被访问
    char path[MAXSIZE][MAXSIZE];	// 存储所有路径
    int lenth[MAX_LENGTH] = { 0 };		// 存储所有路径对应的长度
    long int num = 0, step= 0;          //声明下标和步数
    long int best = INT_MAX ;       //声明最短长度
