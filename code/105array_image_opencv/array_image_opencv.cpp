#include <iostream>
#include <opencv2/opencv.hpp>
 
using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	/*
		400 x 400 的灰度图 做反色 黑色 ==> 白色 
		一个字节unsigned char 表示灰度 
		255 - 灰度 做反色
	*/
	
	/*补0 用于4字节对齐
		1 2 3 0
		4 5 6 0
		7 8 9 0
		1 2 3 0 4 5 6 0 7 8 9 0
	*/

	auto img {imread("lena_hed.jpg",IMREAD_GRAYSCALE)};
	const auto height{ img.rows }, width{ img.cols };
	cout << "img.elemSize() = " << img.elemSize() << '\n';
	imshow("test1", img);
	/*通过指针访问连续的二维数组*/
	for (int i{}; i < height; ++i) {

		for (int j{}; j < width; ++j) {

			const auto c{ img.data[i * width + j] };
			img.data[i * width + j] = 255 - c;
		}
	}

	imshow("test2",img);
	waitKey(0);
	(void)getchar();
	return 0;
}
