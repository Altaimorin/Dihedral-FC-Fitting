#include<iostream>
#include<fstream>
#include<string>
using namespace std;


int main()
{
  int* d1_pos = new int[36];
  int* d2_pos = new int[36];
  
  ifstream d1_val("fix_d1_namelist.txt");
  for(int i=0;i<36;i++)
     d1_val>>d1_pos[i];
  d1_val.close();
  
  ifstream d2_val("fix_d2_namelist.txt");
  for(int i=0;i<36;i++)
     d2_val>>d2_pos[i];
  d2_val.close();
  
  string skip = "";
  string** d1_fc_phase = new string*[36];
  for(int i=0;i<36;i++)
     d1_fc_phase[i] = new string[4];
  
  ifstream fix_d1_fc("fix_d1_fc_slice.txt");
  for(int i=0;i<36;i++)
     {
         getline(fix_d1_fc,skip);
         for(int j=0;j<4;j++)
            {
                 getline(fix_d1_fc,d1_fc_phase[i][j]);
            }
         getline(fix_d1_fc,skip);
     }  
     
  string** d2_fc_phase = new string*[36];
  for(int i=0;i<36;i++)
     d2_fc_phase[i] = new string[4];
  
  ifstream fix_d2_fc("fix_d2_fc_slice.txt");
  for(int i=0;i<36;i++)
     {
         getline(fix_d2_fc,skip);
         for(int j=0;j<4;j++)
            {            
                 getline(fix_d2_fc,d2_fc_phase[i][j]);
            }
         getline(fix_d2_fc,skip);
     }


  for(int i=0;i<36;i++)
  {
     for(int j=0;j<36;j++)
     {
        string line = "";
        string mark = "DIHE";
        string frcmodname = "YOPRO_S0_"+to_string(d1_pos[i])+"_"+to_string(d2_pos[j])+".frcmod";
        ofstream this_frcmod(frcmodname);
        ifstream templ("YOPRO.frcmod");
        
        while(getline(templ,line))
        {
             if(line.find(mark)!=string::npos)
               {
                 getline(templ,line);
                 getline(templ,line);
                 for(int k=0;k<4;k++)
                 {
                     this_frcmod<<d1_fc_phase[i][k]<<endl;
                 }
                 for(int k=0;k<4;k++)
                 {
                     this_frcmod<<d2_fc_phase[j][k]<<endl;
                 }
                
               }          
             
             this_frcmod<<line<<endl;
        }
       this_frcmod.close();
       templ.close();
     }
  }
    delete[] d1_pos;
    delete[] d2_pos;
    delete[] d1_fc_phase;
    delete[] d2_fc_phase;
}
