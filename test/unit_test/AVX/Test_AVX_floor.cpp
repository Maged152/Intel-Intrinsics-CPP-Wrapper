#include "test_helper.h"
#include "gtest/gtest.h"
#include "shakhbat_avx.h"
#include <cmath>

// Define the test parameters types
struct AVXFloor : ::testing::TestWithParam<std::tuple<
    double, // min value
    double,  // max value
    test::vector_t
    >>
{};


template <class d_t, class vec_t>
void DoTest(const double min_val, const double max_val)
{
    constexpr float threshold = 0.0f;

    // vector objects
    vec_t vec1{};
    vec_t vec2{};

    // scalar objects
    test::Array<d_t> scal1{ vec1.Length() };
    test::Array<d_t> scal_dst{ vec1.Length() };
    test::Array<d_t> vec_dst{ vec1.Length() };

    // random initialization
    scal1.RandomInit(min_val, max_val);

    // do scalar operation
    auto scal_Floor = [](d_t in) { return std::floor(in); };
    scal1.Operation(scal_dst, scal_Floor);

    // load input vector
    vec1.Load(scal1.data);

    // do vector operation
    vec2 = vec1.Floor();

    // store results
    vec2.Store(vec_dst.data);

    // compare results
    bool res = test::Compare(vec_dst, scal_dst, threshold);

    EXPECT_EQ(res, true);
}

// Define a parameterized test case
TEST_P(AVXFloor, Test_AVXAdd)
{

    // extract the parameters
    auto& [min_val, max_val, vec_t] = GetParam();

    test::PrintParameter(min_val, "min_val");
    test::PrintParameter(max_val, "max_val");
    test::PrintParameter(vec_t, "data type");

    if (vec_t == test::vector_t::AVX_float)
    {
        DoTest<float, qlm::v8float_t>(min_val, max_val);
    }
}


// Instantiate the test case with combinations of values
INSTANTIATE_TEST_CASE_P(
    Test_AVXAdd, AVXFloor,
    ::testing::Combine(
        ::testing::Values(0.0, -100.0),
        ::testing::Values(1.0, 100.0),
        ::testing::Values(test::vector_t::AVX_float)
    ));