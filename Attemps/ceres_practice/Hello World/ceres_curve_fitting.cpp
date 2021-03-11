#include <ceres/ceres.h>
#include <opencv2/core/core.hpp>
#include<vector>
using namespace std;
using ceres::AutoDiffCostFunction;
using ceres::CostFunction;
using ceres::Problem;
using ceres::Solver;
using ceres::Solve;


struct ExponentialResidual {
  ExponentialResidual(double x, double y)
      : x_(x), y_(y) {}
  template <typename T> bool operator()(const T* const m,
                                        const T* const c,
                                        T* residual) const {
    residual[0] = y_ - exp(m[0] * x_ + c[0]);
    return true;
  }
 private:
  const double x_;
  const double y_;
};
int main(int argc, char** argv) {
  google::InitGoogleLogging(argv[0]);

  double gt_m = 2.0;
  double gt_c =9.0;
  double m = 0.0;
  double c = 0.0;

int N=1000;                          // 数据点
double w_sigma=0.001;                 // 噪声Sigma值
cv::RNG rng;                        // OpenCV随机数产生器


    vector<double> x_data, y_data;      // 数据
    cout<<"generating data: "<<endl;
    for ( int i=0; i<N; i++ ) {
    double x = i/1000.0;
    x_data.push_back ( x );
    y_data.push_back (exp(gt_m * x + gt_c)+ rng.gaussian ( w_sigma ));
    }

  Problem problem;
  for (int i = 0; i < N; ++i) {
    problem.AddResidualBlock(
        new AutoDiffCostFunction<ExponentialResidual, 1, 1, 1>(
            new ExponentialResidual(x_data[i], y_data[i])),
        NULL,
        &m, &c);
  }
  Solver::Options options;
  options.max_num_iterations = 25;
  options.linear_solver_type = ceres::DENSE_QR;
  options.minimizer_progress_to_stdout = true;
  Solver::Summary summary;
  Solve(options, &problem, &summary);
  std::cout << summary.BriefReport() << "\n";
  std::cout << "Initial m: " << 0.0 << " c: " << 0.0 << "\n";
  std::cout << "Final   m: " << m << " c: " << c << "\n";
  return 0;
}

