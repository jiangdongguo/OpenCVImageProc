#include"ImageMorphology.h"

// 形态学腐蚀操作
Mat ImageMorphology::erodeImage(Mat srcImage, int ksize) {
	Mat dstImage;
	Mat element = getStructuringElement(MORPH_RECT, Size(ksize, ksize));
	erode(srcImage, dstImage, element);
	return dstImage;
}

// 形态学膨胀操作
Mat ImageMorphology::dilateImage(Mat srcImage, int ksize) {
	Mat dstImage;
	Mat element = getStructuringElement(MORPH_RECT, Size(ksize, ksize));
	dilate(srcImage, dstImage, element);
	return dstImage;
}