/* © Jose Andino, 2018, all rights reserved
  Professor: Dr. Varick Erickson
  Computer Science 2
  Assignment 1
*/

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#
using namespace std;


int main()
{	
	string input;
	string output;
	char pSix[10];		// indicates this is a PPM image
	int width = 0;		// width of the image
	int height = 0;		// heigt of the image
	int r=0,b=0,g=0;
	int ch; //choices
	int avg;//for gray scale
	
	
	cout<<"Portable Pixmap (PPM) Image Modder\n";
	cout<<"Enter image file name (ppm):";
	cin>>input;
	
	cout<<"\nEnter output image file name: ";
	cin>>output;

	ifstream img1;
	img1.open(input.c_str());
	ofstream img2;
	img2.open(output.c_str());
	
	//img1<<"p3"<<endl;
	//img1<<width<<" "<<height<<endl;
	//img1<<"255"<<endl;
	//fscanf(img1, "%s", pSix);	
	img1>>pSix;
	cout<<pSix;
	img1>>width>>height;
	if ((strncmp(pSix, "p3" , 10) != 0) &&(height>=1000))
	{
		cout<<"They are not the same\n";
		cout<<"There pixel are less than 1000";
		return 0;
	} 
	else 
	{
		printf("They are the same\n");
	}
	//img1>>width>>height;
    //fscanf(fr, "%d\n", maximum);
	img2<<pSix<<endl;;	
	img2<<width<<" "<<height<<endl;
	img2<<"255"<<endl;	
	if(img1.is_open())
	{
		cout<<"\nImage Processing Choices:";
		cout<<"\n1. Convert to grayscale";
		cout<<"\n2. Invert Red"; 
		cout<<"\n3. Invert Green";
		cout<<"\n4. Invert Blue";
		cout<<"\n5. Invert All";
		cout<<"\nEnter Choice: ";
		cin>>ch;
		if(ch==1)
		{
			//for changing the image gray scale		
			for(int y=0; y< height;y++)
			{	for(int x=0; x< width;x++)
				{
					img1>>r>>b>>g;
					avg = (r+b+g)/3;
					r = avg;
					b = avg;
					g = avg;
					img2 << r<< " " << g << " "<< b << " ";			
				}
				img2<<endl;
			}	
		}
		else if(ch==2)
		{
			//for changing the image invert Red	
			for(int y=0; y< height;y++)
			{	for(int x=0; x< width;x++)
				{
					img1>>r>>b>>g;
					r = 255-r;
					img2 << r<< " " << g << " "<< b << endl;			
				}
			}
		}
		else if(ch==3)
		{
				//for changing the image invert green		
			for(int y=0; y< height;y++)
			{	for(int x=0; x< width;x++)
				{
					img1>>r>>b>>g;
					g = 255-g;
					img2 << r<< " " << g << " "<< b << endl;			
				}
			}			
		}
		else if(ch==4)
		{
			//for changing the image invert blue		
			for(int y=0; y< height;y++)
			{	for(int x=0; x< width;x++)
				{
					img1>>r>>b>>g;
					b = 255-b;
					img2 << r<< " " << g << " "<< b << endl;			
				}
			}	
		}
		else if(ch==5)
		{
			//for changing the image invert All		
			for(int y=0; y< height;y++)
			{	for(int x=0; x< width;x++)
				{
					img1>>r>>b>>g;
					r = 255-r;
					b = 255-b;
					g = 255-g;
					img2 << r<< " " << g << " "<< b << endl;			
				}
			}	
		}			
		else
		{
			cout<<"Entered Invalid Option";
			
		}
	}
	else
	{
		cout<<"File cannot open";
	}
	img1.close();
	img2.close();
	
	return 0;

}

