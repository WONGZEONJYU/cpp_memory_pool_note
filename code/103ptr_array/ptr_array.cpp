#include <iostream>

using namespace std;

class XData
{
public:
    int x = 0;
    int y = 0;
};

static void One_dimensional()
{
    int arr1[10];
    memset(arr1, 0, sizeof(arr1));
    int arr2[5]{ 1,2,3,4,5 };
    int arr3[32]{ 1,2,3 };
    int arr4[1024]{  };
    int arr5[]{ 1,2,3,4 };
    char str1[]{ "test001" };

    cout << "sizeof(arr5) = " << sizeof(arr5) <<
        "\nsizeof(str1) = " << sizeof(str1) << '\n';

    for (auto s : str1) {
        cout << s << "-" << flush;
    }

    cout << "\n&arr2[0] = " << &arr2[0] <<
        "\n&arr2[1] = " << &arr2[1] <<
        "\narr2+2 = " << arr2 + 2 << '\n';

    (void)std::find(std::begin(arr5), std::end(arr5), 3);
    /*查找数值`3`在数组的那个位置,函数返回元素的地址*/

    int* parr1{ new int[1024] };
    int psize{ 2048 };
    auto parr2{ new unsigned char[psize] };

    memset(parr2, 0, psize);
    auto parr3{ new int[psize] };
    memset(parr3, 0, psize * sizeof(int));

    int* parr4{ new int[3] { 1, 2, 3 } };
    int* parr5{ new int[] { 1,2,3,6 } };
    int* parr6{ new int[] { 0 } };

    cout << "parr5[2] = " << parr5[2] <<
        "\n*(parr5+3) = " << *(parr5 + 3) <<
        "\n&parr5[0] = " << &parr5[0] <<
        "\n&parr5[1] = " << &parr5[1] <<
        "\nparr5+2 = " << parr5 + 2 << '\n';

    delete[] parr1;
    parr1 = nullptr;
    delete[] parr2;
    parr2 = nullptr;
    delete[] parr3;
    parr3 = nullptr;
    delete[] parr4;
    parr4 = nullptr;
    delete[] parr5;
    parr5 = nullptr;
    delete[] parr6;
    parr6 = nullptr;
    XData* datas = new XData[1024];
    delete[] datas;
    datas = nullptr;
    /*释放动态数组的时候,delete必须加上[],否则容易引起一些奇怪的问题*/
}

#define ARRSIZE 3

static void multidimensional()
{
  // 2x3
// 1 2 3
// 4 5 6

    unsigned char arr1[2][ARRSIZE]  { {1,2,3},{4,5,6} };
    unsigned char arr2[][ARRSIZE]  {
        {1,2,3},
        {2,3,4},
        {3,4,5} 
    };

    cout << "arr1[2][3] sizeof(arr1) = " << sizeof(arr1) << '\n';
    cout << "arr2[][3] sizeof(arr2) = " << sizeof(arr2) << '\n';

    int arr3[2][3][4] {
        {{1,2,3,4},{2,3,4,5},{1,2,3,4}},
        {{1,2,3,4},{2,3,4,5},{1,2,3,4}},
    };

    int arr4[][3][4] {
        {{1,2,3,4},{2,3,4,5},{1,2,3,4}},
        {{1,2,3,4},{2,3,4,5},{1,2,3,4}},
        {{1,2,3,4},{2,3,4,5},{1,2,3,4}},
    };

    for (auto arr : arr2) {
        for (int i{}; i < ARRSIZE; i++) {
            cout << static_cast<int>(arr[i]) << " " << flush;
        }
        cout << '\n';
    }

    int width{ ARRSIZE };
    int height { sizeof(arr2) / (ARRSIZE * sizeof(unsigned char)) };

    for (int i{}; i < height; i++) {

        for (int j {}; j < width; j++) {
            arr2[i][j]++;
            cout << (int)arr2[i][j] << "-" << flush;
        }
        cout << '\n';
    }
}

int main(int argc, char* argv[])
{
    //One_dimensional();
    multidimensional();
	return 0;
}

