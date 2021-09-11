#include <cassert>
#include <tuptup.hpp>

template<typename T>
struct is_over2byte{
    constexpr static bool value = sizeof(T) >= 2;
};

int main(){
    std::tuple<std::string, int, int> sii{"test", 5, 6};
    
    auto filtered = tuptup::tuple_filter<std::is_integral>(sii);
    assert((filtered == std::tuple<int, int>{5, 6}));

    assert((std::is_same<
        tuptup::tuple_filter_t<is_over2byte, std::tuple<int8_t, int16_t, int8_t, int64_t>>,
        std::tuple<int16_t, int64_t>
    >::value));
}