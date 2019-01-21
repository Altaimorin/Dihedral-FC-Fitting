#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<iomanip>

using std::vector;
using std::ifstream;
using std::ofstream;
using std::string;
using std::cout; using std::endl;

int main()
{
    double **a = new double* [36];
    double **b = new double* [36];
    for(int i =0;i<36;i++)
    {
        a[i]= new double[4];
        b[i]= new double[4];
    }
    ifstream input("amber_YOPRO_s0_4cos.txt");
    string mark="Coefficients (with 95% confidence bounds):";
    string temp_str=" ";
    string skip = " ";
    for(int i=0;i<36;i++)
    {
        while(getline(input, temp_str))
        {
            if(temp_str.find(mark)!= string::npos)
            {
                getline(input, temp_str);
                for(int j=0;j<4;j++)
                {
                    input>>skip>>skip>>a[i][j]>>skip>>skip;
                }
                for(int j=0;j<4;j++)
                {
                    input>>skip>>skip>>b[i][j]>>skip>>skip;
                }
                break;
            }
        }
    }
    
    input.close();
    /*
    double* d1 = new double [2304];
    double* d2 = new double [2304];
   // double* ene = new double [2304];
    
    ifstream input2("d1__d2_kcal");
    for(int i=0;i<2304;i++)
        input2>>d1[i]>>d2[i]>>skip;
    
    double* d1_ave = new double[48];
    for(int i=0;i<48;i++)
    {
        double d1_sum = 0;
        for(int j=0;j<48;j++)
        {
            d1_sum += d1[48*i+j];
        }
        d1_ave[i] = d1_sum/48;
    }
    */
    
    double* d1_ave = new double[36];
    ifstream nl("fix_d2_namelist.txt");
    
    for(int i=0;i<36;i++)
        nl>>d1_ave[i];
    
    nl.close();
      
// for outputs
    
    ofstream output ("fix_d2_fc_slice.txt"); //output!
    for(int i=0;i<36;i++)
    {
        output<<int(d1_ave[i])<<endl;
        output.precision(3);
        output<<std::fixed;
        
        for(int j=0;j<4;j++)
        {
            if(a[i][j]>0)
            output<<"X -ca-ce-X    4"<<std::setw(9)<<a[i][j]/(double(2))<<std::setw(14)<<b[i][j]<<std::setw(16)<<2*double(j+1)<<endl;
            
            else
            output<<"X -ca-ce-X    4"<<std::setw(9)<<-a[i][j]/(double(2))<<std::setw(14)<<b[i][j]+double(180)<<std::setw(16)<<2*double(j+1)<<endl;    
        }
             
        output<<endl;
    }
}

