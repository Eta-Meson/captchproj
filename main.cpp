/*

	Group 1
	IITG

*/

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "font.hpp"
#include "bitmap_image.hpp"

int letters[26][2];

void init()
{

int i,count=0,j=0;
letters[0][0]=0;
letters[25][1]=1327;
for(i=0;i<1328;i++)
{
	if(im[0][i]=='a'){
		letters[j++][1]=i-1;
		letters[j][0]=i+1;
	}
}
}

void addline(int x1,int y1, int x2, int y2,bitmap_image &image)
{


}

int main()
{
	init();

	std::string str="kunal";
	int offset=0,x;
   const unsigned int dim = 100;
   bitmap_image image(180,52); // (w,h)

   for (unsigned int y = 0; y < 52; ++y)
   {
      for (unsigned int x = 0; x < 180; ++x)
      {
        	image.set_pixel(x,y,0,0,100); //(r,g,b)
      }
   }
for(unsigned int k=0; k<str.length(); ++k)
{
	   for (unsigned int y = 0; y < 52; ++y)
	   {
	      for (x = letters[str[k]-'a'][0]; x < letters[str[k]-'a'][1]; ++x)
	      {
	        	if(im[y][x]!=' ') image.set_pixel(offset+x-letters[str[k]-'a'][0],y,0,100,0);
	      }
	   }
	   offset=offset+letters[str[k]-'a'][1]-letters[str[k]-'a'][0]-15;
}
	srand(time(NULL));
	image_drawer draw(image);
	for(x=0;x<20;x++)
	{
		
   		draw.pen_width(1);
   		draw.pen_color(rand()%255,rand()%255,rand()%255);
   		draw.line_segment(rand()%180,rand()%52,rand()%180,rand()%52);

     }
    image.save_image("myimg.bmp");

  return 0;
}