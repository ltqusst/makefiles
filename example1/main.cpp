#include <stdio.h>
#include <opencv2/opencv.hpp>
#include "main.h"

using namespace cv;

int main(int argc, char** argv )
{
    if ( argc != 2 )
    {
		for(int i=0;i<argc;i++)
			printf("\targv[%d]=\"%s\"\n", i, argv[i]); 
        printf("usage: DisplayImage.out <Image_Path>\n");
		printf("version: %s\n", MAIN_VER);
        return -1;
    }

    Mat image;
    image = imread( argv[1], 1 );
    resize(image, image, Size(), 8,8);
    if ( !image.data )
    {
        printf("No image data \n");
        return -1;
    }
    namedWindow("Display Image", WINDOW_AUTOSIZE );
    imshow("Display Image", image);

    waitKey(0);

	//hello();
    return 0;
}

