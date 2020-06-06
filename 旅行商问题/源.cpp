#include<iostream>
#include"DFS.h"
using namespace std;


ofstream DFS_fout("C:\\Users\\48684\\source\\repos\\旅行商问题\\旅行商问题\\输出用文本.txt"); //输出变量声明

//创建无向图(文件）
void CreateGraph(Graph &G)
{
    //文件获取操作
    ifstream read_in;
    read_in.open("C:\\Users\\48684\\source\\repos\\旅行商问题\\旅行商问题\\6顶点.txt");     //输入变量声明
    //异常处理
    if (!read_in.is_open())     
    {
        cout << "文件获取失败！" << endl;
        return;
    }
    
    //获取顶点个数及顶点信息
    read_in >> G.vexnum;
    G.arcnum = 0;
    for (int i = 0; i < G.vexnum; i++)
    {
        read_in >> G.vexs[i];
    }
    

    //获取边的信息
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            read_in >> G.arcs[i][j];
            if (G.arcs[i][j] > 0)
            {
                G.arcnum++;
            }
        }
    }

    G.arcnum = G.arcnum / 2;    //因为无向图，实际边数减半（并无影响）

    //展示已获取的信息（供检查用）
    cout << "————————————————————————————————"<<endl;
    cout << "创建的图顶点共有" << G.vexnum << "个" << endl;
    cout << "创建的图边共有" << G.arcnum << "条" << endl;
    cout << "顶点信息：" << endl;
    for (int i = 0; i < G.vexnum;i++)
    {
        cout << G.vexs[i];
    }
    cout << endl;
    cout << "边信息" << endl;
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            cout  << setw(G.vexnum) << G.arcs[i][j] << " ";
        }
        cout << endl;
    }
    cout << "————————————————————————————————" << endl;

    
}

//获取城市所储存的下标
int getvex(Graph G, VElemType v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}

void DFS(Graph G, VElemType start)      //默认起始城市为A
{
    int v_index = getvex(G, start);	// 起始城市,每次调用（递归）都更新.

    if (step == G.vexnum - 1 ) //如果是最后一个城市，说明整条路线已记录，完成路线并计算该路线长度
    {
        path[num][step] = start;        //更新路线
        path[num][step + 1] = 'A';   // A为末尾城市（只记录前4个城市）
        

        // 计算路径长度
        for (int i = 0; i < G.vexnum; i++)
        {
            int m = path[num][i] - 65;      //找到记录字符的行号
            int k = path[num][i + 1] - 65;      //找到记录字符的列号
            lenth[num] += G.arcs[m][k];     //累加计算长度
        }

        if (best > lenth[num])
        {
            // 更新最短路径
            best = lenth[num];
        }

        //输出路径信息
        DFS_fout << "第" << (num + 1) << "条路径！" << endl;
        for (int i = 0; i <= G.vexnum; i++)
        {
            DFS_fout << path[num][i]<<"->";
        }
        DFS_fout << "长度为："<<lenth[num] << endl;
        DFS_fout << endl;
        num++;	// 下一条路径
        // 初始化下一次路径与上一次相同（为了只改变需要改变的步数）
        for (int i = 0; i < G.vexnum; i++)
        {
            path[num][i] = path[num - 1][i];
        }
        return;
    }
    else        //如果当前步数没有到路径末尾，则继续向下找节点
    {
        for (int i = 0; i < G.vexnum; i++)
        {
            if (G.arcs[v_index][i] > 0 && !is_visited[i])       //下一个节点是否有路或被访问过
            {
                path[num][step] = start;        //记录找到的节点
                step++;     //步数++
                is_visited[v_index] = true;     //找到的节点改为已访问
                DFS(G, (char)(i + 65));     //继续调用
                step--;     //调用结束返回，步数--，准备更改上一步信息
                is_visited[v_index] = false;        //修改访问信息
            }
        }
    }
   
        
   
}

//展示函数
void display(int *lenth)
{
    DFS_fout << "最短的路线长度为：" << best << endl;
    for (int i = 0; i < num; i++)
    {
        if (lenth[i] == best)
        {
            DFS_fout << "最短路径为：" << path[i]<<endl;
        }
    }
}




int main()
{
    Graph G;
    CreateGraph(G);
    char start = 'A';
    DFS(G,start);
    display(lenth);
}