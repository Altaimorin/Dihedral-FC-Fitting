#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
using namespace std;


int main()
{
   double* d1 = new double[1235];
   double* d2 = new double[1235];
   double* ene = new double[1235];
   
   int* ave_d1 = new int[36];

   ifstream input("d1__d2_kcal_gnup");
   for(int i=0;i<1235;i++)
      input>>d1[i]>>d2[i]>>ene[i];
     
   input.close();
   
   ifstream nl("namelist");
   for(int i=0;i<36;i++)
      nl>>ave_d1[i];
   nl.close();
  
   ofstream transposed("d2__d1_kcal");
   transposed<<fixed;
   transposed<<setprecision(12);
   for(int i=0;i<36;i++)
   {
      for(int j=0;j<1235;j++)
      {
         if(abs(d2[j]-ave_d1[i])<6)
           transposed<<d2[j]<<"  "<<d1[j]<<"  "<<ene[j]<<endl;
      }
   }

   transposed.close();  
   delete[] d1, d2, ene;


}
