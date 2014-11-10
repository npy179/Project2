#include <iostream>
#include <stdio.h>
#include<cstdlib>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

struct AdjListnode    // creat a adjlist node, include prvious and next, and weight
{
  int dest;
  double weight;
  struct AdjListnode* next;
};

struct AdjList          //creat an adjlist
{
  struct AdjListnode * header;
}


class Graph
{
  private:
  int V; // number of vetics in the graph
  int E; // number of edges
  string filename;//input the filename
  //  list<Vetics> *adj;// declare a adjency list of graph

  public:
  Graph(string);//construct fucntion,
  vector<double> ReadGraph(string);
  //  int DetermComp();
  struct AdjListnode* newAdjListnode(int, double);
};

Graph::Graph(string filename)
{
  vector<double> Arr = ReadGraph(filename);//read the data from .txt, and then put it into the vector
  vector<double>::iterator it;
  this->V = Arr.front();
  //  this->E = Arr
  this->E = Arr.at(1);
  adj = new list<Vetics>[V];//create V list to hold the Vetics with weight

  int  v = int(V);
 double adjmatrix[v][v];

  for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10;j++)
        {
          adjmatrix[i][j] = 0;
        }
    }
  for (int  i = 1; i < v; i++)
    {
      int posx = Arr.at(3*i-1)-1;
      int posy = Arr.at(3*i)-1;
      adjmatrix[posx][posy] = Arr.at(3*i+1);
    }
 for (int i = 0; i < 10; i++)
    {
      for (int j = 0; j < 10; j++)
        {
          cout <<adjmatrix[i][j]<<" ";
        }
      cout<<endl;
      }
 cout<<"this the one element"<<Arr.at(5);
 for (it = Arr.begin();it != Arr.end();++it)
    {
      cout<<" "<<*it;
    }
  cout<<"-----------------------------------------------------------"<<endl;
  cout<<V<<" "<<E<<endl;
  cout<<"-----------------------------------------------------------"<<endl;
}

vector<double> Graph::ReadGraph(string filename)
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

struct AdjListnode* Graph::newAdjListnode(int dest, double weight)
{
  struct AdjListnode*  newNode =
}
 int main()
{
    string filename = "graph1.txt";
    Graph gp = Graph(filename);
    return 0;
 }
