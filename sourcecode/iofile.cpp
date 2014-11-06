// basic file operations
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main () {
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
    string::size_type sz;
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
                
                vector<double>::const_iterator i;
		for(i =vt.begin(); i!=vt.end();i++)
		{
                     cout<<*i<<endl;
		}
	}
	myfile.close();
  cout<<"the first element is:"<<vt.front()<<endl;
  }
  return 0;
}
