#include<highgui\highgui.hpp>
#include<core\core.hpp>
#include<imgproc\imgproc.hpp>
#include<stdio.h>
#include<iostream>
#include"ImageSmoothing.h"
#include"ImageMorphology.h"
void resizeBrightnessAndContrast(int a, int b);
void smoothOperator();

using namespace cv;
using namespace std;

ImageSmoothing smooth;
ImageMorphology morphology;

int main() {

	/*-------------------------------------------------------------
	*  点算子：调整亮度和对比度
	*-------------------------------------------------------------*/
	resizeBrightnessAndContrast(1,100);

	/*-------------------------------------------------------------
	 *  描述： 进行方框滤波，进行模糊处理
	 *   ksize越大，模糊效果越明显
	 *-------------------------------------------------------------*/
	//smoothOperator();

	/*-------------------------------------------------------------
	*  描述： 形态学系列操作
	*-------------------------------------------------------------*/
//	imshow("腐蚀操作", morphology.erodeImage(srcImage, 15));
//	imshow("膨胀操作", morphology.dilateImage(srcImage, 15));
	waitKey(0);
	return 0;
}

void resizeBrightnessAndContrast(int a, int b) {
	Mat src, dst;
	src = imread("yuwenwen.jpg");
	if (!src.data) {
		printf("加载源图像失败");
	}
	namedWindow("源图像");
	imshow("源图像", src);
	// dst矩阵尺寸、像素类型与源图像一致，并初始化置零
	dst = Mat::zeros(src.size(), src.type());
	// 遍历所有像素，使用点算子处理
	// g(i,j) = a*f(i,j) + b;
	for (int i = 0; i < src.rows; i++) {
		for (int j = 0; j < src.cols; j++) {
			if (src.channels() == 1) {
				// 灰度图像
				dst.at<uchar>(i, j) = saturate_cast<uchar>(a*src.at<uchar>(i, j) + b);
			}
			else {
				// 彩色图像
				for (int channel = 0; channel < src.channels(); channel++) {
					dst.at<Vec3b>(i, j)[channel] = saturate_cast<uchar>(a*src.at<Vec3b>(i, j)[channel] + b);
				}
			}
		}
	}
	imshow("a=1,b=100效果图", dst);
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