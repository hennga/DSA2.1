//
// Created by marcel on 5/8/17.
//

#ifndef ADS_P3_CLION_RANDOM_GEN_H
#define ADS_P3_CLION_RANDOM_GEN_H

#include <random>


//random function die etwas besser ist
//http://stackoverflow.com/questions/5743678/generate-random-number-between-0-and-10
template <typename T>
T randomFrom(const T min, const T max)
{
    static std::random_device rdev;
    static std::default_random_engine re(rdev());
    typedef typename std::conditional<
            std::is_floating_point<T>::value,
    std::uniform_real_distribution<T>,
            std::uniform_int_distribution<T>>::type dist_type;
    dist_type uni(min, max);
    return static_cast<T>(uni(re));
}




#endif //ADS_P3_CLION_RANDOM_GEN_H
