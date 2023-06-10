#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
    Mat img = imread("blurry_image.jpg", IMREAD_GRAYSCALE); // 读取模糊图像
    imshow("Blurry Image", img);

    int ksize = 21;                                       // 滤波器大小
    double sigma = 5;                                     // 高斯核标准差
    Mat kernel = getGaussianKernel(ksize, sigma, CV_64F); // 生成高斯核
    Mat kernel_transpose = kernel.t();                    // 转置高斯核

    Mat psf = kernel * kernel_transpose; // 生成点扩散函数
    Mat psf_shifted;                     // 生成中心化的点扩散函数
    int cx = psf.cols / 2;
    int cy = psf.rows / 2;
    Mat q0 = Mat::zeros(psf.size(), psf.type());
    Mat q1 = Mat::zeros(psf.size(), psf.type());
    Mat q2 = Mat::zeros(psf.size(), psf.type());
    Mat q3 = Mat::zeros(psf.size(), psf.type());
    psf(Rect(0, 0, cx, cy)).copyTo(q0(Rect(cx, cy, cx, cy)));
    psf(Rect(cx, 0, cx, cy)).copyTo(q1(Rect(0, cy, cx, cy)));
    psf(Rect(0, cy, cx, cy)).copyTo(q2(Rect(cx, 0, cx, cy)));
    psf(Rect(cx, cy, cx, cy)).copyTo(q3(Rect(0, 0, cx, cy)));
    q0.copyTo(psf_shifted(Rect(0, 0, cx, cy)));
    q1.copyTo(psf_shifted(Rect(cx, 0, cx, cy)));
    q2.copyTo(psf_shifted(Rect(0, cy, cx, cy)));
    q3.copyTo(psf_shifted(Rect(cx, cy, cx, cy)));

    Mat img_float;
    img.convertTo(img_float, CV_64F); // 将图像转换为双精度浮点型

    Mat img_padded;
    int pad_size = psf_shifted.cols / 2;
    copyMakeBorder(img_float, img_padded, pad_size, pad_size, pad_size, pad_size, BORDER_CONSTANT, Scalar(0)); // 对图像进行边界填充

    Mat img_fft;
    dft(img_padded, img_fft, DFT_COMPLEX_OUTPUT); // 对填充后的图像进行傅里叶变换

    Mat psf_fft;
    dft(psf_shifted, psf_fft, DFT_COMPLEX_OUTPUT); // 对中心化的点扩散函数进行傅里叶变换

    Mat img_fft_conj;
    complexConj(img_fft, img_fft_conj); // 对图像的傅里叶变换进行共轭

    Mat img_fft_conj_times_psf_fft;
    mulSpectrums(img_fft_conj, psf_fft, img_fft_conj_times_psf_fft, 0); // 对共轭后的图像傅里叶变换和点扩散函数傅里叶变换进行逐元素相乘

    Mat img_fft_conj_times_psf_fft_divided_by_psf_fft_squared;
    Mat psf_fft_squared;
    mulSpectrums(psf_fft, psf_fft, psf_fft_squared, 0);                                                            // 对点扩散函数傅里叶变换进行平方
    divide(img_fft_conj_times_psf_fft, psf_fft_squared, img_fft_conj_times_psf_fft_divided_by_psf_fft_squared, 0); // 对逐元素相乘的结果进行逐元素相除

    Mat img_fft_conj_times_psf_fft_divided_by_psf_fft_squared_ifft;
    idft(img_fft_conj_times_psf_fft_divided_by_psf_fft_squared, img_fft_conj_times_psf_fft_divided_by_psf_fft_squared_ifft, DFT_SCALE | DFT_REAL_OUTPUT); // 对逐元素相除的结果进行傅里叶逆变换

    Mat img_deblurred;
    img_fft_conj_times_psf_fft_divided_by_psf_fft_squared_ifft(Rect(pad_size, pad_size, img.cols, img.rows)).copyTo(img_deblurred); // 去除填充的边界

    img_deblurred.convertTo(img_deblurred, CV_8U); // 将图像转换为8位无符号整型
    imshow("Deblurred Image", img_deblurred);
    waitKey(0);

    return 0;
}
