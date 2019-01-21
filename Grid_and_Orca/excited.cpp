// orca inputs for S1
#include<fstream>
using std::string; using std::to_string;
using std::endl;using std::cout;using std::ifstream;using std::ofstream;
int main()
{
   string input[1296];
   string output[1296];
   for(long long i=0;i<1296;i++)
   {
    input[i]="conf"+to_string(i+1)+".orca";
    output[i]="conf_new"+to_string(i+1)+".orca";
   }


   for(long long i=0;i<1296;i++)
   {
    ifstream my_old(input[i]);
    ofstream my_new(output[i]);

    my_new<<"! B3LYP 6-31g* TightSCF Engrad NoKeepInts"<<endl;
    my_new<<"%tddft NRoots 3"<<endl;
    my_new<<"       Iroot 1"<<endl;
    my_new<<"       end"<<endl;

    string line;
    getline(my_old,line);
    getline(my_old,line);
    getline(my_old,line);
    getline(my_old,line);
    getline(my_old,line);
    getline(my_old,line);
    getline(my_old,line);
    getline(my_old,line);

    while(getline(my_old,line))
    {my_new<<line<<endl;}

    my_old.close();
    my_new.close();

   }
}
