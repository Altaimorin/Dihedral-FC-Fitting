#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using std::string;
using std::cout; using std::endl;
using std::ifstream; using std::ofstream;
using std::to_string;
using std::fixed;
int main()
{ 
   double* d1 = new double [37];
   double* d2 = new double [37];
   double* ene = new double [37];

   ifstream input("d2__d1_kcal_splitted");
   for(int i=0;i<1271;i++)
   {
      if(input.eof())
        break;
      for(int j=0;j<37;j++)
         {      
          input>>d2[j]>>d1[j]>>ene[j];
          if(ene[j]==9999)
            { cout<<"j="<<j<<endl;
               double d2_sum = 0;
               double d2_ave = 0;
               for(int k=0;k<j;k++)
                  {
                    d2_sum+=d2[k];
                  }  
               d2_ave = d2_sum/j;
               string D2_slice ="d2_at_"+ to_string((long long)(d2_ave))+".txt";
               ofstream output(D2_slice);
               for(int k=0;k<j;k++) 
                  {
                      output.precision(12);
                      output<<fixed;
                      output<<d1[k]<<"    "<<ene[k]<<endl; 
                  }
               cout<<d2_ave<<"get!"<<endl;
               output.close();
               cout<<"break"<<endl;
               break;
            } 
         }

   }
    delete[] d1,d2,ene;
}
