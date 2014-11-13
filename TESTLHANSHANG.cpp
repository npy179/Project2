#include <iostream>
#include <fstream>
using namespace std;


int bfs_graph_pp(int adj_list[][100], int count_num[], int num_v, int node[])
{


    int queue[num_v + 1];
    for (int i = 0; i <= num_v; i++)
        queue[i] = 0;


    int count_queue = 0;
    int point_queue = 0;


    for (int i = 1; i <= num_v; i++)
    {
        if (node[i] == 1)
        {
            queue[1] = i;
            node[i] = 0;
            break;
        }

    }

    if(queue[1] == 0)
        return 0;

    count_queue = 1;
    point_queue = 1;




    for (int i = point_queue; i <= count_queue; i++)
    {
        int current_node = queue[point_queue];

//        cout << "current point is " << point_queue << endl;
//        cout << "current node is " << current_node << endl;


        for (int j = 0; j < count_num[current_node]; j++)
        {
//            cout << count_num[current_node] << endl;


            int tag = 0;

            for (int k = 1; k <= count_queue; k++)
            {
                if (adj_list[current_node][j] == queue[k])
                {
                    tag = 1;
                }
            }



            if (tag == 0)
            {
                queue[count_queue + 1] = adj_list[current_node][j];
//                cout << "put " << adj_list[current_node][j] << " into the queue" << endl;
                node[adj_list[current_node][j]] = 0;
                count_queue++;
            }


        }


        point_queue++;

    }







//    cout << count;

    cout << endl;

    return 1;

}


bool if_in_set(int set[], int input, int num_of_set)
{
    for (int i = 1; i<=num_of_set; i++)
    {
        if (set[i] == input)
        {
            return 1;
        }
    }
    return 0;
}





void prim_tree(int node_comp[], int start, int end, double adj_matrix[][100], int adj_list[][100], int num_of_neigbour[], int spanning_tree[][3])
{

    int V[end - start + 2];
    int G[end - start + 2];
    for (int i = 1; i <= end - start + 1; i++)
    {
        V[i] = 0;
        G[i] = node_comp[start + i - 1];
    }

    int num_v = 0;
    int num_g = end - start + 1;

    V[1] = G[1];
    num_v++;
    num_g--;

    int mini_spanning_edge[end - start + 2][3];
    for (int i = 0; i <= end - start + 1; i++)
    {
        for (int j = 0; j <= 2 ; j++)
        {
            mini_spanning_edge[i][j] = 0;
           // cout << mini_spanning_edge[i][j];
        }
    }

    int temp_node_a = 0;
    int temp_node_b = 0;
    int count = 0;

    while (num_g)
    {

        for (int i = 1; i <= num_v; i++)
        {
            cout << "V: " << V[i] << " ";
        }
        cout << endl;
        int temp_mini_edge = 66536;
        temp_node_a = 0;
        temp_node_b = 0;

        for (int i = 1; i <= num_v; i++)
        {

            int cur_node = V[i];

            for (int j = 0; j < num_of_neigbour[cur_node]; j++)
            {

                int cur_neigbour = adj_list[cur_node][j];

              //  cout << cur_node << " " << cur_neigbour << endl;




                if ( (adj_matrix[i][cur_neigbour] < temp_mini_edge) && (!if_in_set(V, cur_neigbour, num_v)) )
                {
                    cout << "!!!" << endl;
                    temp_mini_edge = adj_matrix[i][cur_neigbour];
                    temp_node_a = cur_node;
                    temp_node_b = cur_neigbour;

                   // cout << "neigbour is" << temp_node_b << endl;
                }
            }
        }

//        cout << "neigbour is " << temp_node_b << endl;

        count++;
        mini_spanning_edge[count][1] = temp_node_a;
        mini_spanning_edge[count][2] = temp_node_b;
        num_g--;
        num_v++;
        V[num_v] = temp_node_b;




    }



    for (int i = 1; i < end - start + 1; i++)
    {
        for (int j = 1; j <= 2 ; j++)
        {
            //mini_spanning_edge[i][j] = 0;
            cout << mini_spanning_edge[i][j];
        }
        cout << endl;
    }




    for (int i = 0; i <= end - start; i++)
    {
        spanning_tree[i][1] = mini_spanning_edge[i][1];
        spanning_tree[i][2] = mini_spanning_edge[i][2];
    }


 /*
    int comp_adj_matrix[start - end + 1][100];


    for(int i = 0; i <= start - end; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            comp_adj_matrix[i][j] = 0;

        }
    }



    for (int i = 1; i <= start - end; i++)
    {
        mini_spanning_edge[i][1] = temp_node_a;
        mini_spanning_edge[i][2] = temp_node_b;
        comp_adj_matrix[temp_node_a][temp_node_b] = adj_matrix[temp_node_a][temp_node_b];
    }

    for(int i = 0; i <= start - end + 1; i++)
    {
        for (int j = 0; j <= start - end + 1; j++)
        {
            cout << comp_adj_matrix[i][j] << " @@@";
        }
        cout << endl;
    }

  */




}



int main(int argc, const char * argv[]) {




    int num_v = 0;
    int num_e = 0;
    string space;


    ifstream in("graph1.txt");
    if (! in.is_open())
    { cout << "Error opening file"; exit (1); }

    in >> num_v >> space >> num_e;
//origin matrix

    double ori_matrix[num_e + 1][4];
//    double temp_matrix[1][4];


    for (int i = 0; i <= num_e; i++)
        for (int j = 0; j < 4; j++)
        {
            ori_matrix[i][j] = 0;

        }


    for (int i = 1; i <= num_e; i++)
    {
        in >> ori_matrix[i][1] >> space >> ori_matrix[i][2] >> space >> ori_matrix[i][3];


    }


//adjacency matrix
    double adj_matrix[100][100];

    for (int i = 1; i <= num_v; i++)
        for (int j = 1; j <= num_v; j++)
        {
            adj_matrix[i][j] = double(0);
        }

    for (int i = 1; i <= num_e; i++)
    {
        int temp_i = ori_matrix[i][1];
        int temp_j = ori_matrix[i][2];
        double temp_length = ori_matrix[i][3];

        adj_matrix[temp_i][temp_j] = temp_length;
        adj_matrix[temp_j][temp_i] = temp_length;


    }

//test
    for (int i = 1; i <= num_e; i++)
    {
        cout << ori_matrix[i][0] << endl;
    }







//print adjacency matrix
    for (int i = 1; i <= num_v; i++)
        cout << " " << i;
    cout << endl;
    for (int i = 1; i <= num_v; i++)
    {
        cout << i << " ";
        for (int j = 1; j <= num_v; j++)
        {

            cout << adj_matrix[i][j];
        }
        cout << endl;

    }

//adjacency list
    int adj_list[num_v + 1][100];
    int count = 0;

//the number of the neigbours of each node
    int count_num[num_v + 1];


    for (int i = 1; i <= num_v; i++)
        for (int j = 0; j < 100; j++)
        {
            adj_list[i][j] = 0;
        }


    for (int i = 1; i <= num_v; i++)
    {
        count = 0;
        for (int j = 1; j <= num_v; j++)
        {
            if(adj_matrix[i][j] != 0)
            {
                adj_list[i][count] = j;
                count ++;
            }
        }
        count_num[i] = count;

    }

//bfs process


    int node[num_v + 1];
    int temp_node[num_v + 1];
    int comp_id[num_v + 1];
    int pt_comp_id = 1;
    int num_comp[num_v + 1];
    int pt_num_comp = 0;


    for (int i = 0; i <= num_v; i++)
    {
        node[i] = 1;
        temp_node[i] = 1;
        comp_id[i] = 0;
        num_comp[i] = 0;

//        cout << node[i] << " ";
    }





    int count_comp = 0;

    //bfs_graph_pp(adj_list, count_num, num_v, node);

    while (bfs_graph_pp(adj_list, count_num, num_v, node))
    {
        pt_num_comp = 0;


        for (int i = 1; i <= num_v; i++)
        {
            if (temp_node[i] != node[i])
            {
  //              cout << "!!!!!" << endl;
                comp_id[pt_comp_id] = i;
                pt_comp_id++;
                pt_num_comp++;
            }
        }



        for (int i = 1; i <= num_v + 1; i++)
        {
            temp_node[i] = node[i];
        }

        count_comp++;
        num_comp[count_comp] = pt_num_comp;


    }


    /*
    for (int i = 1; i <= num_v + 1; i++)
    {
        cout << comp_id[i] <<" ";
        //cout << endl;
    }
     */


    cout << "The number of components is " << count_comp << endl;

//print the adjacency list

    for (int i = 1; i < num_v + 1; i++)
    {
        cout << "node " << i << ": ";
        for (int j = 0; j < count_num[i]; j++)
        {
            cout << adj_list[i][j] << " ";
        }
        cout << endl;
    }


    int count_comp_indi = 1;
    for (int i = 1; i <= count_comp; i++)
    {
        cout << "The adjacency list of component " << i << "is : "<< endl;
        for (int j = count_comp_indi; j < count_comp_indi + num_comp[i]; j++)
        {
            cout << "node " << comp_id[j] << ": ";
            for (int k = 0; k < count_num[comp_id[j]]; k++)
            {
                cout << adj_list[comp_id[j]][k] << " ";

            }
            cout << endl;

        }
        count_comp_indi = count_comp_indi + num_comp[i];
    }



    for (int i = 1; i <= num_e; i++)
    {
        cout << ori_matrix[i][3];
        cout << endl;
    }

//mini spannning tree
    int tree[num_v + 1][3];

    for (int i = 0; i <= num_v; i ++)
    {
        for (int j = 0; j < 3; j++)
        {
            tree[i][j] = 0;
        }
    }




    int start = 1;
    int end = 0;

    int temp_a = 0;
    int temp_b = 0;

    double spanning_matrix[num_v + 1][num_v + 1];
    for (int i = 0; i <= num_v; i++)
    {
        for (int j = 0; j <=num_v; j++)
        {
            spanning_matrix[i][j] = 0;
        }
    }


    for (int i = 1; i <= count_comp; i++)
    {
        for (int j = 0; j <= num_v; j ++)
        {
            for (int k = 0; k < 3; k++)
            {
                tree[j][k] = 0;
            }
        }
        start = start + num_comp[i - 1];
        end = start + num_comp[i] - 1;





        prim_tree(comp_id, start, end, adj_matrix, adj_list, count_num, tree);
        cout << "=="<< start << " " << end << endl;

        int number = end - start + 1;

        for (int m = 1; m < number; m++)
        {
            for (int n = 1; n <= 2; n++)
            {
                cout << tree[m][n];
            }
            cout << endl;
        }


        for (int m = 1; m < number; m++)
        {
            temp_a = tree[m][1];
            temp_b = tree[m][2];
            spanning_matrix[temp_a][temp_b] = adj_matrix[temp_a][temp_b];
            spanning_matrix[temp_b][temp_a] = adj_matrix[temp_a][temp_b];
        }


        //remember put 'i' into the next paragraph
        cout << "the adjacency matrix of the minimum spanning tree of componet " << i << " is :" << endl;

        for (int s = start; s <= end; s++)
        {
            for (int t = start; t <= end; t++)
            {
                temp_a = comp_id[s];
                temp_b = comp_id[t];

                cout << spanning_matrix[temp_a][temp_b];
            }
            cout << endl;
        }






    }
    /*
    for (int i = 1; i <= num_v; i++)
    {
        for (int j = 1; j <=num_v; j++)
        {
            cout << spanning_matrix[i][j];
        }
        cout << endl;
    }
     */










    return 0;
}
