#include <Eigen/Core>
#include <Eigen/LU>
#include <Eigen/QR>
#include <Eigen/Cholesky>
#include <Eigen/Geometry>
#include <Eigen/Jacobi>
#include <Eigen/Eigenvalues>
#include <iostream>

using namespace Eigen;
using namespace std;

int main(int, char**)
{
  cout.precision(3);
  MatrixXd X = MatrixXd::Random(5,5);
MatrixXd A = X + X.transpose();
cout << "Here is a random symmetric 5x5 matrix:" << endl << A << endl << endl;

VectorXd diag(5);
VectorXd subdiag(4);
internal::tridiagonalization_inplace(A, diag, subdiag, true);
cout << "The orthogonal matrix Q is:" << endl << A << endl;
cout << "The diagonal of the tridiagonal matrix T is:" << endl << diag << endl;
cout << "The subdiagonal of the tridiagonal matrix T is:" << endl << subdiag << endl;

  return 0;
}
