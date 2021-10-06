/*
 * The code below is meant to detect whether the Red Ruby
 * is present. The starategy implemented by the code is not very effective. 
 * Study the code so that you understand what the strategy is and how 
 * it is implemented. Then design and implement a better startegy.
 * 
 * */



#include <iostream>
#include "E101.h"

using namespace std;
bool red_true(int totred, int totgreen, int totblue){
return(((totred > (2*totblue)) && (totred > (2*totgreen)))); //the second half here, compares against the blue/green values in the diamond with the spot on the white piece of paper.
}

int main()
{
  int err = init(0);
  cout<<" Hello. err="<<err<<endl;
  int totred = 0; // combined value of all red values of all pixels
  int totgreen = 0; //combined value of all green pixels
  int totblue = 0; //combined value of all blue value
  int totint = 0; // ditto for grey
  //int notrubytotred = 0; // combined value of all red values of all pixels
  //int notrubytotgreen = 0; //combined value of all green pixels
  //int notrubytotblue = 0; //combined value of all blue value
  //int notrubytotint = 0; // ditto for grey
  float redness = 0; // ratio of redness to greyness
  open_screen_stream();
  
  
  // make 1000 runs  
  for(int countrun =0; countrun <1000; countrun=countrun+1)
  {
	take_picture();
	update_screen();	
    totred = 0;
    totgreen = 0;
    totblue = 0;
    totint = 0;
    redness = 0; 
    // for all pixels in latest image
 


	totred = totred + (int)get_pixel(120,160,0);
	totgreen = totgreen + (int)get_pixel(120,160,1);
	totblue = totblue + (int)get_pixel(120,160,2);
	totint = totint + (int)get_pixel(120,160,3);
	
	//notrubytotred = notrubytotred + (int)get_pixel(50,50,0);
	//notrubytotgreen = notrubytotgreen + (int)get_pixel(50,50,1);
	//notrubytotblue= notrubytotblue + (int)get_pixel(50,50,2);
	//notrubytotint = notrubytotint + (int)get_pixel(50,50,3);
    int left = 320;
    int right = 0; 
    int top = 240;
    int bottom = 0;
    int firstleftval = left;
    int firstrightval = right;
    int firsttopval = top;
    int firstbottomval = bottom;
    for(int i =0; i <= 1; i++){
		take_picture();
		
    for (int row = 0 ; row<=240 ; row=row+1)
	{	
		for (int col=0; col<=320; col=col+1)
		{
			if(red_true((int)get_pixel(row,col,0),(int)get_pixel(row,col,1),(int)get_pixel(row,col,2))){
				if(col < left){
					left = col;
				}
				if(col > right){
					right = col;
				}
				if(row < top){
					top = row;
				}
				if(row > top){
					bottom = row;
				}
			}
			firstleftval = left;
			firstrightval = right;
			firsttopval = top;
			firstbottomval = bottom;
		}	  
	}
}
cout<<firstleftval<<endl;  
cout<<firstrightval<<endl; 
cout<<firsttopval<<endl;
cout<<firstbottomval<<endl;

    for (int row = 0 ; row<=240 ; row=row+1)
	{	
		for (int col=0; col<=320; col=col+1)
		{
			if(red_true((int)get_pixel(row,col,0),(int)get_pixel(row,col,1),(int)get_pixel(row,col,2))){
				if(col < left){
					left = col;
				}
				if(col > right){
					right = col;
				}
				if(row < top){
					top = row;
				}
				if(row > top){
					bottom = row;
				}
			}
		}	  
	}

if((firstleftval == left && firstrightval == right) || (firsttopval == top && firstbottomval == bottom)){
	cout<<"RUBY IS SECURED"<<endl;
} else {
		cout<<"THE RUBY IS STOLEN"<<endl;
		return 0;
	}
	

	/*if(red_true(totred, totgreen, totblue)){
		cout<<"RUBY IS SECURED"<<endl;
	} else {
		cout<<"THE RUBY IS STOLEN"<<endl;
		return 0;
	} */
	
	//redness = (float)totred/(50*((float)totgreen*(float)totblue));
	//cout<<" countrun="<<countrun;
	//cout<<" Total red "<< totred;
	//cout<<" Total green "<< totgreen;
	//cout<<" Total blue "<< totblue;
	//cout<<" Total int "<< totint;
	
	//cout<<" Total notrubyred "<< notrubytotred;
	//cout<<" Total notrubygreen "<< notrubytotgreen;
	//cout<<" Total notrubyblue "<< notrubytotblue;
	//cout<<" Total notrubyint "<< notrubytotint;
	



	cout<<" Total int "<< totint<<endl;
	//cout<<" Redness "<< redness<<endl;
	sleep1(100); // slow down a bit to make display easier
  }  
  close_screen_stream();

}
