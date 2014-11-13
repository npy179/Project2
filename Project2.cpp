#include <iostream>
#include <stdio.h>
#include <cstdlib>
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
// void findNeigbour

 int main()
{
    string filename = "graph2.txt";
    vector<double> Arr;
    Arr = ReadGraph(filename);
    int numV = Arr.at(0);
    int numE = Arr.at(1);
	//cout<<"node"<<numV<<endl;
  //****************************************************************************
    //print adjmatrix
   int  v = int(numV);
   
   double adjmatrix[v+1][v+1];

  for (int i = 0; i <=v; i++)
    {
      for (int j = 0; j <= v;j++)
        {
          adjmatrix[i][j] = 0;
        }
    }
  for (int  i = 1; i <= numE; i++)
    {
      int posx = Arr.at(3*i-1);
      int posy = Arr.at(3*i);
      adjmatrix[posx][posy] = Arr.at(3*i+1);
    }
  cout<<"the matrix representation of graph is following:"<<endl;
  cout<<"*****************************************************"<<endl;
  for (int i = 1; i <= v;i++)
    {
      for (int j = 1; j <= v;j++)
        {
          cout <<" " <<adjmatrix[i][j];
        }
      cout<<endl;
    }
  cout<<"*****************************************************"<<endl;

  //*************************************************************************
  //dfs find the count of connected of component and connnected component
  // visisted flag
  bool visited[v];
  for (int i = 0 ; i < v; i++)
    {
      visited[i] = false;
    }	
//find the component and number of component
  int count = 0;
  int NumOfComp;
  list<list<int>> Components;

   int i=0;
	int C[3][20];
	for(int i = 0; i<3;i++)
	{
		for(int j = 0; j<20; j++)
		{
				C[i][j] = 0;
			
		}
	}
  for (int k = 1; k <= v; k++)
  {
	list<int>component;
	if(visited[k-1]!=true)
	{
		 //dfs find the component
		visited[k-1] = true;// draw the node 1 as visited
		queue<int> Q;
		Q.push(k);//put into queue
		component.push_back(k);
   		cout<<"***********************************************"<<endl;
	  while(!Q.empty())
		{
		  int currentNode = Q.front();
		  //pop out currentNode
		  Q.pop();
		  //*********************************
		  //get the neighbour of currentNode
		  list<int> neighbour;
		  for (int i=1; i<=v; i++)
			{
			  if (adjmatrix[currentNode][i] != 0)
			  {
				neighbour.push_back(i);
			  }
			  if (adjmatrix[i][currentNode] != 0)
			  {
				neighbour.push_back(i);
			  }
			}
		
		  // if currentnode has neighbours, do 
		  if(!neighbour.empty())
			{
			
			  for(list<int>::iterator it=neighbour.begin();it!=neighbour.end();it++)
				{
				  if(visited[*it-1]==false)
					{
					  Q.push(*it);
					  visited[*it-1] =true;
					  component.push_back(*it);//find the node that connected with current 
					 
					}
				}
			}
		}
		//print component
		cout<<"component "<<count+1<<" is "<<endl;
		cout<<endl;


		for (list<int>::iterator it = component.begin();it!=component.end();it++)
		 {
			C[count][i] = *it;
			cout<<*it<<" ";
			i++;
		 }
		cout<<endl;
		count++;
	}
	Components.push_back(component);
	NumOfComp = count;

   }

   
 /*  for(int i = 0; i<3; i++)
   {
	for(int j = 0; j<20; j++)
	{
		if(C[i][j]!=0)
		{
			cout<<C[i][j]<<"***";
		}

	}
	   cout<<endl;
    }*/

     
   cout<<"**********************************************************"<<endl;
   cout<<"adjacency list representation"<<endl;

   
   for(list<list<int>>::iterator it=Components.begin(); it != Components.end(); it++)
   {

	for(list<int>::iterator It=it->begin(); It != it->end(); It++)
	{
		int node = *It;
		cout<<"Node #"<<node;
		
		for (int j = node; j <= numV; j++)
		{
			if(adjmatrix[node][j] != 0)
			{
				cout<<"--"<<j;
			}	
		
		}
		cout<<endl;		
   } 
	cout<<endl;   
	//CPVectorS.push_back(PVector);
  }
   //test


   //K Minimum Spanning Tree Algorithm*/
   double   Array[2+3*numE];   
   for (int i = 0; i<3*numE+2;i++)
   {
	 Array[i] = Arr.at(i); 
   }
   
   //*****************************
   /*for(int i = 0; i<2+3*numE;i++)
   {
	cout<<Array[i]<<" ";
   }
   cout<<endl;*/
   //******************************
   
   
   double TMP[3];
   for(int i = 1; i < numE; i++)
   {
	for(int j = i+1; j <= numE; j++)
	{
		if(Array[3*i+1]>Array[3*j+1])
			{
				TMP[0] = Array[3*i-1];
				TMP[1] = Array[3*i];
				TMP[2] = Array[3*i+1];
				
				Array[3*i-1] = Array[3*j-1];
				Array[3*i] = Array[3*j];
				Array[3*i+1] = Array[3*j+1];
				
				Array[3*j-1] = TMP[0];
				Array[3*j] = TMP[1];
				Array[3*j+1] = TMP[2];			
			}
	}
   }
   
   //TEST
/*cout<<"+++++++++++++++++++++++++++++++"<<endl;
   for(int i = 0; i<3*numE+2;i++)
   {
	cout<<Array[i]<<" ";
   }
   cout<<endl;*/
   
   //find pair nodes
   bool explored[numV];
   for(int i = 0; i < numV; i++)
   {
	explored[i] = false;
   }

   int FPair[30];
   for (int i = 0; i<30;i++)
   {
	FPair[i] = 0;
   }
   
   int countpair=0;
   for(int i = 1; i < numE;i++)
   {
	 int posf = (int) Array[3*i-1];
	 int post = (int) Array[3*i];
	 if(explored[posf-1]==false || explored[post-1]==false)
	 {
		FPair[countpair] = posf;
		FPair[++countpair] = post;
		explored[posf-1] = true;
		explored[post-1] = true;
		
		countpair++;
	 }

	}
	
	
   double	CompMatrix[numV+1][numV+1];
	
	for(int i = 0; i<= numV; i++)
	{
		for(int j = 0; j <= numV; j++)
		{
			CompMatrix[i][j] = 0;
		}
	}
	
	for (int i = 0; i<30; i = i+2)
	{
		if(FPair[i] != 0)
		{
			int pos1 = FPair[i];
			int pos2 = FPair[i+1];
			CompMatrix[pos1][pos2] = adjmatrix[pos1][pos2];

		}
		//else
		//{	break;}
	}
	
	cout<<"the component MST"<<endl;
	for(int i = 1; i<=numV;i++)
	{
		for(int j = 1; j<=numV;j++)
		{
			cout<<CompMatrix[i][j]<<" ";
		}
		cout<<endl;
	}
	
	//print out the list of MST
   
  return 0;
 }
