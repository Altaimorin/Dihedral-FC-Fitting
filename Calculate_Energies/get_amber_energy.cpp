int main()
{
   string *fn = new string[1296];
   
   for(long long i=0;i<1296;i++)
   {
    fn[i] = "min_"+to_string(i+1)+".out";
    cout<<fn[i]<<endl;
   }
   
   string mark="NSTEP       ENERGY          RMS            GMAX         NAME    NUMBER";
   string line="";
   string skip="";
   double energy=0;
   ifstream file_name;
   ofstream out_put("amber_energy.txt");
   
   for(long long i=0;i<1296;i++)
   {
      file_name.open(fn[i]);
      if(!file_name.is_open())
      {
          cout<<"bad!"<<endl;
          break;
      }
      while(true)
      { 
         getline(file_name,line);
         if(line.find(mark) != string::npos)
         {
           file_name>>skip>>energy>>skip>>skip>>skip>>skip;
           out_put<<i+1<<" "<<energy<<endl;
           break;
         }
         if(file_name.eof())
           {
              cout<<fn[i]<<" is bad"<<endl;
              break;
           }
      }
     file_name.close();
   }
  delete[] fn;
}
