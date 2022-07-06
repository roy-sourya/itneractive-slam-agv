// Reading GPS Data 
// read_gps_data
// Converting lat/long to cartesian

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

int main()
 {
   ifstream f;
   f.open("gps_data.txt");
   ifstream g;
   g.open("gps_data1.txt");
   fstream h;
   h.open("xyz_coord_c.txt", ios::out);
   double latitude[5000],longitude[5000];
   int i=0,k=0,j,lt=0,lg=0,p=0,q=0;
   double pi = 2*acos(0.0);
   int R = 6371; //radius of earth
   double x[5000],y[5000],z[5000];
   double temp[12];
   
   while(!f.eof()) 
    {  
         for(j =0 ;j<12;j++)
          {
            f>>temp[j];
          }
       
         latitude[lt++] = temp[0];
         longitude[lg++] = temp[1];
         k++;
       
    }
    
   while(!g.eof()) 
    {
         for(j =0 ;j<12;j++)
          {
            g>>temp[j];
          }
       
         latitude[lt++] = temp[0];
         longitude[lg++] = temp[1];
         k++;
      
    }

     int lt_size = sizeof(latitude)/sizeof(latitude[0]);
     for(i=0; i<k; i++)
      {
        latitude[i] = latitude[i]*pi/180.0;    
        longitude[i] = longitude[i]*pi/180.0;
        x[i] = R*cos(latitude[i])*cos(longitude[i]);
        y[i] = R*cos(latitude[i])*sin(longitude[i]);
        z[i] = R*sin(latitude[i]);
        h<< x[i]<<" "<< y[i]<<" "<< z[i] <<'\n';
      }
     h.close();
     g.close();
     f.close();
     return 0;
 }
   
 

