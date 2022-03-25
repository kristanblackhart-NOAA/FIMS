#include <iostream>
#include "../inst/include/common/data_object.hpp"

int main() {
    fims::DataObject<double> dobject(5);
    std::cout<<"size = "<<dobject.get_imax()<<std::endl;
    for(int i=0; i < dobject.get_imax(); i++){
          dobject.at(i) = i;
          std::cout<<dobject(i)<<"\n";
    }
    return 0;
}
