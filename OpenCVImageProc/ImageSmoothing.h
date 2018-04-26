#include<highgui\highgui.hpp>
#include<core\core.hpp>
#include<imgproc\imgproc.hpp>

using namespace cv;

class ImageSmoothing {
public:
	// 线性方框滤波
	void boxFilterImage(Mat srcImage, Mat &dstImage, int ksize);
	// 线性均值滤波
	void blurImage(Mat srcImage, Mat &dstImage,int ksize);
	// 线性高斯滤波
	void gaussianBlurImage(Mat srcImage, Mat &dstImage,int ksize);
	// 非线性中值滤波
	void mediaBlurImage(Mat srcImage, Mat &dstImage,int ksize);
	// 非线性双边滤波
	// d为每个像素领域的直径；sigmaColor为颜色空间滤波器sigma
	void bilateralFilterImage(Mat srcImage, Mat &dstImage,int d, double sigmaColor,double sigmaSpace);
}; 
