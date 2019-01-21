#include<iostream>
#include<string>
#include<sstream>
#include <fstream>
using std::string;
using std::endl;using std::cout;
using std::to_string;
using std::ifstream; using std::ofstream;
int main()
{
    string* fn =new string[1296];
    
    for(long long i=0;i<1296;i++)
        fn[i]="conf_new"+to_string(i+1)+".out";
        
    string sg="FINAL SINGLE POINT ENERGY";
    string line;
    ifstream file_name;
    
    ofstream out_put("single_point.txt"); 
    
    for(long long i=0;i<1296;i++)
    {      
       file_name.open(fn[i]);
        if(!file_name.is_open())
        {
            cout<<fn[i]<<"not open!"<<endl;
            break;
        }      
        while(true)
        {
            getline(file_name,line);
           // cout<<line<<endl;
            if(line.find(sg) != string::npos)
            {
                out_put<<"sys   "<<"YOPRO.top   "<<"conf"<<i+1<<".crd"<<"\t"<<line<<endl;
                break;
            }
            if(file_name.eof())
            {
               cout<<fn[i]<<"bad"<<endl;
               break;    
            }
        }   
        file_name.close();
    }
 delete[] fn;
}
