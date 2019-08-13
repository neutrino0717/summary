class boVector {
    int size;
    double* arr_;
  public:
    boVector(const boVector& rhs){ //copy constructor
      size = rhs.size;
      arr_ = new double[size];
      for (int i=0; i<size; i++) { arr_[i] = rhs.arr_[i];}
    }
    ~boVector() { delete arr_; }
};

int main(){
}
