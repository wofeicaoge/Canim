#include <iostream>
#include <animation/animation.h>

int main()
{
    std::cout<<"Welcome to Canim!"<<std::endl;
    animation anim(12);
    anim.echo();
    std::cout<<anim.get_run_time()<<std::endl;
    return 0;
}
