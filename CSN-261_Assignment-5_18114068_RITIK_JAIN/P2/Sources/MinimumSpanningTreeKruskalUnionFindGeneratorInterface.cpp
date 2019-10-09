/**
 * @file MinimumSpanningTreeKruskalUnionFindGenerator.cpp
 * @date 18/09/2019
 * @author Ritik Jain
 * @brief Minimum Spanning Tree Generation Interface
 */

#include "MinimumSpanningTreeKruskalUnionFindGenerator.cpp"

int main(int argc, char **argv)
{
    cout << "Copyright (C) 2019 Ritik Jain" << endl << "Minimum Spanning Tree Generation [Kruskal's Algorithm] ver 1.0.0" << endl  << endl;

    MSTGen mst;

    char in[500];
    cout << "Input CSV File : " << endl;
    cin >> in;

    if(!mst.load_csv(in))
    {
        cout << "MST CSV File Not Found !!!" << endl << endl;
        return 1;
    }

    cout<<"Input [Graph] :"<<endl;
    mst.display();
    cout<<endl<<"Total Weight of Graph : "<<mst.weight()<<endl<<endl;
    cout<<"Output [Minimum Spanning Tree/ Forest { Kruskal's Algorithm }] :"<<endl;
    mst.genMST();
    mst.display();
    cout<<endl<<"Total Weight of MST : "<< mst.weight()<<endl<<endl;
    
    cout << "Output DOT File : " << endl;
    char out[500];
    cin >> out;
    
    if(!mst.save_dot(out))
    {
        cout << "MST DOT File cannot be saved !!!" << endl << endl;
        return 1;
    }

    cout << endl<<endl;
      
}
