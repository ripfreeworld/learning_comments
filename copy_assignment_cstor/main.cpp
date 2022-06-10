#include <iostream>
#include <string>

class SelfManageResource
{
public:
    SelfManageResource():
        i(0),
        p_str(new std::string("abc"))
    {}

    SelfManageResource(const SelfManageResource& _toCopy):
        i(_toCopy.i),
        p_str(new std::string(*_toCopy.p_str))
    {

    }

    SelfManageResource operator=(const SelfManageResource& _toAssign){
        auto new_str = new std::string(*_toAssign.p_str);
        delete p_str;
        this->p_str = new_str;

        this->i = _toAssign.i;
        return *this;
    }

    ~SelfManageResource(){
        delete p_str;
    }

private:
    int i;
    std::string* p_str;
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
