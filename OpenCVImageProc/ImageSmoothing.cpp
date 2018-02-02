/*
* 描述：图像去噪(平滑)处理
* Created by Jiangdongguo on 2018.2.2
*/

#include "ImageSmoothing.h"

// 线性方框滤波
Mat ImageSmoothing::boxFilterImage(Mat srcImage, int ksize) {
	Mat dstImage;
	if (ksize >= 0) {
		boxFilter(srcImage, dstImage, -1, Size(ksize, ksize));
	}
	return dstImage;
}

// 线性均值滤波
Mat ImageSmoothing::blurImage(Mat srcImage, int ksize) {
	Mat dstImage;
	blur(srcImage, dstImage, Size(ksize, ksize));
	return dstImage;
}

// 线性高斯滤波
Mat ImageSmoothing::gaussianBlurImage(Mat srcImage, int ksize) {
	Mat dstImage;
	GaussianBlur(srcImage, dstImage, Size(ksize, ksize), 0, 0);
	return dstImage;
}

// 非线性中值滤波
Mat ImageSmoothing::mediaBlurImage(Mat srcImage, int ksize) {
	Mat dstImage;
	medianBlur(srcImage, dstImage, ksize);
	return dstImage;
}

// 非线性双边滤波
Mat ImageSmoothing::bilateralFilterImage(Mat srcImage, int d, double sigmaColor, double sigmaSpace) {
	Mat dstImage;
	bilateralFilter(srcImage, dstImage, d, sigmaColor, sigmaSpace);
	return dstImage;
}