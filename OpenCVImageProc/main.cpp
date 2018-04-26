#include<highgui\highgui.hpp>
#include<core\core.hpp>
#include<imgproc\imgproc.hpp>
#include<stdio.h>
#include<iostream>
#include"ImageSmoothing.h"
#include"ImageMorphology.h"

void smoothOperator();

using namespace cv;
using namespace std;

ImageSmoothing smooth;
ImageMorphology morphology;

int main() {
	/*-------------------------------------------------------------
	 *  描述： 进行方框滤波，进行模糊处理
	 *   ksize越大，模糊效果越明显
	 *-------------------------------------------------------------*/
	smoothOperator();

	/*-------------------------------------------------------------
	*  描述： 形态学系列操作
	*-------------------------------------------------------------*/
//	imshow("腐蚀操作", morphology.erodeImage(srcImage, 15));
//	imshow("膨胀操作", morphology.dilateImage(srcImage, 15));
	waitKey(0);
	return 0;
}

void smoothOperator() {
	Mat dstBox, dstBlur, dstGussian, dstMedia, dstBilateral;
	Mat srcImage = imread("yuwenwen.jpg");
	namedWindow("原始图片");
	imshow("原始图片", srcImage);
	smooth.boxFilterImage(srcImage, dstBox, 3);
	smooth.blurImage(srcImage, dstBlur, 3);
	smooth.gaussianBlurImage(srcImage, dstGussian, 3);
	smooth.mediaBlurImage(srcImage, dstMedia,3);
	smooth.bilateralFilterImage(srcImage, dstBilateral, 25, 25 * 2, 25 / 2);
	imshow("方框滤波处理", dstBox);
	imshow("均值滤波处理", dstBlur);
	imshow("高斯滤波处理", dstGussian);
	imshow("中值滤波处理", dstMedia);
	imshow("双边滤波处理", dstBilateral);
}