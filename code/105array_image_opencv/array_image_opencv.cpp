#include <iostream>
#include <opencv2/opencv.hpp>
 
using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	/*
		400 x 400 �ĻҶ�ͼ ����ɫ ��ɫ ==> ��ɫ 
		һ���ֽ�unsigned char ��ʾ�Ҷ� 
		255 - �Ҷ� ����ɫ
	*/
	
	/*��0 ����4�ֽڶ���
		1 2 3 0
		4 5 6 0
		7 8 9 0
		1 2 3 0 4 5 6 0 7 8 9 0
	*/

	auto img {imread("lena_hed.jpg",IMREAD_GRAYSCALE)};
	const auto height{ img.rows }, width{ img.cols };
	cout << "img.elemSize() = " << img.elemSize() << '\n';
	imshow("test1", img);
	/*ͨ��ָ����������Ķ�ά����*/
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
