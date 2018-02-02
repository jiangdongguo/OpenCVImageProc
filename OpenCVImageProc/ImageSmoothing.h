#include<highgui\highgui.hpp>
#include<core\core.hpp>
#include<imgproc\imgproc.hpp>

using namespace cv;

class ImageSmoothing {
public:
	// 线性方框滤波
	Mat boxFilterImage(Mat srcImage, int ksize);
	// 线性均值滤波
	Mat blurImage(Mat srcImage,int ksize);
	// 线性高斯滤波
	Mat gaussianBlurImage(Mat srcImage,int ksize);
	// 非线性中值滤波
	Mat mediaBlurImage(Mat srcImage,int ksize);
	// 非线性双边滤波
	// d为每个像素领域的直径；sigmaColor为颜色空间滤波器sigma
	Mat bilateralFilterImage(Mat srcImage,int d, double sigmaColor,double sigmaSpace);
}; 
