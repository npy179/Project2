#include<iostream>
#include<list>
#include<vector>
#include<string>
using namespace std;

struct Vetics
{
	int id;//id of vetics
	double w;//weight when connect to former vectex
};

class Graph
{
	private:
	int V; //number of vectex in the graph.
        int E;//number of edges
	string filename;
	list<Vetics> *adj;//pointer to the adjacency list of graph

        public:
	Graph(string); // construct the Graph, transfer the number of x
	int DetermComponent(int);//s is the source of graph
	//void PrintadjMatrix(list<Vetics>);//print adjacency matrix x
        vector<double> ReadGraph(string);
};

Graph::Graph(string filename)//constructor of graph
{
  vector<double> Arr = ReadGraph(filename);//call readgraph
  this->V = Arr.front() ;//find the number of vatex.
  adj = new list<Vetics>[V];//creat V list
}
/*int Graph::DetermComponent(int s)
{
}*/


void Graph::PrintadjMatrix(list<Vetics> adj[V])
{
  vector< vector<double> > adjMatrix;//declare a 2D matrix
	for (int i = 0; i < V; i++)//initial it by 0
	{
		for (int j = 0; j < V; j++)
		{
			adjMatrix[i][j] = 0;
		}
	}
	//construct the adjacency matrix from adjacency
	
	Vetics vt;
	int id;rub
	for (int i = 0; i < V; i++)
	{
		for (list<Vetics>::iterator it=adj[i].begin(); it != adj[i].end();it++)
		{
			id = it->id;
			adjMatrix[i][id] = it->w;
		}
	}
	//print out the adjacency matrix
	cout<<"The adjacency matrix is:"<<endl;
	cout<<"----------------------------------"<<endl;
	for (int i = 0; i< adjMatrix.size(); i++)
	{
		for (int j = 0; j < adjMatrix[i].size(); j++)
		{
			cout<<" "<<adjMatrix[i][j];
		}
	}
	cout<<endl;
	cout<<"-----------------------------------"<<endl;
}


vector<double>  Graph::ReadGraph(string filename)
{
  ifstream myfile;
  myfile.open ("graph2.txt");
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

int main()
{
	int V = 10;
	Vetics vt;
	vt.id = 2;
	vt.w = 3.1;
	Graph gh(V);
	gh.addEdge(1,vt);
	gh.addEdge(2,vt);
	gh.addEdge(0,vt);
	Vetics vtn1 = gh.getVetics(1);
	Vetics vtn2 = gh.getVetics(2);
	Vetics vtn3 = gh.getVetics(0);
	cout<<"the id is: "<<vtn1.id<<vtn2.id<<vtn3.id<<endl;

        string filename = "graph2.txt";
        return 0;
}
