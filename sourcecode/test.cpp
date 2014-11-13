#include <iostream>
#include <stdio.h>
#include<cstdlib>
#include <fstream>
#include <list>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
struct people
{
  int id;
  double weight;
};
int main()
{
  int v=10;
  people p;
  p.id = 1.1;
  p.weight = 1.3;
  vector< list <people>> adj[v];
  adj[1].push_back(p);
}
