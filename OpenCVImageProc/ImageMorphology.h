#include<highgui\highgui.hpp>
#include<core\core.hpp>
#include<imgproc\imgproc.hpp>

using namespace cv;

class ImageMorphology {
public:
	// 形态学腐蚀操作
	Mat erodeImage(Mat srcImage,int ksize);
	// 形态学膨胀操作
	Mat dilateImage(Mat srcImage, int ksize);
};
