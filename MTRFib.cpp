#include <iostream>
using namespace std;
typedef pair<pair<long long, long long>, pair<long long, long long>> matrix;
#define x_ first
#define y_ second
long long p = 1000000007;


matrix mult(matrix a, matrix b){
    matrix c;
    c.y_.y_ = (a.y_.y_ * b.y_.y_ + a.y_.x_ * b.x_.y_) % p;
    c.x_.y_ = (a.x_.y_ * b.y_.y_ + a.x_.x_ * b.x_.y_) % p;
    c.y_.x_ = (a.y_.y_ * b.y_.x_ + a.y_.x_ * b.x_.x_) % p;
    c.x_.x_ = (a.x_.y_ * b.y_.x_ + a.x_.x_ * b.x_.x_) % p;
    return c;
}

pair<long long, long long> mult(matrix a, pair<long long, long long> b){
    pair<long long, long long> c;
    c.y_ = (a.y_.y_ * b.y_ + a.y_.x_ * b.x_) % p;
    c.x_ = (a.x_.y_ * b.y_ + a.x_.x_ * b.x_) % p;
    return c;
}

matrix copyOf(matrix a){
    matrix b;
    b.x_.x_ = a.x_.x_;
    b.x_.y_ = a.x_.y_;
    b.y_.x_ = a.y_.x_;
    b.y_.y_ = a.y_.y_;
    return b;
}

matrix pow(matrix x, long long e){
    matrix res = {{1, 0}, {0, 1}};

    while(e > 0){
        if(e % 2){
            res = mult(res, x);
        }
        e = e >> 1;
        x = mult(x, x);
    }
    return res;
}

pair<long long, long long> Fib(int n){
    matrix a = pow({{1, 1}, {1, 0}}, n - 1);
    return mult(a, {1, 1});
}

pair<long long, long long> sum(pair<long long, long long> a, pair<long long, long long> b){
    pair<long long, long long> c;
    c.y_ = (a.y_ + b.y_) % p;
    c.x_ = (a.x_ + b.x_) % p;
    return c;
}

int main() {
    int n;
    std::cin >> n;
    cout << Fib(n).y_ << endl;
}
