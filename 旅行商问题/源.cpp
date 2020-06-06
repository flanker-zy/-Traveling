#include<iostream>
#include"DFS.h"
using namespace std;


ofstream DFS_fout("C:\\Users\\48684\\source\\repos\\����������\\����������\\������ı�.txt"); //�����������

//��������ͼ(�ļ���
void CreateGraph(Graph &G)
{
    //�ļ���ȡ����
    ifstream read_in;
    read_in.open("C:\\Users\\48684\\source\\repos\\����������\\����������\\6����.txt");     //�����������
    //�쳣����
    if (!read_in.is_open())     
    {
        cout << "�ļ���ȡʧ�ܣ�" << endl;
        return;
    }
    
    //��ȡ���������������Ϣ
    read_in >> G.vexnum;
    G.arcnum = 0;
    for (int i = 0; i < G.vexnum; i++)
    {
        read_in >> G.vexs[i];
    }
    

    //��ȡ�ߵ���Ϣ
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

    G.arcnum = G.arcnum / 2;    //��Ϊ����ͼ��ʵ�ʱ������루����Ӱ�죩

    //չʾ�ѻ�ȡ����Ϣ��������ã�
    cout << "����������������������������������������������������������������"<<endl;
    cout << "������ͼ���㹲��" << G.vexnum << "��" << endl;
    cout << "������ͼ�߹���" << G.arcnum << "��" << endl;
    cout << "������Ϣ��" << endl;
    for (int i = 0; i < G.vexnum;i++)
    {
        cout << G.vexs[i];
    }
    cout << endl;
    cout << "����Ϣ" << endl;
    for (int i = 0; i < G.vexnum; i++)
    {
        for (int j = 0; j < G.vexnum; j++)
        {
            cout  << setw(G.vexnum) << G.arcs[i][j] << " ";
        }
        cout << endl;
    }
    cout << "����������������������������������������������������������������" << endl;

    
}

//��ȡ������������±�
int getvex(Graph G, VElemType v)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        if (G.vexs[i] == v)
            return i;
    }
    return -1;
}

void DFS(Graph G, VElemType start)      //Ĭ����ʼ����ΪA
{
    int v_index = getvex(G, start);	// ��ʼ����,ÿ�ε��ã��ݹ飩������.

    if (step == G.vexnum - 1 ) //��������һ�����У�˵������·���Ѽ�¼�����·�߲������·�߳���
    {
        path[num][step] = start;        //����·��
        path[num][step + 1] = 'A';   // AΪĩβ���У�ֻ��¼ǰ4�����У�
        

        // ����·������
        for (int i = 0; i < G.vexnum; i++)
        {
            int m = path[num][i] - 65;      //�ҵ���¼�ַ����к�
            int k = path[num][i + 1] - 65;      //�ҵ���¼�ַ����к�
            lenth[num] += G.arcs[m][k];     //�ۼӼ��㳤��
        }

        if (best > lenth[num])
        {
            // �������·��
            best = lenth[num];
        }

        //���·����Ϣ
        DFS_fout << "��" << (num + 1) << "��·����" << endl;
        for (int i = 0; i <= G.vexnum; i++)
        {
            DFS_fout << path[num][i]<<"->";
        }
        DFS_fout << "����Ϊ��"<<lenth[num] << endl;
        DFS_fout << endl;
        num++;	// ��һ��·��
        // ��ʼ����һ��·������һ����ͬ��Ϊ��ֻ�ı���Ҫ�ı�Ĳ�����
        for (int i = 0; i < G.vexnum; i++)
        {
            path[num][i] = path[num - 1][i];
        }
        return;
    }
    else        //�����ǰ����û�е�·��ĩβ������������ҽڵ�
    {
        for (int i = 0; i < G.vexnum; i++)
        {
            if (G.arcs[v_index][i] > 0 && !is_visited[i])       //��һ���ڵ��Ƿ���·�򱻷��ʹ�
            {
                path[num][step] = start;        //��¼�ҵ��Ľڵ�
                step++;     //����++
                is_visited[v_index] = true;     //�ҵ��Ľڵ��Ϊ�ѷ���
                DFS(G, (char)(i + 65));     //��������
                step--;     //���ý������أ�����--��׼��������һ����Ϣ
                is_visited[v_index] = false;        //�޸ķ�����Ϣ
            }
        }
    }
   
        
   
}

//չʾ����
void display(int *lenth)
{
    DFS_fout << "��̵�·�߳���Ϊ��" << best << endl;
    for (int i = 0; i < num; i++)
    {
        if (lenth[i] == best)
        {
            DFS_fout << "���·��Ϊ��" << path[i]<<endl;
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