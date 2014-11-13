#include <iostream>
#include <stdio.h>
#include<cstdlib>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
using namespace std;

//read the .txt file
vector<double> ReadGraph(string filename)
{
  ifstream myfile;
  myfile.open (filename);
  string line;
  vector<string> VT;
  if(myfile.is_open())
  {
    string token;
    string token0;
    string token1;
    stringstream iss;
    stringstream iss2;
    stringstream iss3;
    double num;
    vector<double> vt;
        while(myfile.good())
        {

                while (getline(myfile, line))
                {
                  iss << line;
                  while(getline(iss,token0,','))
                    {
                      iss2<<token0;
                      while(getline(iss2,token,' '))
                        {
                          iss3<<token;
                          while(getline(iss3,token1,'\n'))
                            {
                              num = stod(token1);
                              vt.push_back(num);
                            }
                          iss3.clear();
                        }
                      iss2.clear();
                    }
                  iss.clear();
                }
        }
        myfile.close();
        return vt;
  }

 }
// Breadth tirst search
int NumOfConnComp(int v, int adjList[][10],int numnode[])
{
        int components=0;
        queue<int> S;
        bool* visited = new bool[v];
        for(int i=1;i<v;i++)
                visited[i]=false;
        visited[0]=true;

        S.push(0);
        while(!S.empty())
        {
                int curvetex = S.front();
                S.pop();
                //********************************
                int nnodes = numnode[curvetex];
                list<int> x;
                for(int i = 0; i<nnodes;i++)
                  {
                    int tmp = adjList[curvetex][i];
                    x.push_back(tmp);
                  }
                //*******************************
                if(!x.empty())
                {
                        list<int>::iterator it;
                for (it=x.begin(); it!=x.end(); it++)
                        {
                                if(visited[*it]==false)
                                {
                                        S.push(*it);
                                        visited[*it]=true;
                                }
                        }
                }

                if(S.empty())
                {
                        components++;
                        for(int i=1;i<v;i++)
                        {
                                if(visited[i]==false)
                                {
                                        S.push(i);
                                        visited[i]=true;
                                        break;
                                }
                        }

                }
        }
        return components;
}

 int main()
{
    string filename = "graph1.txt";
    vector<double> Arr;
    Arr = ReadGraph(filename);
    int numV = Arr.at(1);
    int numE = Arr.at(2);
  //****************************************************************************
    //print adjmatrix
   int  v = int(numV);
   double adjmatrix[v+1][v+1];

  for (int i = 0; i <=10; i++)
    {
      for (int j = 0; j <= 10;j++)
        {
          adjmatrix[i][j] = 0;
        }
    }
  for (int  i = 1; i <= v; i++)
    {
      int posx = Arr.at(3*i-1);
      int posy = Arr.at(3*i);
      adjmatrix[posx][posy] = Arr.at(3*i+1);
    }
  cout<<"the matrix representation of graph is following:"<<endl;
  cout<<"---------------------------------------------------"<<endl;
  for (int i = 1; i <= v;i++)
    {
      for (int j = 1; j <= v;j++)
        {
          cout <<" " <<adjmatrix[i][j];
        }
      cout<<endl;
    }
  cout<<"-------------------------------------------------"<<endl;
  //**************************************************************************creat adjList
  int adjList[v+1][20];
  double weight[v+1][20];
  int  node;
  int numnode[v+1];

  for(int i=1; i<=v;i++)
    {
      for (int j = 0; j<20;j++)
        {
          adjList[i][j] = 0;
          weight[i][j] = 0;
        }
    }

  for (int i = 1;  i<= v; i++)
    {
      node = 0;
      for (int j = j; j<=v; j++)
        {
          if(adjmatrix[i][j] != 0)
            {
              adjList[i][node] = j;
              weight[i][node] = adjmatrix[i][j];
              node++;
             }
        }
       numnode[i] = node;
 }
  cout<<"the number of each node"<<endl;
  for (int i = 1; i <= v; i++)
    {
      cout<<" "<<numnode[i];
    }
  cout<<endl;
  cout<<"====================";
  cout<<"The adjence list repretation: w is weight"<<endl;
  cout<<"============================="<<endl;
  for (int i  = 1; i <=v; i++)
    {
      cout<<"Node # "<<i;
      for (int j = 0; j<=numnode[i]; j++)
        {
          if(adjList[i][j]!=0)
            {
              cout<<"  "<<adjList[i][j]<<"|w:"<<weight[i][j];
            }
        }
      cout<<endl;
    }
    cout<<"============================="<<endl;
  //*************************************************************************
   //**********************************************************************
  //dfs find the count of connected of component and connnected component
  // visisted flag
  /* bool visited[10];
  for (int i = 0 ; i < 10; i++)
    {
      visited[i] = false;
    }

  //dfs find the component
  int s = 0;
  visited[0] = true;// draw the node o as visited
  queue<int> Q;
  Q.push(s);
  list<int> component;
  component.push_back(s);
  while(!Q.empty())
    {
      int currentNode = Q.front();
      //pop out currentNode
      Q.pop();
      //*********************************
      //get the neighbour of currentNode
      list<int> neighbour;
      for (int i=0; i<numnode[currentNode]; i++)
        {
          neighbour.push_back( adjList[0][i]);
        }
      // if currentnode has neighbours
      if(!neighbour.empty())
        {
          list<int>::iterator it;
          for(it=neighbour.begin();it!=neighbour.end();it++)
            {
              if(visited[*it]==false)
                {
                  Q.push(*it);
                  visited[*it] =true;
                 component.push_back(*it);//find the node that connected with current node
                }
            }
        }
        cout<<component.front()<<endl;



      //*********************************
      }*/


  //**********************************************************************
  return 0;
 }
