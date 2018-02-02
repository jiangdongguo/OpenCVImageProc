#include<highgui\highgui.hpp>
#include<core\core.hpp>
#include<imgproc\imgproc.hpp>
#include"ImageSmoothing.h"
#include"ImageMorphology.h"

using namespace cv;

int main() {
	ImageSmoothing smooth;
	ImageMorphology morphology;
	
	// 载入原图
	Mat srcImage = imread("hashiqi.jpg");
	namedWindow("原始图片");
	imshow("原始图片", srcImage);

	/*-------------------------------------------------------------
	 *  描述： 进行方框滤波，进行模糊处理
	 *   ksize越大，模糊效果越明显
	 *-------------------------------------------------------------*/
//	imshow("方框滤波处理", smooth.boxFilterImage(srcImage,5));
//	imshow("均值滤波处理", smooth.blurImage(srcImage, 7));
//	imshow("高斯滤波处理", smooth.gaussianBlurImage(srcImage, 5));
//	imshow("中值滤波处理", smooth.mediaBlurImage(srcImage, 7));
//	imshow("双边滤波处理",smooth.bilateralFilterImage(srcImage,25,25*2,25/2));

	/*-------------------------------------------------------------
	*  描述： 形态学系列操作
	*-------------------------------------------------------------*/
	imshow("腐蚀操作", morphology.erodeImage(srcImage, 15));
	imshow("膨胀操作", morphology.dilateImage(srcImage, 15));
	waitKey(0);
	return 0;
}