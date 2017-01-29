#include "image.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MIN_START 256 
#define MAX_START -1
#define NUM_CONVERSION_COMPONENTS 3
#define R_LUMA_FACTOR .3
#define G_LUMA_FACTOR .59
#define B_LUMA_FACTOR .11

////////////////////////////
// Image processing stuff //
////////////////////////////
Pixel::Pixel(const Pixel32& p)
{
}
Pixel32::Pixel32(const Pixel& p)
{
}

float* Image32::RGBtoHSV(const float r, const float g, const float b) const
{
    float Min = MIN_START, Max = MAX_START, d;
    float hsv[NUM_CONVERSION_COMPONENTS]; // will return array with the corresponding indeces: 0=h; 1=s; 2=v
    //Find min and max of rgb values
    if (r>g)
    {
        Max = r;
        Min = g;
    } else {
        Max = g;
        Min = r;
    }
    if (b<Min)
        Min = b;
    else if (b>Max)
        Max = b;

    hsv[2] = Max;
    d = Max-Min;
    if( Max != 0 )
		hsv[1] = d/Max;
	else {
		hsv[1] = 0;
		hsv[0] = -1;
		return hsv;
	}
	if( r == Max )
		hsv[0] = ( g - b ) / d;
	else if( g == Max )
		hsv[0] = 2 + ( b - r ) / d;
	else
		hsv[0] = 4 + ( r - g ) / d;
	hsv[0] *= 60;
	if( hsv[0] < 0 )
		hsv[0] += 360;
    return hsv;
}

float* Image32::HSVtoRGB(const float hue, const float s, const float v ) const
{
    float rgb[NUM_CONVERSION_COMPONENTS]; // will return array with the corresponding indeces: 0=r; 1=g; 2=b
	int i;
	float f, p, q, t, h = hue;
	if( s == 0 ) {
		// achromatic (grey)
		rgb[0] = rgb[1] = rgb[2] = v;
		return rgb;
	}

	h /= 60;			// sector 0 to 5
	i = floor( h );
	f = h - i;			// factorial part of h
	p = v * ( 1 - s );
	q = v * ( 1 - s * f );
	t = v * ( 1 - s * ( 1 - f ) );
	switch( i ) {
		case 0:
			rgb[0] = v;
			rgb[1] = t;
			rgb[2] = p;
			break;
		case 1:
			rgb[0] = q;
			rgb[1] = v;
			rgb[2] = p;
			break;
		case 2:
			rgb[0] = p;
			rgb[1] = v;
			rgb[2] = t;
			break;
		case 3:
			rgb[0] = p;
			rgb[1] = q;
			rgb[2] = v;
			break;
		case 4:
			rgb[0] = t;
			rgb[1] = p;
			rgb[2] = v;
			break;
		default:
			rgb[0] = v;
			rgb[1] = p;
			rgb[2] = q;
			break;
	}
	return rgb;
}

int Image32::AddRandomNoise(const float& noise,Image32& outputImage) const
{
    if (noise >= 0 && noise <= 1)
    {
        int width = this->w, height = this->h, rNum;
        int noiseNum = noise * 100;
        outputImage.setSize(width, height);
        Pixel32 pin, prand;
        srand (time(NULL));

        for (int x = 0; x < width; x++)
        {
            for (int y = 0; y < height; y++)
            {
                pin = this->pixel(x,y);
                rNum = rand() % 100;
                //printf("rNum %d\n", rNum);
                if (rNum < noiseNum)
                {
                    prand = this->pixel(rand() % width, rand() % height);
                    outputImage.pixel(x,y).r = prand.r;
                    outputImage.pixel(x,y).g = prand.g;
                    outputImage.pixel(x,y).b = prand.b;
                  //  printf("prand %d\n", prand.r);
                } else {
                    outputImage.pixel(x,y).r = pin.r;
                    outputImage.pixel(x,y).g = pin.g;
                    outputImage.pixel(x,y).b = pin.b;
                    
                }
            }
        }
	    return 1;
    }
    return 0;
}
int Image32::Brighten(const float& brightness,Image32& outputImage) const
{
   outputImage.setSize(this->w, this->h);
    for (int x = 0; x++; x <= this->w)
    {
        for (int y = 0; y++; y <= this->h)
        {
            float * hsv = RGBtoHSV(this->getR(x,y), this->getG(x,y), this->getB(x,y));
            //printf("hsv %f %f %f\n", h, s, v);
            hsv[2] *= brightness;
            float *rgb = HSVtoRGB(hsv[0],hsv[1],hsv[2]);
            //printf("rgb %f %f %f\n", outr, outg, outb);
            outputImage.pixel(x,y).r = rgb[0];
            outputImage.pixel(x,y).g = rgb[1];
            outputImage.pixel(x,y).b = rgb[2];
        }
    }
	return 1;
	//return 0;
}

int Image32::Luminance(Image32& outputImage) const
{
    int width = this->w, height = this->h, rNum;
    outputImage.setSize(width, height);
    Pixel32 pin;
    srand (time(NULL));

    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            pin = this->pixel(x,y);
            outputImage.pixel(x,y).r = outputImage.pixel(x,y).g = outputImage.pixel(x,y).b = pin.r*R_LUMA_FACTOR + pin.g*G_LUMA_FACTOR + pin.b*B_LUMA_FACTOR;
        }
    }
    return 1;

}

int Image32::Contrast(const float& contrast,Image32& outputImage) const
{
	return 0;
}

int Image32::Saturate(const float& saturation,Image32& outputImage) const
{
	return 0;
}

int Image32::Quantize(const int& bits,Image32& outputImage) const
{
	return 0;
}

int Image32::RandomDither(const int& bits,Image32& outputImage) const
{
	return 0;
}
int Image32::OrderedDither2X2(const int& bits,Image32& outputImage) const
{
	return 0;
}

int Image32::FloydSteinbergDither(const int& bits,Image32& outputImage) const
{
	return 0;
}

int Image32::Blur3X3(Image32& outputImage) const
{
	return 0;
}

int Image32::EdgeDetect3X3(Image32& outputImage) const
{
	return 0;
}
int Image32::ScaleNearest(const float& scaleFactor,Image32& outputImage) const
{
	return 0;
}

int Image32::ScaleBilinear(const float& scaleFactor,Image32& outputImage) const
{
	return 0;
}

int Image32::ScaleGaussian(const float& scaleFactor,Image32& outputImage) const
{
	return 0;
}

int Image32::RotateNearest(const float& angle,Image32& outputImage) const
{
	return 0;
}

int Image32::RotateBilinear(const float& angle,Image32& outputImage) const
{
	return 0;
}
	
int Image32::RotateGaussian(const float& angle,Image32& outputImage) const
{
	return 0;
}


int Image32::SetAlpha(const Image32& matte)
{
	return 0;
}

int Image32::Composite(const Image32& overlay,Image32& outputImage) const
{
	return 0;
}

int Image32::CrossDissolve(const Image32& source,const Image32& destination,const float& blendWeight,Image32& ouputImage)
{
	return 0;
}
int Image32::Warp(const OrientedLineSegmentPairs& olsp,Image32& outputImage) const
{
	return 0;
}

int Image32::FunFilter(Image32& outputImage) const
{
	return 0;
}
int Image32::Crop(const int& x1,const int& y1,const int& x2,const int& y2,Image32& outputImage) const
{
    int width = this->w, height = this->h, rNum;
    if (x1 <= x2 <= width && y1 <= y2 <= height)
    {
        //replacing width and height to be that of the output image's
        width = x2 - x1;
        height = y2 - y1;
        outputImage.setSize(width, height);
        Pixel32 pin;
        int ox, oy;
        
        for (int x = x1; x < x2; x++)
        {
            for (int y = y1; y < y2; y++)
            {
                pin = this->pixel(x,y);
                //account for the change in xy values for outputImage
                ox = x - x1;
                oy = y - y1;
                outputImage.pixel(ox,oy).r = pin.r;
                outputImage.pixel(ox,oy).g = pin.g;
                outputImage.pixel(ox,oy).b = pin.b;
            }
        }
        return 1;
    }
	return 0;
}


Pixel32 Image32::NearestSample(const float& x,const float& y) const
{
	return Pixel32();
}
Pixel32 Image32::BilinearSample(const float& x,const float& y) const
{
	return Pixel32();
}
Pixel32 Image32::GaussianSample(const float& x,const float& y,const float& variance,const float& radius) const
{
	return Pixel32();
}
