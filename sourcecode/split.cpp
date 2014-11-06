/* strtok example */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main ()
{
  
  ifstream myfile;
  myfile.open ("graph2.txt");
  string str;
  
  cout<<"-------------------------------"<<endl;
  if(myfile.is_open())
  {

	while(myfile.good())
	{
		getline(myfile,str);
		char * pch;
		vector<string> vt;
		vector<string>::const_iterator i;
		printf ("Splitting string \"%s\" into tokens:\n",str);
		pch = strtok (str," ,");
		while(pch != NULL)
		{
			vt.push_back(pch);
			pch = strtok(NULL," ,");
		}
		for(i=vt.begin(); i!=vt.end();++i)
		{
			cout<<(*i)<<endl;
		}
	}
  return 0;
}