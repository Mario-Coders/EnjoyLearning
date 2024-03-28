#include <memory>

class ReallyBigType {};
std::weak_ptr<ReallyBigType> wptr;

void process(std::weak_ptr<ReallyBigType>) {
}

void test_shared_ptr_with_make_shared() {
  // some logic.
  // ......
  {
    auto sptr = std::make_shared<ReallyBigType>();

    wptr = sptr;
    auto another_sptr = wptr.lock();
    if (another_sptr) {
      // do something with another_sptr
    }
  }
  // Here, the ReallyBigType is destroyed but the memory formerly occupied
  // by large object remains allocated.
}

void test_shared_ptr_with_shared_ctor() {
  // some logic.
  // ......
  {
    std::shared_ptr<ReallyBigType> sptr(new ReallyBigType);

    wptr = sptr;
    auto another_sptr = wptr.lock();
    if (another_sptr) {
      // do something with another_sptr
    }
  }
  // Here, the ReallyBigType is destroyed and the memory occupied is released.
  // But, control block remains allocated.
}

int main() {
  return 0;
}
