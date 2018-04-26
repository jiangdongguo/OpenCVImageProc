/*
* 描述：图像去噪(平滑)处理
* Created by Jiangdongguo on 2018.2.2
*/

#include "ImageSmoothing.h"

// 线性方框滤波
void ImageSmoothing::boxFilterImage(Mat srcImage, Mat &dstImage,int ksize) {
	if (ksize <= 0) {
		printf("ksize should be > 0, and the best to be odd number like 1,3,5,7...\n");
		return;
	}
	if (!srcImage.data) {
		printf("open source image error!\n");
		return;
	}
	boxFilter(srcImage, dstImage, -1, Size(ksize, ksize));
}

// 线性均值滤波
void ImageSmoothing::blurImage(Mat srcImage, Mat &dstImage, int ksize) {
	if (ksize <= 0) {
		printf("ksize should be > 0, and the best to be odd number like 1,3,5,7...\n");
		return;
	}
	if (!srcImage.data) {
		printf("open source image error!\n");
		return;
	}
	blur(srcImage, dstImage, Size(ksize, ksize));;
}

// 线性高斯滤波
void ImageSmoothing::gaussianBlurImage(Mat srcImage, Mat &dstImage, int ksize) {
	if (ksize <= 0) {
		printf("ksize should be > 0, and the best to be odd number like 1,3,5,7...\n");
		return;
	}
	if (!srcImage.data) {
		printf("open source image error!\n");
		return;
	}
	GaussianBlur(srcImage, dstImage, Size(ksize, ksize), 0, 0);
}

// 非线性中值滤波
void ImageSmoothing::mediaBlurImage(Mat srcImage, Mat &dstImage, int ksize) {
	if (ksize <= 0) {
		printf("ksize should be > 0, and the best to be odd number like 1,3,5,7...\n");
		return;
	}
	if (!srcImage.data) {
		printf("open source image error!\n");
		return;
	}
	medianBlur(srcImage, dstImage, ksize);
}

// 非线性双边滤波
void ImageSmoothing::bilateralFilterImage(Mat srcImage, Mat &dstImage, int d, double sigmaColor, double sigmaSpace) {
	if (!srcImage.data) {
		printf("open source image error!\n");
		return;
	}
	bilateralFilter(srcImage, dstImage, d, sigmaColor, sigmaSpace);
}