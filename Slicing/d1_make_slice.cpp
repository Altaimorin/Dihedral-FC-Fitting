include<iostream>
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

   ifstream input("d1__d2_kcal");
   for(int i=0;i<1276;i++)
   {
      if(input.eof())
        break;
      for(int j=0;j<37;j++)
         {
          input>>d1[j]>>d2[j]>>ene[j];
          if(ene[j]==9999)
            { cout<<"j="<<j<<endl;
               double d1_sum = 0;
               double d1_ave = 0;
               for(int k=0;k<j;k++)
                  {
                    d1_sum+=d1[k];
                  }
               d1_ave = d1_sum/j;
               string D1_slice ="d1_at_"+ to_string((long long)(d1_ave))+".txt";
               ofstream output(D1_slice);
               for(int k=0;k<j;k++)
                  {
                      output.precision(12);
                      output<<fixed;
                      output<<d2[k]<<"    "<<ene[k]<<endl;
                  }
               cout<<d1_ave<<"get!"<<endl;
               output.close();
               cout<<"break"<<endl;
               break;
            }
         }

   }
   delete[] d1, d2, ene;
}
