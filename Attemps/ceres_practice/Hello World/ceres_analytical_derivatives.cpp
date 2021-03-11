#include<ceres/ceres.h>
#include <opencv2/core/core.hpp>
#include <chrono>
using namespace std;
using namespace ceres;
using ceres::AutoDiffCostFunction;
using ceres::CostFunction;
using ceres::Problem;
using ceres::Solver;

// 使用自动求导的方式
struct CostFunctor
{
  CostFunctor( double x, double y ) : _x ( x ), _y ( y ) {}
  template <typename T> bool operator()(const T* const bb,      //模型参数，有4维
                                        T* residual) const      //残差
  {
    residual[0] = bb[0]/pow(1.0+exp(bb[1]-bb[2]*T(_x)),1.0/bb[3])-T(_y);
    return true;
  }
  const double _x, _y;    // x,y数据
};
void optimizedAutoDiff(){

      double b1=1,b2=2,b3=3,b4=4;         // 真实参数值
      int N=100;                          // 数据点
      double w_sigma=0.001;                 // 噪声Sigma值
        cv::RNG rng;                        // OpenCV随机数产生器
        double bEst[4] = {1,1,1,1};            // b参数的估计值

        vector<double> x_data, y_data;      // 数据
        cout<<"generating data: "<<endl;
        for ( int i=0; i<N; i++ ) {
        double x = i/100.0;
        x_data.push_back ( x );
        y_data.push_back (b1/pow(1.0+exp(b2-b3*x),1.0/b4)+ rng.gaussian ( w_sigma ));
        cout<<x_data[i]<<" "<<y_data[i]<<endl;
        }
        // Build the problem.
        Problem problem;
        for ( int i=0; i<N; i++ )
        {
        CostFunction* cost_function =new AutoDiffCostFunction<CostFunctor, 1, 4>(new CostFunctor( x_data[i], y_data[i] ));
        problem.AddResidualBlock(cost_function, NULL, bEst);
        }

        // Run the solver!
        Solver::Options options;
        options.minimizer_progress_to_stdout = true;
        Solver::Summary summary;
        chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
        ceres::Solve ( options, &problem, &summary );
        chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
        chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>( t2-t1 );
        cout<<"solve time cost = "<<time_used.count()<<" seconds. "<<endl;

        std::cout << summary.BriefReport() << "\n";
        std::cout << "output b1: " << bEst[0] << "\n";
        std::cout << "output b2: " << bEst[1] << "\n";
        std::cout << "output b3: " << bEst[2] << "\n";
        std::cout << "output b4: " << bEst[3] << "\n";

 }

// 使用解析解， 告诉每个估计项的 雅克比矩阵
class Rat43Analytic : public SizedCostFunction<1,4> {
   public:
     Rat43Analytic(const double x, const double y) : x_(x), y_(y) {}
     virtual ~Rat43Analytic() {}  // 析构需要虚函数
     // Evaluate parameters作为输入，residuals作为残差输出和Jacobians作为雅可比矩阵的输出
     virtual bool Evaluate(double const* const* parameters,
                           double* residuals,
                           double** jacobians) const {
       const double b1 = parameters[0][0];  // 估计参数1 
       const double b2 = parameters[0][1]; // 估计参数2
       const double b3 = parameters[0][2];  // 估计参数3 
       const double b4 = parameters[0][3];  // 估计参数4 

       residuals[0] = b1 *  pow(1 + exp(b2 -  b3 * x_), -1.0 / b4) - y_;  // 定义 residual loss
       
    if (jacobians != NULL && jacobians[0] != NULL) {
        // b1-b4的偏导数
       jacobians[0][0] = pow(1 + exp(b2 - b3 * x_), -1.0 / b4);
       jacobians[0][1] = -b1 * exp(b2 - b3 * x_) *
                     pow(1 + exp(b2 - b3 * x_), -1.0 / b4 - 1) / b4;
       jacobians[0][2] = x_ * b1 * exp(b2 - b3 * x_) *
                     pow(1 + exp(b2 - b3 * x_), -1.0 / b4 - 1) / b4;
       jacobians[0][3] = b1 * log(1 + exp(b2 - b3 * x_)) *
                     pow(1 + exp(b2 - b3 * x_), -1.0 / b4) / (b4 * b4);
    }
       return true;
     }

    private:
     const double x_;
     const double y_;
 };

 void optimizedAnalyDiff()
 {
    double b1=1,b2=2,b3=3,b4=4;         // 真实参数值
    int N=100;                          // 数据点
    double w_sigma=0.001;                 // 噪声Sigma值
    cv::RNG rng;                        // OpenCV随机数产生器
    double bEst[4] = {1,1,1,1};            // b参数的估计值

    vector<double> x_data, y_data;      // 数据
    cout<<"generating data: "<<endl;
    for ( int i=0; i<N; i++ )
    {
        double x = i/100.0;
        x_data.push_back ( x );
        y_data.push_back (b1/pow(1.0+exp(b2-b3*x),1.0/b4)+ rng.gaussian ( w_sigma ));
        cout<<x_data[i]<<" "<<y_data[i]<<endl;
    }
    // Build the problem.
    Problem problem;
    for ( int i=0; i<N; i++ )
    {
        CostFunction* cost_function =new Rat43Analytic( x_data[i], y_data[i]);
        problem.AddResidualBlock(cost_function, NULL, bEst);
    }
    Solver::Options options;
    //  options.minimizer_progress_to_stdout = true;
    // Run the solver!
    Solver::Summary summary;
    chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
    ceres::Solve ( options, &problem, &summary );
    chrono::steady_clock::time_point t2 = chrono::steady_clock::now();
    chrono::duration<double> time_used = chrono::duration_cast<chrono::duration<double>>( t2-t1 );
    cout<<"solve time cost = "<<time_used.count()<<" seconds. "<<endl;

    std::cout << summary.BriefReport() << "\n";
    std::cout << "output b1: " << bEst[0] << "\n";
    std::cout << "output b2: " << bEst[1] << "\n";
    std::cout << "output b3: " << bEst[2] << "\n";
    std::cout << "output b4: " << bEst[3] << "\n";




 }


int main(int argc, char** argv)
{
  google::InitGoogleLogging(argv[0]);
optimizedAutoDiff();
optimizedAnalyDiff();
  return 0;
}
