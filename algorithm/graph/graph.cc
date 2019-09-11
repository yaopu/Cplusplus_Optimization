// 8个顶点连通无向图的边，有多少个？
//图的搜素
//深度优先遍历
//广度优先遍历
//图的存储
//连接矩阵
//顶点的度数
//深度优先算法的实现
// /https://blog.csdn.net/fanyun_01/article/details/82864580
/// https://www.cnblogs.com/tiffany018/p/9955246.html
// https://blog.csdn.net/qq_35295155/article/details/78639997
#include <iostream>
#include <stdio.h>
#define N 20
int visited[N]; /*访问标志数组,*/

typedef struct /*图的邻接矩阵,,数据结构体形式存放*/
{
  int vexnum;     // 1. 顶点数
  int arcnum;     // 2. 边的数
  char vexs[N];   // 3.顶点数组(N)
  int arcs[N][N]; // 4.边数组（N^2)
} graph;          //邻接矩阵存储图的信息

//深度优先
void createGraph(graph &g); /*建立一个无向图的邻接矩阵*/
void dfs(int i, graph &g);  /*从第i个顶点出发深度优先搜索*/
void tdfs(graph *g);        /*深度优先搜索整个图*/

//广度
void bfs(int k, graph *g); /*从第k个顶点广度优先搜索*/
void tbfs(graph *g);       /*广度优先搜索整个图*/
void init_visit();         /*初始化访问标识数组*/

/*建立一个无向图的邻接矩阵*/
void createGraph(graph &g) {
  int i, j;
  char v;
  g.vexnum = 0; //顶点数目
  g.arcnum = 0; //边的数目
  i = 0;
  printf("\n输入顶点序列(以#结束)：\n");
  while ((v = getchar()) != '#' || i < g.vexnum) {
    g.vexs[i] = v; /*读入顶点信息*/
    i++;
  }
  g.vexnum = i;                      /*顶点数目*/
  for (int i = 0; i < g.vexnum; i++) /*邻接矩阵初始化*/
  {
    for (int j = 0; j < g.vexnum; j++) {
      g.arcs[i][j] = 0; /*（1）-邻接矩阵元素初始化为0*/
    }
  }

  printf("\n输入边的信息(顶点序号,顶点序号)，以(-1,-1)结束：\n");
  scanf("%d,%d", &i, &j); /*读入边(i,j)*/
  if (i >= g.vexnum || j >= g.vexnum) {
    fprintf(stderr, "ERROR index \n");
  }
  while (i != -1) /*读入i为－1时结束*/
  {
    g.arcs[i][j] = 1; //-i,j对应边等于1,表示连接关系
    g.arcnum++;       //边数增加

    scanf("%d,%d", &i, &j); //继续读入
  }
} /* createGraph */
/*（3)---从第i个顶点出发深度优先搜索，补充完整算法*/
void dfs(int i, graph &g) { //单点递归，遍历所有相连的
  int j;
  printf("%c", g.vexs[i]);
  visited[i] = true; //修改标志，目标是把所有没被标记的都标记为true
  for (j = 0; j < g.vexnum; j++) {
    if (g.arcs[i][j] == 1 && !visited[j])
      dfs(j, g); //递归
  }
}

/*深度优先搜索整个图*/
void tdfs(graph &g) {
  int i;
  printf("\n从顶点%c开始深度优先搜索序列：\n", g.vexs[0]);
  for (i = 0; i < g.vexnum; i++)
    if (visited[i] != true) //---对尚未访问过的顶点进行深度优先搜索
      dfs(i, g);
  printf("\n");
} /*tdfs*/

void init_visit() /*初始化访问标识数组*/
{
  int i;
  for (i = 0; i < N; i++)
    visited[i] = false; //对于顶点的访问性质置false
}

int main() {
  graph ga;
  int i, j;
  printf("***********图邻接矩阵存储和图的遍历***********\n");
  printf("\n第一步：输入图的基本信息：顶点标记,边的连接阵\n");
  createGraph(ga);
  printf("\n2 第二步:输出图的邻接矩阵：\n");
  for (i = 0; i < ga.vexnum; i++) {
    for (j = 0; j < ga.vexnum; j++)
      printf("%3d", ga.arcs[i][j]);
    printf("\n");
  }
  printf("\n第三步-图的遍历：\n");
  init_visit(); /*初始化访问数组*/
  tdfs(ga);     /*深度优先搜索图*/

  // init_visit();
  // tbfs(&ga); /*广度优先搜索图*/
  return 0;
}

typedef struct /*队列的定义*/
{
  int data[N];
  int front;
  int rear;
} queue;
/*从第k个顶点广度优先搜索*/
void bfs(int k, graph *g) {
  int i, j;
  queue qlist, *q;
  q = &qlist;
  q->rear = 0;
  q->front = 0;
  printf("%c", g->vexs[k]);
  visited[k] = true;
  q->data[q->rear] = k;
  q->rear = (q->rear + 1) % N;
  while (q->rear != q->front) /*当队列不为空，进行搜索*/
  {
    i = q->data[q->front];
    q->front = (q->front + 1) % N;
    for (j = 0; j < g->vexnum; j++)
      if ((g->arcs[i][j] == 1) && (!visited[j])) {
        printf("%c", g->vexs[j]);
        visited[j] = true;
        q->data[q->rear] = j;        /*（5）---刚访问过的结点入队*/
        q->rear = (q->rear + 1) % N; /*（6）---修改队尾指针*/
      }
  }
} /*bfs*/

/*广度优先搜索整个图*/
void tbfs(graph *g) {
  int i;
  printf("\n从顶点%C开始广度优先搜索序列：", g->vexs[0]);
  for (i = 0; i < g->vexnum; i++)
    if (visited[i] != true)
      bfs(i, g); /*从顶点i开始广度优先搜索*/
  printf("\n");
} /*tbfs*/